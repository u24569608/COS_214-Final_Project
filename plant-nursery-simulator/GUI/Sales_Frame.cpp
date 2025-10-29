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
