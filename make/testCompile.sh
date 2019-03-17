echo "Compiling..."
cd ..
cd src
g++ -std=c++14 -Wall ../tests/test.cpp cpu.cpp alu.cpp memory.cpp registers.cpp programcounter.cpp asmb.cpp -o ../test
echo "Compiled"