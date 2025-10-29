//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Add_Plant.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAddPlant *frmAddPlant;
//---------------------------------------------------------------------------
__fastcall TfrmAddPlant::TfrmAddPlant(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAddPlant::btnCancelClick(TObject *Sender)
{
    frmAddPlant->Close();
}
//---------------------------------------------------------------------------
