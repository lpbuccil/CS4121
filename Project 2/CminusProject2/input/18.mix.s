.data
	.newl: .asciiz "\n"
	i: .word 0
	j: .word 0
	k: .word 0
	l: .word 0
	m: .word 0
	n: .word 0
	.string_const0: .asciiz "i = "
	.string_const1: .asciiz "j = "
	.string_const2: .asciiz "k = "
	.string_const3: .asciiz "l = "
	.string_const4: .asciiz "m = "
.text
	.globl main
main:	nop
	la $s0, .string_const0
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, i
	#Read into variable $s0
	li $v0, 5
	syscall
	#Assign variable $s0 = $v0
	sw $v0, 0($s0)
	la $s0, .string_const1
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, j
	#Read into variable $s0
	li $v0, 5
	syscall
	#Assign variable $s0 = $v0
	sw $v0, 0($s0)
	la $s0, .string_const2
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, k
	#Read into variable $s0
	li $v0, 5
	syscall
	#Assign variable $s0 = $v0
	sw $v0, 0($s0)
	la $s0, .string_const3
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, l
	#Read into variable $s0
	li $v0, 5
	syscall
	#Assign variable $s0 = $v0
	sw $v0, 0($s0)
	la $s0, .string_const4
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, m
	#Read into variable $s0
	li $v0, 5
	syscall
	#Assign variable $s0 = $v0
	sw $v0, 0($s0)
	la $s0, n
	la $s1, k
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, j
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	la $s1, l
	#Get value from address in reg $s1
	lw $s4, 0($s1)
	#Add/Sub variable $s3 and $s4
	add $s1, $s3, $s4
	#Compare variable $s2 and $s1
	li $s3, 0
	bge $s2, $s1, compBranch0
	li $s3, 1
compBranch0: nop
	la $s1, i
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, k
	#Get value from address in reg $s1
	lw $s4, 0($s1)
	#Compare variable $s2 and $s4
	li $s1, 1
	bgt $s2, $s4, compBranch1
	bgt $s4, $s2, compBranch1
	li $s1, 0
compBranch1: nop
	#Bitwise variable $s1 and $s1
	sltu  $s2, $zero, $s1
	xori  $s2, $s2, 1
	#Bitwise variable $s3 and $s2
	and $s1, $s3, $s2
	#Assign variable $s0 = $s1
	sw $s1, 0($s0)
	la $s0, n
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
	la $s0, l
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Mult/Div variable $s1 and $s2
	mult $s1, $s2
	mflo $s0
	la $s1, j
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, k
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Mult/Div variable $s2 and $s3
	mult $s2, $s3
	mflo $s1
	#Compare variable $s0 and $s1
	li $s2, 1
	bgt $s0, $s1, compBranch2
	li $s2, 0
compBranch2: nop
	#Load immediate to $s0
	li $s0, 1
	la $s1, m
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Compare variable $s0 and $s3
	li $s1, 0
	bgt $s0, $s3, compBranch3
	li $s1, 1
compBranch3: nop
	#Bitwise variable $s2 and $s1
	or $s0, $s2, $s1
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
	la $s0, l
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Mult/Div variable $s1 and $s2
	mult $s1, $s2
	mflo $s0
	la $s1, j
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, k
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	#Add/Sub variable $s2 and $s3
	add $s1, $s2, $s3
	la $s2, l
	#Get value from address in reg $s2
	lw $s3, 0($s2)
	#Add/Sub variable $s1 and $s3
	add $s2, $s1, $s3
	#Compare variable $s0 and $s2
	li $s1, 1
	bgt $s0, $s2, compBranch4
	li $s1, 0
compBranch4: nop
	la $s0, i
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	la $s0, j
	#Get value from address in reg $s0
	lw $s3, 0($s0)
	#Compare variable $s2 and $s3
	li $s0, 1
	bgt $s2, $s3, compBranch5
	bgt $s3, $s2, compBranch5
	li $s0, 0
compBranch5: nop
	#Bitwise variable $s1 and $s0
	and $s2, $s1, $s0
	la $s0, l
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, n
	#Get value from address in reg $s0
	lw $s3, 0($s0)
	#Compare variable $s1 and $s3
	li $s0, 1
	bgt $s1, $s3, compBranch6
	li $s0, 0
compBranch6: nop
	#Bitwise variable $s2 and $s0
	or $s1, $s2, $s0
	#Print variable $s1
	li $v0, 1
	move $a0, $s1
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, l
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	la $s0, j
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Mult/Div variable $s1 and $s2
	div $s1, $s2
	mflo $s0
	la $s1, i
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	#Add/Sub variable $s0 and $s2
	sub $s1, $s0, $s2
	la $s0, m
	#Get value from address in reg $s0
	lw $s2, 0($s0)
	#Compare variable $s1 and $s2
	li $s0, 1
	bgt $s1, $s2, compBranch7
	li $s0, 0
compBranch7: nop
	la $s1, k
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, l
	#Get value from address in reg $s1
	lw $s3, 0($s1)
	la $s1, n
	#Get value from address in reg $s1
	lw $s4, 0($s1)
	#Mult/Div variable $s3 and $s4
	mult $s3, $s4
	mflo $s1
	#Add/Sub variable $s2 and $s1
	add $s3, $s2, $s1
	la $s1, l
	#Get value from address in reg $s1
	lw $s2, 0($s1)
	la $s1, k
	#Get value from address in reg $s1
	lw $s4, 0($s1)
	la $s1, n
	#Get value from address in reg $s1
	lw $s5, 0($s1)
	#Mult/Div variable $s4 and $s5
	mult $s4, $s5
	mflo $s1
	#Add/Sub variable $s2 and $s1
	add $s4, $s2, $s1
	#Compare variable $s3 and $s4
	li $s1, 1
	bgt $s3, $s4, compBranch8
	bgt $s4, $s3, compBranch8
	li $s1, 0
compBranch8: nop
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
