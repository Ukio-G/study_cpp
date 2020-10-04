/**
 * Project Untitled
 */


#include <iostream>
#include "DataStorage.h"

/**
 * DataStorage implementation
 */
void DataStorage::print() {
    std::cout << "Population:\n";
    for (auto &item : population)
        std::cout << item.name << " address:" << item.address.street_name << ", " << item.address.house_number << "\n";
    std::cout << "Homeless:\n";
    for (auto &item : population)
        if (item.address.isNull())
            std::cout << item.name << "\n";
    std::cout << "Empty buildings:\n";
    for (auto &item : empty_buildings)
        std::cout << item.street_name << " " << item.house_number << "\n";
}
