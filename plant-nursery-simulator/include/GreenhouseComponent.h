#ifndef GREENHOUSE_COMPONENT_H
#define GREENHOUSE_COMPONENT_H

#include <string>
#include <memory>

class GreenhouseIterator;

/**
 * @file GreenhouseComponent.h
 * @brief The abstract 'Component' interface for the Composite pattern. (FR10, FR11)
 */
class GreenhouseComponent {
public:
    virtual ~GreenhouseComponent();
    
    /**
     * @brief Performs a care action on this component.
     * @details For a leaf (Plant), it cares for itself.
     * For a composite (Bed), it cascades to children.
     */
    virtual void performCare() = 0;

    // Composite-only methods
    virtual void add(GreenhouseComponent* component);
    virtual void remove(GreenhouseComponent* component);

    virtual std::string getName() const;

    std::unique_ptr<GreenhouseIterator> createIterator();

protected:
    std::string name;
};

#endif // GREENHOUSE_COMPONENT_H