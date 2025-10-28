//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "Greenhouse_Information_Frame.h"
#include "Sales_Frame.h"
#include <System.SysUtils.hpp>
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
			setName(nameValue); // Use Plant's public setName
			setType(typeValue); // Use Plant's public setType
		}

		// Copy constructor needed for cloning
		ConcretePlant(const ConcretePlant& other) : Plant() {
			setName(other.getName());
			setType(other.getType());
			// Note: Does not copy default strategies from base Plant. Add if needed.
		}


		// Implement the pure virtual clone() method
		Plant* clone() const override {
			// Create a copy using the copy constructor
			return new ConcretePlant(*this); // Return raw pointer as per base class
		}
};
// --------------------------------------------------------------------------
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
	// --- BEGIN Mediator Pattern Setup ---
	// 1. Create the Mediator object
	objMediator = std::make_unique<NurseryMediator>();

	// 2. Create Colleagues
	//    The constructor is Colleague(int id, FloorMediator* mediator)
	vtrColleagues.push_back(std::make_unique<Staff>(101, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(201, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Customer>(202, objMediator.get()));
	vtrColleagues.push_back(std::make_unique<Staff>(102, objMediator.get()));

	// 3. Register all colleagues with the mediator
	for (const auto& colleague : vtrColleagues) {
		objMediator->addColleague(colleague.get());
	}

	// 4. Fill GUI combo boxes with the IDs
	PopulateColleagueComboBoxes();
	// --- END Mediator Pattern Setup ---




	// --- Core System Setup (Composite & Prototype) ---

	// 1. Create the Plant Prototype Registry
	objPrototypeRegistry = std::make_unique<PlantPrototypeRegistry>();

	// 2. Add concrete prototypes to the registry using ConcretePlant
	objPrototypeRegistry->addPrototype("Rose", std::make_unique<ConcretePlant>("Rose", "Flower"));
	objPrototypeRegistry->addPrototype("Fern", std::make_unique<ConcretePlant>("Fern", "Foliage"));
	objPrototypeRegistry->addPrototype("Spruce", std::make_unique<ConcretePlant>("Spruce", "Conifer"));

	// THIS NEEDS TO BE POPULATED DIFFERNTLY -- NB
	// 3. Create the main Greenhouse root
	objGreenhouse = std::make_unique<GreenhouseBed>("Main Greenhouse");

	// 4. Create a bed (using raw pointer for add() method)
	//    ASSUMPTION: GreenhouseBed::add TAKES OWNERSHIP of the raw pointer.
	//    If not, this will leak memory. You might need unique_ptr management.
	GreenhouseBed* roseBedPtr = new GreenhouseBed("Rose Bed");

	// 5. Create plant instances BY CLONING from the registry
	Plant* roseClone1 = objPrototypeRegistry->createPlant("Rose", ""); // Returns RAW pointer
	if (roseClone1) {
		// PlantInstance constructor takes RAW Plant*
		// GreenhouseBed::add takes RAW GreenhouseComponent*
		roseBedPtr->add(new PlantInstance(roseClone1, "Rose 1")); // ASSUMPTION: add() takes ownership
        // If PlantInstance does NOT copy prototype info AND Bed doesn't own prototype, delete needed.
        // Assuming PlantInstance copies or Bed add owns prototype:
         delete roseClone1; // Delete the clone AFTER instance uses it
	}

    Plant* roseClone2 = objPrototypeRegistry->createPlant("Rose", "");
    if (roseClone2) {
        roseBedPtr->add(new PlantInstance(roseClone2, "Rose 2"));
        delete roseClone2; // Delete the clone AFTER instance uses it
    }

	// 6. Add the bed (with plants) to the main greenhouse
	//    ASSUMPTION: add() takes ownership of roseBedPtr
	objGreenhouse->add(roseBedPtr);

    // Add another empty bed
    objGreenhouse->add(new GreenhouseBed("Empty Bed")); // Assumes add() takes ownership


	// 7. === Populate the TreeView ===
	// Make sure tvGreenhouse is the correct name of your TTreeView component
	tvGreenhouse->Items->Clear();
	PopulateGreenhouseTree(nullptr, objGreenhouse.get()); // Start recursion
	tvGreenhouse->FullExpand(); // Optional: expand all nodes

	// 8. === Populate the Prototype ComboBox ===
	//    (We'll add this later when implementing the Clone button)
	// PopulatePrototypeComboBox();

    // --- Create Inventory Object ---
	objInventory = std::make_unique<Inventory>();

    // Give the Inventory pointers to the other systems it needs
    objInventory->setPlantRegistry(objPrototypeRegistry.get());
    objInventory->setGreenhouseRoot(objGreenhouse.get());
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
	redtLog->Lines->Add("Welcome to Plant Palace!");
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
    // 1. Get all the data from the GUI
	UnicodeString senderIdStr = cmbSender->Text;
	UnicodeString receiverIdStr = cmbReceiver->Text;
	std::string message = AnsiString(edtMessageBody->Text).c_str();

	// 3. Convert GUI strings back to INTs
	int senderId = -1;
	int receiverId = -1;

	try {
		senderId = std::stoi(AnsiString(senderIdStr).c_str());
		receiverId = std::stoi(AnsiString(receiverIdStr).c_str());
	}
	catch(...) {
		ShowMessage("Error: Invalid Sender or Receiver ID");
		return;
	}

	// 4. Find the sender Colleague object in our list (using the INT ID)
	Colleague* sender = nullptr;
	for (const auto& colleague : vtrColleagues) {
		if (colleague->getID() == senderId) {
			sender = colleague.get();
			break;
		}
	}

	// 5. Call the backend send() method
	if (sender != nullptr) {
		// === THIS IS THE MEDIATOR PATTERN IN ACTION ===
		sender->send(message, receiverId);

		// 6. Log the message to the RichEdit (using ID strings)
		UnicodeString logLine = senderIdStr + " -> " + receiverIdStr + ": " + message.c_str();
		redtMessages->Lines->Add(logLine);

		// 7. Clear the message box
		edtMessageBody->Text = "";
	} else {
		ShowMessage("Error: Could not find sender object.");
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

	// 1. Get the name from the component
	std::string name = component->getName();

	// 2. Create a new TTreeNode
	TTreeNode* node;
	if (parentNode == nullptr) { // Root node
		node = tvGreenhouse->Items->Add(nullptr, name.c_str());
	} else { // Child node
		node = tvGreenhouse->Items->AddChild(parentNode, name.c_str());
	}

	// 3. Store the C++ object pointer in the node's Data property
	node->Data = component;

	// 4. Check if the component is a GreenhouseBed (Composite)
	GreenhouseBed* bed = dynamic_cast<GreenhouseBed*>(component);
	if (bed != nullptr)
	{
		// 5. It's a bed, so get its iterator
		std::unique_ptr<GreenhouseIterator> it = bed->createIterator();

		// 6. Loop using the iterator - CORRECTED LOOP
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
	// If it's not a bed, it's a PlantInstance (Leaf), so recursion stops here.
}

void __fastcall TfrmMain::tvGreenhouseChange(TObject *Sender, TTreeNode *Node)
{
	// On Greenhouse List View Change
    // 1. Get the currently selected node in the TreeView
	TTreeNode* selectedNode = tvGreenhouse->Selected;

	// 2. Check if a node is actually selected
	if (selectedNode != nullptr && selectedNode->Data != nullptr)
	{
		// 3. Get the C++ object stored in the node's Data property
		GreenhouseComponent* component = static_cast<GreenhouseComponent*>(selectedNode->Data);

		// 4. Try to safely cast it to a PlantInstance*
		PlantInstance* plant = dynamic_cast<PlantInstance*>(component);

		// 5. Check if the cast was successful (i.e., the user clicked a plant)
		if (plant != nullptr)
		{
			// --- Update the Greenhouse Information Frame ---
			// Ensure the frame pointer (e.g., frmGreenhouseInformation1) is correct

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
			// You might have a specific growth property later
			int health = plant->getHealth(); //
			frmGreenhouseInformation1->pbGrowth->Position = health;

			// d) Enable care buttons (since a plant is selected)
			frmGreenhouseInformation1->rgWaterStrategy->Enabled = true;
			frmGreenhouseInformation1->rgFertiliseStrategy->Enabled = true;
			// (Call the button enable/disable logic you wrote earlier)
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
	// Load Inventory
    // 1. Show the Open Dialog (Ensure name is dlgOpenLoadInventory)
	if (dlgOpenLoadInventory->Execute())
	{
		// 2. Get file path and extension
		UnicodeString uFileName = dlgOpenLoadInventory->FileName;
		UnicodeString uExt = ExtractFileExt(uFileName);
		std::string filePath = AnsiString(uFileName).c_str();

		// 3. Create the correct Adapter
		FileAdapter* adapter = nullptr;
		if (uExt.LowerCase() == ".csv") {
			adapter = new CSVAdapter(); //
		} else if (uExt.LowerCase() == ".txt") {
			adapter = new TXTAdapter(); //
		}

		// 4. Load the file using the adapter
		if (adapter != nullptr) {
			try {
				// Call backend Inventory::loadFromFile
				// WRONG order
				objInventory->loadFromFile(adapter, filePath);

				// 5. Refresh the ListView display
				RefreshInventoryListView(); // Call helper function

				ShowMessage("Inventory loaded successfully from '" + uFileName + "'");
			}
			catch (const std::exception &ex) {
				ShowMessage("Error loading file: " + String(ex.what()));
			}
			delete adapter; // Clean up adapter
		} else {
			ShowMessage("Error: Unsupported file type selected.");
		}
	}
}
//---------------------------------------------------------------------------

void TfrmMain::RefreshInventoryListView()
{
	// 1. Clear previous items (Ensure name is lvInventory)
	lvInventory->Items->Clear();

	// 2. Get iterator (returns InventoryIterator*)
	InventoryIterator* itRaw = objInventory->createIterator();
    if (!itRaw) {
		ShowMessage("Error: Could not get inventory iterator.");
		return;
	}
    // Use unique_ptr for automatic cleanup
    std::unique_ptr<InventoryIterator> it(itRaw);

	// 3. Loop through inventory using first() / next() / hasNext()
	for (StockItem* item = it->first(); it->hasNext(); item = it->next())
	{
		if (item) // Check if item is valid (currentItem might return null if hasNext is tricky)
		{
            item = it->currentItem(); // Get current item explicitly
            if (!item) continue; // Skip if somehow currentItem is null despite hasNext

			// 4. Create a new item in the TListView
			TListItem *listItem = lvInventory->Items->Add();

			// --- Populate ListView Columns ---
			// Column 0 (Caption): Item Name
			listItem->Caption = item->getname().c_str(); //

			// Column 1: Item Price (Ensure column exists in designer)
			listItem->SubItems->Add(FloatToStrF(item->getPrice(), ffCurrency, 8, 2)); //

			// Column 2: Availability Status (Ensure column exists in designer)
			listItem->SubItems->Add(item->getDisplayStatus().c_str()); //
		}
	}
     // Iterator unique_ptr automatically cleans up here
}
