	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	add $s0, $gp, 200
	li $s1, 0
	sw $s1, 0($s0)
label0:	nop
	add $s0, $gp, 200
	lw $s1, 0($s0)
	li $s0, 50
	slt $s2, $s1, $s0
	li $s0, 1
	bne $s2, $s0, label1
	add $s1, $gp, 200
	lw $s2, 0($s1)
	add $s1, $gp, 0
	li $s3, 4
	mult $s3, $s2
	mflo $s3
	add $s1,$s1, $s3
	li $s2, 0
	sw $s2, 0($s1)
	add $s1, $gp, 200
	add $s2, $gp, 200
	lw $s3, 0($s2)
	li $s2, 1
	add $s4, $s3, $s2
	sw $s4, 0($s1)
	j label0
label1:	 nop
	add $s1, $gp, 204
	li $s2, 0
	sw $s2, 0($s1)
label2:	nop
	add $s1, $gp, 204
	lw $s2, 0($s1)
	li $s1, 50
	slt $s3, $s2, $s1
	li $s1, 1
	bne $s3, $s1, label3
	add $s2, $gp, 204
	lw $s3, 0($s2)
	add $s2, $gp, 212
	li $s4, 4
	mult $s4, $s3
	mflo $s4
	add $s2,$s2, $s4
	add $s3, $gp, 204
	lw $s4, 0($s3)
	li $s3, 50
	add $s5, $s4, $s3
	sw $s5, 0($s2)
	add $s2, $gp, 204
	add $s3, $gp, 204
	lw $s4, 0($s3)
	li $s3, 1
	add $s5, $s4, $s3
	sw $s5, 0($s2)
	j label2
label3:	 nop
	add $s2, $gp, 200
	li $s3, 0
	sw $s3, 0($s2)
	add $s2, $gp, 208
	li $s3, 0
	sw $s3, 0($s2)
label4:	nop
	add $s2, $gp, 200
	lw $s3, 0($s2)
	li $s2, 100
	slt $s4, $s3, $s2
	li $s2, 1
	bne $s4, $s2, label5
	add $s3, $gp, 200
	lw $s4, 0($s3)
	li $s3, 50
	slt $s5, $s4, $s3
	li $s3, 0
	beq $s5, $s3, label6
	add $s4, $gp, 208
	add $s5, $gp, 208
	lw $s6, 0($s5)
	add $s5, $gp, 200
	lw $s7, 0($s5)
	add $s5, $gp, 0
	li $t0, 4
	mult $t0, $s7
	mflo $t0
	add $s5,$s5, $t0
	lw $s7, 0($s5)
	add $s5, $s6, $s7
	sw $s5, 0($s4)
	j label7
label6:	 nop
	add $s4, $gp, 208
	add $s5, $gp, 208
	lw $s6, 0($s5)
	add $s5, $gp, 200
	lw $s7, 0($s5)
	li $s5, 50
	sub $t0, $s7, $s5
	add $s5, $gp, 212
	li $s7, 4
	mult $s7, $t0
	mflo $s7
	add $s5,$s5, $s7
	lw $s7, 0($s5)
	add $s5, $s6, $s7
	sw $s5, 0($s4)
label7:	 nop
	add $s4, $gp, 200
	add $s5, $gp, 200
	lw $s6, 0($s5)
	li $s5, 1
	add $s7, $s6, $s5
	sw $s7, 0($s4)
	j label4
label5:	 nop
	add $s4, $gp, 208
	lw $s5, 0($s4)
	move $a0, $s5
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $s4, 5
	add $s5, $gp, 0
	li $s6, 4
	mult $s6, $s4
	mflo $s6
	add $s5,$s5, $s6
	lw $s4, 0($s5)
	move $a0, $s4
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $s4, 10
	add $s5, $gp, 212
	li $s6, 4
	mult $s6, $s4
	mflo $s6
	add $s5,$s5, $s6
	lw $s4, 0($s5)
	move $a0, $s4
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $v0, 10
	syscall
