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
	add $s0, $gp, 8
	li $v0, 5
	syscall
	sw $v0, 0($s0)
	add $s0, $gp, 8
	lw $s1, 0($s0)
	li $s0, 2
	div $s2, $s1, $s0
	li $s0, 2
	mul $s1, $s2, $s0
	add $s0, $gp, 8
	lw $s2, 0($s0)
	seq $s0, $s1, $s2
	li $s1, 0
	beq $s0, $s1, label0
	add $s0, $gp, 4
	li $s2, 1
	sw $s2, 0($s0)
	add $s0, $gp, 0
	li $s2, 0
	sw $s2, 0($s0)
label1:	nop
	add $s0, $gp, 4
	lw $s2, 0($s0)
	add $s0, $gp, 8
	lw $s3, 0($s0)
	sle $s0, $s2, $s3
	li $s2, 1
	bne $s0, $s2, label2
	add $s0, $gp, 0
	add $s3, $gp, 0
	lw $s4, 0($s3)
	add $s3, $gp, 4
	lw $s5, 0($s3)
	add $s3, $s4, $s5
	sw $s3, 0($s0)
	add $s0, $gp, 4
	add $s3, $gp, 4
	lw $s4, 0($s3)
	li $s3, 1
	add $s5, $s4, $s3
	sw $s5, 0($s0)
	j label1
label2:	 nop
	j label3
label0:	 nop
	add $s0, $gp, 4
	li $s3, 1
	sw $s3, 0($s0)
	add $s0, $gp, 0
	li $s3, 1
	sw $s3, 0($s0)
label4:	nop
	add $s0, $gp, 4
	lw $s3, 0($s0)
	add $s0, $gp, 8
	lw $s4, 0($s0)
	sle $s0, $s3, $s4
	li $s3, 1
	bne $s0, $s3, label5
	add $s0, $gp, 0
	add $s4, $gp, 0
	lw $s5, 0($s4)
	add $s4, $gp, 4
	lw $s6, 0($s4)
	mul $s4, $s5, $s6
	sw $s4, 0($s0)
	add $s0, $gp, 4
	add $s4, $gp, 4
	lw $s5, 0($s4)
	li $s4, 1
	add $s6, $s5, $s4
	sw $s6, 0($s0)
	j label4
label5:	 nop
label3:	 nop
	add $s0, $gp, 0
	lw $s4, 0($s0)
	move $a0, $s4
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $v0, 10
	syscall
