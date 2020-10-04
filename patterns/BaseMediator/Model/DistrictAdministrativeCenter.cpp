/**
 * Project Untitled
 */


#include <algorithm>
#include "DistrictAdministrativeCenter.h"

/**
 * DistrictAdministrativeCenter implementation
 */
void DistrictAdministrativeCenter::notify(BaseService *service, Person &person, Address address) {
    if (dynamic_cast<MaternityService*>(service) == service) {
        dataStorage->population.emplace_back(person);
    } else if (dynamic_cast<FuneralService*>(service) == service) {
        auto last_iter = dataStorage->population.end();
        for(auto iterator = dataStorage->population.begin(); iterator != last_iter; iterator++) {
            if (*iterator == person) {
                dataStorage->population.erase(iterator);
                if (!person.address.isNull())
                    dataStorage->empty_buildings.push_back(person.address);
                break;
            }
        }
    } else if (dynamic_cast<MigrationService*>(service) == service) {
        address.isNull();
        if (address.isNull()) { // Evict
            if(!person.address.isNull())
                dataStorage->empty_buildings.push_back(person.address);
            person.address.house_number = -1;
            person.address.street_name.clear();
        } else {
            person.address = address;
        }
    }
}
