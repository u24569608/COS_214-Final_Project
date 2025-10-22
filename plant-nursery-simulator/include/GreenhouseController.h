#ifndef GREENHOUSE_CONTROLLER_H
#define GREENHOUSE_CONTROLLER_H

/**
 * @file GreenhouseController.h
 * @brief The 'controller' class. Preforms the growthTick opertion.
 */

#include "GreenhouseBed.h"

class GreenhouseController{
    public:
    void runGrowthTick();


    private:
    GreenhouseBed* rootBed;

};

#endif