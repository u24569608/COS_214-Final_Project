#ifndef ROSE_H
#define ROSE_H

#include "Plant.h"

/**
 * @file Rose.h
 * @brief Concrete prototype for a Rose.
 */
class Rose : public Plant {
public:
    Rose();
    Plant* clone() const override;
    std::string getName() const override;
    std::string getType() const override;
    std::string getRequiredSunlight() const override;
    std::string getNativeEnvironment() const override;
};

#endif // ROSE_H