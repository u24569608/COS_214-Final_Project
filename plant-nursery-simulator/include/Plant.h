#ifndef PLANT_H
#define PLANT_H

#include <string>
#include "WaterStrategy.h"
#include "FertilizeStrategy.h"


/**
 * @file Plant.h
 * @brief Abstract 'Prototype' interface for all plant types.
 */
class Plant {
public:
    /**
     * @brief Constructs an empty prototype with no default strategies configured.
     */
    Plant();
    virtual ~Plant();

    /**
     * @brief Creates a deep copy of this plant prototype.
     * @return Plant* A pointer to the newly cloned plant.
     */
    virtual Plant* clone() const = 0;

    std::string getName() const;
    std::string getType() const;

    /**
     * @brief Assigns a human-readable display name to the prototype.
     * @param newName The name to set.
     */
    void setName(const std::string& newName);

    /**
     * @brief Updates the categorical type for the prototype (e.g. Succulent, Herb).
     * @param newType The type string to assign.
     */
    void setType(const std::string& newType);

    /**
     * @brief Creative Function: Gets the ideal water strategy for this plant.
     * @return WaterStrategy*.
     */
    WaterStrategy* getDefaultWaterStrat() const;

    /**
     * @brief Creative Function: Gets the ideal fertilizer strategy.
     * @return FertilizeStrategy*.
     */
    FertilizeStrategy* getDefaultFertStrat() const;

    /**
     * @brief Sets the default watering strategy associated with this prototype.
     * @param strategy Pointer to a WaterStrategy instance (non-owning).
     */
    void setDefaultWaterStrat(WaterStrategy* strategy);

    /**
     * @brief Sets the default fertilizing strategy associated with this prototype.
     * @param strategy Pointer to a FertilizeStrategy instance (non-owning).
     */
    void setDefaultFertStrat(FertilizeStrategy* strategy);

protected:
    std::string name;
    std::string type;
private:
    WaterStrategy* defaultWaterStrat;
    FertilizeStrategy* defaultFertilizerStrat;

};

#endif // PLANT_H
