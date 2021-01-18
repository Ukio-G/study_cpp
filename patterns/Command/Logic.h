//
// Created by ukio on 18.01.2021.
//

#ifndef COMMAND_LOGIC_H
#define COMMAND_LOGIC_H


#include <string>
#include <ostream>
#include <fstream>

class Logic {
public:
    static void init();
    void open_stream(std::string filename);
    void write_to_stream(const std::string &content);
    static Logic * get();
    ~Logic();
private:
    static Logic * instance;
    std::string filename;
    std::ofstream out_stream;
    Logic();

};


#endif //COMMAND_LOGIC_H
