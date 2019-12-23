.data
	.newl: .asciiz "\n"
	i: .word 0
	j: .word 0
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
	li $s1, 0
	#Assign variable $s0 = $s1
	sw $s1, 0($s0)
	la $s0, i
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	#Print variable $s1
	li $v0, 1
	move $a0, $s1
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, j
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	#Bitwise variable $s1 and $s1
	sltu  $s0, $zero, $s1
	xori  $s0, $s0, 1
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
	#Print variable $s1
	li $v0, 1
	move $a0, $s1
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, i
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	#Bitwise variable $s1 and $s1
	sltu  $s0, $zero, $s1
	xori  $s0, $s0, 1
	#Print variable $s0
	li $v0, 1
	move $a0, $s0
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
