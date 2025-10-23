#include <iostream>
#include <utility>

#include "../include/Customer.h"
#include "../include/FloorMediator.h"

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
    (void)item; // Placeholder for future cart behavior
    std::cout << "[Customer " << id << "] added item to cart.\n";
}