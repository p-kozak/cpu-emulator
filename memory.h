#ifndef MEMORY
#define MEMORY

#include <vector>
#include <stdint.h>
#include <iostream>

//Enumarate opcodes
enum {ADD = 0b00000, ADDI = 0b00001, SUB = 0b00010, LW = 0b00011, \
SW = 0b00100, BEQ = 0b00101};
/*Instruction format(Here we go!):
32 bits
5 bits for opcode - 31:27
5 bits for target 26:22
Now, if it's of type add/sub or w/e:
5 bits for source 1  21:17
5 bits for source 2 16:12
If it's of type load or  w/e:
21:0 for address 

Also, if it's of type BNE
5 opcode, 5 target 1, 5 target 2, 

opcodes:
ADD     00000
ADDI    00001
SUB     00010     No need for SUBI as you can simply use ADDI and negative number
LW      00011
SW      00100
BEQ     00101  BRANCH EQUAL
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