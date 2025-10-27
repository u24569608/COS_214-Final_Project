#include "../include/StockItem.h"
#include "../include/PlantInstance.h"

#include <utility>

/**
 * @brief Constructor implementation
 */
StockItem::StockItem(std::string n, double p, PlantInstance* pl)
    : name(std::move(n)),
      price(p),
      plant(nullptr),
      isAvailable(true),
      displayStatus("Available") {
    bindToPlant(pl);
}

StockItem::~StockItem() {
    detachFromPlant();
}

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
    switch (event.type) {
    case ObserverEventType::AvailabilityChanged: {
        if (event.availability.has_value()) {
            setIsAvailible(*event.availability);
        }
        if (!event.message.empty()) {
            displayStatus = event.message;
        } else if (event.availability.has_value()) {
            displayStatus = *event.availability ? "Available" : "Unavailable";
        }
        break;
    }
    case ObserverEventType::SubjectDestroyed: {
        // Subject will remove this observer; ensure local pointer no longer used.
        plant = nullptr;
        setIsAvailible(false);
        if (!event.message.empty()) {
            displayStatus = event.message;
        }
        break;
    }
    default:
        break;
    }
}

void StockItem::setPlant(PlantInstance* newPlant) {
    bindToPlant(newPlant);
}

void StockItem::bindToPlant(PlantInstance* newPlant) {
    if (plant == newPlant) {
        return;
    }

    detachFromPlant();

    if (newPlant == nullptr) {
        setIsAvailible(true);
        return;
    }

    plant = newPlant;
    plant->attach(this);

    const bool available = plant->isAvailableForSale();
    setIsAvailible(available);
    displayStatus = available ? "Plant ready for sale" : "Plant unavailable for sale";
}

void StockItem::detachFromPlant() {
    if (plant != nullptr) {
        plant->detach(this);
        plant = nullptr;
    }
}
