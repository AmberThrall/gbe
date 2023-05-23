#include <iostream>
#include <fmt/core.h>
#include "opcodes.hpp"
#include "register.hpp"

int main(int argc, char **argv) {
    Register hl(0x12, 0xAB);
    hl = 0xAB12;

    std::cout << "Hello World! hl = " << hl + hl << std::endl;
    std::cout << "Test: " << fmt::format(OPCODES[0x01].format, hl.AsWord()) << std::endl;
    std::cout << "hl == 0x12AB ? " << (hl == 0x12AB ? "True" : "False") << std::endl;
    
    return 0;
}