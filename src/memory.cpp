#include "memory.h"

using namespace std;

int32_t Memory::readCell(int32_t cell){
    DA DPV("Reading memory value at address: ", cell);
    if(cell < (int32_t)memory.size()){
        return memory[cell];
    }else{
        cout << "ERROR: Trying to read NULL memory address" << endl;
        std::exit(1);
    }
    return 0;
}

void Memory::writeCell(uint32_t cell, int32_t content){
    DA DPV("Writing to memory at address: ", cell);
    DA DPV("The argument is: ", content);

    if(cell < memory.size()){
        memory[cell] = content;
    }else{
        cout << "ERROR: Trying to write to NULL address: " << cell << " Size is: " << memory.size() << endl;
    }
}

void Memory::pushCell(int32_t content){
    D DPV("Pushing memory with: ", content);
    memory.push_back(content);
    return; 
}

void Memory::printMemory(uint32_t num){
    //prints n elements in the vector
    if(num > memory.size()){
        return;
    }
    for(uint32_t i = 0; i < num; i++){
        cout << readCell(i) << " ";
    }
    cout << endl;
}

void Memory::printMemory(){
    int size = memory.size();
    for(int i = 0; i < size; i++){
        cout << readCell(i) << " ";
    }
    cout << endl;

}

