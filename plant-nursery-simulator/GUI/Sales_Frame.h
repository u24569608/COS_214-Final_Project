//---------------------------------------------------------------------------

#ifndef Sales_FrameH
#define Sales_FrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TfrmSales : public TFrame
{
__published:	// IDE-managed Components
	TLabel *lblBuildOrderHeading;
	TComboBox *cmbPlantSelection;
	TLabel *lblPlantSelectionHeading;
	TComboBox *cmbPotSizeSelection;
	TLabel *lblPotSizeSelectionHeading;
	TCheckBox *chkGiftWrapping;
	TPanel *pnlAddToOrder;
	TBitBtn *btnAddToOrder;
	TLabel *lblCheckoutHeading;
	TRichEdit *redtOrderDetails;
	TLabeledEdit *lbledtCustomerName;
	TPanel *pnlProcessPayment;
	TBitBtn *btnProcessPayment;
	TLabel *lblOrderSummaryHeading;
	void __fastcall cmbPlantSelectionChange(TObject *Sender);
	void __fastcall cmbPotSizeSelectionChange(TObject *Sender);
	void __fastcall btnAddToOrderClick(TObject *Sender);
	void __fastcall lbledtCustomerNameChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmSales(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSales *frmSales;
//---------------------------------------------------------------------------
#endif
