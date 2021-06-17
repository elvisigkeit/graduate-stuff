	.file	"teste.c"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	je	.L2
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jne	.L3
.L2:
	movl	$0, %eax
	jmp	.L4
.L3:
	movl	8(%ebp), %eax
	cmpl	12(%ebp), %eax
	jge	.L5
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	cmpl	8(%ebp), %eax
	jge	.L5
	movl	8(%ebp), %eax
	subl	12(%ebp), %eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	movl	8(%ebp), %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	jmp	.L4
.L5:
	movl	12(%ebp), %eax
	subl	8(%ebp), %eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	subl	8(%ebp), %eax
	imull	%edx, %eax
.L4:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
