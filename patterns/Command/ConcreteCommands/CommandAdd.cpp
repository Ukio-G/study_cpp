//
// Created by ukio on 18.01.2021.
//

#include "CommandAdd.h"

void CommandAdd::execute() {
    result_buffer = a + b;
}

CommandAdd::CommandAdd(int a, int b, int & result) : a(a), b(b), result_buffer(result) {
}
