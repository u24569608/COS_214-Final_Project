//---------------------------------------------------------------------------

#ifndef Add_ItemH
#define Add_ItemH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TfrmAddItem : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblHeading;
	TPanel *pnlBase;
	TButton *btnCancel;
	TButton *btnAdd;
	TLabeledEdit *lbledtItemName;
	TLabeledEdit *lbledtItemPrice;
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnAddClick(TObject *Sender);
	void __fastcall lbledtItemNameChange(TObject *Sender);
	void __fastcall lbledtItemPriceChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmAddItem(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAddItem *frmAddItem;
//---------------------------------------------------------------------------
#endif
