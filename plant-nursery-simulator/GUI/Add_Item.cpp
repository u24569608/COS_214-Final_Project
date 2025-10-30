//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Add_Item.h"
#include "Main.h"
#include <memory>
#include <System.SysUtils.hpp>
#include "../include/StockItem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAddItem *frmAddItem;
//---------------------------------------------------------------------------
__fastcall TfrmAddItem::TfrmAddItem(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAddItem::btnCancelClick(TObject *Sender)
{
    frmAddItem->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmAddItem::btnAddClick(TObject *Sender)
{
    // 1. Get and validate Name
    std::string itemName = AnsiString(lbledtItemName->Text).c_str();
    if (itemName.empty()) {
        ShowMessage("Item Name cannot be Empty");
        lbledtItemName->SetFocus();
        return;
    }

    // 2. Get and validate Price
    double itemPrice = 0.0;
    try {
        itemPrice = StrToFloat(lbledtItemPrice->Text);
    }
    catch(const EConvertError &e) {
        ShowMessage("Invalid Price. Please enter a Valid Number (e.g., 12.99).");
        lbledtItemPrice->SetFocus();
        return;
    }
    if (itemPrice <= 0) {
		ShowMessage("Price must be Greater than Zero.");
        lbledtItemPrice->SetFocus();
        return;
    }

    try
    {
        // 3. Create the new StockItem
        // We pass nullptr because this form only adds non-plant items
        auto newItem = std::make_unique<StockItem>(itemName, itemPrice, nullptr); //

        // 4. Add the new item to the main Inventory object
        frmMain->objInventory->additem(std::move(newItem)); //

        // 5. Refresh the main UI to show the new item
        frmMain->RefreshInventoryListView(); //
        frmMain->PopulateSalesItemComboBox(); //
        frmMain->redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Successfully Added Item to Inventory: '" + lbledtItemName->Text + "'");

		// Before we close the form, let us reset it.
		lbledtItemName->Clear();
		lbledtItemPrice->Clear();
		btnAdd->Enabled = false;
		lbledtItemPrice->Enabled = false;

        // 6. Close this "Add Item" form
        Close();
    }
    catch (const std::exception& ex)
    {
		// ShowMessage("An error occurred while adding the item: " + String(ex.what()));
        frmMain->redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] An error occurred while adding the item: '" + String(ex.what()) + "'");
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddItem::lbledtItemNameChange(TObject *Sender)
{
    lbledtItemPrice->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddItem::lbledtItemPriceChange(TObject *Sender)
{
    btnAdd->Enabled = true;
}
//---------------------------------------------------------------------------

