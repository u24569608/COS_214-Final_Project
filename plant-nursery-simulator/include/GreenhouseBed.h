#ifndef GREENHOUSE_BED_H
#define GREENHOUSE_BED_H

#include "GreenhouseComponent.h"
#include <vector>
#include <string>
#include <memory>

/**
 * @file GreenhouseBed.h
 * @brief The 'Composite' class. Holds other components (beds or plants). (FR10)
 */
class GreenhouseBed : public GreenhouseComponent {
public:
    GreenhouseBed();
   

    void add(GreenhouseComponent* component) override;
    void remove(GreenhouseComponent* component) override;

    /**
     * @brief Cascades the care action to all children. (FR11)
     */
    void performCare() override;

    /**
     * @brief Creative Function: Finds a plant in this bed by name.
     * @param plantName The name of the plant to find.
     * @return GreenhouseComponent* A pointer to the plant, or nullptr.
     */
    GreenhouseComponent* findPlantInBed(std::string plantName);

    /**
     * @brief Creative Function: Gets the current capacity.
     * @return int The number of components in this bed.
     */
    int getSize() const;

    std::unique_ptr<GreenhouseIterator> createIterator();

private:
    std::vector<GreenhouseComponent*> children; ///< Child components.
};

#endif // GREENHOUSE_BED_H