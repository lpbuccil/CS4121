.data
	.newl: .asciiz "\n"
	i: .word 0
	j: .word 0
	k: .word 0
	l: .word 0
	m: .word 0
	s0: .word 0
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
	#Load immediate to $s1
	li $s1, 7
	#Add/Sub variable $s2 and $s1
	add $s3, $s2, $s1
	#Assign variable $s0 = $s3
	sw $s3, 0($s0)
	la $s0, m
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
	la $s0, s0
	la $s1, l
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	#Load immediate to $s1
	li $s1, 5
	#Add/Sub variable $s2 and $s1
	sub $s3, $s2, $s1
	#Assign variable $s0 = $s3
	sw $s3, 0($s0)
	la $s0, s0
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
	la $s0, k
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Mult/Div variable $s1 and $s2
	mult $s1, $s2
	mflo $s0
	la $s1, l
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	#Mult/Div variable $s0 and $s2
	mult $s0, $s2
	mflo $s1
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
	la $s0, k
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Mult/Div variable $s1 and $s2
	mult $s1, $s2
	mflo $s0
	la $s1, l
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	#Add/Sub variable $s0 and $s2
	sub $s1, $s0, $s2
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
	la $s0, k
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, l
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Mult/Div variable $s1 and $s2
	mult $s1, $s2
	mflo $s0
	la $s1, j
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	#Mult/Div variable $s0 and $s2
	div $s0, $s2
	mflo $s1
	la $s0, i
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Add/Sub variable $s1 and $s2
	sub $s0, $s1, $s2
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
	la $s0, j
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Add/Sub variable $s1 and $s2
	add $s0, $s1, $s2
	la $s1, k
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, i
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	la $s1, m
	#Get value from address in reg $s1
	lw $s4, 0($s1)
	#Mult/Div variable $s3 and $s4
	mult $s3, $s4
	mflo $s1
	#Add/Sub variable $s2 and $s1
	add $s3, $s2, $s1
	#Mult/Div variable $s0 and $s3
	mult $s0, $s3
	mflo $s1
	la $s0, s0
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Mult/Div variable $s1 and $s2
	div $s1, $s2
	mflo $s0
	#Print variable $s0
	li $v0, 1
	move $a0, $s0
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
