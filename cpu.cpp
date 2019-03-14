#include "cpu.h"

using namespace std;
   
Cpu::Cpu(/* args */){
    instruction = 0;
}

Cpu::~Cpu(){

}

uint32_t Cpu::instructionFetch(int index){
    return memory.readCell(index);
}

uint32_t Cpu::instructionDecodeOpcode(uint32_t instruction){
    //Opcode is first five bits
    return (instruction & (0xF8 << (31 - 5)) >> (31-5));
}

uint32_t Cpu::instructionDecodeFirstRegister(uint32_t instruction){
    return (instruction & (0xF8 << (31 - 10)) >> (31-10));
}

uint32_t Cpu::instructionDecodeSecondRegister(uint32_t instruction){
    return (instruction & (0xF8 << (31 - 15)) >> (31-15));
}

uint32_t Cpu::instructionDecodeThirdRegister(uint32_t instruction){
    return (instruction & (0xF8 << (31 - 15)) >> (31-15));
}

uint32_t Cpu::instructionDecodeMemoryAddress(uint32_t instruction){
    //Here we are just going to set the first 10 MS bits to 0 and return the rest
    return (instruction & (0x003 << (31 - 10)));
}

uint32_t Cpu::instructionDecodeMemoryAddress(uint32_t instruction){
    //Here we are just going to set the first 10 MS bits to 0 and return the rest
    return (instruction & (0x003 << (31 - 10)));
}

uint32_t Cpu::instructionDecodeAddiNumber(uint32_t instruction){
    //Work on this, not complete. return 17 bit's in 2's complement but won't be recognised as such
    return  (instruction & (0x1FFFF));

    // uint32_t sign  = numBin >> 16;
    // if(sign == 0){
    //     return numBin;
    // }else{
    //     return (~numBin + 1);
    // }
}


//Instruction execution

void Cpu::instructionExecute(uint32_t instruction){
    uint32_t opcode = instructionDecodeOpcode(instruction);
    //not all will be used but I declare  them here to not waste space
    uint32_t regTarget, regSecond, regThird, memoryAddress; 
    switch(opcode){
        case ADD:
            break;
        case ADDI:
            break;
        case SUB:
            break;
        case LW:
            break;
        case SW:
            break;
        case BEQ:
            break;


    }
}