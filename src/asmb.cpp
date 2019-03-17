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

void Assembler::convertAssemblyToMachineCode(){
    while(inFile >> opcode){
        readSingleLine(opcode);
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

void Assembler::readSingleLine(std::string opcode){
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

        cout << ins << endl;
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
        
        cout << ins <<endl;

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

    }

    if(opcode == "SW"){
        ins = (ins | (SW << (32-5)));
        D DP("Instruction LW");
        //read target register
        bitword = readWord();
        D DPV("Reg1: ", bitword);
        ins = (ins | (bitword << (32-10)));
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

    }

    if(opcode == "LBL"){
        ins = (ins | (LBL << (32-5)));
        D DP("Instruction LW");
        //read label number
        bitword = readWord();
        D DPV("Label index: ", bitword);
        ins = (ins | (bitword << (32-10)));

    }

    if(opcode == "JP"){
        ins = (ins | (JP << (32-5)));
        D DP("Instruction JP");
        //read label number
        bitword = readWord();
        D DPV("Label index: ", bitword);
        ins = (ins | (bitword << (32-10)));

    }

    if(opcode == "EF"){
        ins = (ins | (EF << (32-5)));
        D DP("Instruction EF");
    }

    
    //remember to add passing to memory later, by reference probably
}

