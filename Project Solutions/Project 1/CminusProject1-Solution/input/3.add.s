	.section	.rodata
	.int_wformat: .string "%d\n"
	.str_wformat: .string "%s\n"
	.int_rformat: .string "%d"
	.comm _gp, 16, 4
	.text
	.globl main
	.type main,@function
main:	nop
	pushq %rbp
	movq %rsp, %rbp
	movl $10, %ebx
	movl $20, %ecx
	addl %ecx, %ebx
	movl %ebx, %esi
	movl $0, %eax
	movl $.int_wformat, %edi
	call printf
	movq $_gp,%rbx
	addq $0, %rbx
	movl $1, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $8, %rbx
	movl $3, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $12, %rbx
	movl $4, %ecx
	movl %ecx, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movq $_gp,%rcx
	addq $0, %rcx
	movl (%rcx), %r8d
	movq $_gp,%rcx
	addq $8, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movq $_gp,%rcx
	addq $12, %rcx
	movl (%rcx), %r9d
	addl %r9d, %r8d
	movl %r8d, (%rbx)
	movq $_gp,%rbx
	addq $4, %rbx
	movl (%rbx), %ecx
	movl %ecx, %esi
	movl $0, %eax
	movl $.int_wformat, %edi
	call printf
	leave
	ret
