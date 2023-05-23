#include "register.hpp"

Register::Register(byte hi, byte lo) : hi(hi), lo(lo) {    
}

Register::Register(word value) { 
    FromWord(value);
}

word Register::AsWord() const {
    return (word(hi) << 8) | word(lo);
}

void Register::FromWord(word value) {
    hi = byte(value >> 8);
    lo = byte(value & 0xFF);
}