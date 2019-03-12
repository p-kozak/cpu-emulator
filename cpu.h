#ifndef CPU
#define CPU

#include <iostream>
#include <memory>
#include "memory.h" 
#include "registers.h"
#include "alu.h"
#include "programcounter.h"

using namespace std;

class Cpu{
private:
    //Subcomponents of the cpu
    Memory memory;
    Alu alu;
    ProgramCounter pc;
    Registers registers;

    uint32_t instruction;

public:
    Cpu(/* args */);
    ~Cpu();
    uint32_t instructionFetch(int index);
};



#endif