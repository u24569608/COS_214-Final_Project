//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Add_Item.h"
#include "Main.h"
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
