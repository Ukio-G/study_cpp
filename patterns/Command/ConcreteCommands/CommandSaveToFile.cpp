//
// Created by ukio on 18.01.2021.
//

#include "CommandSaveToFile.h"
#include <iomanip>
#include <fstream>

CommandSaveToFile::CommandSaveToFile(const std::string & content) : content(content)
{ }

void CommandSaveToFile::execute() {
    Logic::get()->write_to_stream(content);
}
