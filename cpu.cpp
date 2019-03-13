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