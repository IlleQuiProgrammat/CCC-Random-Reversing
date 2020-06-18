// MIPS.cpp : Defines the entry point for the application.
//

#include "MIPS.h"
#include "Emulator.h"

using namespace std;

int main()
{
	Emulator e;
	e.loadMemory("./stack.mem");
	e.parse("./code.txt");
	return 0;
}
