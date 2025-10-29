//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sales_Frame.h"
#include "Main.h"
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
void __fastcall TfrmSales::btnAddToOrderClick(TObject *Sender)
{
	// 1. Get selected item name from ComboBox
	UnicodeString selectedItemNameU = cmbItemSelection->Text;
	std::string selectedItemName = AnsiString(selectedItemNameU).c_str();

	// Validate selection (check for empty or placeholder text)
	if (selectedItemName.empty() || selectedItemNameU == "Select an Item") {
		ShowMessage("Please select an item to add.");
		return;
	}

	// 2. Find the StockItem in the main form's inventory
	// Access main form's inventory via the global frmMain pointer
	StockItem* itemToAdd = frmMain->objInventory->findItem(selectedItemName); //

	// Validate item found and available
	if (!itemToAdd) {
		ShowMessage("Error: Could not find '" + selectedItemNameU + "' in inventory.");
		return;
	}
	if (!itemToAdd->getIsAvailible()) { //
		ShowMessage("Sorry, '" + selectedItemNameU + "' is currently out of stock.");
		return;
	}

	// 3. Use the main form's OrderBuilder to add the item
	try {
		// Call backend builder's addItem
		frmMain->objOrderBuilder->addItem(itemToAdd);

		// --- Update Running Total and Display ---

		// a) Add item price to the frame's running total
		// StockItem::getPrice() returns int, cast to double
		currentOrderTotal += static_cast<double>(itemToAdd->getPrice());

		// b) Manually update the RichEdit display
		if (redtOrderDetails->Text == "(Order is empty)") {
			 // First item added, setup the display
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
        cmbCustomerSelect->Enabled = true; // Ensure customer selection is enabled

		// Trigger the check for enabling the payment button based on customer selection AND order items
		cmbCustomerSelectChange(Sender); // Checks both customer selection and order state
	}
	catch (const std::exception& ex) {
		 // Display any errors from the backend addItem call
		 ShowMessage("Error adding item to order: " + String(ex.what()));
	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmSales::cmbItemSelectionChange(TObject *Sender)
{
	if (cmbItemSelection->Text != "Select an Item") {
        btnAddToOrder->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmSales::btnProcessPaymentClick(TObject *Sender)
{
	// 1. Get Customer ID string and validate
	UnicodeString customerIdU = cmbCustomerSelect->Text;
	std::string customerIdStr = AnsiString(customerIdU).c_str();
	if (cmbCustomerSelect->ItemIndex == -1 || customerIdStr.empty() || customerIdU == "Select Customer ID") {
		ShowMessage("Please select a Customer ID.");
		return;
	}

	// 2. Convert ID string to INT
	int customerIdSelected = -1;
	try {
		 customerIdSelected = std::stoi(customerIdStr);
	} catch (...) {
		 ShowMessage("Error: Invalid Customer ID selected.");
		 return;
	}

	// 3. Find the Customer* object by ID
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

	// 4. === GET THE ORDER FROM THE BUILDER ===
	// OrderBuilder::getOrder() returns a raw Order* and releases ownership [cite: OrderBuilder.cpp, OrderBuilder.h]
	std::unique_ptr<Order> finalOrder(frmMain->objOrderBuilder->getOrder());

	// Check if the order is valid (e.g., has items)
	if (!finalOrder || finalOrder->getItems().empty()) { // [cite: Order.h]
		ShowMessage("Cannot process payment: The order is empty.");
        // We took ownership, but it's empty, so reset the builder
        frmMain->objOrderBuilder->createNewOrder(); // [cite: OrderBuilder.h]
		return;
	}

	// 5. === Call the Sales Facade with Customer*, items, and payment type ===
	bool success = false;
	try {
		// Pass Customer*, the vector of items from the order, and payment type string
		success = frmMain->objSalesFacade->buildAndFinalizeOrder(
													customerPtr,
													finalOrder->getItems() // Pass the vector [cite: SalesFacade.h, Order.h]
													                  // Pass payment type
													);

		// 6. Handle the Result
		if (success) {
			ShowMessage("Payment successful! Order finalized.");
			frmMain->redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Order finalized for Customer ID " + customerIdU);

			// Reset UI, Refresh Inventory, Repopulate Combos
			frmMain->UpdateOrderDisplay();       // Resets Sales Frame UI
			frmMain->RefreshInventoryListView();
			frmMain->PopulateSalesItemComboBox();
			frmMain->PopulateCustomerComboBox();
            // Builder is already empty because we called getOrder()
            // We need to create a NEW empty order in the builder for the next customer
            frmMain->objOrderBuilder->createNewOrder();

		} else {
			ShowMessage("Order processing failed. Please check inventory or payment details.");
            frmMain->redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] Order processing failed for Customer ID " + customerIdU);
            // Builder is already empty because we called getOrder()
            frmMain->objOrderBuilder->createNewOrder(); // Ensure builder is ready
		}
        // unique_ptr finalOrder goes out of scope and deletes the Order object here
	}
	catch (const std::exception& ex) {
		ShowMessage("An error occurred during checkout: " + String(ex.what()));
        frmMain->redtLog->Lines->Add("[" + DateTimeToStr(Now()) + "] EXCEPTION during checkout for Customer ID " + customerIdU + ": " + String(ex.what()));
        // Builder is likely empty, ensure it's reset
        frmMain->objOrderBuilder->createNewOrder();
        // unique_ptr finalOrder will still delete if exception occurred after getOrder()
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

