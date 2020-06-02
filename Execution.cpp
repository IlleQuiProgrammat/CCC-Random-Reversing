#include "Emulator.h"

void Emulator::run_beq(reg& s, reg& t, int32_t offset)
{
	if (s == t)
	{
		this->registers.PC += offset;
	}
}

void Emulator::run_bgez(reg& s, int32_t offset)
{
	if (s >= 0)
	{
		this->registers.PC += offset;
	}
}

void Emulator::run_bgezal(reg& s, int32_t offset)
{
	if (s >= 0)
	{
		this->registers.ra = this->registers.PC;
		this->registers.PC += offset;
	}
}

void Emulator::run_bgtz(reg& s, int32_t offset)
{
	if (s > 0)
	{
		this->registers.PC += offset;
	}
}

void Emulator::run_blez(reg& s, int32_t offset)
{
	if (s <= 0)
	{
		this->registers.PC += offset;
	}
}

void Emulator::run_bltz(reg& s, int32_t offset)
{
	if (s < 0)
	{
		this->registers.PC += offset;
	}
}

void Emulator::run_bltzal(reg& s, int32_t offset)
{
	if (s < 0)
	{
		this->registers.ra = this->registers.PC;
		this->registers.PC += offset;
	}
}

void Emulator::run_bne(reg& s, reg& t, int32_t offset)
{
	if (s != t)
	{
		this->registers.PC += offset;
	}
}

void Emulator::run_j(uint32_t target)
{
	this->registers.PC = target;
}

void Emulator::run_jal(uint32_t target)
{
	this->registers.ra = this->registers.PC;
	this->registers.PC = target;
}

void Emulator::run_jr(reg& s)
{
	this->registers.PC = s;
}
