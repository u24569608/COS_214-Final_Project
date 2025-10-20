#ifndef HERB_H
#define HERB_H

#include "Plant.h"

/**
 * @file Herb.h
 * @brief Concrete prototype for an Herb.
 */
class Herb : public Plant {
public:
    Herb();
    Plant* clone() const override;
    std::string getName() const override;
    std::string getType() const override;
    std::string getRequiredSunlight() const override;
    std::string getNativeEnvironment() const override;
};

#endif // HERB_H