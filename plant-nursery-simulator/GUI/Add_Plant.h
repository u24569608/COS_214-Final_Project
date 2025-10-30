#ifndef Add_PlantH
#define Add_PlantH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

/**
 * @file Add_Plant.h
 * @brief VCL dialog that guides the user through adding a plant prototype.
 */
class TfrmAddPlant : public TForm
{
__published:	// IDE-managed Components
	TPanel *pnlBase;
	TButton *btnCancel;
	TButton *btnAdd;
	TLabel *lblBuildOrderHeading;
	TLabeledEdit *LabeledEdit1;
	TRadioGroup *rgFertiliseStrategy;
	TRadioGroup *rgWaterStrategy;
    /**
     * @brief Cancels the dialog and closes the form.
     * @param Sender Component raising the event.
     */
	void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    /**
     * @brief Constructs the add-plant dialog and sets up radio groups.
     * @param Owner Component responsible for the dialog lifetime.
     */
	__fastcall TfrmAddPlant(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAddPlant *frmAddPlant;
//---------------------------------------------------------------------------
#endif
