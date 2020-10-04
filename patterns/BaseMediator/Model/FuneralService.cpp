/**
 * Project Untitled
 */


#include "FuneralService.h"

/**
 * FuneralService implementation
 */


/**
 * @param person
 */
void FuneralService::bury(Person & person) {
    organization->notify(this, person, Address::nullAddress());
}