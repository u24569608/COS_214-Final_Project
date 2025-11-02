//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Greenhouse_Information_Frame.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

void TfrmGreenhouseInformation::enableDisableCareButtons() {
	if (frmMain != nullptr) {
		frmMain->UpdateCareActionState();
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
