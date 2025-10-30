#ifndef Add_ItemH
#define Add_ItemH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>

/**
 * @file Add_Item.h
 * @brief VCL form that captures details for adding a new inventory item.
 */
class TfrmAddItem : public TForm
{
__published:	// IDE-managed Components
	TLabel *lblHeading;
	TPanel *pnlBase;
	TButton *btnCancel;
	TButton *btnAdd;
	TLabeledEdit *lbledtItemName;
	TLabeledEdit *lbledtItemPrice;
    /**
     * @brief Closes the dialog without applying changes.
     */
	void __fastcall btnCancelClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    /**
     * @brief Constructs the add-item dialog and initialises controls.
     * @param Owner Owning component, typically the main form.
     */
	__fastcall TfrmAddItem(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAddItem *frmAddItem;
//---------------------------------------------------------------------------
#endif
