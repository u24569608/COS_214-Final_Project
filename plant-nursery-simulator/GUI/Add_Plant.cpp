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

void __fastcall TfrmAddPlant::lbledtPlantNameChange(TObject *Sender)
{
    rgWaterStrategy->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddPlant::rgWaterStrategyClick(TObject *Sender)
{
    rgFertiliseStrategy->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddPlant::rgFertiliseStrategyClick(TObject *Sender)
{
    btnAdd->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddPlant::btnAddClick(TObject *Sender)
{
    // 1. Validate Plant Name
    if (lbledtPlantName->Text.IsEmpty()) {
        ShowMessage("Please enter a name for the plant prototype.");
        lbledtPlantName->SetFocus();
        return; // Stay on the form
    }

    // 2. Validate Water Strategy selection
    if (rgWaterStrategy->ItemIndex == -1) {
        ShowMessage("Please select a default watering strategy.");
        rgWaterStrategy->SetFocus();
        return;
    }

    // 3. Validate Fertilize Strategy selection
    if (rgFertiliseStrategy->ItemIndex == -1) {
        ShowMessage("Please select a default fertilizing strategy.");
        rgFertiliseStrategy->SetFocus();
        return;
    }

    // 4. All checks passed. Set ModalResult to mrOk and the form will close.
	this->ModalResult = mrOk;
}
//---------------------------------------------------------------------------

