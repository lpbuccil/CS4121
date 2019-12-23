	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	add $s0, $gp, 0
	li $s1, 0
	sw $s1, 0($s0)
label0:	nop
	add $s0, $gp, 0
	lw $s1, 0($s0)
	li $s0, 10
	slt $s2, $s1, $s0
	li $s0, 1
	bne $s2, $s0, label1
	add $s1, $gp, 0
	lw $s2, 0($s1)
	add $s1, $gp, 4
	li $s3, 4
	mult $s3, $s2
	mflo $s3
	add $s1,$s1, $s3
	add $s2, $gp, 0
	lw $s3, 0($s2)
	sw $s3, 0($s1)
	add $s1, $gp, 0
	add $s2, $gp, 0
	lw $s3, 0($s2)
	li $s2, 1
	add $s4, $s3, $s2
	sw $s4, 0($s1)
	j label0
label1:	 nop
	add $s1, $gp, 0
	li $s2, 0
	sw $s2, 0($s1)
label2:	nop
	add $s1, $gp, 0
	lw $s2, 0($s1)
	li $s1, 10
	slt $s3, $s2, $s1
	li $s1, 1
	bne $s3, $s1, label3
	add $s2, $gp, 0
	lw $s3, 0($s2)
	li $s2, 5
	slt $s4, $s3, $s2
	li $s2, 0
	beq $s4, $s2, label4
	add $s3, $gp, 0
	lw $s4, 0($s3)
	add $s3, $gp, 4
	li $s5, 4
	mult $s5, $s4
	mflo $s5
	add $s3,$s3, $s5
	lw $s4, 0($s3)
	move $a0, $s4
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	j label5
label4:	 nop
	li $s3, 0
	move $a0, $s3
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label5:	 nop
	add $s3, $gp, 0
	add $s4, $gp, 0
	lw $s5, 0($s4)
	li $s4, 1
	add $s6, $s5, $s4
	sw $s6, 0($s3)
	j label2
label3:	 nop
	li $v0, 10
	syscall
