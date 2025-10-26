#ifndef GREENHOUSE_COMPONENT_H
#define GREENHOUSE_COMPONENT_H

#include <memory>
#include <string>

class GreenhouseIterator;

/**
 * @file GreenhouseComponent.h
 * @brief The abstract 'Component' interface for the Composite pattern. (FR10, FR11)
 */
class GreenhouseComponent {
public:
    /**
     * @brief Construct a component with a human-readable name.
     * @param nameIn The logical name for this component.
     */
    GreenhouseComponent(std::string name);

    /**
     * @brief Virtual destructor to ensure proper cleanup via base pointers.
     */
    virtual ~GreenhouseComponent();
    
    /**
     * @brief Performs a care action on this component.
     * @details For a leaf (Plant), it cares for itself.
     * For a composite (Bed), it cascades to children.
     */
    virtual void performCare() = 0;

    // Composite-only methods
    /**
     * @brief Adds a child component.
     * @param component The component to add.
     * @throws std::logic_error for leaf components.
     */
    virtual void add(GreenhouseComponent* component);

    /**
     * @brief Removes a child component.
     * @param component The component to remove.
     * @throws std::logic_error for leaf components.
     */
    virtual void remove(GreenhouseComponent* component);

    /**
     * @brief Gets the display name of this component.
     * @return The component's name.
     */
    virtual std::string getName() const;

    /**
     * @brief Creates an iterator over the plants held by this component.
     * @note The iterator implementation is provided separately.
     * @return A unique pointer to a greenhouse iterator or nullptr until implemented.
     */
    virtual std::unique_ptr<GreenhouseIterator> createIterator();

protected:
    std::string name; ///< Human-readable component name.
};

#endif // GREENHOUSE_COMPONENT_H
