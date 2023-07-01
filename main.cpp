#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

    std::string file_string = load_file(argv[1]);
    
    return 0;
}
