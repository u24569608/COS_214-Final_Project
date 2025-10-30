/**
 * @file CareRequestHandler.cpp
 * @brief Implements the CareRequestHandler behaviour defined in the corresponding header.
 */

#include "../include/CareRequestHandler.h"
#include <iostream>

CareRequestHandler::CareRequestHandler() {
    this->nextHandler = nullptr;
}

CareRequestHandler::~CareRequestHandler() = default;

void CareRequestHandler::handleRequest(PlantInstance* plant, std::string requestType) {
    // Base handler cannot process; forward if there is a next handler.
    if (this->nextHandler != nullptr) {
        this->nextHandler->handleRequest(plant, requestType);
        return;
    }

    // End of chain and still not handled
    std::cerr << "[CoR] Unhandled Care Request Type: " << requestType << std::endl;
}