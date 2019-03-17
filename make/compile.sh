#!/bin/bash

echo "Compiling..."
cd ..
cd src
g++ -std=c++14 -Wall main.cpp cpu.cpp alu.cpp memory.cpp registers.cpp asmb.cpp programcounter.cpp -o ../cpu
echo "Compiled"