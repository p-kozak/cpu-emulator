#ifndef REGISTERS
#define REGISTERS

#include "config.h"


class Registers{
    public:
    Registers();
    ~Registers();
    int32_t readRegister(int32_t index);
    void writeRegister(int32_t index, int32_t content);
    void printRegisters();
    private:
    int32_t* registers;

};

#endif