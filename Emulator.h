#pragma once

#include <cstdint>
#include <vector>

class Emulator
{
public:
	Emulator();
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

	const uint32_t zero = 0; // guess
	uint32_t at; // reserved for pseudo-instructions

	// function return values
	uint32_t v0;
	uint32_t v1;

	// function arguments - not preserved by subprograms
	uint32_t a0;
	uint32_t a1;
	uint32_t a2;
	uint32_t a3;

	// Temporary registers -> not preserved by subprograms
	uint32_t t0;
	uint32_t t1;
	uint32_t t2;
	uint32_t t3;
	uint32_t t4;
	uint32_t t5;
	uint32_t t6;
	uint32_t t7;

	// Saved registers -> preserved by subprograms
	uint32_t s0;
	uint32_t s1;
	uint32_t s2;
	uint32_t s3;
	uint32_t s4;
	uint32_t s5;
	uint32_t s6;
	uint32_t s7;

	// More temporary registers
	uint32_t t8;
	uint32_t t9;

	// Kernel registers
	uint32_t k0;
	uint32_t k1;

	uint32_t gp; // Global area pointer
	uint32_t sp; // Stack pointer
	uint32_t fp; // Frame pointer
	uint32_t ra; // return address

	// FP return values
	float f0;
	float f1;
	float f2;
	float f3;

	// Temporary registers
	float f4;
	float f5;
	float f6;
	float f7;
	float f8;
	float f9;
	float f10;

	// First two(?) arguments to subprograms
	float f12;
	float f13;
	float f14;

	// Unspecified
	float f15;

	// Temporary registers
	float f16;
	float f17;
	float f18;

	// Unspecified
	float f19;

	// Saved registers
	float f20;
	float f21;
	float f22;
	float f23;
	float f24;
	float f25;
	float f26;
	float f27;
	float f28;
	float f29;
	float f30;
	float f31;
	float f32;
	uint8_t stack[1024 * 1024];
};
