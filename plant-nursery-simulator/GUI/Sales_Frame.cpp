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
void __fastcall TfrmSales::cmbPlantSelectionChange(TObject *Sender)
{
	// VALIDATION OF PLANT SELECTION MUST STILL OCCUR
	if (cmbPlantSelection->Text != "Plant") {
		cmbPotSizeSelection->Enabled = true;
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSales::cmbPotSizeSelectionChange(TObject *Sender)
{
	std::string potSize = AnsiString(cmbPotSizeSelection->Text).c_str();
	if (potSize == "Small" || potSize == "Medium" || potSize == "Large") {
		chkGiftWrapping->Enabled = true;
		btnAddToOrder->Enabled = true;
	}
	else {
        chkGiftWrapping->Enabled = false;
		btnAddToOrder->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmSales::btnAddToOrderClick(TObject *Sender)
{
	redtOrderDetails->Enabled = true;
    lbledtCustomerName->Enabled = true;
	// Add to Order

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
