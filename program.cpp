//Global Header
#include <iostream>
#include <stdexcept>

//Local Header
#include "./includes/System.h"

int main() {
    std::string command = "echo Hello World";
    try {
        std::string output = System::exec(command.c_str());
        std::cout << "Command output: " << output << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}