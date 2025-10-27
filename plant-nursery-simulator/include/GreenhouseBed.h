#ifndef GREENHOUSE_BED_H
#define GREENHOUSE_BED_H

#include "GreenhouseComponent.h"
#include <vector>
#include <string>
#include <memory>

class ConcreteGreenhouseIterator;
class PlantInstance;

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
     * @note Calling this overload transfers ownership of the supplied pointer to the bed.
     *       Only pass dynamically allocated components that are no longer managed elsewhere.
     */
    void add(GreenhouseComponent* component) override;

    /**
     * @brief Transfers ownership of a child component into this bed.
     * @param component Newly created component to adopt.
     * @return Raw pointer to the adopted component, or nullptr when ignored.
     */
    GreenhouseComponent* add(std::unique_ptr<GreenhouseComponent> component);

    /**
     * @brief Removes a child component from this bed.
     * @param component The component pointer to remove.
     * @note Removing a child releases and destroys it unless `release` was used to transfer ownership.
     */
    void remove(GreenhouseComponent* component) override;

    /**
     * @brief Transfers ownership of a specific child back to the caller.
     * @param component Target child pointer.
     * @return Unique pointer owning the component, or nullptr if not found.
     */
    std::unique_ptr<GreenhouseComponent> release(GreenhouseComponent* component);

    /**
     * @brief Convenience wrapper to transfer a plant leaf out of the bed.
     * @param plant Leaf component to extract.
     * @return Owning unique_ptr for the plant, or nullptr when not present.
     */
    std::unique_ptr<PlantInstance> releasePlant(PlantInstance* plant);

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
     * @return Unique pointer to a greenhouse iterator traversing the composite hierarchy.
     */
    std::unique_ptr<GreenhouseIterator> createIterator() override;

private:
    friend class ConcreteGreenhouseIterator; ///< Allows iterator to traverse private children.
    std::vector<std::unique_ptr<GreenhouseComponent>> children; ///< Owned child components.
};

#endif // GREENHOUSE_BED_H
