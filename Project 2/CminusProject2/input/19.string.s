.data
	.newl: .asciiz "\n"
	.string_const0: .asciiz "Your grader"
	.string_const1: .asciiz "will put"
	.string_const2: .asciiz "a random"
	.string_const3: .asciiz "string here"
.text
	.globl main
main:	nop
	la $s0, .string_const0
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, .string_const1
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, .string_const2
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	la $s0, .string_const3
	#Print variable $s0
	li $v0, 4
	la $a0, 0($s0)
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
