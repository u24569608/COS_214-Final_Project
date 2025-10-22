#ifndef FERTILIZING_HANDLER_H
#define FERTILIZING_HANDLER_H

#include "CareRequestHandler.h"
#include <string>

// Forward declaration
class PlantInstance;

/**
 * @file FertilizingHandler.h
 * @brief A 'ConcreteHandler' for fertilizing requests.
 */
class FertilizingHandler : public CareRequestHandler {
public:
    FertilizingHandler();
    void handleRequest(PlantInstance* plant, std::string requestType) override;
    bool canHandle(std::string requestType) override;
};

#endif // FERTILIZING_HANDLER_H