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
	// 1. Get selected item name
	UnicodeString selectedItemNameU = cmbItemSelection->Text;
	std::string selectedItemName = AnsiString(selectedItemNameU).c_str();

	// Validate selection
	if (selectedItemName.empty() || selectedItemNameU == "Select an Item") {
		ShowMessage("Please select an item to add.");
		return;
	}

	// 2. Find the StockItem
	StockItem* itemToAdd = frmMain->objInventory->findItem(selectedItemName); //

	// Validate item found and available
	if (!itemToAdd) {
		ShowMessage("Error: Could not find '" + selectedItemNameU + "' in inventory.");
		return;
	}
	if (!itemToAdd->getIsAvailible()) { //
		ShowMessage("Sorry, '" + selectedItemNameU + "' is currently out of stock.");
		return;
	}

	// 3. Use the OrderBuilder to add the item
	try {
		frmMain->objOrderBuilder->addItem(itemToAdd); //

		// --- Update Total and Display ---

		// a) Add item price to running total
		// StockItem::getPrice() returns int, cast to double
		currentOrderTotal += static_cast<double>(itemToAdd->getPrice());

		// b) Manually update the RichEdit display
		if (redtOrderDetails->Text == "(Order is empty)") {
			 redtOrderDetails->Clear();
			 redtOrderDetails->Lines->Add("Current Order:");
			 redtOrderDetails->Lines->Add("--------------------");
		} else {
            // Remove the old total line if it exists (usually the last line)
            if (redtOrderDetails->Lines->Count > 0 && redtOrderDetails->Lines->Strings[redtOrderDetails->Lines->Count - 1].Pos("Total Due:") == 1) {
                redtOrderDetails->Lines->Delete(redtOrderDetails->Lines->Count - 1);
            }
             // Remove the separator line above the total
            if (redtOrderDetails->Lines->Count > 0 && redtOrderDetails->Lines->Strings[redtOrderDetails->Lines->Count - 1] == "--------------------") {
                 redtOrderDetails->Lines->Delete(redtOrderDetails->Lines->Count - 1);
            }
        }


		// Add the newly added item's details
		UnicodeString line = " - ";
		line += itemToAdd->getname().c_str(); //
		line += " (";
		line += FloatToStrF(static_cast<double>(itemToAdd->getPrice()), ffCurrency, 8, 2);
		line += ")";
		redtOrderDetails->Lines->Add(line);

        // Add separator and the NEW total line
        redtOrderDetails->Lines->Add("--------------------");
        redtOrderDetails->Lines->Add("Total Due: " + FloatToStrF(currentOrderTotal, ffCurrency, 8, 2));


		// 5. Enable downstream controls
		redtOrderDetails->Enabled = true;
		lbledtCustomerName->Enabled = true;
		lbledtCustomerNameChange(Sender); // Trigger check for payment button
	}
	catch (const std::exception& ex) {
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

