/**
 * @file Colleague.cpp
 * @brief Implements the Colleague behaviour defined in the corresponding header.
 */

#include "../include/Colleague.h"
#include "../include/FloorMediator.h"

Colleague::Colleague(FloorMediator* mediator) {
    this->mediator = mediator; 
    this->inventory = nullptr; 
}

Colleague::~Colleague() = default;