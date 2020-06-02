#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "Registers.h"

const int STACK_SIZE = 1024*1024;

typedef uint32_t reg;
// TODO: Make note that this doesn't distinguish between positive and negative values
class Emulator
{
public:
	Emulator();

	~Emulator();

	void run_noop();
#pragma region arithmetic_operators
	void run_add(reg& d, reg& s, reg& t);
	void run_sub(reg& d, reg& s, reg& t);
	void run_addi(reg& d, reg& s, uint32_t imm);
	void run_addu(reg& d, reg& s, reg& t);
	void run_subu(reg& d, reg& s, reg& t);
	void run_addiu(reg& d, reg& s, uint32_t imm);
	void run_mult(reg& s, reg& t);
	void run_multu(reg& s, reg& t);
	void run_div(reg& s, reg& t);
	void run_divu(reg& s, reg& t);
#pragma endregion
#pragma region logical_operators
	void run_and(reg& d, reg& s, reg& t);
	void run_or(reg& d, reg& s, reg& t);
	void run_andi(reg& d, reg& s, uint32_t imm);
	void run_ori(reg& d, reg& s, uint32_t imm);
	void run_sll(reg& d, reg& s, uint32_t imm);
	void run_sllv(reg& d, reg& s, reg& t);
	void run_srl(reg& d, reg& s, uint32_t imm);
	// TODO: Warn that this does nothing
	// void run_sra();
	void run_srlv(reg& d, reg& s, reg& t);
	void run_xor(reg& d, reg& s, reg& t);
	void run_xori(reg& d, reg& s, uint32_t imm);
#pragma endregion
#pragma region memory_operators
	void run_lw(reg& d, reg& s, int32_t offset);
	void run_lb(reg& d, reg& s, int32_t offset);
	void run_lui(reg& d, uint16_t imm);
	void run_sw(reg& s, reg& d, int32_t offset);
	void run_sb(reg& s, reg& d, int32_t offset);

	// TODO: 2 Pseudo instuctions.. how do we process them?.. ignore for now
	void run_la();
	void run_li();

	void run_mfhi(reg& d);
	void run_mflo(reg& d);

	// TODO: Not sure about category
	void run_slt(reg& d, reg& s, reg& t);
	void run_slti(reg& d, reg& s, uint32_t imm);
	void run_sltiu(reg& d, reg&s, uint32_t imm);
	void run_sltu(reg& d, reg&s, reg& imm);

	// TODO: Another pseudo-instruction
	void run_move();
#pragma endregion
#pragma region branch_operators
	void run_beq(reg& s, reg& t, int32_t offset);
	void run_bgez(reg& s, int32_t offset);
	void run_bgezal(reg& s, int32_t offset);
	void run_bgtz(reg& s, int32_t offset);
	void run_blez(reg& s, int32_t offset);
	void run_bltz(reg& s, int32_t offset);
	void run_bltzal(reg& s, int32_t offset);
	void run_bne(reg& s, reg& t, int32_t offset);

	void run_j(uint32_t target);
	void run_jal(uint32_t target);
	void run_jr(reg& s);

#pragma endregion
#pragma region syscalls
	void run_syscall(std::string name);
#pragma endregion 
private:
	Registers registers;
	uint8_t* stack;
};
