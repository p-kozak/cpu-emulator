#include "programcounter.h"
#include <iostream>

ProgramCounter::ProgramCounter(){
    counter = 0;
}

void ProgramCounter::incrementCounter(){
    counter++; 
    return;
}

void ProgramCounter::incrementCounter(int32_t i){
    counter+=i;
    return;
}

void ProgramCounter::setCounter(int32_t index){
    if(index >= 0){
        counter = index;
    }else{
        std::cout << "ERROR: Trying to set PC to invalid value" << std::endl;
    }
    return;
}

int ProgramCounter::checkCounter(){
    return counter;
}