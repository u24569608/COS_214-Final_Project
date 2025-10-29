//---------------------------------------------------------------------------

#ifndef UpdaH
#define UpdaH
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
	TComboBox *cmbItemSelection;
	TLabel *lblItemSelectionHeading;
	TPanel *pnlAddToOrder;
	TBitBtn *btnAddToOrder;
	TLabel *lblCheckoutHeading;
	TRichEdit *redtOrderDetails;
	TLabeledEdit *lbledtCustomerName;
	TPanel *pnlProcessPayment;
	TBitBtn *btnProcessPayment;
	TLabel *lblOrderSummaryHeading;
	TBitBtn *btnRefund;
	void __fastcall btnAddToOrderClick(TObject *Sender);
	void __fastcall lbledtCustomerNameChange(TObject *Sender);
	void __fastcall cmbItemSelectionChange(TObject *Sender);
private:	// User declarations

public:		// User declarations
	__fastcall TfrmSales(TComponent* Owner);
    double currentOrderTotal;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSales *frmSales;
//---------------------------------------------------------------------------
#endif
