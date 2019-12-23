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
	li $s0, 0
	sw $s0, 0($s1)
	li $s0, 1
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 1
	sw $s0, 0($s1)
	li $s0, 2
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 2
	sw $s0, 0($s1)
	li $s0, 3
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 3
	sw $s0, 0($s1)
	li $s0, 4
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 4
	sw $s0, 0($s1)
	li $s0, 5
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 5
	sw $s0, 0($s1)
	li $s0, 6
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 6
	sw $s0, 0($s1)
	li $s0, 7
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 7
	sw $s0, 0($s1)
	li $s0, 8
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 8
	sw $s0, 0($s1)
	li $s0, 9
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 9
	sw $s0, 0($s1)
	li $s0, 10
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 8
	sw $s0, 0($s1)
	li $s0, 11
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 7
	sw $s0, 0($s1)
	li $s0, 12
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 6
	sw $s0, 0($s1)
	li $s0, 13
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 5
	sw $s0, 0($s1)
	li $s0, 14
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 4
	sw $s0, 0($s1)
	li $s0, 15
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 3
	sw $s0, 0($s1)
	li $s0, 16
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 2
	sw $s0, 0($s1)
	li $s0, 17
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 1
	sw $s0, 0($s1)
	li $s0, 18
	add $s1, $gp, 0
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 0
	sw $s0, 0($s1)
	li $s0, 0
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 0
	sw $s0, 0($s1)
	li $s0, 1
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 1
	sw $s0, 0($s1)
	li $s0, 2
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 3
	sw $s0, 0($s1)
	li $s0, 3
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 5
	sw $s0, 0($s1)
	li $s0, 4
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 7
	sw $s0, 0($s1)
	li $s0, 5
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 9
	sw $s0, 0($s1)
	li $s0, 6
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 11
	sw $s0, 0($s1)
	li $s0, 7
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 4
	sw $s0, 0($s1)
	li $s0, 8
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 3
	sw $s0, 0($s1)
	li $s0, 9
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 2
	sw $s0, 0($s1)
	li $s0, 10
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 1
	sw $s0, 0($s1)
	li $s0, 11
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 9
	sw $s0, 0($s1)
	li $s0, 12
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 8
	sw $s0, 0($s1)
	li $s0, 13
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 7
	sw $s0, 0($s1)
	li $s0, 14
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 6
	sw $s0, 0($s1)
	li $s0, 15
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s0
	mflo $s2
	add $s1,$s1, $s2
	li $s0, 0
	sw $s0, 0($s1)
	add $s0, $gp, 1756
	li $s1, 20
	sw $s1, 0($s0)
	add $s0, $gp, 1740
	li $s1, 0
	sw $s1, 0($s0)
label0:	nop
	add $s0, $gp, 1740
	lw $s1, 0($s0)
	li $s0, 1
	add $s2, $s1, $s0
	add $s0, $gp, 0
	li $s1, 4
	mult $s1, $s2
	mflo $s1
	add $s0,$s0, $s1
	lw $s1, 0($s0)
	li $s0, 0
	sne $s2, $s1, $s0
	li $s0, 1
	bne $s2, $s0, label1
	add $s1, $gp, 1740
	lw $s2, 0($s1)
	add $s1, $gp, 140
	li $s3, 4
	mult $s3, $s2
	mflo $s3
	add $s1,$s1, $s3
	add $s2, $gp, 1740
	lw $s3, 0($s2)
	sw $s3, 0($s1)
	add $s1, $gp, 1740
	add $s2, $gp, 1740
	lw $s3, 0($s2)
	li $s2, 1
	add $s4, $s3, $s2
	sw $s4, 0($s1)
	j label0
label1:	 nop
	add $s1, $gp, 1740
	add $s2, $gp, 1740
	lw $s3, 0($s2)
	li $s2, 1
	sub $s4, $s3, $s2
	sw $s4, 0($s1)
	add $s1, $gp, 1744
	li $s2, 0
	sw $s2, 0($s1)
label2:	nop
	add $s1, $gp, 1744
	lw $s2, 0($s1)
	li $s1, 1
	add $s3, $s2, $s1
	add $s1, $gp, 76
	li $s2, 4
	mult $s2, $s3
	mflo $s2
	add $s1,$s1, $s2
	lw $s2, 0($s1)
	li $s1, 0
	sne $s3, $s2, $s1
	li $s1, 1
	bne $s3, $s1, label3
	add $s2, $gp, 1744
	lw $s3, 0($s2)
	add $s2, $gp, 1756
	lw $s4, 0($s2)
	mul $s2, $s3, $s4
	add $s3, $gp, 140
	li $s4, 4
	mult $s4, $s2
	mflo $s4
	add $s3,$s3, $s4
	add $s2, $gp, 1744
	lw $s4, 0($s2)
	sw $s4, 0($s3)
	add $s2, $gp, 1744
	add $s3, $gp, 1744
	lw $s4, 0($s3)
	li $s3, 1
	add $s5, $s4, $s3
	sw $s5, 0($s2)
	j label2
