	.file	"swap_add.c"
	.text
	.globl	swap_add
	.type	swap_add, @function
swap_add:
.LFB23:
	.cfi_startproc
	endbr64
	movq	(%rdi), %rax
	movq	(%rsi), %rdx
	movq	%rdx, (%rdi)
	movq	%rax, (%rsi)
	addq	%rdx, %rax
	ret
	.cfi_endproc
.LFE23:
	.size	swap_add, .-swap_add
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	movl	$40, %ebx
	movq	%fs:(%rbx), %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	movq	$534, 8(%rsp)
	movq	$1057, 16(%rsp)
	leaq	16(%rsp), %rsi
	leaq	8(%rsp), %rdi
	call	swap_add
	movq	%rax, %rdx
	movq	8(%rsp), %rax
	subq	16(%rsp), %rax
	imull	%edx, %eax
	movq	24(%rsp), %rcx
	xorq	%fs:(%rbx), %rcx
	jne	.L5
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L5:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
