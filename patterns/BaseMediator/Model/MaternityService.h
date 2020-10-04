/**
 * Project Untitled
 */


#ifndef _MATERNITYSERVICE_H
#define _MATERNITYSERVICE_H

#include "BaseService.h"


class MaternityService: public BaseService {
public: 
    MaternityService(BureaucraticOrganization * organization) : BaseService(organization) { }
    /**
     * @param name
     */

    virtual ~MaternityService() {

    }

    void registerBirth(Person person);
};

#endif //_MATERNITYSERVICE_H