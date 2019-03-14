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
    return (instruction & (0x003FFFFF ));
}

int32_t Cpu::instructionDecodeAddiNumber(int32_t instruction){
    // DONE. Work on this, not complete. return 17 bit's in 2's complement but won't be recognised as such
    // Actually I'm not sure if all this mess is required. Probably I could just cast the instruction to int16_t and work on this...
    // But ir works so I'm fine :)))

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
    //cout << "Opcode " << opcode << endl;
    //not all will be used but I declare  them here to not waste space
    int32_t regTargetAddress, regTargetVal, regSecondAddress, regThirdAddress, memoryAddress, regSecondVal, regThirdVal, memoryVal; 
    switch(opcode){
        case ADD:
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regThirdAddress = instructionDecodeThirdRegister(instruction);
            regSecondVal = registers.readRegister(regSecondAddress);
            regThirdVal = registers.readRegister(regThirdAddress);
            registers.writeRegister(regTargetAddress, alu.add(regSecondVal, regThirdVal));
            break;
        case ADDI:
            //Here I am using the rhird register variable just to store the value of ADDI immediate value
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regSecondVal = registers.readRegister(regSecondAddress);
            regThirdVal  = instructionDecodeAddiNumber(instruction);
            registers.writeRegister(regTargetAddress, alu.add(regSecondVal, regThirdVal));
            break;
        case SUB:
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regSecondAddress = instructionDecodeSecondRegister(instruction);
            regThirdAddress = instructionDecodeThirdRegister(instruction);

            regSecondVal = registers.readRegister(regSecondAddress);
            regThirdVal = registers.readRegister(regThirdAddress);
      
            registers.writeRegister(regTargetAddress, alu.sub(regSecondVal, regThirdVal));
            break;
        case LW:
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            memoryAddress = instructionDecodeMemoryAddress(instruction);
            memoryVal = memory.readCell(memoryAddress);
            registers.writeRegister(regTargetAddress, memoryVal);
            break;
        case SW:
            regTargetAddress = instructionDecodeFirstRegister(instruction);
            regTargetVal = registers.readRegister(regTargetAddress);
            memory.pushCell(regTargetVal);
            break;
        case BEQ:
            break;


    }
}