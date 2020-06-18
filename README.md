11nmcavoy@mcsoxford.org

# CCC Random Reversing

Repository for the Random Reversing challenge for CCC

## Flag

Flag: `CCCCTF{scr4mBIED_M1P5_!s_f8n_59}`

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
 3. observe file loading technique: i.e. 1st number is the seed to the random op picker (note the special rand() function) and the latter is the length
 4. Look into stack.mem with a hex editor to see that it contains a key (indicated with ascii `key: ...`) and the ciphertext indicated with: `Flag: ...`
 5. With ghidra see that some strings (relating to the MIPS architecture) are being used, but also notice that the control flow is very different and so manual changes will need to be made
 6. By looking back at the loading method one can use a similar approach to write to the file (as seeding a value will mean it's always in the same position)
 7. Write MIPS assembly using the `xor` instruction to decrypt the flag
 8. Print the flag using the syscall instruction

## PoC

unscrambled code
```
200900f0
200a0130
200b0200
000b6020
812d0000
814e0000
01ae6826
a18d0000
21290001
214a0001
218c0001
15a00004
20040200
FFFFFFFF
```

scrambling code
```python
inp = open("unrandomised_code.txt", 'r')
lines = [int(x, 16) for x in inp.read().split("\n")]
file_length = len(lines)
inp.close()
outp = open("code.txt", 'w')
seed = 0
current_rand = 0
def srand(seed):
	global current_rand
	current_rand = seed

def rand():
	global current_rand
	current_rand *= 1103515245;
	current_rand += 12345;
	return (0xFFFFFFFF & (current_rand // 65536)) % 32768;

unrandomised = [int(n) for n in lines]	
randomised = [-1 for n in lines]
found_nums = set()
for i in range(file_length):
	currindex = rand() % file_length;
	while currindex in found_nums:
		currindex = rand() % file_length
	randomised[currindex] = unrandomised[i]
	found_nums.add(currindex)
print(randomised)

outp.write(f"{seed} {file_length}\n" + "\n".join([str(r) for r in randomised]))
outp.close
```

scrambled code
```
0 14
537460976
2167209984
537133568
2710372352
28207142
562823169
537526576
558497793
556335105
362807300
2169372672
537592320
745504
4294967295
```