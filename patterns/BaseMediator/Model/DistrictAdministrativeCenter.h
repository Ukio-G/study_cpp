/**
 * Project Untitled
 */


#ifndef _DISTRICTADMINISTRATIVECENTER_H
#define _DISTRICTADMINISTRATIVECENTER_H

#include "BureaucraticOrganization.h"
#include "MigrationService.h"
#include "MaternityService.h"
#include "FuneralService.h"
#include "DataStorage.h"


class DistrictAdministrativeCenter: public BureaucraticOrganization {
public: 
    MigrationService *migrationService;
    MaternityService *maternityService;
    FuneralService *funeralService;
    DataStorage *dataStorage;

    void notify(BaseService *service, Person &person, Address address) override;
};

#endif //_DISTRICTADMINISTRATIVECENTER_H