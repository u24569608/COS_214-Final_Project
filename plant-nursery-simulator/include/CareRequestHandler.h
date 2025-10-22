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
    CareRequestHandler();
    virtual ~CareRequestHandler();

    void setNext(CareRequestHandler* h);

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