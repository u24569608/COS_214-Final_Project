#include <iostream>
#include <memory>
#include <string>

// === Include headers ===
#include "../include/Plant.h"
#include "../include/PlantInstance.h"
#include "../include/GreenhouseComponent.h"
#include "../include/GreenhouseBed.h"
#include "../include/GreenhouseController.h"
#include "../include/FrequentWatering.h"
#include "../include/SparseWatering.h"
#include "../include/SeasonalWatering.h"
#include "../include/LiquidFertilizer.h"
#include "../include/SlowReleaseFertilizer.h"
#include "../include/OrganicFertilizer.h"
#include "../include/WaterPlant.h"
#include "../include/FertilizePlant.h"
#include "../include/CareRequestHandler.h"
#include "../include/WateringHandler.h"
#include "../include/FertilizingHandler.h"
#include "../include/SalesFacade.h"

#include "../include/Inventory.h"
#include "../include/PaymentProcessor.h"
#include "../include/OrderBuilder.h"
#include "../include/CustomOrderBuilder.h"
#include "../include/Customer.h"
#include "../include/StockItem.h"
#include "../include/Order.h"
// === Pattern Demonstration Functions ===


// STATE PATTERN
void demoState() {
    std::cout << "\n===== STATE PATTERN DEMO =====\n";
    PlantInstance dummy(nullptr, "Seedling");
    std::cout << "Starting lifecycle... applying growth ticks.\n";
    for (int i = 0; i < 5; ++i) {
        dummy.applyGrowthTick();
        std::cout << "Tick " << (i + 1)
                  << " -> Health: " << dummy.getHealth()
                  << ", Water: " << dummy.getWaterLevel()
                  << ", Nutrients: " << dummy.getNutrientLevel()
                  << std::endl;
    }
}

// COMMAND PATTERN
void demoCommand() {
    std::cout << "\n===== COMMAND PATTERN DEMO =====\n";
    PlantInstance plant(nullptr, "Basil");
    WaterPlant waterCmd(&plant);
    FertilizePlant fertCmd(&plant);

    std::cout << "Executing WaterPlant command...\n";
    waterCmd.handleRequest();

    std::cout << "Executing FertilizePlant command...\n";
    fertCmd.handleRequest();

    std::cout << "Final status -> Health: " << plant.getHealth()
              << ", Water: " << plant.getWaterLevel()
              << ", Nutrients: " << plant.getNutrientLevel() << std::endl;
}

// COMPOSITE + ITERATOR + CONTROLLER
void demoComposite() {
    std::cout << "\n===== COMPOSITE, ITERATOR & CONTROLLER PATTERN DEMO =====\n";

    // Create a root greenhouse bed (composite)
    auto rootBed = std::make_unique<GreenhouseBed>("MainBed");

    // Add some plants into the main bed
    auto rose = new PlantInstance(nullptr, "Rose");
    auto tulip = new PlantInstance(nullptr, "Tulip");
    auto daisy = new PlantInstance(nullptr, "Daisy");

    rootBed->add(rose);
    rootBed->add(tulip);
    rootBed->add(daisy);

    // Add a sub-bed (nested composite)
    auto subBed = std::make_unique<GreenhouseBed>("SubBed");
    subBed->add(new PlantInstance(nullptr, "Lavender"));
    subBed->add(new PlantInstance(nullptr, "Mint"));
    rootBed->add(subBed.release()); // transfer ownership to main bed

    // Show structure
    std::cout << "Created greenhouse structure:\n";
    std::cout << "  MainBed\n";
    std::cout << "  ├── Rose\n";
    std::cout << "  ├── Tulip\n";
    std::cout << "  ├── Daisy\n";
    std::cout << "  └── SubBed\n";
    std::cout << "       ├── Lavender\n";
    std::cout << "       └── Mint\n\n";

    // Create a controller to manage the composite
    GreenhouseController controller(rootBed.get());

    std::cout << "Applying a growth tick across the entire greenhouse...\n";
    controller.runGrowthTick();

    // Manually perform care to show recursive traversal
    std::cout << "\nTriggering performCare() on MainBed...\n";
    rootBed->performCare();

    // Show results after care
    std::cout << "\nPlant conditions after automatic care:\n";
    std::cout << "  Rose   -> Health: " << rose->getHealth()
              << ", Water: " << rose->getWaterLevel()
              << ", Nutrients: " << rose->getNutrientLevel() << '\n';
    std::cout << "  Tulip  -> Health: " << tulip->getHealth()
              << ", Water: " << tulip->getWaterLevel()
              << ", Nutrients: " << tulip->getNutrientLevel() << '\n';
    std::cout << "  Daisy  -> Health: " << daisy->getHealth()
              << ", Water: " << daisy->getWaterLevel()
              << ", Nutrients: " << daisy->getNutrientLevel() << '\n';

    std::cout << "  (SubBed plants managed recursively by the composite.)\n";
}

