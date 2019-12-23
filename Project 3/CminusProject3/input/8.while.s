	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	add $s0, $gp, 4
	li $s1, 1
	sw $s1, 0($s0)
label0:	nop
	add $s0, $gp, 4
	lw $s1, 0($s0)
	li $s0, 10
	sle $s2, $s1, $s0
	li $s0, 1
	bne $s2, $s0, label1
	add $s1, $gp, 0
	li $s2, 1
	sw $s2, 0($s1)
label2:	nop
	add $s1, $gp, 0
	lw $s2, 0($s1)
	li $s1, 10
	sle $s3, $s2, $s1
	li $s1, 1
	bne $s3, $s1, label3
	add $s2, $gp, 0
	lw $s3, 0($s2)
	add $s2, $gp, 4
	lw $s4, 0($s2)
	mul $s2, $s3, $s4
	move $a0, $s2
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s2, $gp, 0
	add $s3, $gp, 0
	lw $s4, 0($s3)
	li $s3, 1
	add $s5, $s4, $s3
	sw $s5, 0($s2)
	j label2
label3:	 nop
	add $s2, $gp, 4
	add $s3, $gp, 4
	lw $s4, 0($s3)
	li $s3, 1
	add $s5, $s4, $s3
	sw $s5, 0($s2)
	j label0
label1:	 nop
	li $v0, 10
	syscall
