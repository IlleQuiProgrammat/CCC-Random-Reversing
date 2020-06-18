### Initial C code
```c
#include <stdint.h>

int main() {
	const uint8_t* SP = 0;
	uint8_t* flag = SP + 0xF0;
	uint8_t* key = SP + 0x130;
	char* result = SP + 0x200;
	int offset = 0;
	while (true) {
		result[offset] = key[offset] ^ flag[offset];
		if (key[offset] == 0) {
			break;
		}
	}
	syscall("print", result);
}
```

### Mixed ASM:tm:
```
mov $r1, &flag			; register pointing to flag address so we can use LB easily
mov $r2, &key			; "
mov $r3, &result		; -------------------------"--------------------- SB easily
mov $r4, $r3			; our offset

while_begin:
	LB $r5, 0($r1)
	LB $r6, 0($r2)
	XOR $r5, $r5, $r6
	SB 0($r4), $r5
	addi $r1, 1
	addi $r2, 1
	addi $r4, 1
	test $r5
	JNZ while_begin
while_end:
	SYSCALL $r3
```

## Transcoded

```
#addi $r1,$zero,0xF0
001001 sssss ttttt iiii iiii iiii iiii
#addi $r2,$zero,0x130
001001 sssss ttttt iiii iiii iiii iiii
#addi $r3,$zero,0x200
001001 sssss ttttt iiii iiii iiii iiii
#add $r4,$zero,$r3
000000 sssss ttttt ddddd 000 0010 0000

#label
#LB $r5, 0($r1)
100000 sssss ttttt iiii iiii iiii iiii
#LB $r6, 0($r2)
100000 sssss ttttt iiii iiii iiii iiii

#XOR $r5, $r5, $r6
000000 sssss ttttt ddddd --- --10 0110

#SB 0($r4), $r5
101000 sssss ttttt iiii iiii iiii iiii

#addi $r1, $r1, 1
#addi $r2, $r2, 1
#addi $r4, $r4, 1
001001 sssss ttttt iiii iiii iiii iiii
001001 sssss ttttt iiii iiii iiii iiii
001001 sssss ttttt iiii iiii iiii iiii

# BNE $r5, $zero
000101 sssss ttttt iiii iiii iiii iiii

# SYSCALL
-1
```

```
addi $t1, $zero, 0xf0
addi $t2, $zero, 0x130
addi $t3, $zero, 0x200
add $t4, $zero, $t3

lb $t5, 0($t1)
lb $t6, 0($t1)
xor $t5, $t5, $t6
sb $t5, 0($4)
addi $t1, $t1, 1
addi $t2, $t2, 1
addi $t4, $t4, 1
bne $t5, $zero, 4
addi $a0, $zero, 0x220
```
site: http://www.kurtm.net/mipsasm/index.cgi
```
200900f0
200a0130
200b0200
000b6020
812d0000
812e0000
01ae6826
a08d0000
21290001
214a0001
218c0001
15a0fff5
20040220
FFFFFFFF
```