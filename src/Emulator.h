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

	int rand();
	void srand(uint32_t seed);
	int exec(uint32_t instruction);
	void run_noop() {};
	void parse(std::string filename);
	void loadMemory(std::string stackfile);
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
	void run_nor(reg& d, reg& s, reg& t);
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

	uint32_t& getRegister(uint32_t number)
	{
		return ((uint32_t*)(&(this->registers)))[number];
	}

#pragma endregion
#pragma region syscalls
	void run_syscall(std::string name);
#pragma endregion 
private:
	volatile Registers registers;
	uint8_t* stack;
	uint32_t next_rand = 0;

	const uint32_t opcodebitmask =	0b11111100000000000000000000000000;
	const uint32_t opcodeshift =	26;
	const uint32_t functbitmask =	0b00000000000000000000000000111111;
	const uint32_t rsbitmask =		0b00000011111000000000000000000000;
	const uint32_t rsbitshift =		21;
	const uint32_t rtbitmask =		0b00000000000111110000000000000000;
	const uint32_t rtbitshift =		16;
	const uint32_t rdbitmask =		0b00000000000000001111100000000000;
	const uint32_t rdbitshift =		11;
	const uint32_t shamtbitmask =   0b00000000000000000000011111000000;
	const uint32_t shamtbitshift =	6;
	const uint32_t immbitmask =		0b00000000000000001111111111111111;
	const uint32_t jformatbitmask = 0b00000011111111111111111111111111;
};
