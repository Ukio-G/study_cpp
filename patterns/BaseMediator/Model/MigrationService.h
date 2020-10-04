/**
 * Project Untitled
 */


#ifndef _MIGRATIONSERVICE_H
#define _MIGRATIONSERVICE_H

#include "BaseService.h"


class MigrationService: public BaseService {
public: 

    MigrationService(BureaucraticOrganization * organization) : BaseService(organization) { }
    /**
     * @param person
     * @param address
     */
    void Settle(Person & person, Address address);

    /**
     * @param person
     * @param address
     */
    void Evict(Person & person);

    virtual ~MigrationService() {

    }
};

#endif //_MIGRATIONSERVICE_H