label3:	 nop
	add $s2, $gp, 1744
	add $s3, $gp, 1744
	lw $s4, 0($s3)
	li $s3, 1
	sub $s5, $s4, $s3
	sw $s5, 0($s2)
	add $s2, $gp, 1748
	li $s3, 1
	sw $s3, 0($s2)
label4:	nop
	add $s2, $gp, 1748
	lw $s3, 0($s2)
	add $s2, $gp, 1744
	lw $s4, 0($s2)
	sle $s2, $s3, $s4
	li $s3, 1
	bne $s2, $s3, label5
	add $s2, $gp, 1752
	li $s4, 1
	sw $s4, 0($s2)
label6:	nop
	add $s2, $gp, 1752
	lw $s4, 0($s2)
	add $s2, $gp, 1740
	lw $s5, 0($s2)
	sle $s2, $s4, $s5
	li $s4, 1
	bne $s2, $s4, label7
	add $s2, $gp, 1748
	lw $s5, 0($s2)
	add $s2, $gp, 1756
	lw $s6, 0($s2)
	mul $s2, $s5, $s6
	add $s5, $gp, 1752
	lw $s6, 0($s5)
	add $s5, $s2, $s6
	add $s2, $gp, 140
	li $s6, 4
	mult $s6, $s5
	mflo $s6
	add $s2,$s2, $s6
	add $s5, $gp, 1748
	lw $s6, 0($s5)
	li $s5, 1
	sub $s7, $s6, $s5
	add $s5, $gp, 1756
	lw $s6, 0($s5)
	mul $s5, $s7, $s6
	add $s6, $gp, 1752
	lw $s7, 0($s6)
	add $s6, $s5, $s7
	li $s5, 1
	sub $s7, $s6, $s5
	add $s5, $gp, 140
	li $s6, 4
	mult $s6, $s7
	mflo $s6
	add $s5,$s5, $s6
	lw $s6, 0($s5)
	sw $s6, 0($s2)
	add $s2, $gp, 1748
	lw $s5, 0($s2)
	add $s2, $gp, 76
	li $s6, 4
	mult $s6, $s5
	mflo $s6
	add $s2,$s2, $s6
	lw $s5, 0($s2)
	add $s2, $gp, 1752
	lw $s6, 0($s2)
	add $s2, $gp, 0
	li $s7, 4
	mult $s7, $s6
	mflo $s7
	add $s2,$s2, $s7
	lw $s6, 0($s2)
	sne $s2, $s5, $s6
	li $s5, 0
	beq $s2, $s5, label8
	add $s2, $gp, 1748
	lw $s6, 0($s2)
	add $s2, $gp, 1756
	lw $s7, 0($s2)
	mul $s2, $s6, $s7
	add $s6, $gp, 1752
	lw $s7, 0($s6)
	add $s6, $s2, $s7
	add $s2, $gp, 140
	li $s7, 4
	mult $s7, $s6
	mflo $s7
	add $s2,$s2, $s7
	add $s6, $gp, 1748
	lw $s7, 0($s6)
	add $s6, $gp, 1756
	lw $t0, 0($s6)
	mul $s6, $s7, $t0
	add $s7, $gp, 1752
	lw $t0, 0($s7)
	add $s7, $s6, $t0
	add $s6, $gp, 140
	li $t0, 4
	mult $t0, $s7
	mflo $t0
	add $s6,$s6, $t0
	lw $s7, 0($s6)
	li $s6, 1
	add $t0, $s7, $s6
	sw $t0, 0($s2)
	j label9
