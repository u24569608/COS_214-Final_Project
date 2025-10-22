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
    PaymentProcessor();
    bool processPayment(std::string customerDetails, double amount);
};

#endif // PAYMENT_PROCESSOR_H