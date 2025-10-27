#ifndef STOCK_ITEM_H
#define STOCK_ITEM_H

#include <string>

#include "Observer.h"

class Order;
class PlantInstance;
class WaterStrategy;

/**
 * @file StockItem.h
 * @brief Represents an inventory entry and observes plant availability.
 */
class StockItem : public Observer {
public:
    /**
     * @brief Constructs a stock record, optionally linked to a specific plant instance.
     * @param n Human-readable name for display.
     * @param p Unit price charged to customers.
     * @param pl Optional plant instance backing this stock item.
     */
    StockItem(std::string n, double p, PlantInstance* pl);

    /**
     * @brief Ensures the stock item detaches from any observed plant.
     */
    ~StockItem() override;

    /**
     * @brief Retrieves the unique identifier assigned to this stock entry.
     * @return Stable identifier usable for cart tracking.
     */
    const std::string& getId() const;
    std::string getname() const;
    int getPrice() const;
    PlantInstance* getplant();
    void setPrice(double price);
    bool isPlant();
    bool getIsAvailible();

    /**
     * @brief Updates the cached availability flag for display purposes.
     * @param isAvailible New availability flag.
     */
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

    /**
     * @brief Rebinds this stock item to a different plant instance.
     * @param newPlant Plant instance to observe; nullptr detaches from any current plant.
     */
    void setPlant(PlantInstance* newPlant);

private:
    std::string id;
    std::string name;
    double price;
    PlantInstance* plant;
    bool isAvailable;
    std::string displayStatus;

    void bindToPlant(PlantInstance* newPlant);
    void detachFromPlant();
};

#endif // STOCK_ITEM_H
