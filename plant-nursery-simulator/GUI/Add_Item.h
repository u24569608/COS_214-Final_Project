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
	/**
	 * @brief Closes the dialog without persisting changes.
	 * @param Sender Component raising the event.
	 */
	void __fastcall btnCancelClick(TObject *Sender);
	/**
	 * @brief Validates input fields and adds the new stock item to the inventory.
	 * @param Sender Component raising the event.
	 */
	void __fastcall btnAddClick(TObject *Sender);
	/**
	 * @brief Enables pricing input once a tentative name is provided.
	 * @param Sender Component raising the event.
	 */
	void __fastcall lbledtItemNameChange(TObject *Sender);
	/**
	 * @brief Activates the confirmation button when a valid price is supplied.
	 * @param Sender Component raising the event.
	 */
	void __fastcall lbledtItemPriceChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	/**
	 * @brief Constructs the add-item form and wires default state.
	 * @param Owner Component that owns this form.
	 */
	__fastcall TfrmAddItem(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAddItem *frmAddItem;
//---------------------------------------------------------------------------
#endif
