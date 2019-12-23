	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	add $s0, $gp, 3844
	li $s1, 30
	sw $s1, 0($s0)
	add $s0, $gp, 3840
	li $s1, 30
	sw $s1, 0($s0)
	add $s0, $gp, 3848
	li $s1, 0
	sw $s1, 0($s0)
label0:	nop
	add $s0, $gp, 3848
	lw $s1, 0($s0)
	add $s0, $gp, 3844
	lw $s2, 0($s0)
	slt $s0, $s1, $s2
	li $s1, 1
	bne $s0, $s1, label1
	add $s0, $gp, 3848
	lw $s2, 0($s0)
	add $s0, $gp, 3844
	lw $s3, 0($s0)
	mul $s0, $s2, $s3
	add $s2, $gp, 240
	li $s3, 4
	mult $s3, $s0
	mflo $s3
	add $s2,$s2, $s3
	add $s0, $gp, 3848
	lw $s3, 0($s0)
	sw $s3, 0($s2)
	add $s0, $gp, 3848
	lw $s2, 0($s0)
	add $s0, $gp, 0
	li $s3, 4
	mult $s3, $s2
	mflo $s3
	add $s0,$s0, $s3
	add $s2, $gp, 3848
	lw $s3, 0($s2)
	li $s2, 1
	add $s4, $s3, $s2
	sw $s4, 0($s0)
	add $s0, $gp, 3848
	add $s2, $gp, 3848
	lw $s3, 0($s2)
	li $s2, 1
	add $s4, $s3, $s2
	sw $s4, 0($s0)
	j label0
label1:	 nop
	add $s0, $gp, 3852
	li $s2, 0
	sw $s2, 0($s0)
label2:	nop
	add $s0, $gp, 3852
	lw $s2, 0($s0)
	add $s0, $gp, 3840
	lw $s3, 0($s0)
	slt $s0, $s2, $s3
	li $s2, 1
	bne $s0, $s2, label3
	add $s0, $gp, 3852
	lw $s3, 0($s0)
	add $s0, $gp, 240
	li $s4, 4
	mult $s4, $s3
	mflo $s4
	add $s0,$s0, $s4
	add $s3, $gp, 3852
	lw $s4, 0($s3)
	sw $s4, 0($s0)
	add $s0, $gp, 3852
	lw $s3, 0($s0)
	add $s0, $gp, 120
	li $s4, 4
	mult $s4, $s3
	mflo $s4
	add $s0,$s0, $s4
	li $s3, 2
	add $s4, $gp, 3852
	lw $s5, 0($s4)
	li $s4, 1
	add $s6, $s5, $s4
	mul $s4, $s3, $s6
	sw $s4, 0($s0)
	add $s0, $gp, 3852
	add $s3, $gp, 3852
	lw $s4, 0($s3)
	li $s3, 1
	add $s5, $s4, $s3
	sw $s5, 0($s0)
	j label2
label3:	 nop
	add $s0, $gp, 3848
	li $s3, 1
	sw $s3, 0($s0)
label4:	nop
	add $s0, $gp, 3848
	lw $s3, 0($s0)
	add $s0, $gp, 3844
	lw $s4, 0($s0)
	slt $s0, $s3, $s4
	li $s3, 1
	bne $s0, $s3, label5
	add $s0, $gp, 3852
	li $s4, 1
	sw $s4, 0($s0)
label6:	nop
	add $s0, $gp, 3852
	lw $s4, 0($s0)
	add $s0, $gp, 3840
	lw $s5, 0($s0)
	slt $s0, $s4, $s5
	li $s4, 1
	bne $s0, $s4, label7
	add $s0, $gp, 3848
	lw $s5, 0($s0)
	add $s0, $gp, 3844
	lw $s6, 0($s0)
	mul $s0, $s5, $s6
	add $s5, $gp, 3852
	lw $s6, 0($s5)
	add $s5, $s0, $s6
	add $s0, $gp, 240
	li $s6, 4
	mult $s6, $s5
	mflo $s6
	add $s0,$s0, $s6
	add $s5, $gp, 3848
	lw $s6, 0($s5)
	li $s5, 1
	sub $s7, $s6, $s5
	add $s5, $gp, 3844
	lw $s6, 0($s5)
	mul $s5, $s7, $s6
	add $s6, $gp, 3852
	lw $s7, 0($s6)
	add $s6, $s5, $s7
	li $s5, 1
	sub $s7, $s6, $s5
	add $s5, $gp, 240
	li $s6, 4
	mult $s6, $s7
	mflo $s6
	add $s5,$s5, $s6
	lw $s6, 0($s5)
	sw $s6, 0($s0)
	add $s0, $gp, 3848
	lw $s5, 0($s0)
	add $s0, $gp, 120
	li $s6, 4
	mult $s6, $s5
	mflo $s6
	add $s0,$s0, $s6
	lw $s5, 0($s0)
	add $s0, $gp, 3852
	lw $s6, 0($s0)
	add $s0, $gp, 0
	li $s7, 4
	mult $s7, $s6
	mflo $s7
	add $s0,$s0, $s7
	lw $s6, 0($s0)
	sne $s0, $s5, $s6
	li $s5, 0
	beq $s0, $s5, label8
	add $s0, $gp, 3848
	lw $s6, 0($s0)
	add $s0, $gp, 3844
	lw $s7, 0($s0)
	mul $s0, $s6, $s7
	add $s6, $gp, 3852
	lw $s7, 0($s6)
	add $s6, $s0, $s7
	add $s0, $gp, 240
	li $s7, 4
	mult $s7, $s6
	mflo $s7
	add $s0,$s0, $s7
	add $s6, $gp, 3848
	lw $s7, 0($s6)
	add $s6, $gp, 3844
	lw $t0, 0($s6)
	mul $s6, $s7, $t0
	add $s7, $gp, 3852
	lw $t0, 0($s7)
	add $s7, $s6, $t0
	add $s6, $gp, 240
	li $t0, 4
	mult $t0, $s7
	mflo $t0
	add $s6,$s6, $t0
	lw $s7, 0($s6)
	li $s6, 1
	add $t0, $s7, $s6
	sw $t0, 0($s0)
	j label9
