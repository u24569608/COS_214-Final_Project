//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sales_Frame.h"
#include "Main.h"
#include "../include/StockItem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSales *frmSales;
// Pot Size Selection
//---------------------------------------------------------------------------
__fastcall TfrmSales::TfrmSales(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void TfrmSales::reserveItem(const std::string& itemId)
{
	if (itemId.empty()) {
		return;
	}
	reservedItemIds.insert(itemId);
}
//---------------------------------------------------------------------------
bool TfrmSales::isItemReserved(const std::string& itemId) const
{
	if (itemId.empty()) {
		return false;
	}
	return reservedItemIds.find(itemId) != reservedItemIds.end();
}
//---------------------------------------------------------------------------
bool TfrmSales::isItemReserved(const StockItem* item) const
{
	if (!item) {
		return false;
	}
	return isItemReserved(item->getId());
}
//---------------------------------------------------------------------------
void TfrmSales::releaseReservations()
{
	reservedItemIds.clear();
}
//---------------------------------------------------------------------------
void TfrmSales::clearOrderState()
{
	releaseReservations();
	currentOrderTotal = 0.0;
	btnAddToOrder->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSales::btnAddToOrderClick(TObject *Sender)
{
	try {
		const int itemIndex = cmbItemSelection->ItemIndex;
		if (itemIndex < 0 || itemIndex >= cmbItemSelection->Items->Count) {
			ShowMessage("Please select an item to add.");
			return;
		}

		UnicodeString selectedItemNameU = cmbItemSelection->Items->Strings[itemIndex];

		StockItem* itemToAdd = frmMain->ResolveSalesItemByIndex(itemIndex, selectedItemNameU);

		// Validate item found and available
		if (!itemToAdd) {
			ShowMessage("Error: Could not find '" + selectedItemNameU + "' in inventory.");
			return;
		}
		if (!itemToAdd->getIsAvailible()) {
			ShowMessage("Sorry, '" + selectedItemNameU + "' is currently out of stock.");
			return;
		}
		if (isItemReserved(itemToAdd)) {
			ShowMessage("This item is already in the order.");
			return;
		}

		// Call backend builder's addItem
		frmMain->objOrderBuilder->addItem(itemToAdd);

		// --- Update Running Total and Display ---

		// a) Add item price to the frame's running total
		// StockItem::getPrice() returns int, cast to double
		currentOrderTotal += static_cast<double>(itemToAdd->getPrice());

		// b) Manually update the RichEdit display
		// Check if the RichEdit currently shows the placeholder
		bool isFirstItem = (redtOrderDetails->Lines->Count == 1 &&
						   redtOrderDetails->Lines->Strings[0] == "(Order is empty)");

		if (isFirstItem) {
			 // First item added, clear placeholder and setup header
			 redtOrderDetails->Clear();
			 redtOrderDetails->Lines->Add("Current Order:");
			 redtOrderDetails->Lines->Add("--------------------");
		} else {
			// Remove the old total and separator lines before adding the new item
			if (redtOrderDetails->Lines->Count > 0 && redtOrderDetails->Lines->Strings[redtOrderDetails->Lines->Count - 1].Pos("Total Due:") == 1) {
				redtOrderDetails->Lines->Delete(redtOrderDetails->Lines->Count - 1); // Remove old total
			}
			 if (redtOrderDetails->Lines->Count > 0 && redtOrderDetails->Lines->Strings[redtOrderDetails->Lines->Count - 1] == "--------------------") {
				 redtOrderDetails->Lines->Delete(redtOrderDetails->Lines->Count - 1); // Remove old separator
			 }
		}

		// Add the newly added item's details
		UnicodeString line = " - ";
		line += itemToAdd->getname().c_str(); //
		line += " (";
		line += FloatToStrF(static_cast<double>(itemToAdd->getPrice()), ffCurrency, 8, 2);
		line += ")";
		redtOrderDetails->Lines->Add(line);

		// Add separator and the NEW running total line
		redtOrderDetails->Lines->Add("--------------------");
		redtOrderDetails->Lines->Add("Total Due: " + FloatToStrF(currentOrderTotal, ffCurrency, 8, 2));

		// 5. Enable downstream controls now that order has items
		redtOrderDetails->Enabled = true;
		cmbCustomerSelect->Enabled = true;

		// Trigger the check for enabling the payment button based on customer selection AND order items
		cmbCustomerSelectChange(Sender);

		// Remove the item from the selection list and mark it reserved to avoid duplicates.
		if (itemIndex < cmbItemSelection->Items->Count) {
			cmbItemSelection->Items->Delete(itemIndex);
			frmMain->RemoveSalesComboEntryById(itemToAdd->getId());
		}
		cmbItemSelection->ItemIndex = -1;
		cmbItemSelection->Text = "Select an Item";
		btnAddToOrder->Enabled = false;
		reserveItem(itemToAdd->getId());
	}
	catch (const Exception& ex) {
		ShowMessage("Error adding item to order: " + ex.Message);
		frmMain->AppendLog(UnicodeString("Order item add error: ") + ex.Message);
	}
	catch (const std::exception& ex) {
		ShowMessage("Error adding item to order: " + String(ex.what()));
		frmMain->AppendLog(UnicodeString("Order item add error: ") + String(ex.what()));
	}
	catch (...) {
		ShowMessage("Unknown error adding item to order.");
		frmMain->AppendLog("Unknown error while adding item to order.");
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSales::cmbItemSelectionChange(TObject *Sender)
{
	const bool validSelection = (cmbItemSelection->ItemIndex >= 0) &&
		(cmbItemSelection->ItemIndex < cmbItemSelection->Items->Count);
	btnAddToOrder->Enabled = validSelection;
}
//---------------------------------------------------------------------------

void __fastcall TfrmSales::btnProcessPaymentClick(TObject *Sender)
{
    try {
        UnicodeString customerIdU = cmbCustomerSelect->Text;
        std::string customerIdStr = AnsiString(customerIdU).c_str();
        if (cmbCustomerSelect->ItemIndex == -1 || customerIdStr.empty() || customerIdU == "Select Customer ID") {
            ShowMessage("Please select a Customer ID.");
            return;
        }

        int customerIdSelected = -1;
        try {
            customerIdSelected = std::stoi(customerIdStr);
        } catch (...) {
            ShowMessage("Error: Invalid Customer ID selected.");
            return;
        }

        Customer* customerPtr = nullptr;
        for (const auto& colleague : frmMain->vtrColleagues) {
            Customer* cust = dynamic_cast<Customer*>(colleague.get());
            if (cust != nullptr && cust->getID() == customerIdSelected) {
                customerPtr = cust;
                break;
            }
        }
        if (customerPtr == nullptr) {
            ShowMessage("Error: Could not find selected customer object (ID: " + customerIdU + ").");
            return;
        }

        std::unique_ptr<Order> finalOrder(frmMain->objOrderBuilder->getOrder());
        if (!finalOrder || finalOrder->getItems().empty()) {
            ShowMessage("Cannot process payment: The order is empty.");
            frmMain->objOrderBuilder->createNewOrder();
            return;
        }

        bool success = frmMain->objSalesFacade->buildAndFinalizeOrder(customerPtr, *finalOrder);

        if (success) {
            UnicodeString logMsg = "[" + DateTimeToStr(Now()) + "] Order Finalised for Customer (ID): " + customerIdU;
            frmMain->redtLog->Lines->Add(logMsg);

            frmMain->redtLog->Lines->Add("------ Receipt (" + customerIdU + ") ------");
            for (const StockItem& item : finalOrder->getItems()) {
                UnicodeString logLine = "  - ";
                logLine += item.getname().c_str();
                logLine += " (";
                logLine += FloatToStrF(static_cast<double>(item.getPrice()), ffCurrency, 8, 2);
                logLine += ")";
                frmMain->redtLog->Lines->Add(logLine);
            }
            frmMain->redtLog->Lines->Add("  -------------------------");
            frmMain->redtLog->Lines->Add("  Total Due: " + FloatToStrF(finalOrder->calculateTotal(), ffCurrency, 8, 2) + " [PAID]");
            frmMain->redtLog->Lines->Add("  -------------------------");

            frmMain->UpdateOrderDisplay();
            frmMain->RefreshInventoryListView();
            frmMain->PopulateSalesItemComboBox();
            frmMain->PopulateCustomerComboBox();
            frmMain->RefreshGreenhouseDisplay();
            frmMain->objOrderBuilder->createNewOrder();
        } else {
            ShowMessage("Order processing failed. Please check inventory or payment details.");
            frmMain->redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Order processing failed for Customer ID " + customerIdU);
            frmMain->UpdateOrderDisplay();
            frmMain->objOrderBuilder->createNewOrder();
            frmMain->PopulateSalesItemComboBox();
        }
    }
    catch (const Exception& ex) {
        ShowMessage("Error while processing payment: " + ex.Message);
        frmMain->AppendLog(UnicodeString("Payment error: ") + ex.Message);
        frmMain->UpdateOrderDisplay();
        frmMain->objOrderBuilder->createNewOrder();
        frmMain->PopulateSalesItemComboBox();
    }
    catch (const std::exception& ex) {
        ShowMessage("Error while processing payment: " + String(ex.what()));
        frmMain->AppendLog(UnicodeString("Payment error: ") + String(ex.what()));
        frmMain->UpdateOrderDisplay();
        frmMain->objOrderBuilder->createNewOrder();
        frmMain->PopulateSalesItemComboBox();
    }
    catch (...) {
        ShowMessage("Unknown error while processing payment.");
        frmMain->AppendLog("Unknown payment error.");
        frmMain->UpdateOrderDisplay();
        frmMain->objOrderBuilder->createNewOrder();
        frmMain->PopulateSalesItemComboBox();
    }
}

//---------------------------------------------------------------------------

void __fastcall TfrmSales::cmbCustomerSelectChange(TObject *Sender)
{
    // Enable payment button only if a customer ID is selected
    // AND the order RichEdit is not showing "(Order is empty)"
    bool orderHasItems = !redtOrderDetails->Text.IsEmpty() && redtOrderDetails->Text != "(Order is empty)";
    btnProcessPayment->Enabled = (cmbCustomerSelect->ItemIndex > -1) && orderHasItems;
}
//---------------------------------------------------------------------------
