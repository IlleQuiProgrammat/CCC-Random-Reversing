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

	// FP return values
	f0,
	f1,
	f2,
	f3,

	// Temporary registers
	f4,
	f5,
	f6,
	f7,
	f8,
	f9,
	f10,

	// First two(?) arguments to subprograms
	f12,
	f13,
	f14,

	// Unspecified
	f15,

	// Temporary registers
	f16,
	f17,
	f18,

	// Unspecified
	f19,

	// Saved registers
	f20,
	f21,
	f22,
	f23,
	f24,
	f25,
	f26,
	f27,
	f28,
	f29,
	f30,
	f31,
	f32,
	HI,
	LO
};

struct Registers
{
	const uint32_t zero = 0; // guess
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

	// FP return values
	float f0 = 0.0;
	float f1 = 0.0;
	float f2 = 0.0;
	float f3 = 0.0;

	// Temporary registers
	float f4 = 0.0;
	float f5 = 0.0;
	float f6 = 0.0;
	float f7 = 0.0;
	float f8 = 0.0;
	float f9 = 0.0;
	float f10 = 0.0;

	// First two(?) arguments to subprograms
	float f12 = 0.0;
	float f13 = 0.0;
	float f14 = 0.0;

	// Unspecified
	float f15 = 0.0;

	// Temporary registers
	float f16 = 0.0;
	float f17 = 0.0;
	float f18 = 0.0;

	// Unspecified
	float f19 = 0.0;

	// Saved registers
	float f20 = 0.0;
	float f21 = 0.0;
	float f22 = 0.0;
	float f23 = 0.0;
	float f24 = 0.0;
	float f25 = 0.0;
	float f26 = 0.0;
	float f27 = 0.0;
	float f28 = 0.0;
	float f29 = 0.0;
	float f30 = 0.0;
	float f31 = 0.0;
	float f32 = 0.0;

	uint32_t HI = 0;
	uint32_t LO = 0;
	uint32_t PC = 0;
};