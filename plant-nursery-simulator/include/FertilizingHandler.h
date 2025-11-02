#ifndef FERTILIZING_HANDLER_H
#define FERTILIZING_HANDLER_H

#include "CareRequestHandler.h"
#include <string>
//
// Forward declaration
class PlantInstance;

/**
 * @file FertilizingHandler.h
 * @brief A 'ConcreteHandler' for fertilizing requests.
 */
class FertilizingHandler : public CareRequestHandler {
public:
    /**
     * @brief Configures a handler dedicated to fertilisation requests.
     */
    FertilizingHandler();

    /**
     * @brief Processes fertilisation requests, delegating when inappropriate.
     * @param plant Target plant instance requiring care.
     * @param requestType Identifier describing the requested action.
     */
    void handleRequest(PlantInstance* plant, std::string requestType) override;

    /**
     * @brief Determines whether this handler is responsible for the request type.
     * @param requestType Action identifier to evaluate.
     * @return True for fertilisation requests.
     */
    bool canHandle(std::string requestType) override;
};

#endif // FERTILIZING_HANDLER_H
