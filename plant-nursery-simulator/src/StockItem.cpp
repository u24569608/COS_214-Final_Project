#include "../include/StockItem.h"
#include "../include/PlantInstance.h"

#include <utility>

/**
 * @brief Constructor implementation
 */
StockItem::StockItem(std::string n, double p, PlantInstance* pl)
    : name(std::move(n)),
      price(p),
      plant(pl),
      isAvailable(true),
      displayStatus("Available") {
    // Constructor body
}

/**
 * @brief Returns the name of the item
 */
std::string StockItem::getname() const{
    return this->name;
}

/**
 * @brief Returns the price as an integer (matches header)
 */
int StockItem::getPrice() const{
    // The header file specified 'int' return type.
    // We cast our 'double' member variable to an 'int'.
    return (int)this->price;
}

/**
 * @brief Returns the associated plant instance
 */
PlantInstance* StockItem::getplant() {
    return this->plant;
}

void StockItem::setPrice(double price) {
    this->price = price;
}

bool StockItem::isPlant() {
    return this->plant != nullptr;
}

bool StockItem::getIsAvailible() {
    return this->isAvailable;
}

void StockItem::setIsAvailible(bool isAvailible) {
    this->isAvailable = isAvailible;
    this->displayStatus = isAvailible ? "Available" : "Unavailable";
}

std::string StockItem::getDisplayStatus() const {
    return displayStatus;
}

void StockItem::update(const ObserverEvent& event) {
    if (event.type != ObserverEventType::AvailabilityChanged) {
        return;
    }

    const bool available = event.message.find("unavailable") == std::string::npos;
    setIsAvailible(available);
    displayStatus = event.message;
}
