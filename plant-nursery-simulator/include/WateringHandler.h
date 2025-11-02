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
    /**
     * @brief Configures a handler dedicated to watering requests.
     */
    WateringHandler();

    /**
     * @brief Processes watering requests or delegates to the next handler.
     * @param plant Plant instance requiring care.
     * @param requestType Logical request type descriptor.
     */
    void handleRequest(PlantInstance* plant, std::string requestType) override;

    /**
     * @brief Determines whether the handler can satisfy the request.
     * @param requestType Action identifier to evaluate.
     * @return True when the request is a watering action.
     */
    bool canHandle(std::string requestType) override;
};

#endif // WATERING_HANDLER_H
