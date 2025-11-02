#ifndef CONCRETE_GREENHOUSE_ITERATOR_H
#define CONCRETE_GREENHOUSE_ITERATOR_H

#include "GreenhouseIterator.h"

#include <cstddef>
#include <vector>

class GreenhouseBed;
class GreenhouseComponent;

/**
 * @file ConcreteGreenhouseIterator.h
 * @brief Depth-first iterator that traverses all plant instances inside a greenhouse bed.
 */
class ConcreteGreenhouseIterator : public GreenhouseIterator {
public:
    /**
     * @brief Constructs an iterator rooted at the supplied greenhouse bed.
     * @param root Pointer to the composite bed that should be traversed.
     */
    explicit ConcreteGreenhouseIterator(GreenhouseBed* root);

    /** @copydoc GreenhouseIterator::first */
    PlantInstance* first() override;

    /** @copydoc GreenhouseIterator::next */
    PlantInstance* next() override;

    /** @copydoc GreenhouseIterator::hasNext */
    bool hasNext() const override;

    /** @copydoc GreenhouseIterator::currentItem */
    PlantInstance* currentItem() const override;

private:
    /**
     * @brief Recursively collects all plants under the supplied component.
     * @param component The component to traverse; may be nullptr.
     */
    void collectPlants(GreenhouseComponent* component);

    GreenhouseBed* rootBed; ///< The bed that owns the traversal (non-owning).
    std::vector<PlantInstance*> traversalOrder; ///< Pre-computed DFS order of plants (borrowed pointers).
    std::size_t currentIndex; ///< Index of the iterator's current position.
};

#endif // ConcreteGreenhouseIterator.h
