	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	li $s0, 3
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 4
	sw $s0, 0($s1)
	li $s0, 3
	add $s1, $gp, 0
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
	li $v0, 10
	syscall
