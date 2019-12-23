	.data
.newline: .asciiz "\n"
.string0: .asciiz "Enter a:"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	la $s0, .string0
	move $a0, $s0
	li $v0, 4
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s0, $gp, 0
	li $v0, 5
	syscall
	sw $v0, 0($s0)
	add $s0, $gp, 0
	lw $s1, 0($s0)
	li $s0, 0
	beq $s1, $s0, label0
	add $s1, $gp, 4
	li $s2, 0
	add $s3, $gp, 0
	lw $s4, 0($s3)
	sub $s3, $s2, $s4
	sw $s3, 0($s1)
	add $s1, $gp, 4
	lw $s2, 0($s1)
	move $a0, $s2
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	j label1
label0:	 nop
	add $s1, $gp, 4
	add $s2, $gp, 0
	lw $s3, 0($s2)
	sw $s3, 0($s1)
	add $s1, $gp, 4
	lw $s2, 0($s1)
	move $a0, $s2
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label1:	 nop
	li $v0, 10
	syscall
