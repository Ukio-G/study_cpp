/**
 * Project Untitled
 */


#ifndef _ADDRESS_H
#define _ADDRESS_H

#include <string>
#include <iostream>

class Address {
public: 
    int house_number;
    std::string  street_name;
    bool operator==(Address & other) {
        return (house_number == other.house_number) && (street_name == other.street_name);
    }

    bool isNull() {
        return house_number == -1;
    }

    static Address nullAddress() {
        Address address;
        address.house_number = -1;
        return address;
    }
};

#endif //_ADDRESS_H