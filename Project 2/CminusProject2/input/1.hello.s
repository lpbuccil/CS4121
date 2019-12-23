.data
	.newl: .asciiz "\n"
	.string_const0: .asciiz "Hello World!"
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
