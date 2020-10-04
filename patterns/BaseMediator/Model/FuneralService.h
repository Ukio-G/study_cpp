/**
 * Project Untitled
 */


#ifndef _FUNERALSERVICE_H
#define _FUNERALSERVICE_H

#include "Person.h"
#include "BaseService.h"


class FuneralService: public BaseService {
public:
    FuneralService(BureaucraticOrganization * organization) : BaseService(organization) { }
    /**
     * @param person
     */
    void bury(Person & person);

    virtual ~FuneralService() {

    }
};

#endif //_FUNERALSERVICE_H