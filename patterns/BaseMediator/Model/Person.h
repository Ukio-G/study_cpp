/**
 * Project Untitled
 */


#ifndef _PERSON_H
#define _PERSON_H

#include <string>
#include "Address.h"

class Person {
public: 
    std::string name;
    Address address;
    bool operator==(Person & other) {
        return (name == other.name) && (address == other.address);
    }
};

#endif //_PERSON_H