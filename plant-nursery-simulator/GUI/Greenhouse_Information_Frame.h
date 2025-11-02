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
	TProgressBar *pbWater;
	TProgressBar *pbNutrients;
	TLabel *lblNutrientLevelHeading;
	TLabeledEdit *lbledtSaleReadiness;
	/**
	 * @brief Handles watering strategy selection updates and refreshes UI state.
	 * @param Sender Component raising the event.
	 */
	void __fastcall rgWaterStrategyClick(TObject *Sender);
	/**
	 * @brief Handles fertilising strategy selection updates and refreshes UI state.
	 * @param Sender Component raising the event.
	 */
	void __fastcall rgFertiliseStrategyClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
	/**
	 * @brief Initialises the greenhouse information frame controls.
	 * @param Owner Component that owns this frame.
	 */
	__fastcall TfrmGreenhouseInformation(TComponent* Owner);
	/**
	 * @brief Toggles care buttons based on the current context and selection.
	 */
	void enableDisableCareButtons();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmGreenhouseInformation *frmGreenhouseInformation;
//---------------------------------------------------------------------------
#endif
