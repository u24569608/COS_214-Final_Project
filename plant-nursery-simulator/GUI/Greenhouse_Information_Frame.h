//---------------------------------------------------------------------------

#ifndef Greenhouse_Information_FrameH
#define Greenhouse_Information_FrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmGreenhouseInformation : public TFrame
{
__published:	// IDE-managed Components
	TLabeledEdit *lbledtPlantName;
	TLabeledEdit *lbledtPlantState;
	TProgressBar *pbGrowth;
	TLabel *lblGrowthLabelHeading;
	TRadioGroup *rgWaterStrategy;
	TRadioGroup *rgFertiliseStrategy;
	TBitBtn *btnWater;
	TBitBtn *btnFertilise;
	TGroupBox *grpAction;
	TComboBox *cmbStaffMember;
	TLabel *lblSelectStaffMemberHeading;
	TLabel *lblWaterLevelHeading;
	TProgressBar *ProgressBar1;
	TProgressBar *ProgressBar2;
	TLabel *lblNutrientLevelHeading;
	TLabeledEdit *lbledtSaleReadiness;
	void __fastcall rgWaterStrategyClick(TObject *Sender);
	void __fastcall rgFertiliseStrategyClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TfrmGreenhouseInformation(TComponent* Owner);
	void enableDisableCareButtons();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGreenhouseInformation *frmGreenhouseInformation;
//---------------------------------------------------------------------------
#endif
