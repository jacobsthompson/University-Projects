.data
n:	.word 25
str1:	.asciiz "Less than\n"
str2:	.asciiz "Less than or equal to\n"
str3:	.asciiz "Greater than\n"
str4:	.asciiz "Greater than or equal to\n"

.text
la $t0, n
lw $s0, 0($t0)

li $v0, 5
syscall
move $s1, $v0

blt $s1, $s0, LESS
bge $s1, $s0, EGREAT
bgt $s1, $s0, GREAT
ble $s1, $s0, ELESS
j END


LESS: li $v0, 4
	la $a0, str1
	syscall
	j END
	
GREAT: li $v0, 4
	la $a0, str3
	syscall
	j END	
	
ELESS: li $v0, 4
	la $a0, str2
	syscall
	j END
	
	
EGREAT: li $v0, 4
	la $a0, str4
	syscall
	j END
	
END: li $v0, 10
	syscall