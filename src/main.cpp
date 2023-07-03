#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "lexer.h"

std::string load_file(char* path) {
    std::string file_string;

    std::ifstream is(path);
    if (!is.is_open()) {
        std::cout << "failed to open file" << std::endl;
    }
    else {
        std::ostringstream str_stream;
        str_stream << is.rdbuf();
        file_string = str_stream.str();
    }

    return file_string;
}


int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cout << "Input file is not specified";
        exit(1);
    }

    std::string file_string = load_file(argv[1]);
    Lexer l;

    Token t;
    std::string::iterator it = file_string.begin();
    while ((t = l.next_token(it))) {

        std::cout << (char)t << std::endl;
    }

    return 0;
}
