.data
	.newl: .asciiz "\n"
	a: .word 0
	.string_const0: .asciiz "input an integer:"
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
	la $s0, a
	#Read into variable $s0
	li $v0, 5
	syscall
	#Assign variable $s0 = $v0
	sw $v0, 0($s0)
	la $s0, a
	#Get value from address in reg $s0
	lw $s1, 0($s0)
	#Print variable $s1
	li $v0, 1
	move $a0, $s1
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	#Load immediate to $s0
	li $s0, 1
	#Print variable $s0
	li $v0, 1
	move $a0, $s0
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
	#Load immediate to $s0
	li $s0, 1
	#Load immediate to $s1
	li $s1, 2
	#Add/Sub variable $s0 and $s1
	add $s2, $s0, $s1
	#Print variable $s2
	li $v0, 1
	move $a0, $s2
	syscall
	#Print newline
	li $v0, 4
	la $a0, .newl
	syscall
