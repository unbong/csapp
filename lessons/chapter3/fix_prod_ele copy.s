	.file	"fix_prod_ele.c"
	.text
	.globl	fix_prod_ele
	.type	fix_prod_ele, @function
fix_prod_ele:
.LFB23:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	movl	$0, %r8d
.L2:
	cmpq	$15, %r8
	jg	.L4
	movq	%rdx, %r9
	salq	$6, %r9
	addq	%rdi, %r9
	movq	%r8, %rax
	salq	$6, %rax
	addq	%rsi, %rax
	movl	(%rax,%rcx,4), %eax
	imull	(%r9,%r8,4), %eax
	addq	$1, %r8
	jmp	.L2
.L4:
	ret
	.cfi_endproc
.LFE23:
	.size	fix_prod_ele, .-fix_prod_ele
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
