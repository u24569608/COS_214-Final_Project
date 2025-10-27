#ifndef STOCK_ITEM_H
#define STOCK_ITEM_H

#include <string>

#include "Observer.h"

class Order;
class PlantInstance;
class WaterStrategy;

/**
 * @file StockItem.h
 * @brief A complex class representing an item in an order.
 */
class StockItem : public Observer {
public:
    StockItem(std::string n, double p, PlantInstance* pl);
    std::string getname() const;
    int getPrice() const;
    PlantInstance* getplant();
    void setPrice(double price);
    bool isPlant();
    bool getIsAvailible();
    void setIsAvailible(bool isAvailible);
    /**
     * @brief Retrieves the human-readable availability notice.
     * @return Status string shown for this stock item.
     */
    std::string getDisplayStatus() const;

    /**
     * @brief Responds to Subject notifications about availability.
     * @param event Payload describing the update.
     */
    void update(const ObserverEvent& event) override;


private:
    std::string name;
    double price;
    PlantInstance* plant;
    bool isAvailable;
    std::string displayStatus;
};

#endif // STOCK_ITEM_H
