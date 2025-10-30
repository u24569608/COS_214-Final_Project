/**
 * @file FertilizingHandler.cpp
 * @brief Implements the FertilizingHandler behaviour defined in the corresponding header.
 */

#include "../include/FertilizingHandler.h"
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

FertilizingHandler::FertilizingHandler() = default;

bool FertilizingHandler::canHandle(std::string requestType) {
    std::string t = toLower(requestType);
    // Accept common variants
    return t == "fertilize" || t == "fertilising" || t == "fertilizing" || t == "fertiliser" || t == "fertilizer";
}

void FertilizingHandler::handleRequest(PlantInstance* plant, std::string requestType) {
    if (this->canHandle(requestType)) {
        if (plant == nullptr) {
            std::cerr << "[FertilizingHandler] Plant is NULL. Cannot Execute Fertilizing." << std::endl;
            return;
        }
        plant->performFertilize();
        return;
    }

    // Not mine -> pass down the chain or report unhandled at tail
    if (this->nextHandler != nullptr) {
        this->nextHandler->handleRequest(plant, requestType);
        return;
    }

    std::cerr << "[CoR] Unhandled Care Request Type: " << requestType << std::endl;
}