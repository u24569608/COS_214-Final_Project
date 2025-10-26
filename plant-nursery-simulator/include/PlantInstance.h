#ifndef PLANT_INSTANCE_H
#define PLANT_INSTANCE_H

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
 * - ConcreteSubject (Observer Pattern) - FR12 (TODO: reintroduce when observer is implemented)
 * - Context (Strategy Pattern) - FR5, FR6, FR7
 * - Receiver (Command Pattern) - FR18
 */
class PlantInstance : public GreenhouseComponent {
public:
    /**
     * @brief Constructs an instance bound to a plant prototype.
     * @param plantType Pointer to the plant used to configure defaults.
     * @param instanceName Optional override for the instance name; defaults to the prototype name.
     */
    PlantInstance(Plant* plantType, std::string instanceName = "");
    ~PlantInstance();

    // === Strategy Pattern ===
    /**
     * @brief Sets the current water strategy. (FR7)
     * @param ws A pointer to the new WaterStrategy.
     */
    void setWaterStrategy(WaterStrategy* ws);
    void setFertilizeStrategy(FertilizeStrategy* fs);

    // === Command Pattern (Receiver methods) ===
    void performWater();
    void performFertilize();

    // === Observer Pattern (Subject methods) ===
    /**
     * @brief Creative Function: Simulates a tick of time passing.
     * @details Lowers water and nutrient levels, then defers to the current state for reactions.
     * @note TODO(FR12): Replace the fixed consumption values once balancing rules are decided.
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
    /**
     * @brief Performs care actions for this leaf component.
     */
    void performCare() override;

    // === Creative Functions (Getters/Setters) ===
    int getHealth() const;
    void setHealth(int newHealth);
    int getWaterLevel() const;
    /**
     * @brief Retrieves the current nutrient saturation level.
     * @return Integer nutrient level in arbitrary units.
     */
    int getNutrientLevel() const;
    std::string getPlantTypeName() const;
    /**
     * @brief Updates the human-readable name of this plant instance.
     * @param newName The new name to assign; ignored when empty.
     */
    void rename(const std::string& newName);

private:
    static std::string deriveInstanceName(Plant* plantType, const std::string& instanceName);

    Plant* plantType; 
    WaterStrategy* wStrategy; ///< Current water strategy
    FertilizeStrategy* fStrategy; ///< Current fertilize strategy
    PlantState* plantState;
    
    int health;
    int waterLevel;
    int nutrientLevel;
};

#endif // PLANT_INSTANCE_H
