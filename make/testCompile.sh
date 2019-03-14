echo "Compiling..."
cd ..
cd src
g++ -Wall test.cpp cpu.cpp alu.cpp memory.cpp registers.cpp programcounter.cpp -o ../test
echo "Compiled"