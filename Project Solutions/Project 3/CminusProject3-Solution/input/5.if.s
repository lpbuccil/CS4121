	.data
.newline: .asciiz "\n"
.string0: .asciiz "enter a:"
.string1: .asciiz "enter b:"
.string2: .asciiz "a = "
.string3: .asciiz "b = "
.string4: .asciiz "a = "
.string5: .asciiz "b = "
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
	add $s0, $gp, 0
	li $v0, 5
	syscall
	sw $v0, 0($s0)
	la $s0, .string1
	move $a0, $s0
	li $v0, 4
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s0, $gp, 4
	li $v0, 5
	syscall
	sw $v0, 0($s0)
	add $s0, $gp, 4
	lw $s1, 0($s0)
	add $s0, $gp, 0
	lw $s2, 0($s0)
	sgt $s0, $s1, $s2
	li $s1, 0
	beq $s0, $s1, label0
	add $s0, $gp, 0
	lw $s2, 0($s0)
	li $s0, 0
	sgt $s3, $s2, $s0
	li $s0, 0
	beq $s3, $s0, label1
	la $s2, .string2
	move $a0, $s2
	li $v0, 4
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s2, $gp, 0
	lw $s3, 0($s2)
	move $a0, $s3
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	j label2
label1:	 nop
	la $s2, .string3
	move $a0, $s2
	li $v0, 4
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s2, $gp, 4
	lw $s3, 0($s2)
	move $a0, $s3
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label2:	 nop
	j label3
label0:	 nop
	add $s2, $gp, 0
	lw $s3, 0($s2)
	li $s2, 0
	slt $s4, $s3, $s2
	li $s2, 0
	beq $s4, $s2, label4
	la $s3, .string4
	move $a0, $s3
	li $v0, 4
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s3, $gp, 0
	lw $s4, 0($s3)
	move $a0, $s4
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	j label5
label4:	 nop
	la $s3, .string5
	move $a0, $s3
	li $v0, 4
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
	add $s3, $gp, 4
	lw $s4, 0($s3)
	move $a0, $s4
	li $v0, 1
	syscall
	li $v0, 4
	la, $a0, .newline
	syscall
label5:	 nop
label3:	 nop
	li $v0, 10
	syscall
