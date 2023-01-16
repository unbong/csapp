	.file	"absdiff.c"
	.text
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB23:
	.cfi_startproc
	endbr64
	movq	%rsi, %rax
	cmpq	%rsi, %rdi
	jge	.L2
	addq	$1, l_count(%rip)
	subq	%rdi, %rax
	ret
.L2:
	addq	$1, g_count(%rip)
	subq	%rsi, %rdi
	movq	%rdi, %rax
	ret
	.cfi_endproc
.LFE23:
	.size	absdiff, .-absdiff
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
	.globl	l_count
	.bss
	.align 8
	.type	l_count, @object
	.size	l_count, 8
l_count:
	.zero	8
	.globl	g_count
	.align 8
	.type	g_count, @object
	.size	g_count, 8
g_count:
	.zero	8
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
