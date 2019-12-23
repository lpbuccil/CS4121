	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	add $s0, $gp, 0
	li $s1, 3
	sw $s1, 0($s0)
	add $s0, $gp, 4
	li $s1, 4
	sw $s1, 0($s0)
	add $s0, $gp, 8
	li $s1, 5
	sw $s1, 0($s0)
	add $s0, $gp, 52
	li $s1, 13
	sw $s1, 0($s0)
	add $s0, $gp, 56
	li $s1, 14
	sw $s1, 0($s0)
	add $s0, $gp, 60
	li $s1, 15
	sw $s1, 0($s0)
	add $s0, $gp, 4
	li $s1, 0
	add $s2, $gp, 0
	lw $s3, 0($s2)
	sub $s2, $s1, $s3
	sw $s2, 0($s0)
	add $s0, $gp, 4
	lw $s1, 0($s0)
	add $s0, $gp, 12
	li $s2, 4
	mult $s2, $s1
	mflo $s2
	add $s0,$s0, $s2
	lw $s1, 0($s0)
	move $a0, $s1
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $s0, 11
	add $s1, $gp, 12
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	lw $s0, 0($s1)
	move $a0, $s0
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s0, $gp, 60
	lw $s1, 0($s0)
	move $a0, $s1
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $s0, 12
	add $s1, $gp, 12
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 100
	sw $s0, 0($s1)
	add $s0, $gp, 60
	lw $s1, 0($s0)
	move $a0, $s1
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $v0, 10
	syscall
