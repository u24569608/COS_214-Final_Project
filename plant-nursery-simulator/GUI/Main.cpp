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
	// --- Create Strategy Instances ---
    // Create one of each concrete strategy to be used as default prototypes
    stratFreqWater = std::make_unique<FrequentWatering>();
    stratSparseWater = std::make_unique<SparseWatering>();
    stratSeasonalWater = std::make_unique<SeasonalWatering>();
    stratLiquidFert = std::make_unique<LiquidFertilizer>();
    stratOrganicFert = std::make_unique<OrganicFertilizer>();
	stratSlowFert = std::make_unique<SlowReleaseFertilizer>();

	PopulatePrototypeComboBox();


	// --- BEGIN Mediator Pattern Setup ---
	// Create the Mediator object
	objMediator = std::make_unique<NurseryMediator>();

	// Create Colleagues
	//    The constructor is Colleague(int id, FloorMediator* mediator)
	vtrColleagues.push_back(std::make_unique<Staff>(101, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(201, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(202, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Staff>(102, objMediator.get()));

	// Register all colleagues with the mediator
	for (const auto& colleague : vtrColleagues) {
		objMediator->addColleague(colleague.get());
	}

	// Fill GUI combo boxes with the IDs
	PopulateColleagueComboBoxes();
	// --- END Mediator Pattern Setup ---

    // Populate the customer selection combobox on the Sales Frame
	PopulateCustomerComboBox();
    UpdateOrderDisplay();

	// --- Core System Setup (Composite & Prototype) ---

	// Create the Plant Prototype Registry
	objPrototypeRegistry = std::make_unique<PlantPrototypeRegistry>();

    // THIS NEEDS TO BE POPULATED DIFFERNTLY -- NB
	// Add concrete prototypes to the registry using ConcretePlant
	objPrototypeRegistry->addPrototype("Rose", std::make_unique<ConcretePlant>("Rose", "Flower"));
	objPrototypeRegistry->addPrototype("Fern", std::make_unique<ConcretePlant>("Fern", "Foliage"));
	objPrototypeRegistry->addPrototype("Spruce", std::make_unique<ConcretePlant>("Spruce", "Conifer"));

	// Create the main Greenhouse root
	objGreenhouse = std::make_unique<GreenhouseBed>("Main Greenhouse");

    // Add another empty bed
	objGreenhouse->add(new GreenhouseBed("Empty Bed"));


	// === Populate the TreeView ===
	tvGreenhouse->Items->Clear();
	PopulateGreenhouseTree(nullptr, objGreenhouse.get());
	tvGreenhouse->FullExpand();

	// === Populate the Prototype ComboBox ===
	//    (We'll add this later when implementing the Clone button)
	// PopulatePrototypeComboBox();

    // --- Create Inventory Object ---
	objInventory = std::make_unique<Inventory>();

    // Give the Inventory pointers to the other systems it needs
    objInventory->setPlantRegistry(objPrototypeRegistry.get());
	objInventory->setGreenhouseRoot(objGreenhouse.get());


    // --- Sales System Setup ---
	// Create Payment Processor
	objPaymentProcessor = std::make_unique<PaymentProcessor>();

	// Create the Order Builder (Concrete Builder)
	objOrderBuilder = std::make_unique<CustomOrderBuilder>();

    // Create an initial empty order for the builder to manage
    objOrderBuilder->createNewOrder();

	// Create the Sales Facade, passing pointers to subsystems
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

	// Populate the item selection combobox on the Sales Frame
	PopulateSalesItemComboBox();

    PopulateGreenhouseBedComboBox(objGreenhouse.get());
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
	// Display Welcome Message in Log
	redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Welcome to Plant Palace!");
}
//---------------------------------------------------------------------------

void TfrmMain::PopulateColleagueComboBoxes()
{
	// Clear any old items
	cmbSender->Clear();
	cmbReceiver->Clear();

	cmbSender->Text = "Sender";
	cmbReceiver->Text = "Receiver";

	// Loop through list of Colleague objects
	for (const auto& colleague : vtrColleagues)
	{
		// Get the INT ID and convert it to a UnicodeString
		UnicodeString idString = colleague->getID();

		// Add the ID string to both comboboxes
		cmbSender->Items->Add(idString);
		cmbReceiver->Items->Add(idString);
	}
}

void __fastcall TfrmMain::btnSendClick(TObject *Sender)
{
    // Get all the data from the GUI
	UnicodeString senderIdStr = cmbSender->Text;
	UnicodeString receiverIdStr = cmbReceiver->Text;
	std::string message = AnsiString(edtMessageBody->Text).c_str();

	// Convert GUI strings back to INTs
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

	// Find the sender Colleague object in our list (using the INT ID)
	Colleague* sender = nullptr;
	for (const auto& colleague : vtrColleagues) {
		if (colleague->getID() == senderId) {
			sender = colleague.get();
			break;
		}
	}

	// Call the backend send() method
	if (sender != nullptr) {
		sender->send(message, receiverId);

		// Log the message to the RichEdit (using ID strings)
		UnicodeString logLine = senderIdStr + " -> " + receiverIdStr + ": " + message.c_str();
		redtMessages->Lines->Add(logLine);

		// Clear the message box
		edtMessageBody->Text = "";
	} else {
		redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] ERROR: Could not find Sender Object");
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnClearMessagesClick(TObject *Sender)
{
    // Clear the Message Output
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

	// Get the name from the component
	std::string name = component->getName();

	// Create a new TTreeNode
	TTreeNode* node;
	if (parentNode == nullptr) { // Root node
		node = tvGreenhouse->Items->Add(nullptr, name.c_str());
	} else { // Child node
		node = tvGreenhouse->Items->AddChild(parentNode, name.c_str());
	}

	// Store the C++ object pointer in the node's Data property
	node->Data = component;

	// Check if the component is a GreenhouseBed (Composite)
	GreenhouseBed* bed = dynamic_cast<GreenhouseBed*>(component);
	if (bed != nullptr)
	{
		// It's a bed, so get its iterator
		std::unique_ptr<GreenhouseIterator> it = bed->createIterator();

		// Loop using the iterator
		if (it) {
			// Start at the first item
			GreenhouseComponent* child = it->first();
			// Loop while hasNext() is true
			while (child != nullptr) {
				// Recursively call this function for the child
				PopulateGreenhouseTree(node, child);
				// Advance to the next item
				child = it->next();
			}
		}
	}
}

void __fastcall TfrmMain::tvGreenhouseChange(TObject *Sender, TTreeNode *Node)
{
	// On Greenhouse List View Change
	// Get the currently selected node in the TreeView
	TTreeNode* selectedNode = tvGreenhouse->Selected;

	// Check if a node is actually selected
	if (selectedNode != nullptr && selectedNode->Data != nullptr)
	{
		// Get the C++ object stored in the node's Data property
		GreenhouseComponent* component = static_cast<GreenhouseComponent*>(selectedNode->Data);

		// Try to safely cast it to a PlantInstance*
		PlantInstance* plant = dynamic_cast<PlantInstance*>(component);

		// Check if the cast was successful (i.e., the user clicked a plant)
		if (plant != nullptr)
		{
			// --- Update the Greenhouse Information Frame ---
			// a) Plant Name: Use getName() from the base GreenhouseComponent
			frmGreenhouseInformation1->lbledtPlantName->Text = plant->getName().c_str();

			// b) Plant State: Get the state object and then its name
			const PlantState* currentState = plant->getState(); //
			if (currentState != nullptr) {
				frmGreenhouseInformation1->lbledtPlantState->Text = currentState->getName().c_str();
			} else {
				frmGreenhouseInformation1->lbledtPlantState->Text = "Unknown State";
			}

			// c) Growth Progress Bar. Using HEALTH for now...
			int health = plant->getHealth(); //
			frmGreenhouseInformation1->pbGrowth->Position = health;

			// d) Enable care buttons (since a plant is selected)
			frmGreenhouseInformation1->rgWaterStrategy->Enabled = true;
			frmGreenhouseInformation1->rgFertiliseStrategy->Enabled = true;

			frmGreenhouseInformation1->enableDisableCareButtons();

			return; // Exit after updating for a plant
		}
	}

	// --- If no node selected, or it wasn't a plant ---
	// Clear the details and disable care buttons
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
	// LOAD INVENTORY
	// Show the Open Dialogue
	if (dlgOpenLoadInventory->Execute())
	{
		// Get file path and extension
		UnicodeString uFileName = dlgOpenLoadInventory->FileName;
		UnicodeString uExt = ExtractFileExt(uFileName);
		std::string filePath = AnsiString(uFileName).c_str();

		// Create the correct Adapter
		FileAdapter* adapter = nullptr;
		if (uExt.LowerCase() == ".csv") {
			adapter = new CSVAdapter();
		} else if (uExt.LowerCase() == ".txt") {
			adapter = new TXTAdapter();
		}

		// Load the file using the adapter
		if (adapter != nullptr) {
			try {
				objInventory->loadFromFile(adapter, filePath);

				// Refresh the ListView display
				RefreshInventoryListView();

                // Populate the sales dropdown
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
    // ADD INVENTORY TO LIST VIEW
	// Clear previous items
	lvInventory->Items->Clear();

	// Get iterator (returns InventoryIterator*)
	InventoryIterator* itRaw = objInventory->createIterator();
    if (!itRaw) {
		redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] ERROR: Could not get Inventory Iterator");
		return;
	}
    std::unique_ptr<InventoryIterator> it(itRaw);

	// Loop through inventory using first() / next() / hasNext()
	for (StockItem* item = it->first(); it->hasNext(); item = it->next())
	{
		if (item) {
			item = it->currentItem();
			if (!item) continue;

			// Create a new item in the TListView
			TListItem *listItem = lvInventory->Items->Add();

			// --- Populate ListView Columns ---
			listItem->Caption = item->getname().c_str();
			listItem->SubItems->Add(FloatToStrF(item->getPrice(), ffCurrency, 8, 2));
			listItem->SubItems->Add(item->getDisplayStatus().c_str());
		}
	}
}
void __fastcall TfrmMain::btnInventoryUpClick(TObject *Sender)
{
    // Scroll Up
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
    // Scroll Down
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
    // SAVE INVENTORY TO FILE
	// Show the Save Dialogue
	if (dlgSaveSaveInventory->Execute())
	{
		// Get the chosen file path and determine extension
		UnicodeString uFileName = dlgSaveSaveInventory->FileName;
		UnicodeString uExt = ExtractFileExt(uFileName);
		std::string filePath = AnsiString(uFileName).c_str();

		// Create the correct Adapter based on the file extension
		FileAdapter* adapter = nullptr;
		if (uExt.LowerCase() == ".csv") {
			adapter = new CSVAdapter();
		} else if (uExt.LowerCase() == ".txt") {
			adapter = new TXTAdapter();
		}

		// Save inventory using the adapter
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

// Populates the item selection dropdown on the Sales Frame
void TfrmMain::PopulateSalesItemComboBox()
{
    // Access the combobox on the Sales Frame instance (frmSales1)
	frmSales1->cmbItemSelection->Clear();

	// Use Inventory Iterator to get available items
	InventoryIterator* itRaw = objInventory->createIterator();
    if (!itRaw) return; // Handle error if iterator fails
    std::unique_ptr<InventoryIterator> it(itRaw);

	// Loop and add item names to the combobox
    for (StockItem* item = it->first(); it->hasNext(); item = it->next())
	{
        item = it->currentItem(); // Get current item
        if (item && item->getIsAvailible()) // Only add available items
        {
			frmSales1->cmbItemSelection->Items->Add(item->getname().c_str());
		}
	}

    frmSales1->cmbItemSelection->ItemIndex = -1;
	frmSales1->cmbItemSelection->Text = "Select an Item";
}

// Updates the RichEdit on the Sales Frame to show the current order
void TfrmMain::UpdateOrderDisplay()
{
   // Access the RichEdit on the Sales Frame instance (frmSales1)
	frmSales1->redtOrderDetails->Clear();
	frmSales1->redtOrderDetails->Lines->Add("(Order is empty)"); // Initial message

	// Disable controls
	frmSales1->redtOrderDetails->Enabled = false;
   //	frmSales1->lbledtCustomerName->Enabled = false;
	frmSales1->btnProcessPayment->Enabled = false;
   //	frmSales1->lbledtCustomerName->Text = "";

    // Reset the frame's internal total counter
    frmSales1->currentOrderTotal = 0.0;
}
void __fastcall TfrmMain::FormActivate(TObject *Sender)
{
     frmSales1->currentOrderTotal = 0.0;
}
//---------------------------------------------------------------------------
void TfrmMain::PopulateCustomerComboBox()
{
    frmSales1->cmbCustomerSelect->Clear(); // Use the new ComboBox name

    for (const auto& colleague : vtrColleagues) {
        // Try to cast to Customer*
        Customer* cust = dynamic_cast<Customer*>(colleague.get());
        if (cust != nullptr) { // Only add if it's actually a Customer
            UnicodeString idString = cust->getID(); // Get the int ID
            frmSales1->cmbCustomerSelect->Items->Add(idString);
        }
    }

    // Set prompt text instead of selecting first item
    frmSales1->cmbCustomerSelect->ItemIndex = -1;
    frmSales1->cmbCustomerSelect->Text = "Select Customer ID";
    // Disable payment button until customer is selected
    frmSales1->btnProcessPayment->Enabled = false;
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::btnAddPlantToRegistryClick(TObject *Sender)
{
	// frmAddPlant->Show();
    // 1. Create the form instance
    std::unique_ptr<TfrmAddPlant> AddForm = std::make_unique<TfrmAddPlant>(this);

    // 2. Show it as a modal dialog
    if (AddForm->ShowModal() == mrOk)
    {
        // 3. User clicked "Add". Get the data from the form's properties
        std::string plantName = AnsiString(AddForm->lbledtPlantName->Text).c_str();
        int waterIndex = AddForm->rgWaterStrategy->ItemIndex;
        int fertIndex = AddForm->rgFertiliseStrategy->ItemIndex;

        // 4. Create the new ConcretePlant prototype
        // (ConcretePlant helper class is defined at top of Main.cpp)
        auto newProto = std::make_unique<ConcretePlant>(plantName, "Plant"); // "Plant" as default type

        // 5. Select the correct WaterStrategy* based on ItemIndex
        WaterStrategy* ws = nullptr;
        if (waterIndex == 0) ws = stratFreqWater.get();
        else if (waterIndex == 1) ws = stratSparseWater.get();
        else if (waterIndex == 2) ws = stratSeasonalWater.get();

        // 6. Select the correct FertilizeStrategy* based on ItemIndex
        FertilizeStrategy* fs = nullptr;
        if (fertIndex == 0) fs = stratLiquidFert.get();
        else if (fertIndex == 1) fs = stratOrganicFert.get();
        else if (fertIndex == 2) fs = stratSlowFert.get();

        // 7. Set the default strategies on the new prototype
        newProto->setDefaultWaterStrat(ws);
        newProto->setDefaultFertStrat(fs);

        // 8. Add the new prototype to the main registry
        objPrototypeRegistry->addPrototype(plantName, std::move(newProto));

        // 9. Refresh the prototype ComboBox to show the new addition
        PopulatePrototypeComboBox();
        // Also add the new item directly to the combobox
        cmbPrototypes->Items->Add(plantName.c_str());

        // 10. Log it
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
    // Go to the "System Admin" tab's combobox
    cmbPrototypes->Clear(); //
    cmbPrototypes->Text = "Plant";
    cmbPrototypes->Items->Add("Rose");
	cmbPrototypes->Items->Add("Fern");
	cmbPrototypes->Items->Add("Spruce");

}
void __fastcall TfrmMain::btnClonePlantClick(TObject *Sender)
{
	// VALIDATE PROTOTYPE SELECTION
	std::string prototypeName = AnsiString(cmbPrototypes->Text).c_str();
	if (cmbPrototypes->ItemIndex == -1 || prototypeName.empty() || cmbPrototypes->Text == "No Prototypes Registered") {
		ShowMessage("Please select a plant prototype to clone.");
		cmbPrototypes->SetFocus();
		return;
	}

	// VALIDATE GREENHOUSE BED SELECTION
	if (cmbGreenhouseSelection->ItemIndex == -1 || cmbGreenhouseSelection->Text == "Select a Bed...") {
		ShowMessage("Please select a greenhouse bed from the dropdown.");
		cmbGreenhouseSelection->SetFocus();
		return;
	}

	// Get the GreenhouseBed* pointer from the ComboBox
	GreenhouseBed* bed = reinterpret_cast<GreenhouseBed*>(cmbGreenhouseSelection->Items->Objects[cmbGreenhouseSelection->ItemIndex]);
	if (bed == nullptr) {
		ShowMessage("An error occurred. The selected bed is invalid.");
		return;
	}

	// VALIDATE PRICE
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
		// CLONE THE PROTOTYPE (Prototype Pattern - FR2)
		Plant* prototypeClone = objPrototypeRegistry->createPlant(prototypeName, ""); //
		if (!prototypeClone) {
			ShowMessage(UnicodeString("Error: Could not clone prototype '") + prototypeName.c_str() + "'.");
			return;
		}

		// CREATE THE PLANT INSTANCE
		PlantInstance* newPlant = new PlantInstance(prototypeClone, ""); //
		delete prototypeClone;
        prototypeClone = nullptr;

		// CREATE THE STOCK ITEM
		auto newStockItem = std::make_unique<StockItem>(
			newPlant->getName(),
			itemPrice,
			newPlant
		); //
		std::string newStockItemName = newStockItem->getname();

		// ADD TO BACKEND SYSTEMS
		bed->add(newPlant);
		objInventory->additem(std::move(newStockItem));

		// REFRESH ALL UIs
		tvGreenhouse->Items->Clear();
		PopulateGreenhouseTree(nullptr, objGreenhouse.get());
		tvGreenhouse->FullExpand();

		RefreshInventoryListView();
		PopulateSalesItemComboBox();

		// Log and clear price
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

