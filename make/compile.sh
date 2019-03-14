#!/bin/bash

echo "Compiling..."
cd ..
cd src
g++ -Wall main.cpp cpu.cpp alu.cpp memory.cpp registers.cpp programcounter.cpp -o ../cpu
echo "Compiled"