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