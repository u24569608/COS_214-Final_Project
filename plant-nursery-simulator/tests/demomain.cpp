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



// MAIN DEMO DRIVER
int main() {
    std::cout << "========== COS 214 FINAL PROJECT DEMO ==========\n";

    demoState();
    demoCommand();

    std::cout << "\n========== DEMO COMPLETE ==========\n";
    return 0;
}
