#ifndef SPARSE_WATERING_H
#define SPARSE_WATERING_H

#include "WaterStrategy.h"

/**
 * @file SparseWatering.h
 * @brief Concrete strategy for sparse watering.
 */
class SparseWatering : public WaterStrategy {
public:
    /**
     * @brief Configures a strategy suited to drought-tolerant plants.
     */
    SparseWatering();

    /**
     * @brief Applies a minimal watering action to the plant.
     * @param plant Plant instance to hydrate sparingly.
     */
    void water(PlantInstance& plant) const override;

    /**
     * @brief Clones the sparse watering strategy instance.
     * @return Newly allocated strategy object.
     */
    WaterStrategy* clone() const override;    
};

#endif // SPARSE_WATERING_H
