/**
 * @file ConcretePlants.h
 * @brief Defines concrete plant prototypes (e.g., Rose, Succulent).
 */
#ifndef CONCRETE_PLANTS_H
#define CONCRETE_PLANTS_H

#include "Plant.h"

// Include the specific strategies needed for these prototypes.
// (These files must exist elsewhere in your project)
#include "FrequentWatering.h"
#include "LiquidFertilizer.h"
#include "SparseWatering.h"
#include "SlowReleaseFertilizer.h"

/**
 * @class Rose
 * @brief Concrete Prototype for a Rose.
 */
class Rose : public Plant {
public:
    /**
     * @brief Constructor sets up the Rose prototype's specific properties.
     */
    Rose() : Plant("Rose", "Flower", new FrequentWatering(), new LiquidFertilizer()) {
    }
    
    /**
     * @brief Clone implementation for Rose.
     * @return Plant* A new Rose object.
     */
    Plant* clone() const override {
        return new Rose(*this); // Calls the private copy constructor
    }

private:
    /**
     * @brief Private copy constructor for deep cloning.
     * @details Ensures a deep copy by creating *new* strategy objects
     * for the clone, rather than sharing pointers.
     */
    Rose(const Rose& other) 
        : Plant(other.name, other.type, 
                new FrequentWatering(), // Deep copy of strategy
                new LiquidFertilizer()) { // Deep copy of strategy
    }
};

/**
 * @class Succulent
 * @brief Concrete Prototype for a Succulent.
 */
class Succulent : public Plant {
public:
    /**
     * @brief Constructor sets up the Succulent prototype's specific properties.
     */
    Succulent() : Plant("Succulent", "Cactus", new SparseWatering(), new SlowReleaseFertilizer()) {
    }

    /**
     * @brief Clone implementation for Succulent.
     * @return Plant* A new Succulent object.
     */
    Plant* clone() const override {
        return new Succulent(*this);
    }

private:
    /**
     * @brief Private copy constructor for deep cloning.
     */
    Succulent(const Succulent& other) 
        : Plant(other.name, other.type,
                new SparseWatering(), // Deep copy of strategy
                new SlowReleaseFertilizer()) { // Deep copy of strategy
    }
};

#endif // CONCRETE_PLANTS_H