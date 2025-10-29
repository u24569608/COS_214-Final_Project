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
	redtOrderDetails->Enabled = true;
    lbledtCustomerName->Enabled = true;
	// Add to Order

    // 1. Get selected item name
	UnicodeString selectedItemNameU = cmbItemSelection->Text;
	std::string selectedItemName = AnsiString(selectedItemNameU).c_str();

	if (selectedItemName.empty()) {
		ShowMessage("Please select an item to add.");
		return;
	}

	// 2. Find the StockItem in the main form's inventory
    // Access main form's inventory via the global frmMain pointer
	StockItem* itemToAdd = frmMain->objInventory->findItem(selectedItemName); // ASSUMPTION: Inventory has findItem(string name) returning StockItem* [Likely based on Inventory.cpp/h]

	if (!itemToAdd) {
		ShowMessage("Error: Could not find '" + selectedItemNameU + "' in inventory.");
		return;
	}
    if (!itemToAdd->getIsAvailible()) { //
        ShowMessage("Sorry, '" + selectedItemNameU + "' is currently out of stock.");
        return;
    }

	// 3. Use the main form's OrderBuilder to add the item
    // CustomOrderBuilder::addItem takes StockItem*
    try {
	    frmMain->objOrderBuilder->addItem(itemToAdd);

        // 4. Update the order display on this frame by calling main form's helper
        frmMain->UpdateOrderDisplay(); // NOW we update the display

        // 5. Enable downstream controls if they aren't already
        redtOrderDetails->Enabled = true;
        lbledtCustomerName->Enabled = true;
        // Check if customer name allows payment button enable
        lbledtCustomerNameChange(Sender); // Trigger check
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

