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
	TLabeledEdit *LabeledEdit1;
	TRadioGroup *rgFertiliseStrategy;
	TRadioGroup *rgWaterStrategy;
	void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmAddPlant(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAddPlant *frmAddPlant;
//---------------------------------------------------------------------------
#endif
