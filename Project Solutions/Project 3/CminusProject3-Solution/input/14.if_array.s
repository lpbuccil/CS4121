	.data
.newline: .asciiz "\n"
.string0: .asciiz "enter i ="
.string1: .asciiz "out of bound!"
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
	add $s0, $gp, 400
	li $v0, 5
	syscall
	sw $v0, 0($s0)
	add $s0, $gp, 400
	lw $s1, 0($s0)
	li $s0, 0
	slt $s2, $s1, $s0
	add $s0, $gp, 400
	lw $s1, 0($s0)
	li $s0, 100
	sge $s3, $s1, $s0
	or $s0, $s2, $s3
	li $s1, 0
	beq $s0, $s1, label0
	la $s0, .string1
	move $a0, $s0
	li $v0, 4
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	j label1
label0:	 nop
	add $s0, $gp, 400
	lw $s2, 0($s0)
	add $s0, $gp, 0
	li $s3, 4
	mult $s3, $s2
	mflo $s3
	add $s0,$s0, $s3
	add $s2, $gp, 400
	lw $s3, 0($s2)
	li $s2, 2
	mul $s4, $s3, $s2
	sw $s4, 0($s0)
	li $s0, 5
	add $s2, $gp, 0
	li $s3, 4
	mult $s3, $s0
	mflo $s3
	add $s2,$s2, $s3
	li $s0, 5
	sw $s0, 0($s2)
	add $s0, $gp, 400
	lw $s2, 0($s0)
	add $s0, $gp, 0
	li $s3, 4
	mult $s3, $s2
	mflo $s3
	add $s0,$s0, $s3
	lw $s2, 0($s0)
	move $a0, $s2
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label1:	 nop
	li $v0, 10
	syscall
