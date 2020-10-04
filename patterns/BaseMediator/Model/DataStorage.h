/**
 * Project Untitled
 */


#ifndef _DATASTORAGE_H
#define _DATASTORAGE_H

#include <vector>
#include "Person.h"
#include "Address.h"

class DataStorage {
public:
    std::vector<Person> population;
    std::vector<Address> empty_buildings;

    void print();
};

#endif //_DATASTORAGE_H