#ifndef GREENHOUSE_ITERATOR_H
#define GREENHOUSE_ITERATOR_H

// Forward declaration
class PlantInstance;

/**
 * @file GreenhouseIterator.h
 * @brief Declares the iteration interface used to traverse nursery plants.
 * @note Returned pointers are non-owning handles into the greenhouse composite; plants must outlive the iterator.
 */
class GreenhouseIterator {
public:
    /**
     * @brief Virtual default destructor to allow polymorphic cleanup.
     */
    virtual ~GreenhouseIterator() = default;

    /**
     * @brief Positions the iterator at the first plant in the traversal.
     * @return Pointer to the first plant, or nullptr when none exist.
     */
    virtual PlantInstance* first() = 0;

    /**
     * @brief Advances the iterator to the next plant.
     * @return Pointer to the next plant, or nullptr when the end is reached.
     */
    virtual PlantInstance* next() = 0;

    /**
     * @brief Reports whether the iterator currently references a valid plant.
     * @return True if the current position is valid, otherwise false.
     */
    virtual bool hasNext() const = 0;

    /**
     * @brief Retrieves the plant at the iterator's current position.
     * @return Pointer to the current plant, or nullptr if invalid.
     */
    virtual PlantInstance* currentItem() const = 0;
};

#endif // GreenhouseIterator.h
