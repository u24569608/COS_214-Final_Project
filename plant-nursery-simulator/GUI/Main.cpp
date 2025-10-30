//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Greenhouse_Information_Frame.h"
#include "Sales_Frame.h"
#include <System.SysUtils.hpp>
#include "Add_Plant.h"
#include "Add_Item.h"
#include "../include/WaterPlant.h"
#include "../include/FertilizePlant.h"
#include "../include/Observer.h"
#include <algorithm>
#include <sstream>
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Greenhouse_Information_Frame"
#pragma link "Sales_Frame"
#pragma resource "*.dfm"
TfrmMain *frmMain;

namespace {
class UIPlantObserver : public Observer {
public:
	explicit UIPlantObserver(TfrmMain* owner) : owner(owner) {}

	void update(const ObserverEvent& event) override {
		if (owner != nullptr) {
			owner->HandlePlantObserverEvent(event);
		}
	}

private:
	TfrmMain* owner;
};
} // namespace

// --- Helper class to make the abstract Plant concrete ---
class ConcretePlant : public Plant {
	public:
		// Use Plant's setters since constructor might be protected or absent
		ConcretePlant(const std::string& nameValue, const std::string& typeValue) {
			setName(nameValue);
			setType(typeValue);
		}

		// Copy constructor needed for cloning
		ConcretePlant(const ConcretePlant& other) : Plant() {
			setName(other.getName());
			setType(other.getType());
		}


