/**
 * Project Untitled
 */


#ifndef _BUREAUCRATICORGANIZATION_H
#define _BUREAUCRATICORGANIZATION_H

#include "Person.h"
#include "Address.h"

class BaseService;
class BureaucraticOrganization {
public: 
    
/**
 * @param service
 * @param person
 * @param address
 */
    virtual void notify(BaseService * service, Person & person, Address address) = 0;
};

#endif //_BUREAUCRATICORGANIZATION_H