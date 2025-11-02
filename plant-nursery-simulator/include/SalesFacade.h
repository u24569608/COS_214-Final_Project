#ifndef SALES_FACADE_H
#define SALES_FACADE_H

#include <string>
#include <vector>
#include <unordered_set>

// Forward declarations for subsystem pointers
class Inventory;
class PaymentProcessor;
class Customer;
class PlantInstance;
class Order;
class OrderBuilder;
class StockItem;
class GreenhouseBed;
class PlantPrototypeRegistry;

/**
 * @file SalesFacade.h
 * @brief The 'Facade' class.
 * @details Provides a simple interface to a complex sales subsystem.
 */
class SalesFacade {
public:
    /**
     * @brief Assembles the facade with pointers to its collaborating subsystems.
     * @param inv Inventory providing stock data and persistence.
     * @param pp Payment processor responsible for transactions.
     * @param ob Builder used to assemble complex orders.
     * @param greenhouse Optional greenhouse root for integrating plant instances.
     * @param registry Optional prototype registry for cloning plants.
     */
    SalesFacade(Inventory* inv,
                PaymentProcessor* pp,
                OrderBuilder* ob,
                GreenhouseBed* greenhouse = nullptr,
                PlantPrototypeRegistry* registry = nullptr);

    /**
     * @brief Registers a customer with the sales subsystem for cart updates.
     */
    void registerCustomer(Customer* customer);

    /**
     * @brief Detaches a customer from sales notifications.
     */
    void unregisterCustomer(Customer* customer);

    /**
     * @brief Sets the greenhouse root bed used for plant inventory tracking.
     */
    void setGreenhouseRoot(GreenhouseBed* root);

    /**
     * @brief Supplies the registry used to clone prototype plants when stocking inventory.
     */
    void setPlantRegistry(PlantPrototypeRegistry* registry);

    /**
     * @brief Marks the given stock name as representing a plant type.
     * @note Ensures new stock entries produce greenhouse-backed plant instances.
     */
    void registerPlantType(const std::string& name);

    /**
     * @brief Simplifies buying a single item at the counter.
     * @return bool True if the sale was successful.
     */
    bool purchaseItem(Customer* customer, StockItem* item);

    /**
     * @brief Adds an inventory entry to the supplied customer's cart.
     * @param customer Recipient of the cart entry.
     * @param itemName Logical stock name to add.
     * @return True when the item was found and tracked.
     */
    bool addItemToCart(Customer* customer, const std::string& itemName);

    /**
     * @brief Creative Function: Processes a complex custom order.
     * @return Order* The finalized order, or nullptr if failed.
     */
    Order* buildAndFinalizeOrder(Customer* customer, std::vector<StockItem> items);

    /**
     * @brief Creative Function: Processes a return.
     * @param order The order to be returned.
     * @return bool True if the return was successful.
     */
    bool processReturn(Order* order);

    /**
     * @brief Creative Function: Checks stock level for an item.
     * @param plantType The name of the plant.
     * @return int The number in stock.
     */
    int checkStock(std::string plantType);

    /**
     * @brief Adds a new item to the inventory and greenhouse (when applicable).
     * @param name Logical stock name.
     * @param price Retail price.
     * @param isPlant When true, a greenhouse plant instance will accompany the stock.
     */
    void addItemToInventory(std::string name, double price, bool isPlant = true);

private:
    /**
     * @brief Notifies registered customers that a stock item has been sold.
     * @param itemId Stable identifier of the removed stock entry (may be empty when unknown).
     * @param itemName Human-readable name of the sold item.
     */
    void notifyItemSold(const std::string& itemId, const std::string& itemName);
    /**
     * @brief Propagates greenhouse and registry pointers into the inventory subsystem.
     */
    void syncInventoryContext();

    /**
     * @brief Determines whether a stock name should create greenhouse plant instances.
     * @param name Logical stock identifier.
     * @return True when the name is treated as a plant.
     */
    bool isPlantStock(const std::string& name) const;

    /**
     * @brief Registers the supplied plant type with the prototype registry if necessary.
     * @param name Plant name to ensure availability for cloning.
     */
    void ensurePrototypeRegistered(const std::string& name);

    Inventory* inventory; ///< Subsystem 1
    PaymentProcessor* paymentProcessor; ///< Subsystem 2
    OrderBuilder* orderBuilder; ///< Subsystem 3
    GreenhouseBed* greenhouseRoot;
    PlantPrototypeRegistry* plantRegistry;
    std::vector<Customer*> customers;
    std::unordered_set<std::string> registeredManualPlants;
};

#endif // SALES_FACADE_H
