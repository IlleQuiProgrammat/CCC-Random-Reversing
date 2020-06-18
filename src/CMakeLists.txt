# CMakeList.txt : CMake project for MIPS, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("MIPS")

# Add source to this project's executable.
add_executable (MIPS "MIPS.cpp" "MIPS.h" "Emulator.cpp" "Emulator.h" "Registers.h" "Arithmetic.cpp" "Logic.cpp" "Memory.cpp" "Execution.cpp")

# TODO: Add tests and install targets if needed.
