#ifndef SPARSE_WATERING_H
#define SPARSE_WATERING_H

#include "WaterStrategy.h"

/**
 * @file SparseWatering.h
 * @brief Concrete strategy for sparse watering.
 */
class SparseWatering : public WaterStrategy {
public:
    SparseWatering();
    void water(PlantInstance& plant) const override;
    WaterStrategy* clone() const override;
    
};

#endif // SPARSE_WATERING_H
