	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	add $s0, $gp, 0
	li $s1, 1
	sw $s1, 0($s0)
	add $s0, $gp, 4
	li $s1, 0
	sw $s1, 0($s0)
label0:	nop
	add $s0, $gp, 0
	lw $s1, 0($s0)
	li $s0, 10
	sle $s2, $s1, $s0
	li $s0, 1
	bne $s2, $s0, label1
	add $s1, $gp, 0
	lw $s2, 0($s1)
	move $a0, $s2
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s1, $gp, 4
	add $s2, $gp, 4
	lw $s3, 0($s2)
	add $s2, $gp, 0
	lw $s4, 0($s2)
	add $s2, $s3, $s4
	sw $s2, 0($s1)
	add $s1, $gp, 0
	add $s2, $gp, 0
	lw $s3, 0($s2)
	li $s2, 1
	add $s4, $s3, $s2
	sw $s4, 0($s1)
	j label0
label1:	 nop
	add $s1, $gp, 4
	lw $s2, 0($s1)
	move $a0, $s2
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $v0, 10
	syscall
