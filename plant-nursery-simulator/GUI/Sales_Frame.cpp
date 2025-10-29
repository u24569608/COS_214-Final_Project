//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sales_Frame.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSales *frmSales;
// Pot Size Selection
//---------------------------------------------------------------------------
__fastcall TfrmSales::TfrmSales(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSales::btnAddToOrderClick(TObject *Sender)
{
	// 1. Get selected item name from ComboBox
	UnicodeString selectedItemNameU = cmbItemSelection->Text;
	std::string selectedItemName = AnsiString(selectedItemNameU).c_str();

	// Validate selection (check for empty or placeholder text)
	if (selectedItemName.empty() || selectedItemNameU == "Select an Item") {
		ShowMessage("Please select an item to add.");
		return;
	}

	// 2. Find the StockItem in the main form's inventory
	// Access main form's inventory via the global frmMain pointer
	StockItem* itemToAdd = frmMain->objInventory->findItem(selectedItemName); // ASSUMPTION: Inventory has findItem(string name) returning StockItem*

	// Validate item found and available
	if (!itemToAdd) {
		ShowMessage("Error: Could not find '" + selectedItemNameU + "' in inventory.");
		return;
	}
	if (!itemToAdd->getIsAvailible()) { //
		ShowMessage("Sorry, '" + selectedItemNameU + "' is currently out of stock.");
		return;
	}

	// 3. Use the main form's OrderBuilder to add the item
	try {
		// Call backend builder's addItem
		frmMain->objOrderBuilder->addItem(itemToAdd);

		// 4. === Manually update the RichEdit display ===
		// If this is the first item, clear the "(Order is empty)" text
		if (redtOrderDetails->Text == "(Order is empty)") {
			 redtOrderDetails->Clear();
			 redtOrderDetails->Lines->Add("Current Order:");
			 redtOrderDetails->Lines->Add("--------------------");
		}

		// Add the newly added item's details to the display
		UnicodeString line = " - ";
		line += itemToAdd->getname().c_str(); //
		line += " (";
		// StockItem::getPrice returns int, cast to double for currency format
		line += FloatToStrF(static_cast<double>(itemToAdd->getPrice()), ffCurrency, 8, 2);
		line += ")";
		redtOrderDetails->Lines->Add(line);

		// NOTE: We cannot display the running total here without calling getOrder(),
		// which would break subsequent adds. Total is calculated by Facade later.

		// 5. Enable downstream controls now that order has items
		redtOrderDetails->Enabled = true;
		lbledtCustomerName->Enabled = true;
		// Trigger the check for enabling the payment button based on customer name
		lbledtCustomerNameChange(Sender);
	}
	catch (const std::exception& ex) {
		 // Display any errors from the backend addItem call
		 ShowMessage("Error adding item to order: " + String(ex.what()));
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSales::lbledtCustomerNameChange(TObject *Sender)
{
	if (lbledtCustomerName->Text.Length() > 0) {
		btnProcessPayment->Enabled = true;
	} else {
        btnProcessPayment->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmSales::cmbItemSelectionChange(TObject *Sender)
{
	if (cmbItemSelection->Text != "Select an Item") {
        btnAddToOrder->Enabled = true;
	}
}
//---------------------------------------------------------------------------

