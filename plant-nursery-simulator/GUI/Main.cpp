//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Greenhouse_Information_Frame.h"
#include "Sales_Frame.h"
#include <System.SysUtils.hpp>
#include "Add_Plant.h"
#include "Add_Item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Greenhouse_Information_Frame"
#pragma link "Sales_Frame"
#pragma resource "*.dfm"
TfrmMain *frmMain;

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
    stratFreqWater = std::make_unique<FrequentWatering>();
    stratSparseWater = std::make_unique<SparseWatering>();
    stratSeasonalWater = std::make_unique<SeasonalWatering>();
    stratLiquidFert = std::make_unique<LiquidFertilizer>();
    stratOrganicFert = std::make_unique<OrganicFertilizer>();
	stratSlowFert = std::make_unique<SlowReleaseFertilizer>();

	PopulatePrototypeComboBox();

	objMediator = std::make_unique<NurseryMediator>();

	vtrColleagues.push_back(std::make_unique<Staff>(101, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(201, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(202, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Staff>(102, objMediator.get()));

	for (const auto& colleague : vtrColleagues) {
		objMediator->addColleague(colleague.get());
	}

	PopulateColleagueComboBoxes();

	PopulateCustomerComboBox();
    UpdateOrderDisplay();

	objPrototypeRegistry = std::make_unique<PlantPrototypeRegistry>();

	objPrototypeRegistry->addPrototype("Rose", std::make_unique<ConcretePlant>("Rose", "Flower"));
	objPrototypeRegistry->addPrototype("Fern", std::make_unique<ConcretePlant>("Fern", "Foliage"));
	objPrototypeRegistry->addPrototype("Spruce", std::make_unique<ConcretePlant>("Spruce", "Conifer"));

	objGreenhouse = std::make_unique<GreenhouseBed>("Main Greenhouse");

	objGreenhouse->add(new GreenhouseBed("Empty Bed"));

	tvGreenhouse->Items->Clear();
	PopulateGreenhouseTree(nullptr, objGreenhouse.get());
	tvGreenhouse->FullExpand();

	objInventory = std::make_unique<Inventory>();

	objInventory->setPlantRegistry(objPrototypeRegistry.get());
	objInventory->setGreenhouseRoot(objGreenhouse.get());

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

    WireStaffTaskEvents();
	RefreshStaffTaskQueue();
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
	redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Welcome to Plant Palace!");
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
        redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] ERROR: Invalid Sender or Receiver ID");
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
		redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] ERROR: Could not find Sender Object");
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

	if (selectedNode != nullptr && selectedNode->Data != nullptr)
	{

		GreenhouseComponent* component = static_cast<GreenhouseComponent*>(selectedNode->Data);

		PlantInstance* plant = dynamic_cast<PlantInstance*>(component);

		if (plant != nullptr)
		{

			frmGreenhouseInformation1->lbledtPlantName->Text = plant->getName().c_str();


			const PlantState* currentState = plant->getState();
			if (currentState != nullptr) {
				frmGreenhouseInformation1->lbledtPlantState->Text = currentState->getName().c_str();
			} else {
				frmGreenhouseInformation1->lbledtPlantState->Text = "Unknown State";
			}


			int health = plant->getHealth();
			frmGreenhouseInformation1->pbGrowth->Position = health;


			frmGreenhouseInformation1->rgWaterStrategy->Enabled = true;
			frmGreenhouseInformation1->rgFertiliseStrategy->Enabled = true;

			frmGreenhouseInformation1->enableDisableCareButtons();

			return;
		}
	}
	frmGreenhouseInformation1->lbledtPlantName->Text = "—";
	frmGreenhouseInformation1->lbledtPlantState->Text = "—";
	frmGreenhouseInformation1->pbGrowth->Position = 0;
	frmGreenhouseInformation1->pbWater->Position = 0;
	frmGreenhouseInformation1->pbNutrients->Position = 0;
	frmGreenhouseInformation1->rgWaterStrategy->Enabled = false;
	frmGreenhouseInformation1->rgFertiliseStrategy->Enabled = false;
	frmGreenhouseInformation1->btnWater->Enabled = false;
	frmGreenhouseInformation1->btnFertilise->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnLoadInventoryClick(TObject *Sender)
{
	if (dlgOpenLoadInventory->Execute())
	{

		UnicodeString uFileName = dlgOpenLoadInventory->FileName;
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
				objInventory->loadFromFile(adapter, filePath);

				RefreshInventoryListView();

                PopulateSalesItemComboBox();

				redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Successfully Loaded Inventory from '" + uFileName + "'");
			}
			catch (const std::exception &ex) {
				redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Error Loading File: " + String(ex.what()));
			}
			delete adapter;
		} else {
			redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] ERROR: Unsupported File Type Selected");
		}
	}
}
//---------------------------------------------------------------------------
void TfrmMain::RefreshInventoryListView()
{
	lvInventory->Items->Clear();

	InventoryIterator* itRaw = objInventory->createIterator();
    if (!itRaw) {
		redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] ERROR: Could not get Inventory Iterator");
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
				redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Successfully Saved Inventory to '" + uFileName + "'");
			}
			catch (const std::exception &ex) {
				redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Error Saving File: " + String(ex.what()));
			}
			delete adapter;
		} else {
			redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] ERROR: Could Not Determine File Type to Save");
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

		cmbPrototypes->Items->Add(plantName.c_str());

        redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] New Prototype Registered: '" + plantName.c_str() + "'");
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
    cmbPrototypes->Text = "Plant";
    cmbPrototypes->Items->Add("Rose");
	cmbPrototypes->Items->Add("Fern");
	cmbPrototypes->Items->Add("Spruce");

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

		tvGreenhouse->Items->Clear();
		PopulateGreenhouseTree(nullptr, objGreenhouse.get());
		tvGreenhouse->FullExpand();

		RefreshInventoryListView();
		PopulateSalesItemComboBox();

		redtLog->Lines->Add(UnicodeString("[") + DateTimeToStr(Now()) + "] New Plant '" + newStockItemName.c_str() + "' Created and Planted");
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

    if (lvStaffTaskQueue->Columns->Count == 0) {
		TListColumn* c1 = lvStaffTaskQueue->Columns->Add(); c1->Caption = "Staff ID";       c1->Width = 200;
		TListColumn* c2 = lvStaffTaskQueue->Columns->Add(); c2->Caption = "Pending Tasks";  c2->Width = 200;
		TListColumn* c3 = lvStaffTaskQueue->Columns->Add(); c3->Caption = "Reminders";      c3->Width = 200;
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
			item->SubItems->Add(IntToStr(staff->getCareReminderCount()));


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


	staff->processNextTask();

	redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Staff " + selected->Caption +
						" processed one task.");

    RefreshStaffTaskQueue();
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

