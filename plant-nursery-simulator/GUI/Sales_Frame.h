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
#include <unordered_set>
#include <string>
class StockItem;
//---------------------------------------------------------------------------
class TfrmSales : public TFrame
{
__published:	// IDE-managed Components
	TLabel *lblBuildOrderHeading;
	TComboBox *cmbItemSelection;
	TLabel *lblItemSelectionHeading;
	TBitBtn *btnAddToOrder;
	TLabel *lblCheckoutHeading;
	TRichEdit *redtOrderDetails;
	TBitBtn *btnProcessPayment;
	TLabel *lblOrderSummaryHeading;
	TComboBox *cmbCustomerSelect;
	TLabel *lblCustomerSelectionHeading;
	/**
	 * @brief Adds the currently selected stock item to the pending order.
	 * @param Sender Component raising the event.
	 */
	void __fastcall btnAddToOrderClick(TObject *Sender);
	/**
	 * @brief Manages button state whenever the item selection changes.
	 * @param Sender Component raising the event.
	 */
	void __fastcall cmbItemSelectionChange(TObject *Sender);
	/**
	 * @brief Finalises the order and submits payment for the selected customer.
	 * @param Sender Component raising the event.
	 */
	void __fastcall btnProcessPaymentClick(TObject *Sender);
	/**
	 * @brief Enables payment once a valid customer selection is made.
	 * @param Sender Component raising the event.
	 */
	void __fastcall cmbCustomerSelectChange(TObject *Sender);
private:	// User declarations
	std::unordered_set<std::string> reservedItemIds; ///< Tracks stock IDs already staged in the order.
	/**
	 * @brief Records an item identifier as already present in the pending order.
	 * @param itemId Identifier obtained from `StockItem::getId()`.
	 */
	void reserveItem(const std::string& itemId);
	/**
	 * @brief Checks whether the supplied identifier has been reserved.
	 * @param itemId Identifier to probe.
	 * @return True when the item may not be added again to the current order.
	 */
	bool isItemReserved(const std::string& itemId) const;
public:		// User declarations
	/**
	 * @brief Sets up the sales frame and initial control state.
	 * @param Owner Component that owns this frame.
	 */
	__fastcall TfrmSales(TComponent* Owner);
    double currentOrderTotal;
	/**
	 * @brief Resets order totals and staged items to their initial state.
	 */
	void clearOrderState();
	/**
	 * @brief Clears the reservation cache without mutating other state.
	 */
	void releaseReservations();
	/**
	 * @brief Convenience wrapper to test reservation status using a stock pointer.
	 * @param item Stock item under consideration.
	 * @return True if the item's identifier is currently reserved.
	 */
	bool isItemReserved(const StockItem* item) const;
	};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSales *frmSales;
//---------------------------------------------------------------------------
#endif
