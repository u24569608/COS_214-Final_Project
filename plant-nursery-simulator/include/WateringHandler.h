#ifndef WATERING_HANDLER_H
#define WATERING_HANDLER_H

#include "CareRequestHandler.h"
#include <string>
//
// Forward declaration
class PlantInstance;

/**
 * @file WateringHandler.h
 * @brief A 'ConcreteHandler' for watering requests.
 */
class WateringHandler : public CareRequestHandler {
public:
    WateringHandler();
    void handleRequest(PlantInstance* plant, std::string requestType) override;
    bool canHandle(std::string requestType) override;
};

#endif // WATERING_HANDLER_H