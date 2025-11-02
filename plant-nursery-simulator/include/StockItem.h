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
     * @brief Creates a shallow copy suitable for order summaries (no observer binding).
     */
	StockItem(const StockItem& other);
    /**
     * @brief Ensures the stock item detaches from any observed plant.
     */
    ~StockItem() override;

    /**
     * @brief Retrieves the unique identifier assigned to this stock entry.
     * @return Stable identifier usable for cart tracking.
     */
    const std::string& getId() const;

    /**
     * @brief Retrieves the display name of the stock item.
     */
    std::string getname() const;

    /**
     * @brief Gets the retail price associated with the stock entry.
     * @return Price rounded down to whole currency units.
     */
    int getPrice() const;

    /**
     * @brief Accesses the underlying plant instance when the stock represents a plant.
     * @return Borrowed pointer to the plant, or nullptr when not applicable.
     */
    PlantInstance* getplant();

    /**
     * @brief Provides read-only access to the associated plant instance.
     */
    const PlantInstance* getplant() const;

    /**
     * @brief Updates the retail price.
     * @param price New unit price.
     */
    void setPrice(double price);

    /**
     * @brief Reports whether this stock item represents a live plant.
     */
    bool isPlant();

    /**
     * @brief Checks if the item is currently available for sale.
     */
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
     * @note The pointer is non-owning; the stock item automatically detaches when either
     *       the plant is destroyed or `setPlant(nullptr)` is invoked.
     */
    void setPlant(PlantInstance* newPlant);

private:
    std::string id;
    std::string name;
    double price;
    PlantInstance* plant; ///< Borrowed pointer to the observed plant instance.
    bool isAvailable;
    std::string displayStatus;

    /**
     * @brief Attaches observer hooks to the supplied plant.
     */
    void bindToPlant(PlantInstance* newPlant);

    /**
     * @brief Removes observer hooks from the current plant.
     */
    void detachFromPlant();
};

#endif // STOCK_ITEM_H
