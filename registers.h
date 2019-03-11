#ifndef REGISTERS
#define REGISTERS

#include <stdint.h>
#include "config.h"

class Registers{
    public:
    Registers();
    ~Registers();

    private:
    uint32_t* registers;

};

#endif