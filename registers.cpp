#include "registers.h"

Registers::Registers(){

    // Inistalises registers as value 0
    registers = new uint32_t[NUMBER_OF_REGISTERS]();
    
}

Registers::~Registers(){
    delete[] registers;
}

void Registers::writeRegister(int index, uint32_t content){
    if(index < NUMBER_OF_REGISTERS && index >= 0){
        registers[index] = content;
    }else{
        std::cout << "ERROR: Wrong address of register" << std::endl;
    }
    return;
}

uint32_t Registers::readRegister(int index){
    if(index < NUMBER_OF_REGISTERS && index >= 0){
        return registers[index];
    }else{
        std::cout << "ERROR: Wrong address of register" << std::endl;
        return 0;
    }

}