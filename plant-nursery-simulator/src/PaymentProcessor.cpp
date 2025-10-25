#include "../include/PaymentProcessor.h"
#include <iostream>

PaymentProcessor::PaymentProcessor() {
    // Constructor
}

/**
 * @brief A mock payment processing function.
 * @details In a real system, this would contact a bank or API.
 * For now, it just pretends to work.
 */
bool PaymentProcessor::processPayment(std::string customerDetails, double amount) {
    std::cout << "[PaymentProcessor] Processing payment of $" << amount
              << " for " << customerDetails << "..." << std::endl;
    // Simulate a successful payment
    std::cout << "[PaymentProcessor] Payment Approved." << std::endl;
    return true;
}