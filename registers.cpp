#include "registers.h"

Registers::Registers(){

    // Inistalises registers as value 
    registers = new uint32_t[NUMBER_OF_REGISTERS]();
    
}

Registers::~Registers(){
    delete[] registers;
}