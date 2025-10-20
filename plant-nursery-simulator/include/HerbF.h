#ifndef HERB_F_H
#define HERB_F_H

#include "PlantFactory.h"

// Forward declaration
class Plant;

/**
 * @file HerbF.h
 * @brief Concrete factory for creating Herb objects.
 */
class HerbF : public PlantFactory {
public:
    HerbF();
    Plant* createPlant() const override;
};

#endif // HERB_F_H