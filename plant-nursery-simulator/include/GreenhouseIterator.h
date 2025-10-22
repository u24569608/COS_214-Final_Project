#ifndef GREENHOUSE_ITERATOR_H
#define GREENHOUSE_ITERATOR_H

// Forward declaration
class PlantInstance;

/**
 * @file GreenhouseIterator.h
 * @brief The green house 'Iterator' interface.
 */
class GreenhouseIterator {
public:
    virtual ~GreenhouseIterator();
    virtual PlantInstance* first() = 0;
    virtual PlantInstance* next() = 0;
    virtual bool hasNext() const = 0;
    virtual PlantInstance* currentItem() const = 0;
};

#endif // GreenhouseIterator.h