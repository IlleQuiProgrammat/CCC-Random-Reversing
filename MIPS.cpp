// MIPS.cpp : Defines the entry point for the application.
//

#include "MIPS.h"
#include "Emulator.h"

using namespace std;

int main()
{
	Emulator e;
	e.loadMemory("C:\\Users\\Nathan\\Documents\\stack.mem");
	e.parse("C:\\Users\\Nathan\\Documents\\code.txt");
	cout << "Hello CMake." << endl;
	return 0;
}
