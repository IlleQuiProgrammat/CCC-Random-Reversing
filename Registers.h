#pragma once

#include <cstdint>

// TODO: Convert this into arrays or something

enum Register {
	zero, // guess
	at, // reserved for pseudo-instructions

	// function return values
	v0,
	v1,

	// function arguments - not preserved by subprograms
	a0,
	a1,
	a2,
	a3,

	// Temporary registers -> not preserved by subprograms
	t0,
	t1,
	t2,
	t3,
	t4,
	t5,
	t6,
	t7,

	// Saved registers -> preserved by subprograms
	s0,
	s1,
	s2,
	s3,
	s4,
	s5,
	s6,
	s7,

	// More temporary registers
	t8,
	t9,

	// Kernel registers
	k0,
	k1,

	gp, // Global area pointer
	sp, // Stack pointer
	fp, // Frame pointer
	ra, // return address
	HI,
	LO
};

struct Registers
{
	uint32_t zero = 0; // guess
	uint32_t at = 0; // reserved for pseudo-instructions

	// function return values
	uint32_t v0 = 0;
	uint32_t v1 = 0;

	// function arguments - not preserved by subprograms
	uint32_t a0 = 0;
	uint32_t a1 = 0;
	uint32_t a2 = 0;
	uint32_t a3 = 0;

	// Temporary registers -> not preserved by subprograms
	uint32_t t0 = 0;
	uint32_t t1 = 0;
	uint32_t t2 = 0;
	uint32_t t3 = 0;
	uint32_t t4 = 0;
	uint32_t t5 = 0;
	uint32_t t6 = 0;
	uint32_t t7 = 0;

	// Saved registers -> preserved by subprograms
	uint32_t s0 = 0;
	uint32_t s1 = 0;
	uint32_t s2 = 0;
	uint32_t s3 = 0;
	uint32_t s4 = 0;
	uint32_t s5 = 0;
	uint32_t s6 = 0;
	uint32_t s7 = 0;

	// More temporary registers
	uint32_t t8 = 0;
	uint32_t t9 = 0;

	// Kernel registers
	uint32_t k0 = 0;
	uint32_t k1 = 0;

	uint32_t gp = 0; // Global area pointer
	uint32_t sp = 0; // Stack pointer
	uint32_t fp = 0; // Frame pointer
	uint32_t ra = 0; // return address

	uint32_t HI = 0;
	uint32_t LO = 0;
	uint32_t PC = 0;
};