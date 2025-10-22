#ifndef TREE_H
#define TREE_H

#include "Plant.h"

/**
 * @file Tree.h
 * @brief Concrete prototype for a Tree.
 */
class Tree : public Plant {
public:
    Tree();
    Plant* clone() const override;
    std::string getName() const override;
    std::string getType() const override;
    std::string getRequiredSunlight() const override;
    std::string getNativeEnvironment() const override;
};

#endif // TREE_H