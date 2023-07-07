#ifndef PL_0_COMPILER_ERROR_H
#define PL_0_COMPILER_ERROR_H

#include <iostream>
#include <string>

void error(const std::string& msg) {

    std::cout << msg << std::endl;
    exit(1);

}


#endif //PL_0_COMPILER_ERROR_H
