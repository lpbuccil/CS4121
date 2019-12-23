.data
	.newl: .asciiz "\n"
	i: .word 0
	j: .word 0
	k: .word 0
	l: .word 0
	m: .word 0
.text
	.globl main
main:	nop
	la $s0, i
	#Load immediate to $s1
	li $s1, 1
	#Assign variable $s0 = $s1
	sw $s1, 0($s0)
	la $s0, j
	#Load immediate to $s1
	li $s1, 2
	#Assign variable $s0 = $s1
	sw $s1, 0($s0)
	la $s0, k
	#Load immediate to $s1
	li $s1, 3
	#Assign variable $s0 = $s1
	sw $s1, 0($s0)
	la $s0, l
	#Load immediate to $s1
	li $s1, 4
	#Assign variable $s0 = $s1
	sw $s1, 0($s0)
	la $s0, m
	la $s1, i
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, j
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Compare variable $s2 and $s3
	li $s1, 0
	bge $s2, $s3, compBranch0
	li $s1, 1
compBranch0: nop
	#Assign variable $s0 = $s1
	sw $s1, 0($s0)
	la $s0, m
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	#Load immediate to $s0
	li $s0, 1
	#Bitwise variable $s1 and $s0
	and $s2, $s1, $s0
	#Print variable $s2
	li $v0, 1
	move $a0, $s2
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, l
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, k
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bgt $s1, $s2, compBranch1
	li $s0, 0
compBranch1: nop
	#Print variable $s0
	li $v0, 1
	move $a0, $s0
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, l
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, k
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bgt $s1, $s2, compBranch2
	li $s0, 0
compBranch2: nop
	#Bitwise variable $s0 and $s0
	sltu  $s1, $zero, $s0
	xori  $s1, $s1, 1
	#Print variable $s1
	li $v0, 1
	move $a0, $s1
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	#Load immediate to $s0
	li $s0, 0
	la $s1, i
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, j
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Compare variable $s2 and $s3
	li $s1, 0
	bge $s2, $s3, compBranch3
	li $s1, 1
compBranch3: nop
	la $s2, k
	#Get value from address in reg $s2
	lw $s3, 0($s2)
	la $s2, l
	#Get value from address in reg $s2
	lw $s4, 0($s2)
	#Compare variable $s3 and $s4
	li $s2, 1
	bgt $s3, $s4, compBranch4
	bgt $s4, $s3, compBranch4
	li $s2, 0
compBranch4: nop
	#Bitwise variable $s1 and $s2
	and $s3, $s1, $s2
	#Bitwise variable $s0 and $s3
	or $s1, $s0, $s3
	#Print variable $s1
	li $v0, 1
	move $a0, $s1
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
