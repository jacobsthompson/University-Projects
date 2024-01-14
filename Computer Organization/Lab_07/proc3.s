	.data
x:	.word 1
y:	.word 2
z:	.word 3
PPLUSQ:	.asciiz "p + q: "
NEW:	.asciiz "\n"

	.text
MAIN:
	la $t0, x
	lw $s0, 0($t0)	#s0 = x
	la $t0, y
	lw $s1, 0($t0)	#s1 = y
	la $t0, z
	lw $s2, 0($t0)	#s2 = z
	
	add $a0, $zero, $s0	#set a0 to x
	add $a1, $zero, $s1	#set a1 to y
	add $a2, $zero, $s2	#set a2 to z
	jal FOO
	add $t0, $s0, $s1	#add x and y
	add $t0, $t0, $s2	# add z and (x+y)
	add $s2, $t0, $v0	# add (x+y+z) and FOO results
	addi $sp, $sp, 16
	addi $a0, $s2, 0 	#put into a0 for printing
	li $v0, 1		#get ready for syscall print 
	syscall			#print answer
	j END
	
FOO:	
	addi $sp, $sp, -16	#make room in stack for 4 words
	sw $ra, 16($sp)		#put return adress to MAIN in 16
	sw $a0, 12($sp)		#put x into 12
	sw $a1, 8($sp)		#put y into 8
	sw $a2, 4($sp)		#put z into 4
	
	add $a0, $a0, $a2	#set a0 to m+o (x+z)
	add $a1, $a1, $a2	#set a1 to n+o (y+z)
	lw $t0, 12($sp)		#set t0 to x
	lw $t1, 8($sp)		#set t1 to y
	add $a2, $t0, $t1	#set a2 to m+n (x+y)
	jal BAR
	
	sw $v0, 0($sp)		#store v0 into 0 (p)
	
	lw $a0, 12($sp)		#load a0 to have x again
	lw $a1, 8($sp)		#load a1 to have y again
	lw $a2, 4($sp)		#load a2 to have z again
	
	sub $a0, $a0, $a2	#set a0 to m-o (x-z)
	lw $t0, 12($sp)		#set t0 to x
	sub $a1, $a1, $t0	#set a1 to n-m (y-x)
	lw $t1, 8($sp)		#set t1 to y
	add $a2, $t1, $t1	#set a2 to n+n (y+y)
	jal BAR
	
	lw $t0, 0($sp)		#load p into t0
	add $v0, $v0, $t0	#add p and v0 (q)
	sw $v0, 0($sp)		#store p+q into 0
	
	li $v0, 4		#print "p + q: "
	la $a0, PPLUSQ 
	syscall
	lw $v0, 0($sp)
	addi $a0, $v0, 0 	#put into p+q for printing
	li $v0, 1		#get ready for syscall print 
	syscall
	li $v0, 4		#print newline
	la $a0, NEW 
	syscall
	
	lw $v0, 0($sp)		#load v0 with p+q
	lw $ra, 16($sp)		#load ra with MAIN adress
	jr $ra
	
	
	

BAR:	
	sub $v0, $a1, $a0	#sub b from a
	sllv $v0, $v0, $a2	#left shift b-a by c
	jr $ra

	
END: