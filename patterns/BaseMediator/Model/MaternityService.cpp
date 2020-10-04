/**
 * Project Untitled
 */


#include "MaternityService.h"

/**
 * MaternityService implementation
 */


/**
 * @param name
 */
void MaternityService::registerBirth(Person person) {
    organization->notify(this, person, person.address);
}