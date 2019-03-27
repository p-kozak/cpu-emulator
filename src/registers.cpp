#include "registers.h"

Registers::Registers(){

    // Inistalises registers as value 0
    registers = new int32_t[NUMBER_OF_REGISTERS]();
    
}

Registers::~Registers(){
    delete[] registers;
}

void Registers::writeRegister(int32_t index, int32_t content){
    if(index < NUMBER_OF_REGISTERS && index >= 0){
        registers[index] = content;
    }else{
        std::cout << "ERROR: Wrong address of register" << std::endl;
        std::exit(1);
    }
    return;
}

int32_t Registers::readRegister(int32_t index){
    if(index < NUMBER_OF_REGISTERS && index >= 0){
        return registers[index];
    }else{
        std::cout << "ERROR: Wrong address of register" << std::endl;
        std::exit(1);
        return 0;
    }

}

void Registers::printRegisters(){
    std::cout << "Registers: " ;
    for(int i = 0; i < 32; i++){
        std::cout << readRegister(i) << " ";
    }
    std::cout << std::endl;
}