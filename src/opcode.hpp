#pragma once

struct Opcode {
    const char * format;
    unsigned int length;
    unsigned int cycles_min;
    unsigned int cycles_max;
};