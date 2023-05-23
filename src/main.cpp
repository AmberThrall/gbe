#include <iostream>
#include <fmt/core.h>
#include "opcodes.hpp"
#include "register.hpp"

int main(int argc, char **argv) {
    Register hl(0x12, 0xAB);

    std::cout << "Hello World! hl = " << hl << std::endl;
    std::cout << "Test: " << fmt::format(OPCODES[0x01].format, hl.AsWord()) << std::endl;
    
    return 0;
}