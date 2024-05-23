#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

namespace System {
    std::string exec(const char* cmd) {
        std::array<char, 128> buffer;
        std::string result;
        std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
        if (!pipe) {
            throw std::runtime_error("popen() failed!");
        }
        while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
            result += buffer.data();
        }
        return result;
    }
}

/*
int main() {
    std::string command = "add -a 10 -b 20";
    try {
        std::string output = exec(command.c_str());
        std::cout << "Command output: " << output << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
*/