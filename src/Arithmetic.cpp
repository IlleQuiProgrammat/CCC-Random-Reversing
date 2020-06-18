#include "Emulator.h"

void Emulator::run_add(reg& d, reg& s, reg& t)
{
	d = s + t;
}

void Emulator::run_sub(reg& d, reg& s, reg& t)
{
	d = s - t;
}

void Emulator::run_addi(reg& d, reg& s, uint32_t imm)
{
	d = s + imm;
}

void Emulator::run_addu(reg& d, reg& s, reg& t)
{
	d = s + t;
}

void Emulator::run_subu(reg& d, reg& s, reg& t)
{
	d = s - t;
}

void Emulator::run_addiu(reg& d, reg& s, uint32_t imm)
{
	d = s + imm;
}

void Emulator::run_mult(reg& s, reg& t)
{
	this->registers.LO = s * t;
}

void Emulator::run_multu(reg& s, reg& t)
{
	this->registers.LO = s * t;
}

void Emulator::run_div(reg& s, reg& t)
{
	this->registers.LO = s / t;
	this->registers.HI = s % t;
}

void Emulator::run_divu(reg& s, reg& t)
{
	this->registers.LO = s / t;
	this->registers.HI = s % t;
}
