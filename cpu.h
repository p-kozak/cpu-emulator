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
    /*We will now decode the fetched instruction part by part.
      Opcode, addresses, registers etc - when the opcode is known the controller will determine what to do */
    uint32_t instructionDecodeOpcode(uint32_t instruction);
    //Next three functions will be used to decode 3 consequitive 5 bits register addresses, user can use
    uint32_t instructionDecodeFirstRegister(uint32_t instruction);
    uint32_t instructionDecodeSecondRegister(uint32_t instruction);
    uint32_t instructionDecodeThirdRegister(uint32_t instruction);
};



#endif