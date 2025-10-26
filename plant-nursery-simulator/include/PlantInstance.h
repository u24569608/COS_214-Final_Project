#ifndef PLANT_INSTANCE_H
#define PLANT_INSTANCE_H

#include "Subject.h" // Is-a Subject (Observer)
#include "GreenhouseComponent.h" // Is-a Component 'Leaf' (Composite)
#include <string>
#include "PlantState.h"

// Forward declarations for pointers (Strategy, Prototype)
class Plant;
class WaterStrategy;
class FertilizeStrategy;

/**
 * @file PlantInstance.h
 * @brief Represents a single, physical plant in the nursery.
 * @details This is a central class that links many patterns:
 * - Leaf (Composite Pattern) - FR11
 * - ConcreteSubject (Observer Pattern) - FR12
 * - Context (Strategy Pattern) - FR5, FR6, FR7
 * - Receiver (Command Pattern) - FR18
 */
class PlantInstance /*: public Subject, public GreenhouseComponent*/ {
public:
    
    /**
     * @brief Constructor that takes a cloned prototype.
     * @param plantType A pointer to a *cloned* Plant object.
     */
    PlantInstance(Plant* plantType);

    /**
     * @brief Destructor.
     */
    ~PlantInstance();

    // === Strategy Pattern ===
    /**
     * @brief Sets the current water strategy. (FR7)
     * @param ws A pointer to the new WaterStrategy.
     */
    void setWaterStrategy(WaterStrategy* ws);
    void setFertilizeStrategy(FertilizeStrategy* fs);

    /**
     * @brief Gets the current water strategy.
     * @return WaterStrategy*
     */
    WaterStrategy* getWaterStrategy() const;

    /**
     * @brief Gets the current fertilize strategy.
     * @return FertilizeStrategy*
     */
    FertilizeStrategy* getFertilizeStrategy() const;

    // === Command Pattern (Receiver methods) ===
    void performWater();
    void performFertilize();

    // === Observer Pattern (Subject methods) ===
    /**
     * @brief Creative Function: Simulates a tick of time passing.
     * @details Lowers water, nutrients, and triggers notify() if needed.
     */
    void applyGrowthTick();

    /**
     * @brief Creative Function: Checks if the plant needs water.
     * @return bool True if waterLevel is below threshold.
     */
    bool isThirsty() const;

    /**
     * @brief Creative Function: Checks if the plant needs fertilizer.
     * @return bool True if nutrientLevel is below threshold.
     */
    bool needsFertilizing() const;

    // === Composite Pattern (Leaf method) ===
    //void performCare() override;

    // === Creative Functions (Getters/Setters) ===
    int getHealth() const;
    void setHealth(int newHealth);
    int getWaterLevel() const;
    std::string getPlantTypeName() const;

private:
    Plant* plantType; ///< The prototype
    WaterStrategy* wStrategy; ///< Current water strategy
    FertilizeStrategy* fStrategy; ///< Current fertilize strategy
    PlantState* plantState;
    
    int health;
    int waterLevel;
    int nutrientLevel;
};

#endif // PLANT_INSTANCE_H