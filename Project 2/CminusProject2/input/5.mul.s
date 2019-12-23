.data
	.newl: .asciiz "\n"
	i: .word 0
	j: .word 0
	k: .word 0
	l: .word 0
.text
	.globl main
main:	nop
	#Load immediate to $s0
	li $s0, 10
	#Load immediate to $s1
	li $s1, 20
	#Mult/Div variable $s0 and $s1
	mult $s0, $s1
	mflo $s2
	#Print variable $s2
	li $v0, 1
	move $a0, $s2
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, i
	#Load immediate to $s1
	li $s1, 7
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
	la $s0, j
	la $s1, i
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, k
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Mult/Div variable $s2 and $s3
	mult $s2, $s3
	mflo $s1
	la $s2, l
	#Get value from address in reg $s2
	lw $s3, 0($s2)
	#Mult/Div variable $s1 and $s3
	mult $s1, $s3
	mflo $s2
	#Assign variable $s0 = $s2
	sw $s2, 0($s0)
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
