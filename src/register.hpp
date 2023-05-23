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

    Register& operator=(const word& rhs) {
        FromWord(rhs);
        return *this;
    }

    Register& operator+=(const word rhs) {
        word v = AsWord();
        v += rhs;
        FromWord(v);
        return *this;
    }
    Register& operator+=(const Register& rhs) {
        (*this) += rhs.AsWord();
        return *this;
    }

    Register& operator-=(const word rhs) {
        word v = AsWord();
        v -= rhs;
        FromWord(v);
        return *this;
    }
    Register& operator-=(const Register& rhs) {
        (*this) -= rhs.AsWord();
        return *this;
    }

    Register& operator++() {
        (*this) += 1;
        return *this;
    }
    Register operator++(int) {
        Register old = *this;
        operator++();
        return old;
    }
    Register& operator--() {
        (*this) -= 1;
        return *this;
    }
    Register operator--(int) {
        Register old = *this;
        operator--();
        return old;
    }

    friend Register operator+(Register lhs, const word& rhs) {
        return Register(lhs.AsWord() + rhs);
    }
    friend Register operator+(Register lhs, const Register& rhs) {
        return Register(lhs.AsWord() + rhs.AsWord());
    }
    friend Register operator-(Register lhs, const word& rhs) {
        return Register(lhs.AsWord() - rhs);
    }
    friend Register operator-(Register lhs, const Register& rhs) {
        return Register(lhs.AsWord() - rhs.AsWord());
    }

    friend bool operator==(const Register& lhs, const Register& rhs) {
        return lhs.hi == rhs.hi && lhs.lo == rhs.lo;
    }
    friend bool operator==(const Register& lhs, const word rhs) {
        return lhs == Register(rhs);
    }
    friend bool operator!=(const Register& lhs, const Register& rhs) {
        return !(lhs == rhs);
    }
    friend bool operator!=(const Register& lhs, const word rhs) {
        return !(lhs == rhs);
    }

    friend std::ostream& operator<<(std::ostream& os, const Register& obj) {
        os << fmt::format("0x{:04X}", obj.AsWord());
        return os;
    }
};