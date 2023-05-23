#pragma once

#include <ostream>
#include <fmt/core.h>
#include "global.hpp"

class Register {
public:
    Register(byte hi, byte lo);
    Register(word value);

    word AsWord() const;
    void FromWord(word value);

    byte hi;
    byte lo;

    friend std::ostream& operator<<(std::ostream& os, const Register& obj) {
        os << fmt::format("0x{:04X}", obj.AsWord());
        return os;
    }
};