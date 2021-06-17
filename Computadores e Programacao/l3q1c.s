	.file	"l3q1c.c"
	.text
	.globl	myopen
	.type	myopen, @function
myopen:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	subl	$8, %esp
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	open
	addl	$16, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	myopen, .-myopen
	.globl	myread
	.type	myread, @function
myread:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	subl	$4, %esp
	pushl	$128
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	read
	addl	$16, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	myread, .-myread
	.globl	mywrite
	.type	mywrite, @function
mywrite:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	subl	$4, %esp
	pushl	16(%ebp)
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	write
	addl	$16, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	mywrite, .-mywrite
	.globl	myclose
	.type	myclose, @function
myclose:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	subl	$12, %esp
	pushl	8(%ebp)
	call	close
	addl	$16, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	myclose, .-myclose
	.section	.rodata
	.align 4
.LC0:
	.string	"forma correta: %s <nomearquivo>\n"
.LC1:
	.string	"errno = %d\n"
.LC2:
	.string	"arq = %d\n"
.LC3:
	.string	"abertura de arquivo"
.LC4:
	.string	"escrita:"
	.text
	.globl	main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x74,0x6
	.cfi_escape 0x10,0x6,0x2,0x75,0x7c
	.cfi_escape 0x10,0x3,0x2,0x75,0x78
	subl	$172, %esp
	movl	%ecx, %eax
	movl	4(%eax), %edx
	movl	%edx, -172(%ebp)
	movl	%gs:20, %ebx
	movl	%ebx, -28(%ebp)
	xorl	%ebx, %ebx
	cmpl	$2, (%eax)
	je	.L10
	movl	-172(%ebp), %eax
	movl	(%eax), %edx
	movl	stderr, %eax
	subl	$4, %esp
	pushl	%edx
	pushl	$.LC0
	pushl	%eax
	call	fprintf
	addl	$16, %esp
	movl	$1, %eax
	jmp	.L16
.L10:
	call	__errno_location
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	call	__errno_location
	movl	(%eax), %edx
	movl	-172(%ebp), %eax
	addl	$4, %eax
	movl	(%eax), %esi
#APP
# 60 "l3q1c.c" 1
	movl $5, %eax
	movl %esi, %ebx
	movl $0, %ecx
	int $0x80
	testl %eax, %eax
	movl $2, %ebx 
	cmovl %ebx, %edx
	movl %eax, %edx
# 0 "" 2
#NO_APP
	movl	%edx, -164(%ebp)
	subl	$8, %esp
	pushl	-164(%ebp)
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	call	__errno_location
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	cmpl	$0, -164(%ebp)
	jns	.L12
	call	__errno_location
	movl	(%eax), %eax
	subl	$8, %esp
	pushl	%eax
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	subl	$12, %esp
	pushl	$.LC3
	call	perror
	addl	$16, %esp
	movl	$1, %eax
	jmp	.L16
.L12:
	subl	$8, %esp
	leal	-156(%ebp), %eax
	pushl	%eax
	pushl	-164(%ebp)
	call	myread
	addl	$16, %esp
	movl	%eax, -168(%ebp)
	jmp	.L13
.L15:
	movl	-168(%ebp), %eax
	subl	$4, %esp
	pushl	%eax
	leal	-156(%ebp), %eax
	pushl	%eax
	pushl	$1
	call	mywrite
	addl	$16, %esp
	movl	%eax, -160(%ebp)
	movl	-160(%ebp), %eax
	cmpl	-168(%ebp), %eax
	je	.L14
	subl	$12, %esp
	pushl	$.LC4
	call	perror
	addl	$16, %esp
	movl	$1, %eax
	jmp	.L16
.L14:
	subl	$8, %esp
	leal	-156(%ebp), %eax
	pushl	%eax
	pushl	-164(%ebp)
	call	myread
	addl	$16, %esp
	movl	%eax, -168(%ebp)
.L13:
	cmpl	$0, -168(%ebp)
	jne	.L15
	subl	$12, %esp
	pushl	-164(%ebp)
	call	myclose
	addl	$16, %esp
	movl	$0, %eax
.L16:
	movl	-28(%ebp), %ecx
	xorl	%gs:20, %ecx
	je	.L17
	call	__stack_chk_fail
.L17:
	leal	-12(%ebp), %esp
	popl	%ecx
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
