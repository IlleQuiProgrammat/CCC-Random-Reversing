#include "Emulator.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <unordered_set>

Emulator::Emulator()
{

	this->stack = new uint8_t[STACK_SIZE];
	this->registers.fp = (int32_t)this->stack;
	this->registers.sp = (int32_t)this->stack;
	this->registers.ra = (int32_t)this->stack;
	this->registers.gp = (int32_t)this->stack;
}

Emulator::~Emulator()
{
	delete[] this->stack;
}

void Emulator::run_syscall(std::string name)
{
	if (name == "print") {
		int pos = this->registers.a0;
		std::stringstream builder;
		while (pos < STACK_SIZE && stack[pos] != 0)
		{
			builder << (char)stack[pos];
		}
		std::cout << builder.str() << std::endl;
	}
}

int Emulator::rand()
{
	this->next_rand *= 1103515245;
	this->next_rand += 12345;
	return (uint32_t)(this->next_rand / 65536) % 32768;
}

void Emulator::srand(uint32_t seed)
{
	this->next_rand = seed;
}
/*
std::vector<std::string>* Emulator::split(std::string line, char character)
{
	auto res = new std::vector<std::string>;
	std::string currbuilder = "";
	for (int i = 0; i < line.size(); i++)
	{
		if (line[i] == character)
		{
			res->push_back(currbuilder);
			currbuilder = "";
		} else
		{
			currbuilder += line[i];
		}
	}
	res->push_back(currbuilder);
	return res;
}
*/

// TODO: implement all the other instructions...
int Emulator::exec(uint32_t instruction)
{
	// R-format instructions
	if ((instruction & opcodebitmask) == 0)
	{
		uint32_t funct = instruction & functbitmask;
		uint32_t& rs = getRegister((instruction & rsbitmask) >> rsbitshift);
		uint32_t& rt = getRegister((instruction & rtbitmask) >> rtbitshift);
		uint32_t& rd = getRegister((instruction & rdbitmask) >> rdbitshift);
		uint32_t shamt = (instruction & shamtbitmask) >> shamtbitshift;
		switch (funct)
		{
			case 32:
				run_add(rd, rs, rt);
				break;
			case 33:
				run_addu(rd, rs, rt);
				break;
			case 34:
				run_sub(rd, rs, rt);
				break;
			case 35:
				run_subu(rd, rs, rt);
				break;
			case 36:
				run_and(rd, rs, rt);
				break;
			case 37:
				run_or(rd, rs, rt);
				break;
			case 39:
				run_nor(rd, rs, rt);
				break;
			case 42:
				run_slt(rd, rs, rt);
				break;
			case 43:
				run_sltu(rd, rs, rt);
				break;
			case 0:
				run_sll(rd, rs, shamt);
				break;
			case 2:
				run_srl(rd, rs, shamt);
				break;
			case 8:
				run_jr(rs);
				return -1;
				break;
		}
	}

	
		uint32_t& rs = getRegister((instruction & rsbitmask) >> rsbitshift);
		uint32_t& rt = getRegister((instruction & rtbitmask) >> rtbitshift);
		uint32_t imm = instruction & immbitmask;

	switch ((instruction & opcodebitmask) >> opcodeshift)
	{
		case 2:
			run_j(instruction & jformatbitmask);
			return -1;
			break;
		case 3:
			run_jal(instruction & jformatbitmask);
			return -1;
			break;
		case 4:
			run_beq(rs, rt, imm);
			return -1;
			break;
		case 5:
			run_bne(rs, rt, imm);
			return -1;
			break;
		case 8:
			run_addi(rt, rs, imm);
			return -1;
			break;
		case 9:
			run_addiu(rt, rs, imm);
			return -1;
			break;
		case 12:
			run_andi(rt, rs, imm);
			break;
		case 13:
			run_ori(rt, rs, imm);
			break;
		case 10:
			run_slti(rt, rs, imm);
			break;
		case 11:
			run_sltiu(rt, rs, imm);
			break;
		case 15:
			run_lui(rt, imm);
			break;
		case 35:
			run_lw(rt, rs, imm);
			break;
		case 43:
			run_sw(rt, rs, imm);
			break;
	}
	return 0;
}


void Emulator::parse(std::string filename)
{
	std::ifstream input(filename, std::ios_base::in);
	if (!input.is_open())
	{
		throw std::runtime_error("Failed to open file");
	}
	int seed, length;
	input >> seed >> length;
	this->srand(seed);
	std::vector<uint32_t> instructions(length);
	std::vector<uint32_t> fixed_instructions(length);
	std::unordered_set<int> found;
	for (auto& it : instructions) input >> it;
	for (int i = 0; i < length; i++)
	{
		int currand = rand() % length;
		while (found.find(currand) != found.end())
		{
			currand = rand() % length;
		}
		fixed_instructions[i] = instructions[currand];
		found.emplace(currand);
	}
	while (this->registers.PC <= length && this->registers.PC >= 0)
	{
		if (exec(fixed_instructions[this->registers.PC]) != -1)
		{
			this->registers.PC += 1;
		}
	}
}

void Emulator::loadMemory(std::string stackfile)
{
	std::ifstream stackf(stackfile, std::ios::binary);
	if (stackf.is_open())
		stackf.read((char*)this->stack, STACK_SIZE);
	stackf.close();
}
