//---------------------------------------------------------------------------

#ifndef Add_PlantH
#define Add_PlantH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TfrmAddPlant : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlBase;
	TButton *btnCancel;
	TButton *btnAdd;
	TLabel *lblBuildOrderHeading;
	TLabeledEdit *lbledtPlantName;
	TRadioGroup *rgFertiliseStrategy;
	TRadioGroup *rgWaterStrategy;
	/**
	 * @brief Cancels prototype creation and closes the dialog.
	 * @param Sender Component raising the event.
	 */
	void __fastcall btnCancelClick(TObject *Sender);
	/**
	 * @brief Enables strategy selection once a candidate name is entered.
	 * @param Sender Component raising the event.
	 */
	void __fastcall lbledtPlantNameChange(TObject *Sender);
	/**
	 * @brief Allows fertilising strategy selection after watering strategy is chosen.
	 * @param Sender Component raising the event.
	 */
	void __fastcall rgWaterStrategyClick(TObject *Sender);
	/**
	 * @brief Enables the add button after a fertilising strategy is confirmed.
	 * @param Sender Component raising the event.
	 */
	void __fastcall rgFertiliseStrategyClick(TObject *Sender);
	/**
	 * @brief Performs final validation and accepts the dialog.
	 * @param Sender Component raising the event.
	 */
	void __fastcall btnAddClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	/**
	 * @brief Initialises the add-plant dialog with default control states.
	 * @param Owner Component that owns this frame.
	 */
	__fastcall TfrmAddPlant(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAddPlant *frmAddPlant;
//---------------------------------------------------------------------------
#endif
