#ifndef CARE_REQUEST_HANDLER_H
#define CARE_REQUEST_HANDLER_H

#include <string>

// Forward declaration
class PlantInstance;
//
/**
 * @file CareRequestHandler.h
 * @brief The 'Handler' interface for the Chain of Responsibility. (FR21, FR22)
 */
class CareRequestHandler {
public:
    /**
     * @brief Initialises the handler with no successor in the chain.
     */
    CareRequestHandler();
    /**
     * @brief Virtual destructor to support cleanup through base pointers.
     */
    virtual ~CareRequestHandler();

    /**
     * @brief Links the next handler in the chain to allow request delegation.
     * @param h Pointer to the handler that should process requests this handler skips.
     */
    void setNext(CareRequestHandler* h);

    /**
     * @brief Passes the request through the chain, letting capable handlers react.
     * @param plant The plant instance requiring care.
     * @param requestType Identifier describing the request to fulfil.
     */
    virtual void handleRequest(PlantInstance* plant, std::string requestType);
    
    /**
     * @brief Creative Function: Checks if this handler can process the request.
     * @param requestType The type of request.
     * @return bool True if it can handle it.
     */
    virtual bool canHandle(std::string requestType) = 0;

protected:
    CareRequestHandler* nextHandler; ///< Next handler in the chain.
};

#endif // CARE_REQUEST_HANDLER_H
