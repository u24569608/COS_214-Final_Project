#ifndef SUCCULENT_F_H
#define SUCCULENT_F_H

#include "PlantFactory.h"

// Forward declaration
class Plant;

/**
 * @file SucculentF.h
 * @brief Concrete factory for creating Succulent objects.
 */
class SucculentF : public PlantFactory {
public:
    SucculentF();
    Plant* createPlant() const override;
};

#endif // SUCCULENT_F_H