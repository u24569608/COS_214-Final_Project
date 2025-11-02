#ifndef PAYMENT_PROCESSOR_H
#define PAYMENT_PROCESSOR_H

#include <string>
//
/**
 * @file PaymentProcessor.h
 * @brief A complex subsystem class used by the Facade.
 */
class PaymentProcessor {
public:
    /**
     * @brief Creates the payment processing subsystem with default configuration.
     */
    PaymentProcessor();

    /**
     * @brief Simulates processing a customer payment.
     * @param customerDetails Identifying information for the payer.
     * @param amount Amount to charge in currency units.
     * @return True when the payment succeeds.
     */
    bool processPayment(std::string customerDetails, double amount);
};

#endif // PAYMENT_PROCESSOR_H
