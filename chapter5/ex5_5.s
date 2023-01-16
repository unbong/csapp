	.file	"ex5_5.c"
	.text
	.globl	poly
	.type	poly, @function
poly:
.LFB23:
	.cfi_startproc
	endbr64
	movapd	%xmm0, %xmm3
	movsd	(%rdi), %xmm0
	cmpq	$1, %rsi
	jle	.L1
	leaq	8(%rdi), %rax
	leaq	(%rdi,%rsi,8), %rdx
	movapd	%xmm3, %xmm1
.L3:
	movapd	%xmm1, %xmm2
	mulsd	(%rax), %xmm2
	addsd	%xmm2, %xmm0
	mulsd	%xmm3, %xmm1
	addq	$8, %rax
	cmpq	%rdx, %rax
	jne	.L3
.L1:
	ret
	.cfi_endproc
.LFE23:
	.size	poly, .-poly
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
	movq	.LC0(%rip), %rax
	movq	%rax, (%rsp)
	movsd	.LC1(%rip), %xmm0
	movsd	%xmm0, 8(%rsp)
	movq	.LC2(%rip), %rax
	movq	%rax, 16(%rsp)
	movq	%rsp, %rdi
	movl	$2, %esi
	call	poly
	movq	24(%rsp), %rdx
	xorq	%fs:(%rbx), %rdx
	jne	.L8
	cvttsd2sil	%xmm0, %eax
	addq	$32, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L8:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	0
	.long	1073741824
	.align 8
.LC1:
	.long	0
	.long	1074266112
	.align 8
.LC2:
	.long	0
	.long	1074790400
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
