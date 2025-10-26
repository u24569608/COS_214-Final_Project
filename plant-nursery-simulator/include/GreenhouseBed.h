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
    /**
     * @brief Constructs an unnamed bed composite.
     */
    GreenhouseBed();

    /**
     * @brief Constructs a named bed composite.
     * @param bedName The name used to identify this bed.
     */
    explicit GreenhouseBed(std::string bedName);

    /**
     * @brief Adds a child component to this bed.
     * @param component The component to add; ignored if nullptr or already present.
     */
    void add(GreenhouseComponent* component) override;

    /**
     * @brief Removes a child component from this bed.
     * @param component The component pointer to remove.
     */
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

    /**
     * @brief Creates an iterator spanning every plant in this bed.
     * @return Unique pointer to a greenhouse iterator, or nullptr until provided.
     */
    std::unique_ptr<GreenhouseIterator> createIterator() override;

private:
    std::vector<GreenhouseComponent*> children; ///< Child components.
};

#endif // GREENHOUSE_BED_H
