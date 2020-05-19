#pragma once

#include <cstdint>
#include <vector>
#include "Registers.h"

const int STACK_SIZE = 1024*1024;

class Emulator
{
public:
	Emulator()
	{
		stack = new uint8_t[STACK_SIZE];
	}

	~Emulator()
	{
		delete[] stack;
	}

	void run_noop();
#pragma region arithmetic_operators
	void run_add();
	void run_sub();
	void run_addi();
	void run_addu();
	void run_subu();
	void run_addiu();
	void run_mult();
	void run_multu();
	void run_div();
	void run_divu();
#pragma endregion
#pragma region logical_operators
	void run_and();
	void run_or();
	void run_andi();
	void run_ori();
	void run_sll();
	void run_sllv();
	void run_srl();
	void run_sra();
	void run_srlv();
	void run_xor();
	void run_xori();
#pragma endregion
#pragma region memory_operators
	void run_lw();
	void run_lb();
	void run_lui();
	void run_sw();
	void run_sb();

	// TODO: 2 Pseudo instuctions.. how do we process them?
	void run_la();
	void run_li();

	void run_mfhi();
	void run_mflo();

	// TODO: Not sure about category
	void run_slt();
	void run_slti();
	void run_sltiu();
	void run_sltu();

	// TODO: Another pseudo-instruction
	void run_move();
#pragma endregion
#pragma region branch_operators
	void run_beq();
	void run_bgez();
	void run_bgezal();
	void run_bgtz();
	void run_blez();
	void run_bltz();
	void run_bltzal();
	void run_bne();

	void run_j();
	void run_jal();
	void run_jr();

#pragma endregion
#pragma region syscalls
	void run_syscall();
#pragma endregion 
private:
	Registers registers;
	uint8_t* stack;
};
