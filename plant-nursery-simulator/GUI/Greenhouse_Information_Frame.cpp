//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Greenhouse_Information_Frame.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

void TfrmGreenhouseInformation::enableDisableCareButtons() {
	if (rgWaterStrategy->ItemIndex != -1 ) {
		btnWater->Enabled = true;
	} else {
		btnWater->Enabled = false;
	}

	if (rgFertiliseStrategy->ItemIndex != -1) {
		btnFertilise->Enabled = true;
	} else {
        btnFertilise->Enabled = false;
    }
}

TfrmGreenhouseInformation *frmGreenhouseInformation;
//---------------------------------------------------------------------------
__fastcall TfrmGreenhouseInformation::TfrmGreenhouseInformation(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmGreenhouseInformation::rgWaterStrategyClick(TObject *Sender)
{
	enableDisableCareButtons();
}
//---------------------------------------------------------------------------
void __fastcall TfrmGreenhouseInformation::rgFertiliseStrategyClick(TObject *Sender)

{
	enableDisableCareButtons();
}
//---------------------------------------------------------------------------
