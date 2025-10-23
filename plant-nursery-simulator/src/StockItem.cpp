#include "../include/StockItem.h"
#include "../include/PlantInstance.h"

/**
 * @brief Constructor implementation
 */
StockItem::StockItem(std::string n, double p, PlantInstance* pl)
    : name(n), price(p), plant(pl), isAvailable(true) {
    // Constructor body
}

/**
 * @brief Returns the name of the item
 */
std::string StockItem::getname() {
    return this->name;
}

/**
 * @brief Returns the price as an integer (matches header)
 */
int StockItem::getPrice() {
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
}