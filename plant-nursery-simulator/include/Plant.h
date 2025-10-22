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
    virtual ~Plant();

    /**
     * @brief Creates a deep copy of this plant prototype.
     * @return Plant* A pointer to the newly cloned plant.
     */
     Plant* clone() const ;

     std::string getName() const ;
     std::string getType() const ;

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

protected:
    std::string name;
    std::string type;
private:
    WaterStrategy* defaultWaterStrat;
    FertilizeStrategy* defaultFertilizerStrat;

};

#endif // PLANT_H