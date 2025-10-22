#ifndef TREE_F_H
#define TREE_F_H

#include "PlantFactory.h"

// Forward declaration
class Plant;

/**
 * @file TreeF.h
 * @brief Concrete factory for creating Tree objects.
 */
class TreeF : public PlantFactory {
public:
    TreeF();
    Plant* createPlant() const override;
};

#endif // TREE_F_H