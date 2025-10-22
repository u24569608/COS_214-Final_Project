#ifndef CONCRETE_GREENHOUSE_ITERATOR_H
#define CONCRETE_GREENHOUSE_ITERATOR_H

#include "GreenhouseIterator.h"
#include "GreenhouseBed.h"
/**
 * @file ConcreteGreenhouseIterator.h
 * @brief The green house 'Iterator' Implementation.
 */
class ConcreteGreenhouseIterator : GreenhouseIterator {
public:

    ConcreteGreenhouseIterator(GreenhouseBed* root);
    
    PlantInstance* first();
    PlantInstance* next();
    bool hasNext() const;
    PlantInstance* currentItem() const;
};

#endif // ConcreteGreenhouseIterator.h