	.file	"testeClasse.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZN5VetorC2Eii,"axG",@progbits,_ZN5VetorC5Eii,comdat
	.align 2
	.weak	_ZN5VetorC2Eii
	.type	_ZN5VetorC2Eii, @function
_ZN5VetorC2Eii:
.LFB1022:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 4(%eax)
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1022:
	.size	_ZN5VetorC2Eii, .-_ZN5VetorC2Eii
	.weak	_ZN5VetorC1Eii
	.set	_ZN5VetorC1Eii,_ZN5VetorC2Eii
	.section	.text._ZN5Vetor4getXEv,"axG",@progbits,_ZN5Vetor4getXEv,comdat
	.align 2
	.weak	_ZN5Vetor4getXEv
	.type	_ZN5Vetor4getXEv, @function
_ZN5Vetor4getXEv:
.LFB1024:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1024:
	.size	_ZN5Vetor4getXEv, .-_ZN5Vetor4getXEv
	.section	.text._ZN5Vetor4getYEv,"axG",@progbits,_ZN5Vetor4getYEv,comdat
	.align 2
	.weak	_ZN5Vetor4getYEv
	.type	_ZN5Vetor4getYEv, @function
_ZN5Vetor4getYEv:
.LFB1025:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1025:
	.size	_ZN5Vetor4getYEv, .-_ZN5Vetor4getYEv
	.section	.rodata
.LC0:
	.string	"Vetor: "
.LC1:
	.string	", "
	.text
	.globl	main
	.type	main, @function
main:
.LFB1026:
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
	subl	$28, %esp
	movl	%gs:20, %eax
	movl	%eax, -28(%ebp)
	xorl	%eax, %eax
	subl	$4, %esp
	pushl	$13
	pushl	$12
	leal	-36(%ebp), %eax
	pushl	%eax
	call	_ZN5VetorC1Eii
	addl	$16, %esp
	subl	$12, %esp
	leal	-36(%ebp), %eax
	pushl	%eax
	call	_ZN5Vetor4getYEv
	addl	$16, %esp
	movl	%eax, %ebx
	subl	$12, %esp
	leal	-36(%ebp), %eax
	pushl	%eax
	call	_ZN5Vetor4getXEv
	addl	$16, %esp
	movl	%eax, %esi
	subl	$8, %esp
	pushl	$.LC0
	pushl	$_ZSt4cout
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$16, %esp
	subl	$8, %esp
	pushl	%esi
	pushl	%eax
	call	_ZNSolsEi
	addl	$16, %esp
	subl	$8, %esp
	pushl	$.LC1
	pushl	%eax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$16, %esp
	subl	$8, %esp
	pushl	%ebx
	pushl	%eax
	call	_ZNSolsEi
	addl	$16, %esp
	movl	$0, %eax
	movl	-28(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L8
	call	__stack_chk_fail
.L8:
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
.LFE1026:
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1030:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	cmpl	$1, 8(%ebp)
	jne	.L11
	cmpl	$65535, 12(%ebp)
	jne	.L11
	subl	$12, %esp
	pushl	$_ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	addl	$16, %esp
	subl	$4, %esp
	pushl	$__dso_handle
	pushl	$_ZStL8__ioinit
	pushl	$_ZNSt8ios_base4InitD1Ev
	call	__cxa_atexit
	addl	$16, %esp
.L11:
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1030:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB1031:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	subl	$8, %esp
	pushl	$65535
	pushl	$1
	call	_Z41__static_initialization_and_destruction_0ii
	addl	$16, %esp
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1031:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 4
	.long	_GLOBAL__sub_I_main
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
