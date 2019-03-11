#ifndef MEMORY
#define MEMORY

#include <vector>
#include <stdint.h>
#include <iostream>



/*Instruction format(Here we go!):
32 bits
5 bits for opcode - 31:27
5 bits for target 26:22
Now, if it's of type add/sub or w/e:
5 bits for source 1  21:17
5 bits for source 2 16:12
If it's of type load or  w/e:
21:0 for address 

opcodes:
ADD     00000
ADDI    00001
SUB     00010
LW      00011
SW      00011
*/

class Memory{
    private:
    std::vector<uint32_t>  memory;

    public:
    void writeCell(int cell, uint32_t content);
    uint32_t readCell(int cell); 
    void pushCell(uint32_t content);

};

#endif 