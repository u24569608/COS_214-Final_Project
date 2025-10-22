#ifndef STOCK_ITEM_H
#define STOCK_ITEM_H

#include <string>

class Order;
class PlantInstance;
class WaterStrategy;

/**
 * @file StockItem.h
 * @brief A complex class representing an item in an order.
 */
class StockItem {
public:
    StockItem(std::string n, double p, PlantInstance* pl);
    void getname();
    void getPrice();
    PlantInstance* getplant();
    void setPrice(double price);
    bool isPlant();
    bool getIsAvailible();
    void setIsAvailible(bool isAvailible);


private:
    std::string name;
    double price;
    PlantInstance* plant;
    bool isAvailable;
};

#endif // STOCK_ITEM_H