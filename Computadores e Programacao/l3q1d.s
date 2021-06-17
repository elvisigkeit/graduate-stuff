	.file	"l3q1d.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.globl	myopen
	.type	myopen, @function
myopen:
.LFB36:
	.cfi_startproc
	jmp	__open_2
	.cfi_endproc
.LFE36:
	.size	myopen, .-myopen
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB1:
	.text
.LHOTB1:
	.p2align 4,,15
	.globl	myread
	.type	myread, @function
myread:
.LFB37:
	.cfi_startproc
	subl	$16, %esp
	.cfi_def_cfa_offset 20
	pushl	$128
	.cfi_def_cfa_offset 24
	pushl	28(%esp)
	.cfi_def_cfa_offset 28
	pushl	28(%esp)
	.cfi_def_cfa_offset 32
	call	read
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
.LFE37:
	.size	myread, .-myread
	.section	.text.unlikely
.LCOLDE1:
	.text
.LHOTE1:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.globl	mywrite
	.type	mywrite, @function
mywrite:
.LFB38:
	.cfi_startproc
	jmp	write
	.cfi_endproc
.LFE38:
	.size	mywrite, .-mywrite
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.text.unlikely
.LCOLDB3:
	.text
.LHOTB3:
	.p2align 4,,15
	.globl	myclose
	.type	myclose, @function
myclose:
.LFB39:
	.cfi_startproc
	jmp	close
	.cfi_endproc
.LFE39:
	.size	myclose, .-myclose
	.section	.text.unlikely
.LCOLDE3:
	.text
.LHOTE3:
	.section	.rodata.str1.4,"aMS",@progbits,1
	.align 4
.LC4:
	.string	"forma correta: %s <nomearquivo>\n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC5:
	.string	"errno = %d\n"
.LC6:
	.string	"arq = %d\n"
.LC7:
	.string	"abertura de arquivo"
.LC8:
	.string	"escrita:"
.LC9:
	.string	"\n%d\n"
	.section	.text.unlikely
.LCOLDB10:
	.section	.text.startup,"ax",@progbits
.LHOTB10:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB40:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x70,0x6
	.cfi_escape 0x10,0x7,0x2,0x75,0x7c
	.cfi_escape 0x10,0x6,0x2,0x75,0x78
	.cfi_escape 0x10,0x3,0x2,0x75,0x74
	subl	$168, %esp
	movl	(%ecx), %eax
	movl	4(%ecx), %ebx
	movl	%gs:20, %edx
	movl	%edx, -28(%ebp)
	xorl	%edx, %edx
	cmpl	$2, %eax
	je	.L7
	pushl	(%ebx)
	pushl	$.LC4
	pushl	$1
	pushl	stderr
	call	__fprintf_chk
	addl	$16, %esp
	movl	$1, %eax
.L8:
	movl	-28(%ebp), %esi
	xorl	%gs:20, %esi
	jne	.L19
	leal	-16(%ebp), %esp
	popl	%ecx
	.cfi_remember_state
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
.L7:
	.cfi_restore_state
	call	__errno_location
	pushl	%ecx
	pushl	(%eax)
	movl	%eax, %edi
	pushl	$.LC5
	pushl	$1
	call	__printf_chk
	addl	$12, %esp
	movl	(%edi), %esi
	movl	4(%ebx), %edx
#APP
# 41 "l3q1d.c" 1
	movl $5, %eax
	movl %edx, %ebx
	movl $0, %ecx
	int $0x80
	movl $0, %edx
	testl %eax, %eax
	movl $2, %ebx 
	cmovl %ebx, %edx
	movl %eax, %esi
# 0 "" 2
#NO_APP
	movl	%edx, (%edi)
	pushl	%esi
	pushl	$.LC6
	pushl	$1
	call	__printf_chk
	addl	$12, %esp
	pushl	(%edi)
	pushl	$.LC5
	pushl	$1
	call	__printf_chk
	addl	$16, %esp
	testl	%esi, %esi
	js	.L20
	leal	-156(%ebp), %edi
#APP
# 64 "l3q1d.c" 1
	movl $3, %eax
	movl %esi, %ebx
	movl %edi, %ecx
	movl $128, %edx
	int $0x80
	movl %eax, -172(%ebp)
# 0 "" 2
#NO_APP
	movl	-172(%ebp), %eax
	testl	%eax, %eax
	je	.L14
#APP
# 76 "l3q1d.c" 1
	movl $4, %eax
	movl $1, %ebx
	movl %edi, %ecx
	movl -172(%ebp), %edx
	int $0x80
	movl %eax, %edi
# 0 "" 2
#NO_APP
	movl	-172(%ebp), %eax
	movl	%edi, %edx
	cmpl	%edx, %eax
	movl	%eax, %edi
	movl	%eax, %ebx
	je	.L16
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L13:
	cmpl	%edi, %ebx
	jne	.L12
.L16:
	subl	$4, %esp
	pushl	%edi
	pushl	$.LC9
	pushl	$1
	call	__printf_chk
	popl	%eax
	pushl	stdin
	call	fflush
	addl	$16, %esp
	testl	%edi, %edi
	jne	.L13
.L14:
	subl	$12, %esp
	pushl	%esi
	call	close
	addl	$16, %esp
	xorl	%eax, %eax
	jmp	.L8
.L12:
	subl	$12, %esp
	pushl	$.LC8
	call	perror
	addl	$16, %esp
	movl	$1, %eax
	jmp	.L8
.L20:
	pushl	%edx
	pushl	(%edi)
	pushl	$.LC5
	pushl	$1
	call	__printf_chk
	movl	$.LC7, (%esp)
	call	perror
	addl	$16, %esp
	movl	$1, %eax
	jmp	.L8
.L19:
	call	__stack_chk_fail
	.cfi_endproc
.LFE40:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE10:
	.section	.text.startup
.LHOTE10:
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
