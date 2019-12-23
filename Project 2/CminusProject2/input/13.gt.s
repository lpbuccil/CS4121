.data
	.newl: .asciiz "\n"
	i: .word 0
	j: .word 0
	k: .word 0
	l: .word 0
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
	la $s0, i
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, j
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bgt $s1, $s2, compBranch0
	li $s0, 0
compBranch0: nop
	#Print variable $s0
	li $v0, 1
	move $a0, $s0
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, i
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, i
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bge $s1, $s2, compBranch1
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
	#Print variable $s0
	li $v0, 1
	move $a0, $s0
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, j
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, k
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bge $s1, $s2, compBranch3
	li $s0, 0
compBranch3: nop
	#Print variable $s0
	li $v0, 1
	move $a0, $s0
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
