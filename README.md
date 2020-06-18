# CCC Random Reversing

Repository for the Random Reversing challenge for CCC

## Flag

Flag: `CCCCTF{scr4mBIED_M1P5_!s_f8n_19237456}`

## Briefing

The program that can be found at [url] is known to be running on [url]:[port], create a valid file to read the flag from memory.
Sample memory files can also be downloaded at [url]. These are samples and hence fo not have the flag. The program has also had it's
input and output limited to the flag and only the flag.

By IlleQuiProgrammat

## Infrastructure
 - Must be compiled in **_32-bit_**
 - Hosting of the binary files
 - Program running within a container that only allows the flag to be output
 - Service runs, pipes input into a file, runs the program, sends the flag back if found

## Risks
 - none I can think of

## Walkthrough

 1. Download file materials and run the example program
 2. disassemble in Ghidra or another disassembler to understand basic flow
 3. observe file loading technique: i.e. 1st number is the seed to the random op picker (note the special rand() function)
 4. Look into stack.mem with a hex editor to see that it contains a key (indicated with ascii `key: ...`) and the ciphertext indicated with: `Flag: ...`
 5. With ghidra see that some strings (relating to the MIPS architecture) are being used 
 6. By looking back at the loading method one can use a similar approach to write to the file (as seeding a value will mean it's always in the same position)
 7. Write MIPS assembly using the `xor` instruction to decrypt the flag
 8. Print the flag using the syscall instruction

## PoC

```
<to be done>
```