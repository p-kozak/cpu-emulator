echo "Compiling..."
cd ..
cd src
g++ -Wall ../tests/test.cpp cpu.cpp alu.cpp memory.cpp registers.cpp programcounter.cpp -o ../test
echo "Compiled"