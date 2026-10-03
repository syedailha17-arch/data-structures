	.file	"bst.c"
	.text
	.globl	createNode
	.def	createNode;	.scl	2;	.type	32;	.endef
	.seh_proc	createNode
createNode:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	$24, %ecx
	call	malloc
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	16(%rbp), %edx
	movl	%edx, 16(%rax)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-8(%rbp), %rax
	movq	(%rax), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	insertNode
	.def	insertNode;	.scl	2;	.type	32;	.endef
	.seh_proc	insertNode
insertNode:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpq	$0, 16(%rbp)
	jne	.L4
	movl	24(%rbp), %eax
	movl	%eax, %ecx
	call	createNode
	jmp	.L5
.L4:
	movq	16(%rbp), %rax
	movl	16(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jge	.L6
	movq	16(%rbp), %rax
	movq	(%rax), %rax
	movl	24(%rbp), %edx
	movq	%rax, %rcx
	call	insertNode
	movq	16(%rbp), %rdx
	movq	%rax, (%rdx)
	jmp	.L7
.L6:
	movq	16(%rbp), %rax
	movl	16(%rax), %eax
	cmpl	%eax, 24(%rbp)
	jle	.L7
	movq	16(%rbp), %rax
	movq	8(%rax), %rax
	movl	24(%rbp), %edx
	movq	%rax, %rcx
	call	insertNode
	movq	16(%rbp), %rdx
	movq	%rax, 8(%rdx)
.L7:
	movq	16(%rbp), %rax
.L5:
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	movq	$0, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$10, %edx
	movq	%rax, %rcx
	call	insertNode
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$20, %edx
	movq	%rax, %rcx
	call	insertNode
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$5, %edx
	movq	%rax, %rcx
	call	insertNode
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$15, %edx
	movq	%rax, %rcx
	call	insertNode
	movq	%rax, -8(%rbp)
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev3, Built by MSYS2 project) 16.2.0"
	.def	malloc;	.scl	2;	.type	32;	.endef
