#include <algorithm>
#include <iostream>
#include <utility>

#include "../include/Customer.h"
#include "../include/FloorMediator.h"
#include "../include/StockItem.h"

Customer::Customer(int id, FloorMediator* mediator) : Colleague(mediator) {
    this->id = id; 
    this->name = "Customer " + std::to_string(id); 
}

int Customer::getID() const {
    return id;
}

void Customer::send(std::string message, int colleagueID) {
    if (this->mediator == nullptr) {
        std::cerr << "[Customer] No mediator set; cannot send.\n";
        return;
    }
    mediator->distribute(std::move(message), id, colleagueID);
}

void Customer::receive(std::string message) {
    std::cout << "[Customer " << id << "] " << message << std::endl;
}

void Customer::askForHelp() {
    send("I need assistance on the floor.", -1);
}

void Customer::browseInventory(InventoryIterator* iter) {
    (void)iter; // Placeholder for future inventory integration
    std::cout << "[Customer " << id << "] browsing inventory...\n";
}

void Customer::addToCart(StockItem* item) {
    if (item == nullptr) {
        std::cout << "[Customer " << id << "] cannot add null item to cart.\n";
        return;
    }
    if (!item->getIsAvailible()) {
        std::cout << "[Customer " << id << "] noted that '" << item->getname()
                  << "' is currently unavailable, keeping it in cart for later.\n";
    }
    if (containsItem(item)) {
        std::cout << "[Customer " << id << "] already has '" << item->getname() << "' in the cart.\n";
        return;
    }
    shoppingCart.push_back({item->getname(), item});
    std::cout << "[Customer " << id << "] added '" << item->getname() << "' to cart.\n";
}

bool Customer::removeFromCart(StockItem* item) {
    if (item == nullptr) {
        return false;
    }
    const auto oldSize = shoppingCart.size();
    shoppingCart.erase(std::remove_if(shoppingCart.begin(),
                                      shoppingCart.end(),
                                      [item](const CartEntry& entry) { return entry.item == item; }),
                       shoppingCart.end());
    return shoppingCart.size() != oldSize;
}

bool Customer::removeFromCart(const std::string& itemName) {
    if (itemName.empty()) {
        return false;
    }
    const auto oldSize = shoppingCart.size();
    shoppingCart.erase(std::remove_if(shoppingCart.begin(),
                                      shoppingCart.end(),
                                      [&itemName](const CartEntry& entry) { return entry.name == itemName; }),
                       shoppingCart.end());
    return shoppingCart.size() != oldSize;
}

void Customer::clearUnavailableItems() {
    const auto oldSize = shoppingCart.size();
    shoppingCart.erase(std::remove_if(shoppingCart.begin(),
                                      shoppingCart.end(),
                                      [](const CartEntry& entry) {
                                          return entry.item == nullptr || !entry.item->getIsAvailible();
                                      }),
                       shoppingCart.end());
    if (shoppingCart.size() != oldSize) {
        std::cout << "[Customer " << id << "] removed unavailable items from cart.\n";
    }
}

void Customer::notifyItemSold(const std::string& itemName) {
    if (removeFromCart(itemName)) {
        std::cout << "[Customer " << id << "] removed sold-out '" << itemName << "' from cart.\n";
    }
}

std::vector<std::string> Customer::getCartSummary() const {
    std::vector<std::string> summary;
    summary.reserve(shoppingCart.size());
    for (const CartEntry& entry : shoppingCart) {
        summary.push_back(entry.name);
    }
    return summary;
}

std::vector<StockItem*> Customer::getCartItems() const {
    std::vector<StockItem*> items;
    items.reserve(shoppingCart.size());
    for (const CartEntry& entry : shoppingCart) {
        items.push_back(entry.item);
    }
    return items;
}

size_t Customer::getCartSize() const {
    return shoppingCart.size();
}

bool Customer::containsItem(StockItem* item) const {
    return std::any_of(shoppingCart.begin(), shoppingCart.end(),
                       [item](const CartEntry& entry) { return entry.item == item; });
}

bool Customer::containsItem(const std::string& itemName) const {
    return std::any_of(shoppingCart.begin(), shoppingCart.end(),
                       [&itemName](const CartEntry& entry) { return entry.name == itemName; });
}
