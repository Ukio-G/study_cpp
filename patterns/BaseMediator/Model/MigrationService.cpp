/**
 * Project Untitled
 */


#include "MigrationService.h"

/**
 * MigrationService implementation
 */


/**
 * @param person
 * @param address
 */
void MigrationService::Settle(Person & person, Address address) {
    organization->notify(this, person, address);
}

/**
 * @param person
 * @param address
 */
void MigrationService::Evict(Person & person) {
    organization->notify(this, person, Address::nullAddress());
}