// STRATEGY PATTERN
void demoStrategy() {
    std::cout << "\n===== STRATEGY PATTERN DEMO =====\n";

    Plant* plantPrototype = nullptr; // We assume Plant is abstract, so we simulate a prototype name
    PlantInstance rose(plantPrototype, "Rose");

    FrequentWatering waterStrat;
    LiquidFertilizer fertStrat;

    rose.setWaterStrategy(&waterStrat);
    rose.setFertilizeStrategy(&fertStrat);

    std::cout << "Before care -> Health: " << rose.getHealth()
              << ", Water: " << rose.getWaterLevel()
              << ", Nutrients: " << rose.getNutrientLevel() << std::endl;

    rose.performWater();
    rose.performFertilize();

    std::cout << "After care -> Health: " << rose.getHealth()
              << ", Water: " << rose.getWaterLevel()
              << ", Nutrients: " << rose.getNutrientLevel() << std::endl;
}

//CHAIN OF RESPONSIBILITY
void demoChainOfResponsibility() {
    std::cout << "\n===== CHAIN OF RESPONSIBILITY DEMO =====\n";
    WateringHandler waterHandler;
    FertilizingHandler fertHandler;
  //  waterHandler.setNext(&fertHandler);

    PlantInstance plant(nullptr, "Aloe");

    std::cout << "Sending 'Water' request...\n";
    waterHandler.handleRequest(&plant, "Water");

    std::cout << "Sending 'Fertilize' request...\n";
    waterHandler.handleRequest(&plant, "Fertilize");
}

// FACADE PATTERN (Sales + Inventory)
void demoFacade() {
    std::cout << "\n===== FACADE PATTERN DEMO =====\n";

    std::cout << "Setting up the nursery sales system...\n";

    // --- Create subsystems (simulated) ---
    Inventory inventory;               // Stock database
    PaymentProcessor paymentProcessor; // Handles payments
    CustomOrderBuilder orderBuilder;   // Builds custom orders
    GreenhouseBed greenhouse("RetailBed"); // The physical plant storage

    // Create the Facade
    SalesFacade facade(&inventory, &paymentProcessor, &orderBuilder, &greenhouse, nullptr);

    // --- Register some stock ---
    std::cout << "Adding stock to the inventory...\n";
    facade.addItemToInventory("Aloe Vera", 60.00, true);
    facade.addItemToInventory("Succulent", 45.00, true);
    facade.addItemToInventory("Fertilizer Pack", 25.00, false);

    // --- Create a customer ---
    Customer customer(1, nullptr);
    facade.registerCustomer(&customer);

    std::cout << "\nWelcome, Let's add some items to your cart.\n";
    facade.addItemToCart(&customer, "Aloe Vera");
    facade.addItemToCart(&customer, "Fertilizer Pack");

    // --- Simulate a purchase ---
    std::cout << "\nProcessing the purchase through the facade...\n";
    StockItem aloe("Aloe Vera", 60.00, nullptr);
    facade.purchaseItem(&customer, &aloe);

    // --- Check remaining stock ---
    int remaining = facade.checkStock("Aloe Vera");
    std::cout << "\nStock check after purchase:\n";
    std::cout << "  Aloe Vera remaining: " << remaining << " in stock.\n";

    // --- Customer return simulation ---
    std::cout << "\nProcessing a simulated return...\n";
    Order* dummyOrder = nullptr; // This would normally be returned from buildAndFinalizeOrder
    bool returnSuccess = facade.processReturn(dummyOrder);
    std::cout << "  Return status: " << (returnSuccess ? "Success" : "Failed (no order)") << "\n";

    std::cout << "\n[Facade] Simplified the entire process of adding stock, managing customers, handling sales, and returns.\n";
    std::cout << "Customer only interacted with the SalesFacade, not the individual subsystems.\n";
}




// MAIN DEMO DRIVER
int main() {
    std::cout << "========== COS 214 FINAL PROJECT DEMO ==========\n";

    demoState();
    demoCommand();
    demoComposite();
    demoStrategy();
    demoChainOfResponsibility();
    demoFacade();

    std::cout << "\n========== DEMO COMPLETE ==========\n";
    return 0;
}
