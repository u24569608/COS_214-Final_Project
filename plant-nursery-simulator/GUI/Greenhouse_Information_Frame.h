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

/**
 * @file Greenhouse_Information_Frame.h
 * @brief VCL frame displaying live data and actions for a selected plant.
 */
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
	TProgressBar *pbWater;
	TProgressBar *pbNutrients;
	TLabel *lblNutrientLevelHeading;
	TLabeledEdit *lbledtSaleReadiness;
    /**
     * @brief Reacts to user selection of a new water strategy.
     */
	void __fastcall rgWaterStrategyClick(TObject *Sender);

    /**
     * @brief Reacts to user selection of a new fertilise strategy.
     */
	void __fastcall rgFertiliseStrategyClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
    /**
     * @brief Constructs the greenhouse information frame and initialises controls.
     * @param Owner Component that owns the frame.
     */
	__fastcall TfrmGreenhouseInformation(TComponent* Owner);

    /**
     * @brief Enables or disables care buttons based on plant availability.
     */
	void enableDisableCareButtons();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGreenhouseInformation *frmGreenhouseInformation;
//---------------------------------------------------------------------------
#endif
