#include "asmb.h"
#include "memory.h"
#include "registers.h"

using namespace std;

Assembler::Assembler(){
    inFile.open("prog.txt");
    //Check if file is opened
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }
}

Assembler::~Assembler(){
    inFile.close();
}

void Assembler::convertAssemblyToMachineCode(Memory &memory){
    while(inFile >> opcode){
        memory.pushCell(readSingleLine(opcode));
    }

}

int32_t Assembler::readWord(){
    //and convert it to int
    int32_t bitword;
    std::string::size_type sz;
    std::string word;
    inFile >> word;
    bitword = stoi(word, &sz);
    return bitword;

}

int32_t Assembler::readSingleLine(std::string opcode){
    D  DP("Assembling a single line");
    //if(DEBUG) cout << "Assembling a single line." << endl;
    //check which opcode is that and generate machine code 
    int32_t ins = 0;
    int32_t bitword;
    std::string word;
    //Convertign string to int

    if(opcode == "SUB" || opcode == "ADD"){
        if (opcode == "SUB"){         
            ins = (ins | (SUB << (32-5)));
            D DP("Instruction SUB");
        }else{
            ins = (ins | (ADD << (32-5)));
            D DP("Instruction ADD");
        }
        //read three addresses
        bitword = readWord();
        D DPV("Reg1: ", bitword);
        ins = (ins | (bitword << (32-10)));

        bitword = readWord();
        D DPV("Reg2: ", bitword);
        ins = (ins | (bitword << (32-15)));

        bitword = readWord();
        D DPV("Reg3: ", bitword);
        ins =  (ins | (bitword << (32-20)));

        D DPV("Machine code instruction: ", ins);
        DEL;
    }

    if(opcode == "ADDI"){
        ins = (ins | (ADDI << (32-5)));
        D DP("Instruction ADDI");


        //read target and source register
        bitword = readWord();
        D DPV("Reg1: ", bitword);
        ins = (ins | (bitword << (32-10)));

        bitword = readWord();
        D DPV("Reg2: ", bitword);
        ins = (ins | (bitword << (32-15)));

        //read immediate value
        bitword = readWord();
        D DPV("Immediate value: ", bitword);
        ins = (ins | bitword);
        
        D DPV("Machine code instruction: ", ins);
        DEL;

    }

    if(opcode == "LW"){
        ins = (ins | (ADDI << (32-5)));
        D DP("Instruction LW");
        //read target register
        bitword = readWord();
        D DPV("Reg1: ", bitword);
        ins = (ins | (bitword << (32-10)));
        //read  address
        bitword = readWord();
        D DPV("Address: ", bitword);
        ins = (ins | bitword);

        D DPV("Machine code instruction: ", ins);
        DEL;
    }

    if(opcode == "SW"){
        ins = (ins | (SW << (32-5)));
        D DP("Instruction LW");
        //read target register
        bitword = readWord();
        D DPV("Reg1: ", bitword);
        ins = (ins | (bitword << (32-10)));

        D DPV("Machine code instruction: ", ins);
        DEL;
    }

    if(opcode == "BEQ"){
         ins = (ins | (BEQ << (32-5)));
        D DP("Instruction BEQ");
        //read two registers
        bitword = readWord();
        D DPV("Reg1: ", bitword);
        ins = (ins | (bitword << (32-10)));
        bitword = readWord();
        D DPV("Reg2: ", bitword);
        ins = (ins | (bitword << (32-15)));

        D DPV("Machine code instruction: ", ins);
        DEL;

    }

    if(opcode == "LBL"){
        ins = (ins | (LBL << (32-5)));
        D DP("Instruction LW");
        //read label number
        bitword = readWord();
        D DPV("Label index: ", bitword);
        ins = (ins | (bitword << (32-10)));

        D DPV("Machine code instruction: ", ins);
        DEL;

    }

    if(opcode == "JP"){
        ins = (ins | (JP << (32-5)));
        D DP("Instruction JP");
        //read label number
        bitword = readWord();
        D DPV("Label index: ", bitword);
        ins = (ins | (bitword << (32-10)));

        D DPV("Machine code instruction: ", ins);
        DEL;

    }

    if(opcode == "EF"){
        ins = (ins | (EF << (32-5)));
        D DP("Instruction EF");

        D DPV("Machine code instruction: ", ins);
        DEL;
    }

    return ins;
}


void Assembler::addAddressesToJumps(Memory &memory){
    D DP("Matching labels...");
    int32_t address, tempcounter, opcode, index, opcodetemp, indextemp, ins;
    // go through the whole memory to find labels
    address = 0;
    do{
        opcode = (memory.readCell(address) &(0b11111 << (32-5))) >> (32-5);
        //find labels
        if(opcode == LBL){
            
            //if label, iterate from the very beginning and find matching jump
            //but first, store index of label
            index = (memory.readCell(address) &(0b11111 << (32-10))) >> (32-10);
            tempcounter = 0 ;
            D DPV("I found label at address: ", address);
            D DPV("Its index is: ", index);
            while(true){ //could add condition to check if not eof
                //check if jump
                opcodetemp = (memory.readCell(tempcounter) & (0b11111 << (32-5))) >> (32-5);
                if(opcodetemp == JP){
                    //check if matching index
                    indextemp =  (memory.readCell(tempcounter) &(0b11111 << (32-10))) >> (32-10);
                    if(indextemp == index){
                        D DPV("I found matching jump at address: ", tempcounter);
                        D DPV("Its index is: ", indextemp);
                        //eveyrthing is matching so retive jump instruction from memory
                        ins = memory.readCell(tempcounter);
                        D DPV("Old instruction of this jumps is:", ins);
                        ins = ins | address;
                        D DPV("New instruction of this jumps is:", ins);
                        DEL;
                        memory.writeCell(tempcounter, ins);
                        break;
                    }
                }     
            tempcounter +=1;
            } 
        }
    address += 1;
    }while(opcode != EF);
    DEL;
}
