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