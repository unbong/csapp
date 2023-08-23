	.file	"float_mov.c"
	.text
	.globl	flaot_mov
	.type	flaot_mov, @function
flaot_mov:
.LFB23:
	.cfi_startproc
	endbr64
	subq	$40, %rsp
	.cfi_def_cfa_offset 48
	movl	$40, %eax
	movq	%fs:(%rax), %rcx
	movq	%rcx, 24(%rsp)
	xorl	%ecx, %ecx
	movq	$0, 8(%rsp)
	movl	4(%rsp), %edx
	movq	24(%rsp), %rsi
	xorq	%fs:(%rax), %rsi
	jne	.L4
	movl	%edx, %eax
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE23:
	.size	flaot_mov, .-flaot_mov
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	ret
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
