/**
 * Project Untitled
 */


#ifndef _BASESERVICE_H
#define _BASESERVICE_H

#include "BureaucraticOrganization.h"
#include "Person.h"
#include "Address.h"


class BaseService {
public:
    BaseService() = default;
    BaseService(BureaucraticOrganization * organization) : organization(organization) { };
    BureaucraticOrganization * organization;

/**
 * @param organization
 */
    void setOrganization(BureaucraticOrganization * organization);
    virtual ~BaseService() { }
};

#endif //_BASESERVICE_H