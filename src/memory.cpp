#include "memory.h"

using namespace std;

int32_t Memory::readCell(int32_t cell){
    if(cell < (int32_t)memory.size()){
        return memory[cell];
    }else{
        cout << "ERROR: Trying to read NULL memory address TEST" << endl;
    }
    return 0;
}

void Memory::writeCell(int32_t cell, int32_t content){
    if(cell >= (int32_t)memory.size()){
        memory[cell] = content;
    }else{
        cout << "ERROR: Trying to write to NULL address. Push instrad" << endl;
    }
}

void Memory::pushCell(int32_t content){
    memory.push_back(content);
    return; 
}


