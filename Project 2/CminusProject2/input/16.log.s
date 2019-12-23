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
	la $s0, i
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, j
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	move $s0, $zero
	bgt $s1, $s2, compBranch1
	bgt $s2, $s1, compBranch1
	li $s0, 1
compBranch1: nop
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
	move $s0, $zero
	bgt $s1, $s2, compBranch2
	bgt $s2, $s1, compBranch2
	li $s0, 1
compBranch2: nop
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
	bgt $s1, $s2, compBranch3
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
	la $s0, j
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, j
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bge $s1, $s2, compBranch4
	li $s0, 0
compBranch4: nop
	#Print variable $s0
	li $v0, 1
	move $a0, $s0
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, k
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, i
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 0
	bgt $s1, $s2, compBranch5
	li $s0, 1
compBranch5: nop
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
	#Compare variable $s1 and $s2
	li $s0, 1
	bgt $s1, $s2, compBranch6
	bgt $s2, $s1, compBranch6
	li $s0, 0
compBranch6: nop
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
	bgt $s1, $s2, compBranch7
	li $s0, 0
compBranch7: nop
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
	la $s0, i
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, j
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bgt $s1, $s2, compBranch8
	li $s0, 0
compBranch8: nop
	la $s1, l
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, k
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Compare variable $s2 and $s3
	li $s1, 1
	bgt $s2, $s3, compBranch9
	li $s1, 0
compBranch9: nop
	#Bitwise variable $s0 and $s1
	or $s2, $s0, $s1
	#Print variable $s2
	li $v0, 1
	move $a0, $s2
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, j
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, i
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bgt $s1, $s2, compBranch10
	li $s0, 0
compBranch10: nop
	la $s1, l
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, k
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Compare variable $s2 and $s3
	li $s1, 1
	bgt $s2, $s3, compBranch11
	li $s1, 0
compBranch11: nop
	#Bitwise variable $s0 and $s1
	and $s2, $s0, $s1
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
	la $s0, j
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	move $s0, $zero
	bgt $s1, $s2, compBranch12
	bgt $s2, $s1, compBranch12
	li $s0, 1
compBranch12: nop
	la $s1, i
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, j
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Compare variable $s2 and $s3
	li $s1, 0
	bge $s2, $s3, compBranch13
	li $s1, 1
compBranch13: nop
	#Bitwise variable $s0 and $s1
	or $s2, $s0, $s1
	la $s0, k
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, l
	#Get value from address in reg $s0
	lw $s3, 0($s0)
	#Compare variable $s1 and $s3
	li $s0, 1
	bgt $s1, $s3, compBranch14
	bgt $s3, $s1, compBranch14
	li $s0, 0
compBranch14: nop
	#Bitwise variable $s2 and $s0
	and $s1, $s2, $s0
	#Print variable $s1
	li $v0, 1
	move $a0, $s1
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
