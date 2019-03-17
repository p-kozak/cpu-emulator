#ifndef CPU
#define CPU

#include "config.h"
#include <memory>
#include "memory.h" 
#include "registers.h"
#include "alu.h"
#include "asmb.h"
#include "programcounter.h"

using namespace std;

class Cpu{
public:
    //Subcomponents of the cpu
    Memory memory;
    Alu alu;
    ProgramCounter pc;
    Registers registers;
    Assembler asmb;

    int32_t instruction;
    int dbg;

public:
    Cpu(/* args */);
    ~Cpu();
    int32_t instructionFetch(int index);
    /*We will now decode the fetched instruction part by part.
      Opcode, addresses, registers etc - when the opcode is known the controller will determine what to do */
    int32_t instructionDecodeOpcode(int32_t instruction);
    //Next three functions will be used to decode 3 consequitive 5 bits register addresses, user can use
    int32_t instructionDecodeFirstRegister(int32_t instruction);
    int32_t instructionDecodeSecondRegister(int32_t instruction);
    int32_t instructionDecodeThirdRegister(int32_t instruction);
    int32_t instructionDecodeMemoryAddress(int32_t instruction);
    int32_t instructionDecodeAddiNumber(int32_t instruction);


    //Functions for execution
    void instructionExecute(int32_t instruction);
};



#endif