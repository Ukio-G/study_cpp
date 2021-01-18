//
// Created by ukio on 18.01.2021.
//

#include "Logic.h"
#include "iostream"

Logic * Logic::instance = nullptr;

Logic::Logic() {

}

void Logic::init() {
    if (Logic::instance == nullptr) {
        Logic::instance = new Logic();
    }
}

void Logic::open_stream(std::string filename) {
    this->filename = filename;
    if (!out_stream.is_open())
        out_stream.open(filename, std::ios::binary);
}

void Logic::write_to_stream(const std::string &content) {
    if (out_stream.is_open())
        out_stream << content << std::endl;
    out_stream.close();
}

Logic::~Logic()
{
    if(out_stream.is_open())
        out_stream.close();
}

Logic *Logic::get() {
    if (Logic::instance)
        return Logic::instance;
}
