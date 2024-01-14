.data 
Enter:	.asciiz "Please enter a number: "
Even:	.asciiz "Sum of even numbers is: "
Odd:	.asciiz "Sum of odd numbers is: "
Line:	.asciiz "\n"

.text 
#Input = $s0
#Even_sum = $s1
#Odd_sum = $s2
LOOP:	li $v0, 4
	la $a0, Enter
	syscall
	li $v0, 5
	syscall
	move $s0, $v0
	
	beq $s0, $zero, PRINT
	addi $t0, $zero, 2
	rem $t1, $s0, $t0
	bne $t1, $zero, ODD
	add $s1, $s1, $s0
	j LOOP
	ODD: add $s2, $s2, $s0
		
	j LOOP



PRINT:	li $v0, 4	#new line
	la $a0, Line
	syscall
	
	li $v0, 4	#Sum of Even Text
	la $a0, Even
	syscall
	
	li $v0, 1	#Sum of Even
	addi $a0, $s1, 0
	syscall
	
	li $v0, 4	#new line
	la $a0, Line
	syscall
	
	li $v0, 4	#Sum of Odd Text
	la $a0, Odd
	syscall
	
	li $v0, 1	#Sum of Odd
	addi $a0, $s2, 0
	syscall
	
	li $v0, 10	#Exit
	syscall
