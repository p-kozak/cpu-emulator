#include "memory.h"

using namespace std;

uint32_t Memory::readCell(int cell){
    if(cell < memory.size()){
        return memory[cell];
    }else{
        cout << "ERROR: Trying to read NULL memory address" << endl;
    }
}

void Memory::writeCell(int cell, uint32_t content){
    if(cell >= memory.size()){
        memory[cell] = content;
    }else{
        cout << "ERROR: Trying to write to NULL address. Push instrad" << endl;
    }
}

void Memory::pushCell(uint32_t content){
    memory.push_back(content);
    return; 
}


