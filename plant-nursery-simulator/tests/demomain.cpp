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


// MAIN DEMO DRIVER
int main() {
    std::cout << "========== COS 214 FINAL PROJECT DEMO ==========\n";

    demoState();
    demoCommand();
    demoComposite();

    std::cout << "\n========== DEMO COMPLETE ==========\n";
    return 0;
}
