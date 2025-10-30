/**
 * @file WateringHandler.cpp
 * @brief Implements the WateringHandler behaviour defined in the corresponding header.
 */

#include "../include/WateringHandler.h"
#include "../include/PlantInstance.h"
#include <algorithm>
#include <cctype>
#include <iostream>

namespace {
    static std::string toLower(std::string s) {
        for (char& ch : s) {
            ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        }
        return s;
    }
}

WateringHandler::WateringHandler() = default;

bool WateringHandler::canHandle(std::string requestType) {
    std::string t = toLower(requestType);
    // Accept common variants
    return t == "water" || t == "watering";
}

void WateringHandler::handleRequest(PlantInstance* plant, std::string requestType) {
    if (this->canHandle(requestType)) {
        if (plant == nullptr) {
            std::cerr << "[WateringHandler] Plant is NULL. Cannot Execute Watering." << std::endl;
            return;
        }

        plant->performWater();
        return;
    }

    // Not mine -> pass down the chain or report unhandled at tail
    if (this->nextHandler != nullptr) {
        this->nextHandler->handleRequest(plant, requestType);
        return;
    }

    std::cerr << "[CoR] Unhandled Care Request Type: " << requestType << std::endl;
}