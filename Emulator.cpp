#include "Emulator.h"
#include <iostream>

Emulator::Emulator()
{

	this->stack = new uint8_t[STACK_SIZE];
	this->registers.fp = (int32_t)this->stack;
	this->registers.sp = (int32_t)this->stack;
	this->registers.ra = (int32_t)this->stack;
	this->registers.gp = (int32_t)this->stack;
}

Emulator::~Emulator()
{
	delete[] this->stack;
}

void Emulator::run_syscall(std::string name)
{
	if (name == "print") {
		std::cout << "Syscall print" << std::endl;
	}
}