#include "programcounter.h"
#include <iostream>
using namespace std;
ProgramCounter::ProgramCounter(){
    counter = 0;
}

void ProgramCounter::incrementCounter(){
    DA DPV("Incrementing counter by: ", 1);
    counter++; 
    return;
}

void ProgramCounter::incrementCounter(int32_t i){
    DA DPV("Incrementing counter by: ", i);
    counter+=i;
    return;
}

void ProgramCounter::setCounter(int32_t index){
    if(index >= 0){
        DA DPV("Setting PC to: ", index);
        counter = index;
    }else{
        std::cout << "ERROR: Trying to set PC to invalid value" << std::endl;
    }
    return;
}

int ProgramCounter::checkCounter(){
    return counter;
}