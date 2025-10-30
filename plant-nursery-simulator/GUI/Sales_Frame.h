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

/**
 * @file Sales_Frame.h
 * @brief VCL frame that provides point-of-sale interactions.
 */
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
	TBitBtn *btnProcessPayment;
	TLabel *lblOrderSummaryHeading;
	TBitBtn *btnRefund;
    /**
     * @brief Adds the selected stock item to the order.
     */
	void __fastcall btnAddToOrderClick(TObject *Sender);

    /**
     * @brief Handles combo-box changes for stock selection.
     */
	void __fastcall cmbItemSelectionChange(TObject *Sender);

    /**
     * @brief Processes payment for the current order.
     */
	void __fastcall btnProcessPaymentClick(TObject *Sender);

    /**
     * @brief Responds when the customer selection changes.
     */
	void __fastcall cmbCustomerSelectChange(TObject *Sender);
private:	// User declarations

public:		// User declarations
    /**
     * @brief Constructs the sales frame with default totals.
     * @param Owner Component that owns the frame.
     */
	__fastcall TfrmSales(TComponent* Owner);
    double currentOrderTotal;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSales *frmSales;
//---------------------------------------------------------------------------
#endif