label8:	 nop
label9:	 nop
	add $s2, $gp, 1748
	lw $s6, 0($s2)
	li $s2, 1
	sub $s7, $s6, $s2
	add $s2, $gp, 1756
	lw $s6, 0($s2)
	mul $s2, $s7, $s6
	add $s6, $gp, 1752
	lw $s7, 0($s6)
	add $s6, $s2, $s7
	add $s2, $gp, 140
	li $s7, 4
	mult $s7, $s6
	mflo $s7
	add $s2,$s2, $s7
	lw $s6, 0($s2)
	add $s2, $gp, 1748
	lw $s7, 0($s2)
	add $s2, $gp, 1756
	lw $t0, 0($s2)
	mul $s2, $s7, $t0
	add $s7, $gp, 1752
	lw $t0, 0($s7)
	add $s7, $s2, $t0
	add $s2, $gp, 140
	li $t0, 4
	mult $t0, $s7
	mflo $t0
	add $s2,$s2, $t0
	lw $s7, 0($s2)
	slt $s2, $s6, $s7
	li $s6, 0
	beq $s2, $s6, label10
	add $s2, $gp, 1748
	lw $s7, 0($s2)
	add $s2, $gp, 1756
	lw $t0, 0($s2)
	mul $s2, $s7, $t0
	add $s7, $gp, 1752
	lw $t0, 0($s7)
	add $s7, $s2, $t0
	add $s2, $gp, 140
	li $t0, 4
	mult $t0, $s7
	mflo $t0
	add $s2,$s2, $t0
	add $s7, $gp, 1748
	lw $t0, 0($s7)
	li $s7, 1
	sub $t1, $t0, $s7
	add $s7, $gp, 1756
	lw $t0, 0($s7)
	mul $s7, $t1, $t0
	add $t0, $gp, 1752
	lw $t1, 0($t0)
	add $t0, $s7, $t1
	add $s7, $gp, 140
	li $t1, 4
	mult $t1, $t0
	mflo $t1
	add $s7,$s7, $t1
	lw $t0, 0($s7)
	li $s7, 1
	add $t1, $t0, $s7
	sw $t1, 0($s2)
	j label11
label10:	 nop
label11:	 nop
	add $s2, $gp, 1748
	lw $s7, 0($s2)
	add $s2, $gp, 1756
	lw $t0, 0($s2)
	mul $s2, $s7, $t0
	add $s7, $gp, 1752
	lw $t0, 0($s7)
	add $s7, $s2, $t0
	li $s2, 1
	sub $t0, $s7, $s2
	add $s2, $gp, 140
	li $s7, 4
	mult $s7, $t0
	mflo $s7
	add $s2,$s2, $s7
	lw $s7, 0($s2)
	add $s2, $gp, 1748
	lw $t0, 0($s2)
	add $s2, $gp, 1756
	lw $t1, 0($s2)
	mul $s2, $t0, $t1
	add $t0, $gp, 1752
	lw $t1, 0($t0)
	add $t0, $s2, $t1
	add $s2, $gp, 140
	li $t1, 4
	mult $t1, $t0
	mflo $t1
	add $s2,$s2, $t1
	lw $t0, 0($s2)
	slt $s2, $s7, $t0
	li $s7, 0
	beq $s2, $s7, label12
	add $s2, $gp, 1748
	lw $t0, 0($s2)
	add $s2, $gp, 1756
	lw $t1, 0($s2)
	mul $s2, $t0, $t1
	add $t0, $gp, 1752
	lw $t1, 0($t0)
	add $t0, $s2, $t1
	add $s2, $gp, 140
	li $t1, 4
	mult $t1, $t0
	mflo $t1
	add $s2,$s2, $t1
	add $t0, $gp, 1748
	lw $t1, 0($t0)
	add $t0, $gp, 1756
	lw $t2, 0($t0)
	mul $t0, $t1, $t2
	add $t1, $gp, 1752
	lw $t2, 0($t1)
	add $t1, $t0, $t2
	li $t0, 1
	sub $t2, $t1, $t0
	add $t0, $gp, 140
	li $t1, 4
	mult $t1, $t2
	mflo $t1
	add $t0,$t0, $t1
	lw $t1, 0($t0)
	li $t0, 1
	add $t2, $t1, $t0
	sw $t2, 0($s2)
	j label13
label12:	 nop
label13:	 nop
	add $s2, $gp, 1752
	add $t0, $gp, 1752
	lw $t1, 0($t0)
	li $t0, 1
	add $t2, $t1, $t0
	sw $t2, 0($s2)
	j label6
label7:	 nop
	add $s2, $gp, 1748
	add $t0, $gp, 1748
	lw $t1, 0($t0)
	li $t0, 1
	add $t2, $t1, $t0
	sw $t2, 0($s2)
	j label4
label5:	 nop
	add $s2, $gp, 1744
	lw $t0, 0($s2)
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s2, $gp, 1740
	lw $t0, 0($s2)
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s2, $gp, 1744
	lw $t0, 0($s2)
	add $s2, $gp, 1756
	lw $t1, 0($s2)
	mul $s2, $t0, $t1
	add $t0, $gp, 1740
	lw $t1, 0($t0)
	add $t0, $s2, $t1
	add $s2, $gp, 140
	li $t1, 4
	mult $t1, $t0
	mflo $t1
	add $s2,$s2, $t1
	lw $t0, 0($s2)
	move $a0, $t0
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	li $v0, 10
	syscall
