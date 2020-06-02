#include "Emulator.h"

void Emulator::run_and(reg& d, reg& s, reg& t)
{
	d = s & t;
}

void Emulator::run_or(reg& d, reg& s, reg& t)
{
	d = s | t;
}

void Emulator::run_andi(reg& d, reg& s, uint32_t imm)
{
	d = s & imm;
}

void Emulator::run_ori(reg& d, reg& s, uint32_t imm)
{
	d = s | imm;
}

void Emulator::run_sll(reg& d, reg& s, uint32_t imm)
{
	d = s << imm;
}

void Emulator::run_sllv(reg& d, reg& s, reg& t)
{
	d = s << t;
}

void Emulator::run_srl(reg& d, reg& s, uint32_t imm)
{
	d = s >> imm;
}

void Emulator::run_srlv(reg& d, reg& s, reg& t)
{
	d = s >> t;
}

void Emulator::run_xor(reg& d, reg& s, reg& t)
{
	d = s ^ t;
}

void Emulator::run_xori(reg& d, reg& s, uint32_t imm)
{
	d = s ^ imm;
}
