#ifndef STOCK_ITEM_H
#define STOCK_ITEM_H

#include <string>

/**
 * @file StockItem.h
 * @brief A simple class representing an item in an order.
 */
class StockItem {
public:
    StockItem(std::string name, double price);
    std::string name;
    double price;
};

#endif // STOCK_ITEM_H