	.data
.newline: .asciiz "\n"
	.text
	.globl main
main:	nop
	move	$fp,$sp
	add $s0, $gp, 0
	li $s1, 0
	sw $s1, 0($s0)
	add $s0, $gp, 4
	add $s1, $gp, 0
	lw $s2, 0($s1)
	li $s1, 2
	sub $s3, $s2, $s1
	sw $s3, 0($s0)
	add $s0, $gp, 0
	lw $s1, 0($s0)
	li $s0, 0
	beq $s1, $s0, label0
	li $s1, 1
	move $a0, $s1
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	j label1
label0:	 nop
	li $s1, 0
	move $a0, $s1
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label1:	 nop
	add $s1, $gp, 4
	lw $s2, 0($s1)
	li $s1, 0
	beq $s2, $s1, label2
	add $s2, $gp, 0
	lw $s3, 0($s2)
	li $s2, 0
	beq $s3, $s2, label3
	li $s3, 0
	move $a0, $s3
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	j label4
label3:	 nop
	li $s3, 1
	move $a0, $s3
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label4:	 nop
	j label5
label2:	 nop
	li $s3, 0
	move $a0, $s3
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label5:	 nop
	li $v0, 10
	syscall
