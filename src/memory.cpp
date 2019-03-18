#include "memory.h"

using namespace std;

int32_t Memory::readCell(int32_t cell){
    if(cell < (int32_t)memory.size()){
        return memory[cell];
    }else{
        cout << "ERROR: Trying to read NULL memory address" << endl;
    }
    return 0;
}

void Memory::writeCell(uint32_t cell, int32_t content){
    if(cell < memory.size()){
        memory[cell] = content;
    }else{
        cout << "ERROR: Trying to write to NULL address: " << cell << " Size is: " << memory.size() << endl;
    }
}

void Memory::pushCell(int32_t content){
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

