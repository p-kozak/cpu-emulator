#include "cpu.h"

using namespace std;
   
Cpu::Cpu(/* args */){
    instruction = 0;
}

Cpu::~Cpu(){

}

int32_t Cpu::instructionFetch(int index){
    return memory.readCell(index);
}

int32_t Cpu::instructionDecodeOpcode(int32_t instruction){
    //Opcode is first five bits
    // cout << instruction << endl;
    // int32_t a,b,c,d;
    // a = 0b11111 << (32 - 5);
    // b = instruction & (0b11111 << (32 - 5));
    // c = ((instruction & (0b11111 << (32 - 5))) >> (32-5));
    // cout << a << endl << b << c << endl;
    
    return ((instruction & (0b11111 << (32 - 5))) >> (32-5));
}

int32_t Cpu::instructionDecodeFirstRegister(int32_t instruction){
    return ((instruction & (0b11111 << (32 - 10))) >> (32-10));
}

int32_t Cpu::instructionDecodeSecondRegister(int32_t instruction){
    return ((instruction & (0b11111 << (32 - 15))) >> (32-15));
}

int32_t Cpu::instructionDecodeThirdRegister(int32_t instruction){
    return ((instruction & (0b11111 << (32 - 20))) >> (32-20));
}

int32_t Cpu::instructionDecodeMemoryAddress(int32_t instruction){
    //Here we are just going to set the first 10 MS bits to 0 and return the rest
    return (instruction & (0x0000000000 << (32 - 10)));
}

int32_t Cpu::instructionDecodeAddiNumber(int32_t instruction){
    // DONE. Work on this, not complete. return 17 bit's in 2's complement but won't be recognised as such
    int32_t numBin = (instruction & (0xFFFF));

    int32_t sign  = numBin >> 15; 
    if(sign == 0){
        return numBin;
    }else{
        return -((~numBin & (0x0000FFFF))  + 1);
    }
}


//Instruction execution

void Cpu::instructionExecute(int32_t instruction){
    int32_t opcode = instructionDecodeOpcode(instruction);
    cout << opcode << endl; 
    //not all will be used but I declare  them here to not waste space
    int32_t regTargetAddress, regSecondAddress, regThirdAddress, memoryAddress, regSecondVal, regThirdVal; 
    cout << "dupa1" << endl;
    switch(opcode){
        case ADD:
            break;
        case ADDI:
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regSecondVal = registers.readRegister(regSecondAddress);
            regThirdVal  = instructionDecodeAddiNumber(instruction);
            registers.writeRegister(regTargetAddress, alu.add(regSecondVal, regThirdVal));
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