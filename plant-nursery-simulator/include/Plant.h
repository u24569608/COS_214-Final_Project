#ifndef PLANT_H
#define PLANT_H

#include <string>

// Forward declarations
#include "WaterStrategy.h"
#include "FertilizeStrategy.h"


/**
 * @file Plant.h
 * @brief Abstract 'Prototype' interface for all plant types.
 */
class Plant {
public:

    /**
     * @brief Virtual destructor.
     * @details Cleans up the default strategy objects owned by the prototype.
     */
    virtual ~Plant();

    /**
     * @brief Pure virtual clone method. 
     * @details Creates a deep copy of this plant prototype.
     * @return Plant* A pointer to the newly cloned plant.
     */
     virtual Plant* clone() const = 0;

     /**
      * @brief Gets the plant's common name.
      * @return std::string 
      */
     std::string getName() const ;

     /**
      * @brief Gets the plant's type (e.g., "Flower", "Cactus").
      * @return std::string 
      */
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
    /**
     * @brief Protected constructor for derived classes.
     * @param name The common name of the plant.
     * @param type The type/category of the plant.
     * @param ws The default water strategy instance.
     * @param fs The default fertilize strategy instance.
     */
    Plant(std::string name, std::string type, WaterStrategy* ws, FertilizeStrategy* fs);
    
    std::string name;
    std::string type;
    WaterStrategy* defaultWaterStrat;
    FertilizeStrategy* defaultFertilizerStrat;

private:
   /**
      * @brief Default constructor is disallowed.
      */
     Plant();
};

#endif // PLANT_H