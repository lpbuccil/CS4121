	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	li $s0, 0
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 32
	sw $s0, 0($s1)
	li $s0, 1
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 11
	sw $s0, 0($s1)
	li $s0, 2
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 111
	sw $s0, 0($s1)
	li $s0, 3
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 88
	sw $s0, 0($s1)
	li $s0, 4
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 11
	sw $s0, 0($s1)
	li $s0, 5
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 44
	sw $s0, 0($s1)
	li $s0, 6
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 33
	sw $s0, 0($s1)
	li $s0, 7
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 33
	sw $s0, 0($s1)
	li $s0, 8
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 22
	sw $s0, 0($s1)
	li $s0, 9
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 77
	sw $s0, 0($s1)
	li $s0, 10
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 45
	sw $s0, 0($s1)
	li $s0, 11
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 65
	sw $s0, 0($s1)
	li $s0, 12
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 76
	sw $s0, 0($s1)
	li $s0, 13
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 87
	sw $s0, 0($s1)
	li $s0, 14
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 34
	sw $s0, 0($s1)
	add $s0, $gp, 60
	li $s1, 0
	sw $s1, 0($s0)
label0:	nop
	add $s0, $gp, 60
	lw $s1, 0($s0)
	li $s0, 14
	slt $s2, $s1, $s0
	li $s0, 1
	bne $s2, $s0, label1
	add $s1, $gp, 72
	add $s2, $gp, 60
	lw $s3, 0($s2)
	sw $s3, 0($s1)
	add $s1, $gp, 64
	add $s2, $gp, 60
	lw $s3, 0($s2)
	li $s2, 1
	add $s4, $s3, $s2
	sw $s4, 0($s1)
label2:	nop
	add $s1, $gp, 64
	lw $s2, 0($s1)
	li $s1, 15
	slt $s3, $s2, $s1
	li $s1, 1
	bne $s3, $s1, label3
	add $s2, $gp, 64
	lw $s3, 0($s2)
	add $s2, $gp, 0
	li $s4, 4
	mult $s4, $s3
	mflo $s4
	add $s2,$s2, $s4
	lw $s3, 0($s2)
	add $s2, $gp, 72
	lw $s4, 0($s2)
	add $s2, $gp, 0
	li $s5, 4
	mult $s5, $s4
	mflo $s5
	add $s2,$s2, $s5
	lw $s4, 0($s2)
	slt $s2, $s3, $s4
	li $s3, 0
	beq $s2, $s3, label4
	add $s2, $gp, 72
	add $s4, $gp, 64
	lw $s5, 0($s4)
	sw $s5, 0($s2)
	j label5
label4:	 nop
label5:	 nop
	add $s2, $gp, 64
	add $s4, $gp, 64
	lw $s5, 0($s4)
	li $s4, 1
	add $s6, $s5, $s4
	sw $s6, 0($s2)
	j label2
label3:	 nop
	add $s2, $gp, 68
	add $s4, $gp, 60
	lw $s5, 0($s4)
	add $s4, $gp, 0
	li $s6, 4
	mult $s6, $s5
	mflo $s6
	add $s4,$s4, $s6
	lw $s5, 0($s4)
	sw $s5, 0($s2)
	add $s2, $gp, 60
	lw $s4, 0($s2)
	add $s2, $gp, 0
	li $s5, 4
	mult $s5, $s4
	mflo $s5
	add $s2,$s2, $s5
	add $s4, $gp, 72
	lw $s5, 0($s4)
	add $s4, $gp, 0
	li $s6, 4
	mult $s6, $s5
	mflo $s6
	add $s4,$s4, $s6
	lw $s5, 0($s4)
	sw $s5, 0($s2)
	add $s2, $gp, 72
	lw $s4, 0($s2)
	add $s2, $gp, 0
	li $s5, 4
	mult $s5, $s4
	mflo $s5
	add $s2,$s2, $s5
	add $s4, $gp, 68
	lw $s5, 0($s4)
	sw $s5, 0($s2)
	add $s2, $gp, 60
	add $s4, $gp, 60
	lw $s5, 0($s4)
	li $s4, 1
	add $s6, $s5, $s4
	sw $s6, 0($s2)
	j label0
label1:	 nop
	add $s2, $gp, 60
	li $s4, 0
	sw $s4, 0($s2)
label6:	nop
	add $s2, $gp, 60
	lw $s4, 0($s2)
	li $s2, 15
	slt $s5, $s4, $s2
	li $s2, 1
	bne $s5, $s2, label7
	add $s4, $gp, 60
	lw $s5, 0($s4)
	add $s4, $gp, 0
	li $s6, 4
	mult $s6, $s5
	mflo $s6
	add $s4,$s4, $s6
	lw $s5, 0($s4)
	move $a0, $s5
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s4, $gp, 60
	add $s5, $gp, 60
	lw $s6, 0($s5)
	li $s5, 1
	add $s7, $s6, $s5
	sw $s7, 0($s4)
	j label6
label7:	 nop
	li $v0, 10
	syscall
