#include "Emulator.h"

void Emulator::run_lw(reg& d, reg& s, int32_t offset)
{
	d = *(uint32_t*)(this->stack + s + offset);
}

void Emulator::run_lb(reg& d, reg& s, int32_t offset)
{
	d = this->stack[s + offset];
}

void Emulator::run_lui(reg& d, uint16_t imm)
{
	d = imm << 16;
}

void Emulator::run_sw(reg& s, reg& d, int32_t offset)
{
	*(uint32_t*)(this->stack + d + offset) = s;
}

void Emulator::run_sb(reg& s, reg& d, int32_t offset)
{
	this->stack[d + offset] = s;
}

void Emulator::run_la() {}

void Emulator::run_li() {}

void Emulator::run_mfhi(reg& d)
{
	d = this->registers.HI;
}

void Emulator::run_mflo(reg& d)
{
	d = this->registers.LO;
}

void Emulator::run_slt(reg& d, reg& s, reg& t)
{
	if (s < t)
	{
		d = 1;
	}
}

void Emulator::run_slti(reg& d, reg& s, uint32_t imm)
{
	if (s < imm)
	{
		d = 1;
	}
}

void Emulator::run_sltiu(reg& d, reg& s, uint32_t imm)
{
	if (s < imm)
	{
		d = 1;
	}
}

void Emulator::run_sltu(reg& d, reg& s, reg& t)
{

	if (s < t)
	{
		d = 1;
	}
}

void Emulator::run_move() {}

