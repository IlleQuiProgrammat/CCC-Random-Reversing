cd ./build/service
g++ ../../src/*.cpp -o ./MIPS -m32 -O3
strip -s ./MIPS
cp MIPS ../download/MIPS
cd ../../