label8:	 nop
label9:	 nop
	add $s0, $gp, 3848
	lw $s6, 0($s0)
	li $s0, 1
	sub $s7, $s6, $s0
	add $s0, $gp, 3844
	lw $s6, 0($s0)
	mul $s0, $s7, $s6
	add $s6, $gp, 3852
	lw $s7, 0($s6)
	add $s6, $s0, $s7
	add $s0, $gp, 240
	li $s7, 4
	mult $s7, $s6
	mflo $s7
	add $s0,$s0, $s7
	lw $s6, 0($s0)
	add $s0, $gp, 3848
	lw $s7, 0($s0)
	add $s0, $gp, 3844
	lw $t0, 0($s0)
	mul $s0, $s7, $t0
	add $s7, $gp, 3852
	lw $t0, 0($s7)
	add $s7, $s0, $t0
	add $s0, $gp, 240
	li $t0, 4
	mult $t0, $s7
	mflo $t0
	add $s0,$s0, $t0
	lw $s7, 0($s0)
	slt $s0, $s6, $s7
	li $s6, 0
	beq $s0, $s6, label10
	add $s0, $gp, 3848
	lw $s7, 0($s0)
	add $s0, $gp, 3844
	lw $t0, 0($s0)
	mul $s0, $s7, $t0
	add $s7, $gp, 3852
	lw $t0, 0($s7)
	add $s7, $s0, $t0
	add $s0, $gp, 240
	li $t0, 4
	mult $t0, $s7
	mflo $t0
	add $s0,$s0, $t0
	add $s7, $gp, 3848
	lw $t0, 0($s7)
	li $s7, 1
	sub $t1, $t0, $s7
	add $s7, $gp, 3844
	lw $t0, 0($s7)
	mul $s7, $t1, $t0
	add $t0, $gp, 3852
	lw $t1, 0($t0)
	add $t0, $s7, $t1
	add $s7, $gp, 240
	li $t1, 4
	mult $t1, $t0
	mflo $t1
	add $s7,$s7, $t1
	lw $t0, 0($s7)
	li $s7, 1
	add $t1, $t0, $s7
	sw $t1, 0($s0)
	j label11
label10:	 nop
label11:	 nop
	add $s0, $gp, 3848
	lw $s7, 0($s0)
	add $s0, $gp, 3844
	lw $t0, 0($s0)
	mul $s0, $s7, $t0
	add $s7, $gp, 3852
	lw $t0, 0($s7)
	add $s7, $s0, $t0
	li $s0, 1
	sub $t0, $s7, $s0
	add $s0, $gp, 240
	li $s7, 4
	mult $s7, $t0
	mflo $s7
	add $s0,$s0, $s7
	lw $s7, 0($s0)
	add $s0, $gp, 3848
	lw $t0, 0($s0)
	add $s0, $gp, 3844
	lw $t1, 0($s0)
	mul $s0, $t0, $t1
	add $t0, $gp, 3852
	lw $t1, 0($t0)
	add $t0, $s0, $t1
	add $s0, $gp, 240
	li $t1, 4
	mult $t1, $t0
	mflo $t1
	add $s0,$s0, $t1
	lw $t0, 0($s0)
	slt $s0, $s7, $t0
	li $s7, 0
	beq $s0, $s7, label12
	add $s0, $gp, 3848
	lw $t0, 0($s0)
	add $s0, $gp, 3844
	lw $t1, 0($s0)
	mul $s0, $t0, $t1
	add $t0, $gp, 3852
	lw $t1, 0($t0)
	add $t0, $s0, $t1
	add $s0, $gp, 240
	li $t1, 4
	mult $t1, $t0
	mflo $t1
	add $s0,$s0, $t1
	add $t0, $gp, 3848
	lw $t1, 0($t0)
	add $t0, $gp, 3844
	lw $t2, 0($t0)
	mul $t0, $t1, $t2
	add $t1, $gp, 3852
	lw $t2, 0($t1)
	add $t1, $t0, $t2
	li $t0, 1
	sub $t2, $t1, $t0
	add $t0, $gp, 240
	li $t1, 4
	mult $t1, $t2
	mflo $t1
	add $t0,$t0, $t1
	lw $t1, 0($t0)
	li $t0, 1
	add $t2, $t1, $t0
	sw $t2, 0($s0)
	j label13
label12:	 nop
label13:	 nop
	add $s0, $gp, 3852
	add $t0, $gp, 3852
	lw $t1, 0($t0)
	li $t0, 1
	add $t2, $t1, $t0
	sw $t2, 0($s0)
	j label6
label7:	 nop
	add $s0, $gp, 3848
	add $t0, $gp, 3848
	lw $t1, 0($t0)
	li $t0, 1
	add $t2, $t1, $t0
	sw $t2, 0($s0)
	j label4
label5:	 nop
	li $s0, 899
	add $t0, $gp, 240
	li $t1, 4
	mult $t1, $s0
	mflo $t1
	add $t0,$t0, $t1
	lw $s0, 0($t0)
	move $a0, $s0
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $v0, 10
	syscall
