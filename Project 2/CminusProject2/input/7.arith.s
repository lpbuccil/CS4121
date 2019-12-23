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
	la $s0, i
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, j
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Add/Sub variable $s1 and $s2
	add $s0, $s1, $s2
	la $s1, k
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, l
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Mult/Div variable $s2 and $s3
	mult $s2, $s3
	mflo $s1
	#Add/Sub variable $s0 and $s1
	add $s2, $s0, $s1
	#Print variable $s2
	li $v0, 1
	move $a0, $s2
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, i
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, l
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	la $s0, i
	#Get value from address in reg $s0
	lw $s3, 0($s0)
	#Add/Sub variable $s2 and $s3
	sub $s0, $s2, $s3
	la $s2, k
	#Get value from address in reg $s2
	lw $s3, 0($s2)
	#Mult/Div variable $s0 and $s3
	div $s0, $s3
	mflo $s2
	#Add/Sub variable $s1 and $s2
	add $s0, $s1, $s2
	la $s1, j
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	#Add/Sub variable $s0 and $s2
	add $s1, $s0, $s2
	#Print variable $s1
	li $v0, 1
	move $a0, $s1
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
