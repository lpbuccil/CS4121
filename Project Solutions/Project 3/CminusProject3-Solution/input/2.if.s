	.data
.newline: .asciiz "\n"
.string0: .asciiz "enter a:"
.string1: .asciiz "Compelte"
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
	sgt $s2, $s1, $s0
	li $s0, 0
	beq $s2, $s0, label0
	li $s1, 1
	move $a0, $s1
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	j label1
label0:	 nop
	li $s1, 0
	move $a0, $s1
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label1:	 nop
	la $s1, .string1
	move $a0, $s1
	li $v0, 4
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $v0, 10
	syscall
