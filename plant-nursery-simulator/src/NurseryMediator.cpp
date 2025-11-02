/**
 * @file NurseryMediator.cpp
 * @brief Implements the NurseryMediator behaviour defined in the corresponding header.
 */

#include "../include/NurseryMediator.h"
#include "../include/Colleague.h"
#include <iostream>

NurseryMediator::NurseryMediator() {

}

void NurseryMediator::addColleague(Colleague* colleague) {
    if (colleague == nullptr) {
        std::cerr << "[Mediator] Attempted to add a NULL colleague." << std::endl;
        return;
    }

    bool alreadyExists = false;

    for (Colleague* existing : this->colleagues) {
        if (existing == colleague) {
            alreadyExists = true;
            break;
        }
    }

    if (alreadyExists == false) {
        this->colleagues.push_back(colleague);
    } else {
        std::cerr << "[Mediator] Colleague already registered." << std::endl;
    }
}

void NurseryMediator::distribute(std::string message, int senderID, int recipientID) {
    if (this->colleagues.empty() == true) {
        std::cerr << "[Mediator] No colleagues available for message distribution." << std::endl;
        return;
    }

    if (recipientID == -1) {
        for (Colleague* colleague : this->colleagues) {
            if ((colleague != nullptr) && (colleague->getID() != senderID)) {
                colleague->receive(message);
            }
        }
        return;
    }

    bool found = false;

    for (Colleague* colleague : this->colleagues) {
        if ((colleague != nullptr) && (colleague->getID() == recipientID)) {
            colleague->receive(message);
            found = true;
            break;
        }
    }

    if (found == false) {
        std::cerr << "[Mediator] Recipient with ID " << recipientID << " not found." << std::endl;
    }
}