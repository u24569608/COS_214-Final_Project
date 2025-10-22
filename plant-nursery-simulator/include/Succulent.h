#ifndef SUCCULENT_H
#define SUCCULENT_H

#include "Plant.h"

/**
 * @file Succulent.h
 * @brief Concrete prototype for a Succulent.
 */
class Succulent : public Plant {
public:
    Succulent();
    Plant* clone() const override;
    std::string getName() const override;
    std::string getType() const override;
    std::string getRequiredSunlight() const override;
    std::string getNativeEnvironment() const override;
};

#endif // SUCCULENT_H