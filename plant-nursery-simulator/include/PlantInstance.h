#ifndef PLANT_INSTANCE_H
#define PLANT_INSTANCE_H

#include "GreenhouseComponent.h" // Is-a Component 'Leaf' (Composite)
#include "PlantState.h"
#include "Subject.h"
#include <memory>
#include <string>

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
class PlantInstance : public GreenhouseComponent, public Subject {
public:
    /**
     * @brief Constructs an instance bound to a plant prototype.
     * @param plantType Pointer to the plant used to configure defaults.
     * @param instanceName Optional override for the instance name; defaults to an auto-numbered prototype name (e.g. Rose1).
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
    /**
     * @brief Executes the configured watering strategy, if present.
     */
    void applyWaterStrategy();
    /**
     * @brief Executes the configured fertilising strategy, if present.
     */
    void applyFertilizeStrategy();
     /**
     * @brief Indicates whether the current care action is a replay triggered by a state transition.
     * @return True when the active state should skip re-invoking strategies to avoid duplication.
     */
    bool isReplayingAction() const;

    /**
     * @brief Assigns a new lifecycle state to this plant.
     * @param nextState Newly allocated state that becomes active immediately.
     * @note Observers are notified when availability or care requirements change.
     */
    void setState(std::unique_ptr<PlantState> nextState);

    /**
     * @brief Inspects the currently active lifecycle state.
     * @return Pointer to the active state, or nullptr if none.
     */
    const PlantState* getState() const;

    // === Observer Pattern (Subject methods) ===
    /**
     * @brief Creative Function: Simulates a tick of time passing.
     * @details Lowers water and nutrient levels, notifies observers when care is required,
     * and defers to the current state for reactions.
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
    /**
     * @brief Indicates whether the plant is ready for retail sale.
     * @return True when the active state marks the plant as market-ready.
     */
    bool isAvailableForSale() const;

    // === Composite Pattern (Leaf method) ===
    /**
     * @brief Performs care actions for this leaf component.
     */
    void performCare() override;

    // === Creative Functions (Getters/Setters) ===
    int getHealth() const;
    void setHealth(int newHealth);
    /**
     * @brief Applies a delta to the health and clamps it within valid bounds.
     * @param delta Signed adjustment amount.
     */
    void changeHealth(int delta);
    int getWaterLevel() const;
    /**
     * @brief Overrides the stored water level, clamped to the valid range.
     * @param newLevel Desired absolute water value.
     */
    void setWaterLevel(int newLevel);
    /**
     * @brief Applies a delta to the water level and clamps the result.
     * @param delta Signed adjustment amount.
     */
    void changeWaterLevel(int delta);
    /**
     * @brief Retrieves the current nutrient saturation level.
     * @return Integer nutrient level in arbitrary units.
     */
    int getNutrientLevel() const;
    /**
     * @brief Overrides the stored nutrient level, clamped to the valid range.
     * @param newLevel Desired nutrient value.
     */
    void setNutrientLevel(int newLevel);
    /**
     * @brief Applies a delta to the nutrient level and clamps the result.
     * @param delta Signed adjustment amount.
     */
    void changeNutrientLevel(int delta);
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
    std::unique_ptr<PlantState> plantState;
    
    int health;
    int waterLevel;
    int nutrientLevel;
    bool replayingAction;

    void setReplayingAction(bool value);
    /**
     * @brief Emits a care request notification if any critical resource is low.
     */
    void requestCareIfNeeded();
};

#endif // PLANT_INSTANCE_H
