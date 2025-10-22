#ifndef ROSE_F_H
#define ROSE_F_H

#include "PlantFactory.h"

// Forward declaration
class Plant;

/**
 * @file RoseF.h
 * @brief Concrete factory for creating Rose objects.
 */
class RoseF : public PlantFactory {
public:
    RoseF();
    Plant* createPlant() const override;
};

#endif // ROSE_F_H