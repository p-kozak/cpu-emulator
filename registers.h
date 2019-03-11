#ifndef REGISTERS
#define REGISTERS

#include <stdint.h>
#include "config.h"
#include <iostream>

class Registers{
    public:
    Registers();
    ~Registers();
    uint32_t readRegister(int index);
    void writeRegister(int index, uint32_t content);

    private:
    uint32_t* registers;

};

#endif