		// Implement the pure virtual clone() method
		Plant* clone() const override {
			return new ConcretePlant(*this);
		}
};
// --------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
    currentPlantSelection = nullptr;
    currentStaffSelection = nullptr;
    snapshotPlant = nullptr;
    currentPlantSnapshot.reset();
    plantLogObserver = std::make_unique<UIPlantObserver>(this);

    stratFreqWater = std::make_unique<FrequentWatering>();
    stratSparseWater = std::make_unique<SparseWatering>();
    stratSeasonalWater = std::make_unique<SeasonalWatering>();
    stratLiquidFert = std::make_unique<LiquidFertilizer>();
    stratOrganicFert = std::make_unique<OrganicFertilizer>();
	stratSlowFert = std::make_unique<SlowReleaseFertilizer>();

	objMediator = std::make_unique<NurseryMediator>();

	vtrColleagues.push_back(std::make_unique<Staff>(101, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(201, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(202, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Staff>(102, objMediator.get()));

	for (const auto& colleague : vtrColleagues) {
		objMediator->addColleague(colleague.get());
	}

	RegisterStaffLoggers();

	PopulateColleagueComboBoxes();

	PopulateCustomerComboBox();
    UpdateOrderDisplay();

	objPrototypeRegistry = std::make_unique<PlantPrototypeRegistry>();

	objPrototypeRegistry->addPrototype("Rose", std::make_unique<ConcretePlant>("Rose", "Flower"));
	objPrototypeRegistry->addPrototype("Fern", std::make_unique<ConcretePlant>("Fern", "Foliage"));
	objPrototypeRegistry->addPrototype("Spruce", std::make_unique<ConcretePlant>("Spruce", "Conifer"));

	PopulatePrototypeComboBox();

	objGreenhouse = std::make_unique<GreenhouseBed>("Main Greenhouse");

	objGreenhouse->add(new GreenhouseBed("Empty Bed"));

	tvGreenhouse->Items->Clear();
	PopulateGreenhouseTree(nullptr, objGreenhouse.get());
	tvGreenhouse->FullExpand();

	objInventory = std::make_unique<Inventory>();

	objInventory->setPlantRegistry(objPrototypeRegistry.get());
	objInventory->setGreenhouseRoot(objGreenhouse.get());

	objGreenhouseController = std::make_unique<GreenhouseController>(objGreenhouse.get());

	objPaymentProcessor = std::make_unique<PaymentProcessor>();


	objOrderBuilder = std::make_unique<CustomOrderBuilder>();

    objOrderBuilder->createNewOrder();

	objSalesFacade = std::make_unique<SalesFacade>(
		objInventory.get(),
		objPaymentProcessor.get(),
		objOrderBuilder.get(),
		objGreenhouse.get(),
		objPrototypeRegistry.get()
	);

    objInventory->setPlantRegistry(objPrototypeRegistry.get());
    objInventory->setGreenhouseRoot(objGreenhouse.get());

	tvGreenhouse->Items->Clear();
	PopulateGreenhouseTree(nullptr, objGreenhouse.get());
	tvGreenhouse->FullExpand();

	PopulateSalesItemComboBox();

	PopulateGreenhouseBedComboBox(objGreenhouse.get());

	AttachGreenhouseFrameHandlers();
	AttachLoggerToAllPlants();

    WireStaffTaskEvents();
	RefreshStaffTaskQueue();
	UpdateCareActionState();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::edtMessageBodyChange(TObject *Sender)
{
	if (edtMessageBody->Text.Length() == 0) {
		btnSend->Enabled = false;
	}
	else if (edtMessageBody->Text.Length() > 0) {
		btnSend->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
	AppendLog("Welcome to Plant Palace!");
}
//---------------------------------------------------------------------------
void TfrmMain::PopulateColleagueComboBoxes()
{
	cmbSender->Clear();
	cmbReceiver->Clear();

	cmbSender->Text = "Sender";
	cmbReceiver->Text = "Receiver";

	for (const auto& colleague : vtrColleagues)
	{
		UnicodeString idString = colleague->getID();

		cmbSender->Items->Add(idString);
		cmbReceiver->Items->Add(idString);
	}

	PopulateStaffMemberComboBox();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnSendClick(TObject *Sender)
{

	UnicodeString senderIdStr = cmbSender->Text;
	UnicodeString receiverIdStr = cmbReceiver->Text;
	std::string message = AnsiString(edtMessageBody->Text).c_str();


	int senderId = -1;
	int receiverId = -1;

	try {
		senderId = std::stoi(AnsiString(senderIdStr).c_str());
		receiverId = std::stoi(AnsiString(receiverIdStr).c_str());
	}
	catch(...) {
		AppendLog("ERROR: Invalid Sender or Receiver ID");
		return;
	}

	Colleague* sender = nullptr;
	for (const auto& colleague : vtrColleagues) {
		if (colleague->getID() == senderId) {
			sender = colleague.get();
			break;
		}
	}

	if (sender != nullptr) {
		sender->send(message, receiverId);

		UnicodeString logLine = senderIdStr + " -> " + receiverIdStr + ": " + message.c_str();
		redtMessages->Lines->Add(logLine);

		edtMessageBody->Text = "";
	} else {
		AppendLog("ERROR: Could not find Sender Object");
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnClearMessagesClick(TObject *Sender)
{
    redtMessages->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnReverseClick(TObject *Sender)
{
	std::string sSender = AnsiString(cmbSender->Text).c_str();
	std::string sReceiver = AnsiString(cmbReceiver->Text).c_str();

	cmbSender->Text = sReceiver.c_str();
	cmbReceiver->Text = sSender.c_str();
}
//---------------------------------------------------------------------------
void TfrmMain::PopulateGreenhouseTree(TTreeNode* parentNode, GreenhouseComponent* component)
{
	if (component == nullptr) {
		return;
	}

	std::string name = component->getName();

	TTreeNode* node;
	if (parentNode == nullptr) {
		node = tvGreenhouse->Items->Add(nullptr, name.c_str());
	} else {
		node = tvGreenhouse->Items->AddChild(parentNode, name.c_str());
	}

	node->Data = component;

	GreenhouseBed* bed = dynamic_cast<GreenhouseBed*>(component);
	if (bed != nullptr)
	{
		std::unique_ptr<GreenhouseIterator> it = bed->createIterator();
		if (it) {
			GreenhouseComponent* child = it->first();
			while (child != nullptr) {
				PopulateGreenhouseTree(node, child);
				child = it->next();
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::tvGreenhouseChange(TObject *Sender, TTreeNode *Node)
{
	TTreeNode* selectedNode = tvGreenhouse->Selected;
	PlantInstance* plant = nullptr;
	if (selectedNode != nullptr && selectedNode->Data != nullptr) {
		GreenhouseComponent* component = static_cast<GreenhouseComponent*>(selectedNode->Data);
		plant = dynamic_cast<PlantInstance*>(component);
	}

	if (plant != nullptr) {
		currentPlantSelection = plant;
		UpdateSelectedPlantDisplay(false);
	} else {
		currentPlantSelection = nullptr;
		ClearPlantDetails();
	}

	UpdateCareActionState();
}

//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnLoadInventoryClick(TObject *Sender)
{
	if (!dlgOpenLoadInventory->Execute()) {
		return;
	}

	UnicodeString uFileName = dlgOpenLoadInventory->FileName;
	UnicodeString uExt = ExtractFileExt(uFileName);
	std::string filePath = AnsiString(uFileName).c_str();

	FileAdapter* adapter = nullptr;
	if (uExt.LowerCase() == ".csv") {
		adapter = new CSVAdapter();
	} else if (uExt.LowerCase() == ".txt") {
		adapter = new TXTAdapter();
	}

	if (adapter == nullptr) {
		AppendLog("ERROR: Unsupported File Type Selected");
		return;
	}

	try {
		objInventory->loadFromFile(adapter, filePath);

		tvGreenhouse->Items->BeginUpdate();
		try {
			tvGreenhouse->Items->Clear();
			PopulateGreenhouseTree(nullptr, objGreenhouse.get());
			tvGreenhouse->FullExpand();
		}
		__finally {
			tvGreenhouse->Items->EndUpdate();
		}

		currentPlantSelection = nullptr;
		ClearPlantDetails();

		RefreshInventoryListView();
		PopulateSalesItemComboBox();
		PopulatePrototypeComboBox();
		AttachLoggerToAllPlants();
		RefreshStaffTaskQueue();
		UpdateCareActionState();

		if (objGreenhouseController) {
			objGreenhouseController->setRootBed(objGreenhouse.get());
		}

		AppendLog(UnicodeString("Successfully loaded inventory from '") + uFileName + UnicodeString("'"));
	}
	catch (const std::exception &ex) {
		AppendLog(UnicodeString("Error loading file: ") + String(ex.what()));
	}
	delete adapter;
}

//---------------------------------------------------------------------------
void TfrmMain::RefreshInventoryListView()
{
	lvInventory->Items->Clear();

	InventoryIterator* itRaw = objInventory->createIterator();
    if (!itRaw) {
		AppendLog("ERROR: Could not get Inventory Iterator");
		return;
	}
    std::unique_ptr<InventoryIterator> it(itRaw);

	for (StockItem* item = it->first(); it->hasNext(); item = it->next())
	{
		if (item) {
			item = it->currentItem();
			if (!item) continue;

			TListItem *listItem = lvInventory->Items->Add();

			listItem->Caption = item->getname().c_str();
			listItem->SubItems->Add(FloatToStrF(item->getPrice(), ffCurrency, 8, 2));
			listItem->SubItems->Add(item->getDisplayStatus().c_str());
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnInventoryUpClick(TObject *Sender)
{
	if (lvInventory->ItemIndex > -1) {
		lvInventory->ItemIndex = lvInventory->ItemIndex - 1;
	} else {
		lvInventory->ItemIndex = 0;
        Beep();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnInventoryDownClick(TObject *Sender)
{
	if (lvInventory->ItemIndex < lvInventory->Items->Count - 1) {
		lvInventory->ItemIndex = lvInventory->ItemIndex + 1;
	} else {
		lvInventory->ItemIndex = lvInventory->Items->Count - 1;
        Beep();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnSaveInventoryClick(TObject *Sender)
{
	if (dlgSaveSaveInventory->Execute())
	{
		UnicodeString uFileName = dlgSaveSaveInventory->FileName;
		UnicodeString uExt = ExtractFileExt(uFileName);
		std::string filePath = AnsiString(uFileName).c_str();

		FileAdapter* adapter = nullptr;
		if (uExt.LowerCase() == ".csv") {
			adapter = new CSVAdapter();
		} else if (uExt.LowerCase() == ".txt") {
			adapter = new TXTAdapter();
		}


		if (adapter != nullptr) {
			try {
				adapter->saveInventory(filePath, objInventory.get());
				AppendLog(UnicodeString("Successfully saved inventory to '") + uFileName + UnicodeString("'"));
			}
			catch (const std::exception &ex) {
				AppendLog(UnicodeString("Error saving file: ") + String(ex.what()));
			}
			delete adapter;
		} else {
			AppendLog("ERROR: Could Not Determine File Type to Save");
		}
	}
}
//---------------------------------------------------------------------------
void TfrmMain::PopulateSalesItemComboBox()
{
	frmSales1->cmbItemSelection->Clear();

	InventoryIterator* itRaw = objInventory->createIterator();
	if (!itRaw) return;
    std::unique_ptr<InventoryIterator> it(itRaw);

    for (StockItem* item = it->first(); it->hasNext(); item = it->next())
	{
		item = it->currentItem();
		if (item && item->getIsAvailible())
        {
			frmSales1->cmbItemSelection->Items->Add(item->getname().c_str());
		}
	}

    frmSales1->cmbItemSelection->ItemIndex = -1;
	frmSales1->cmbItemSelection->Text = "Select an Item";
}
//---------------------------------------------------------------------------
void TfrmMain::UpdateOrderDisplay()
{
	frmSales1->redtOrderDetails->Clear();
	frmSales1->redtOrderDetails->Lines->Add("(Empty Order)");

	frmSales1->redtOrderDetails->Enabled = false;
	frmSales1->btnProcessPayment->Enabled = false;

    frmSales1->currentOrderTotal = 0.0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormActivate(TObject *Sender)
{
	 frmSales1->currentOrderTotal = 0.0;

}
//---------------------------------------------------------------------------
void TfrmMain::PopulateCustomerComboBox()
{
    frmSales1->cmbCustomerSelect->Clear();

	for (const auto& colleague : vtrColleagues) {
		Customer* cust = dynamic_cast<Customer*>(colleague.get());
		if (cust != nullptr) {
			UnicodeString idString = cust->getID();
            frmSales1->cmbCustomerSelect->Items->Add(idString);
        }
    }

    frmSales1->cmbCustomerSelect->ItemIndex = -1;
    frmSales1->cmbCustomerSelect->Text = "Select Customer ID";


    frmSales1->btnProcessPayment->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnAddPlantToRegistryClick(TObject *Sender)
{
	std::unique_ptr<TfrmAddPlant> AddForm = std::make_unique<TfrmAddPlant>(this);

	if (AddForm->ShowModal() == mrOk)
	{
        std::string plantName = AnsiString(AddForm->lbledtPlantName->Text).c_str();
        int waterIndex = AddForm->rgWaterStrategy->ItemIndex;
        int fertIndex = AddForm->rgFertiliseStrategy->ItemIndex;

		auto newProto = std::make_unique<ConcretePlant>(plantName, "Plant");


        WaterStrategy* ws = nullptr;
        if (waterIndex == 0) ws = stratFreqWater.get();
        else if (waterIndex == 1) ws = stratSparseWater.get();
        else if (waterIndex == 2) ws = stratSeasonalWater.get();

        FertilizeStrategy* fs = nullptr;
        if (fertIndex == 0) fs = stratLiquidFert.get();
        else if (fertIndex == 1) fs = stratOrganicFert.get();
        else if (fertIndex == 2) fs = stratSlowFert.get();

        newProto->setDefaultWaterStrat(ws);
        newProto->setDefaultFertStrat(fs);

        objPrototypeRegistry->addPrototype(plantName, std::move(newProto));


	PopulatePrototypeComboBox();

		AppendLog(UnicodeString("New Prototype Registered: '") + UnicodeString(plantName.c_str()) + UnicodeString("'"));
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnAddItemClick(TObject *Sender)
{
	frmAddItem->Show();
}
//---------------------------------------------------------------------------
void TfrmMain::PopulatePrototypeComboBox()
{
	cmbPrototypes->Clear();
	if (!objPrototypeRegistry) {
		cmbPrototypes->Text = "No Prototypes Registered";
		return;
	}

	auto names = objPrototypeRegistry->listPrototypes();
	std::sort(names.begin(), names.end());

	for (const auto& name : names) {
		cmbPrototypes->Items->Add(name.c_str());
	}

	if (cmbPrototypes->Items->Count == 0) {
		cmbPrototypes->Text = "No Prototypes Registered";
	} else {
		cmbPrototypes->Text = "Select Prototype";
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnClonePlantClick(TObject *Sender)
{
	std::string prototypeName = AnsiString(cmbPrototypes->Text).c_str();
	if (cmbPrototypes->ItemIndex == -1 || prototypeName.empty() || cmbPrototypes->Text == "No Prototypes Registered") {
		ShowMessage("Please select a plant prototype to clone.");
		cmbPrototypes->SetFocus();
		return;
	}

	if (cmbGreenhouseSelection->ItemIndex == -1 || cmbGreenhouseSelection->Text == "Select a Bed...") {
		ShowMessage("Please select a greenhouse bed from the dropdown.");
		cmbGreenhouseSelection->SetFocus();
		return;
	}

	GreenhouseBed* bed = reinterpret_cast<GreenhouseBed*>(cmbGreenhouseSelection->Items->Objects[cmbGreenhouseSelection->ItemIndex]);
	if (bed == nullptr) {
		ShowMessage("An error occurred. The selected bed is invalid.");
		return;
	}

	double itemPrice = 0.0;
	try {
		itemPrice = StrToFloat(lbledtPlantPrice->Text);
	}
	catch(const EConvertError &e) {
		ShowMessage("Invalid Price. Please enter a valid number (e.g., 14.99).");
		lbledtPlantPrice->SetFocus();
		return;
	}
	if (itemPrice <= 0) {
		ShowMessage("Price must be greater than zero.");
		lbledtPlantPrice->SetFocus();
		return;
	}

	try
	{
		Plant* prototypeClone = objPrototypeRegistry->createPlant(prototypeName, ""); //
		if (!prototypeClone) {
			ShowMessage(UnicodeString("Error: Could not Clone Prototype '") + prototypeName.c_str() + "'");
			return;
		}

		PlantInstance* newPlant = new PlantInstance(prototypeClone, ""); //
		delete prototypeClone;
        prototypeClone = nullptr;

		auto newStockItem = std::make_unique<StockItem>(
			newPlant->getName(),
			itemPrice,
			newPlant
		);
		std::string newStockItemName = newStockItem->getname();

	bed->add(newPlant);
	objInventory->additem(std::move(newStockItem));
	AttachObserverToPlant(newPlant);

		tvGreenhouse->Items->Clear();
		PopulateGreenhouseTree(nullptr, objGreenhouse.get());
		tvGreenhouse->FullExpand();

		RefreshInventoryListView();
		PopulateSalesItemComboBox();

	AppendLog(UnicodeString("New plant '") + UnicodeString(newStockItemName.c_str()) + UnicodeString("' created and planted"));
		lbledtPlantPrice->Text = "";

		lbledtPlantPrice->Enabled = false;
		cmbGreenhouseSelection->Enabled = false;
		cmbPrototypes->Text = "Plant";
        cmbGreenhouseSelection->Text = "Greenhouse";
	}
	catch (const std::exception& ex)
	{
		ShowMessage("An error occurred: " + String(ex.what()));
	}
}
//---------------------------------------------------------------------------
void TfrmMain::PopulateGreenhouseBedComboBox(GreenhouseComponent* component, const std::string& prefix)
{
	if (component == nullptr) return;

	GreenhouseBed* bed = dynamic_cast<GreenhouseBed*>(component);
	if (bed != nullptr)
	{
		std::string bedName = prefix + bed->getName();
		int index = cmbGreenhouseSelection->Items->Add(bedName.c_str());

		cmbGreenhouseSelection->Items->Objects[index] = (TObject*)bed;

		std::unique_ptr<GreenhouseIterator> it = bed->createIterator();
		if (it) {
			for (GreenhouseComponent* child = it->first(); it->hasNext(); child = it->next()) {
				child = it->currentItem();
				PopulateGreenhouseBedComboBox(child, bedName + " > ");
			}
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::cmbPrototypesChange(TObject *Sender)
{
    cmbGreenhouseSelection->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::cmbGreenhouseSelectionChange(TObject *Sender)
{
    lbledtPlantPrice->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::lbledtPlantPriceChange(TObject *Sender)
{
    btnClonePlant->Enabled = true;
}
//---------------------------------------------------------------------------
void TfrmMain::WireStaffTaskEvents()
{
    lvStaffTaskQueue->ViewStyle = vsReport;
    lvStaffTaskQueue->ReadOnly = true;
    lvStaffTaskQueue->RowSelect = true;
    lvStaffTaskQueue->HideSelection = false;

    lvStaffTaskQueue->Columns->BeginUpdate();
    try {
		lvStaffTaskQueue->Columns->Clear();
		TListColumn* c1 = lvStaffTaskQueue->Columns->Add();
		c1->Caption = "Staff ID";
		c1->Width = 200;
		TListColumn* c2 = lvStaffTaskQueue->Columns->Add();
		c2->Caption = "Pending Tasks";
		c2->Width = 200;
    }
    __finally {
		lvStaffTaskQueue->Columns->EndUpdate();
    }

    btnProcessNextTask->OnClick = btnProcessNextTaskClick;
}
//---------------------------------------------------------------------------
void TfrmMain::RefreshStaffTaskQueue()
{
    lvStaffTaskQueue->Items->BeginUpdate();
    try {
		lvStaffTaskQueue->Items->Clear();

        for (const auto& col : vtrColleagues) {
            auto* staff = dynamic_cast<Staff*>(col.get());
		if (!staff) continue;

		TListItem* item = lvStaffTaskQueue->Items->Add();
		item->Caption = IntToStr(staff->getID());
		item->SubItems->Add(IntToStr(staff->getTaskQueueSize()));


		item->Data = staff;
	}
    }
    __finally {
        lvStaffTaskQueue->Items->EndUpdate();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnProcessNextTaskClick(TObject *Sender)
{
    if (!lvStaffTaskQueue->Selected) {
        ShowMessage("Select a Staff Row First");
        return;
    }

    auto* selected = lvStaffTaskQueue->Selected;
    auto* staff = reinterpret_cast<Staff*>(selected->Data);
    if (!staff) {
		ShowMessage("Invalid Staff Selection");
        return;
    }

	if (staff->getTaskQueueSize() <= 0) {
		ShowMessage("No Tasks in this Staff Member's Queue");
        return;
    }


	const int staffId = staff->getID();
	PlantInstance* affectedPlant = staff->processNextTask();
	RefreshStaffTaskQueue();
	SelectStaffRowById(staffId);
	if (affectedPlant != nullptr && affectedPlant == currentPlantSelection) {
		UpdateSelectedPlantDisplay(false);
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::lvStaffTaskQueueSelectItem(TObject *Sender, TListItem *Item,
          bool Selected)
{
	if (lvStaffTaskQueue->ItemIndex != -1) {
		btnProcessNextTask->Enabled = true;
	} else {
        btnProcessNextTask->Enabled = false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::lvStaffTaskQueueDblClick(TObject *Sender)
{
	if (!lvStaffTaskQueue || !lvStaffTaskQueue->Selected) {
		return;
	}

	TListItem* item = lvStaffTaskQueue->Selected;
	auto* staff = item ? reinterpret_cast<Staff*>(item->Data) : nullptr;
	if (!staff) {
		ShowMessage("Invalid staff selection.");
		return;
	}

	const auto tasks = staff->describePendingTasks();
	UnicodeString header = "Tasks for Staff " + item->Caption;
	if (tasks.empty()) {
		ShowMessage(header + ": No pending tasks.");
		return;
	}

	UnicodeString message = header + ":\n";
	for (std::size_t i = 0; i < tasks.size(); ++i) {
		message += IntToStr(static_cast<int>(i + 1)) + ". " + UnicodeString(tasks[i].c_str()) + "\n";
	}
	ShowMessage(message);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnSimulateClick(TObject *Sender)
{
	if (!objGreenhouseController) {
		AppendLog("WARNING: Greenhouse controller unavailable");
		return;
	}

	objGreenhouseController->runGrowthTick();
	AppendLog("Simulation: Applied growth tick to all plants");

	if (currentPlantSelection != nullptr) {
		UpdateSelectedPlantDisplay(false);
	}

	RefreshInventoryListView();
	PopulateSalesItemComboBox();
	RefreshStaffTaskQueue();
	UpdateCareActionState();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::cmbStaffMemberChange(TObject *Sender)
{
	if (!frmGreenhouseInformation1) {
		return;
	}

	TComboBox* combo = frmGreenhouseInformation1->cmbStaffMember;
	currentStaffSelection = ResolveStaffFromCombo(combo->ItemIndex);
	if (currentStaffSelection == nullptr) {
		int staffId = 0;
		if (TryStrToInt(combo->Text, staffId)) {
			currentStaffSelection = FindStaffById(staffId);
		}
	}

	UpdateCareActionState();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnWaterClick(TObject *Sender)
{
	if (!currentPlantSelection || !currentStaffSelection) {
		ShowMessage("Select a plant and staff member first.");
		return;
	}

	currentStaffSelection->addCommandToQueue(std::make_unique<WaterPlant>(currentPlantSelection));
	RefreshStaffTaskQueue();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnFertiliseClick(TObject *Sender)
{
	if (!currentPlantSelection || !currentStaffSelection) {
		ShowMessage("Select a plant and staff member first.");
		return;
	}

	currentStaffSelection->addCommandToQueue(std::make_unique<FertilizePlant>(currentPlantSelection));
	RefreshStaffTaskQueue();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnAssignObserveClick(TObject *Sender)
{
	if (!currentPlantSelection || !currentStaffSelection) {
		ShowMessage("Select a plant and staff member first.");
		return;
	}

	currentStaffSelection->observePlant(currentPlantSelection);
	AppendLog(UnicodeString("Staff ") + IntToStr(currentStaffSelection->getID()) + UnicodeString(" now observing '") +
		UnicodeString(currentPlantSelection->getName().c_str()) + UnicodeString("'"));

	UpdateCareActionState();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::rgWaterStrategyClick(TObject *Sender)
{
	if (!currentPlantSelection) {
		UpdateCareActionState();
		return;
	}

	const int index = frmGreenhouseInformation1->rgWaterStrategy->ItemIndex;
	WaterStrategy* strategy = WaterStrategyFromIndex(index);
	if (!strategy) {
		return;
	}

	if (currentPlantSelection->getWaterStrategy() == strategy) {
		return;
	}

	currentPlantSelection->setWaterStrategy(strategy);
	AppendLog(UnicodeString("Updated watering strategy for '") + UnicodeString(currentPlantSelection->getName().c_str()) + UnicodeString("'"));
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::rgFertiliseStrategyClick(TObject *Sender)
{
	if (!currentPlantSelection) {
		UpdateCareActionState();
		return;
	}

	const int index = frmGreenhouseInformation1->rgFertiliseStrategy->ItemIndex;
	FertilizeStrategy* strategy = FertilizeStrategyFromIndex(index);
	if (!strategy) {
		return;
	}

	if (currentPlantSelection->getFertilizeStrategy() == strategy) {
		return;
	}

	currentPlantSelection->setFertilizeStrategy(strategy);
	AppendLog(UnicodeString("Updated fertilising strategy for '") + UnicodeString(currentPlantSelection->getName().c_str()) + UnicodeString("'"));
}
//---------------------------------------------------------------------------
void TfrmMain::PopulateStaffMemberComboBox()
{
	if (!frmGreenhouseInformation1) {
		return;
	}

	TComboBox* combo = frmGreenhouseInformation1->cmbStaffMember;
	combo->Items->BeginUpdate();
	try {
		combo->Items->Clear();
		combo->Text = "Staff Member";
		combo->ItemIndex = -1;

		for (const auto& colleague : vtrColleagues) {
			Staff* staff = dynamic_cast<Staff*>(colleague.get());
			if (!staff) {
				continue;
			}
			UnicodeString idText = IntToStr(staff->getID());
			combo->Items->AddObject(idText, reinterpret_cast<TObject*>(staff));
		}
	}
	__finally {
		combo->Items->EndUpdate();
	}

	currentStaffSelection = nullptr;
	UpdateCareActionState();
}
//---------------------------------------------------------------------------
void TfrmMain::AttachGreenhouseFrameHandlers()
{
	if (!frmGreenhouseInformation1) {
		return;
	}

	frmGreenhouseInformation1->btnWater->OnClick = btnWaterClick;
	frmGreenhouseInformation1->btnFertilise->OnClick = btnFertiliseClick;
	frmGreenhouseInformation1->cmbStaffMember->OnChange = cmbStaffMemberChange;
	frmGreenhouseInformation1->rgWaterStrategy->OnClick = rgWaterStrategyClick;
	frmGreenhouseInformation1->rgFertiliseStrategy->OnClick = rgFertiliseStrategyClick;
btnAssignObserve->OnClick = btnAssignObserveClick;
btnSimulate->OnClick = btnSimulateClick;
}
//---------------------------------------------------------------------------
void TfrmMain::AppendLog(const UnicodeString& message)
{
	redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] " + message);
}
//---------------------------------------------------------------------------
void TfrmMain::RegisterStaffLoggers()
{
	ResetStaffLoggers();
	for (const auto& colleague : vtrColleagues) {
		Staff* staff = dynamic_cast<Staff*>(colleague.get());
		if (!staff) {
			continue;
		}
		const int staffId = staff->getID();
		staff->setLogSink([this, staffId](const std::string& message) {
			AppendLog(UnicodeString(message.c_str()));
			RefreshStaffTaskQueue();
			SelectStaffRowById(staffId);
			UpdateSelectedPlantDisplay(false);
		});
	}
}
//---------------------------------------------------------------------------
void TfrmMain::ResetStaffLoggers()
{
	for (const auto& colleague : vtrColleagues) {
		Staff* staff = dynamic_cast<Staff*>(colleague.get());
		if (!staff) {
			continue;
		}
		staff->setLogSink({});
	}
}
//---------------------------------------------------------------------------
void TfrmMain::DetachObserverFromAllPlants()
{
	if (!plantLogObserver) {
		return;
	}

	std::vector<PlantInstance*> plants(loggedPlants.begin(), loggedPlants.end());
	for (PlantInstance* plant : plants) {
		if (plant != nullptr) {
			plant->detach(plantLogObserver.get());
		}
	}
	loggedPlants.clear();
}
//---------------------------------------------------------------------------
void TfrmMain::SelectStaffRowById(int staffId)
{
	if (!lvStaffTaskQueue) {
		return;
	}

	const UnicodeString idText = IntToStr(staffId);
	for (int index = 0; index < lvStaffTaskQueue->Items->Count; ++index) {
		TListItem* item = lvStaffTaskQueue->Items->Item[index];
		if (item != nullptr && item->Caption == idText) {
			item->Selected = true;
			item->Focused = true;
			item->MakeVisible(true);
			btnProcessNextTask->Enabled = true;
			return;
		}
	}

	btnProcessNextTask->Enabled = lvStaffTaskQueue->Selected != nullptr;
}
//---------------------------------------------------------------------------
void TfrmMain::AttachObserverToPlant(PlantInstance* plant)
{
	if (!plant || !plantLogObserver) {
		return;
	}

	if (loggedPlants.insert(plant).second) {
		plant->attach(plantLogObserver.get());
	}
}
//---------------------------------------------------------------------------
void TfrmMain::AttachLoggerToAllPlants()
{
	if (!objGreenhouse) {
		return;
	}

	DetachObserverFromAllPlants();

	std::unique_ptr<GreenhouseIterator> iterator = objGreenhouse->createIterator();
	if (!iterator) {
		return;
	}

	for (GreenhouseComponent* component = iterator->first(); component != nullptr; component = iterator->next()) {
		if (auto* instance = dynamic_cast<PlantInstance*>(component)) {
			AttachObserverToPlant(instance);
		}
	}
}
//---------------------------------------------------------------------------
TfrmMain::PlantDisplaySnapshot TfrmMain::BuildSnapshot(PlantInstance* plant) const
{
	PlantDisplaySnapshot snapshot{};
	snapshot.typeName = plant ? plant->getPlantTypeName() : "";
	snapshot.stateName = plant && plant->getState() ? plant->getState()->getName() : "Unknown State";
	snapshot.health = plant ? plant->getHealth() : 0;
	snapshot.water = plant ? plant->getWaterLevel() : 0;
	snapshot.nutrients = plant ? plant->getNutrientLevel() : 0;
	snapshot.saleReady = plant ? plant->isAvailableForSale() : false;
	return snapshot;
}
//---------------------------------------------------------------------------
void TfrmMain::LogSnapshotDelta(const PlantDisplaySnapshot& before,
	const PlantDisplaySnapshot& after,
	const UnicodeString& plantLabel)
{
	auto logDelta = [this, &plantLabel](const UnicodeString& metric, int oldValue, int newValue) {
		if (oldValue == newValue) {
			return;
		}
		const int delta = newValue - oldValue;
		UnicodeString message = plantLabel + UnicodeString(": ") + metric + UnicodeString(" changed to ") + IntToStr(newValue);
		if (delta != 0) {
			message += UnicodeString(" (") + (delta > 0 ? UnicodeString("+") : UnicodeString("")) + IntToStr(delta) + UnicodeString(")");
		}
		AppendLog(message);
	};

	logDelta("Health", before.health, after.health);
	logDelta("Water level", before.water, after.water);
	logDelta("Nutrient level", before.nutrients, after.nutrients);

	if (before.saleReady != after.saleReady) {
		AppendLog(plantLabel + UnicodeString(": Availability changed to ") + UnicodeString(after.saleReady ? "Available" : "Unavailable"));
	}
}
//---------------------------------------------------------------------------
void TfrmMain::HandlePlantObserverEvent(const ObserverEvent& event)
{
	PlantInstance* plant = event.source ? dynamic_cast<PlantInstance*>(event.source) : nullptr;
	if (!plant) {
		return;
	}

	if (event.type == ObserverEventType::SubjectDestroyed) {
		loggedPlants.erase(plant);
	} else {
		AttachObserverToPlant(plant);
	}

	UnicodeString plantLabel = UnicodeString(plant->getPlantTypeName().c_str()) + " (" + plant->getName().c_str() + ")";
	UnicodeString message;
	if (!event.message.empty()) {
		message = UnicodeString(event.message.c_str());
	} else if (event.type == ObserverEventType::AvailabilityChanged && event.availability.has_value()) {
		message = UnicodeString((*event.availability == AvailabilityStatus::Available) ? "Available" : "Unavailable");
	}

	if (!message.IsEmpty()) {
		AppendLog(plantLabel + ": " + message);
	}

	if (plant == currentPlantSelection) {
		UpdateSelectedPlantDisplay(false);
	}

	RefreshStaffTaskQueue();
	if (event.type == ObserverEventType::AvailabilityChanged) {
		RefreshInventoryListView();
	}
}
//---------------------------------------------------------------------------
__fastcall TfrmMain::~TfrmMain()
{
	ResetStaffLoggers();
	DetachObserverFromAllPlants();
}
void TfrmMain::LoadPlantDetails(PlantInstance* plant, bool logChanges)
{
	if (!plant || !frmGreenhouseInformation1) {
		return;
	}

	AttachObserverToPlant(plant);

	const bool samePlant = snapshotPlant == plant && currentPlantSnapshot.has_value();
	PlantDisplaySnapshot latest = BuildSnapshot(plant);
	UnicodeString plantLabel = UnicodeString(latest.typeName.c_str()) + " (" + plant->getName().c_str() + ")";

	if (logChanges && samePlant) {
		LogSnapshotDelta(*currentPlantSnapshot, latest, plantLabel);
	}

	currentPlantSnapshot = latest;
	snapshotPlant = plant;

	frmGreenhouseInformation1->lbledtPlantName->Text = plant->getName().c_str();
	frmGreenhouseInformation1->lbledtPlantState->Text = latest.stateName.c_str();
	frmGreenhouseInformation1->lbledtSaleReadiness->Text = latest.saleReady ? "Ready" : "Not Ready";
	frmGreenhouseInformation1->pbGrowth->Position = latest.health;
	frmGreenhouseInformation1->pbWater->Position = latest.water;
	frmGreenhouseInformation1->pbNutrients->Position = latest.nutrients;

	frmGreenhouseInformation1->rgWaterStrategy->ItemIndex = WaterStrategyIndexFromPointer(plant->getWaterStrategy());
	frmGreenhouseInformation1->rgFertiliseStrategy->ItemIndex = FertilizeStrategyIndexFromPointer(plant->getFertilizeStrategy());
	frmGreenhouseInformation1->rgWaterStrategy->Enabled = true;
	frmGreenhouseInformation1->rgFertiliseStrategy->Enabled = true;
}
//---------------------------------------------------------------------------
void TfrmMain::ClearPlantDetails()
{
	if (!frmGreenhouseInformation1) {
		return;
	}

	frmGreenhouseInformation1->lbledtPlantName->Text = "-";
	frmGreenhouseInformation1->lbledtPlantState->Text = "-";
	frmGreenhouseInformation1->lbledtSaleReadiness->Text = "-";
	frmGreenhouseInformation1->pbGrowth->Position = 0;
	frmGreenhouseInformation1->pbWater->Position = 0;
	frmGreenhouseInformation1->pbNutrients->Position = 0;
	frmGreenhouseInformation1->rgWaterStrategy->ItemIndex = -1;
	frmGreenhouseInformation1->rgFertiliseStrategy->ItemIndex = -1;
	frmGreenhouseInformation1->rgWaterStrategy->Enabled = false;
	frmGreenhouseInformation1->rgFertiliseStrategy->Enabled = false;
	currentPlantSnapshot.reset();
	snapshotPlant = nullptr;
}
//---------------------------------------------------------------------------
void TfrmMain::UpdateSelectedPlantDisplay(bool logChanges)
{
	if (currentPlantSelection != nullptr) {
		LoadPlantDetails(currentPlantSelection, logChanges);
	}
}
//---------------------------------------------------------------------------
void TfrmMain::UpdateCareActionState()
{
	if (!frmGreenhouseInformation1) {
		return;
	}

	const bool hasPlant = currentPlantSelection != nullptr;
	const bool hasStaff = currentStaffSelection != nullptr;

	frmGreenhouseInformation1->btnWater->Enabled = hasPlant && hasStaff;
	frmGreenhouseInformation1->btnFertilise->Enabled = hasPlant && hasStaff;
	btnAssignObserve->Enabled = hasPlant && hasStaff;
	frmGreenhouseInformation1->rgWaterStrategy->Enabled = hasPlant;
	frmGreenhouseInformation1->rgFertiliseStrategy->Enabled = hasPlant;
}
//---------------------------------------------------------------------------
Staff* TfrmMain::ResolveStaffFromCombo(int index) const
{
	if (!frmGreenhouseInformation1) {
		return nullptr;
	}

	TComboBox* combo = frmGreenhouseInformation1->cmbStaffMember;
	if (index < 0 || index >= combo->Items->Count) {
		return nullptr;
	}

	return reinterpret_cast<Staff*>(combo->Items->Objects[index]);
}
//---------------------------------------------------------------------------
Staff* TfrmMain::FindStaffById(int id) const
{
	for (const auto& colleague : vtrColleagues) {
		Staff* staff = dynamic_cast<Staff*>(colleague.get());
		if (staff && staff->getID() == id) {
			return staff;
		}
	}
	return nullptr;
}
//---------------------------------------------------------------------------
WaterStrategy* TfrmMain::WaterStrategyFromIndex(int index) const
{
	switch (index) {
		case 0: return stratFreqWater.get();
		case 1: return stratSparseWater.get();
		case 2: return stratSeasonalWater.get();
		default: return nullptr;
	}
}
//---------------------------------------------------------------------------
FertilizeStrategy* TfrmMain::FertilizeStrategyFromIndex(int index) const
{
	switch (index) {
		case 0: return stratLiquidFert.get();
		case 1: return stratOrganicFert.get();
		case 2: return stratSlowFert.get();
		default: return nullptr;
	}
}
//---------------------------------------------------------------------------
int TfrmMain::WaterStrategyIndexFromPointer(WaterStrategy* strategy) const
{
	if (dynamic_cast<FrequentWatering*>(strategy) != nullptr) {
		return 0;
	}
	if (dynamic_cast<SparseWatering*>(strategy) != nullptr) {
		return 1;
	}
	if (dynamic_cast<SeasonalWatering*>(strategy) != nullptr) {
		return 2;
	}
	return -1;
}
//---------------------------------------------------------------------------
int TfrmMain::FertilizeStrategyIndexFromPointer(FertilizeStrategy* strategy) const
{
	if (dynamic_cast<LiquidFertilizer*>(strategy) != nullptr) {
		return 0;
	}
	if (dynamic_cast<OrganicFertilizer*>(strategy) != nullptr) {
		return 1;
	}
	if (dynamic_cast<SlowReleaseFertilizer*>(strategy) != nullptr) {
		return 2;
	}
	return -1;
}
//---------------------------------------------------------------------------
