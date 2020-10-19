	.file	"sort.c"
	.text
	.p2align 4
	.globl	bubblesort
	.type	bubblesort, @function
bubblesort:
.LFB0:
	.cfi_startproc
	endbr64
	subq	$1, %rsi
	testq	%rsi, %rsi
	jle	.L1
	.p2align 4,,10
	.p2align 3
.L5:
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L4:
	movq	(%rdi,%rax,8), %rdx
	movq	8(%rdi,%rax,8), %rcx
	cmpq	%rcx, %rdx
	jle	.L3
	movq	%rcx, (%rdi,%rax,8)
	movq	%rdx, 8(%rdi,%rax,8)
.L3:
	addq	$1, %rax
	cmpq	%rax, %rsi
	jg	.L4
	subq	$1, %rsi
	jne	.L5
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	bubblesort, .-bubblesort
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
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
