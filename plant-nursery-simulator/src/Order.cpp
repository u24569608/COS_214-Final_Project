#include "../include/Order.h"
#include <iostream>

Order::Order() : status("Pending"), orderID(0) {
    // Default constructor
}

/**
 * @brief Adds a COPY of a StockItem to the order.
 */
void Order::addItem(StockItem item) {
    items.push_back(item);
}

/**
 * @brief Calculates total price based on items in the vector.
 * Relies on the dummy implementation of StockItem::getPrice().
 */
double Order::calculateTotal() const {
    double total = 0.0;
    for (const auto& item : items) {
        // We call getPrice() on the *copy* stored in our vector
        // Note: Your StockItem.h says getPrice() returns int,
        // so we cast it to double.
        total += (double)item.getPrice();
    }
    return total;
}

std::string Order::getOrderStatus() const {
    return this->status;
}

void Order::setOrderStatus(std::string newStatus) {
    this->status = newStatus;
}

void Order::printOrder() const {
    std::cout << "--- Order #" << orderID << " (" << status << ") ---" << std::endl;
    for (const auto& item : items) {
        // We need to const-cast to call getname() because
        // the dummy StockItem::getname() wasn't marked const.
        std::string name = const_cast<StockItem&>(item).getname();
        int price = const_cast<StockItem&>(item).getPrice();
        std::cout << "  - " << name << " ($" << price << ")" << std::endl;
    }
    std::cout << "  Total: $" << calculateTotal() << std::endl;
    std::cout << "-------------------------" << std::endl;
}

const std::vector<StockItem>& Order::getItems() const {
    return this->items;
}