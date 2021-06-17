int foo(int a, int b, int *p)
{
	if (a==(*p) || a==b)
		return 0;
	else
		if (a<b && a>(*p))
			return ((a-b)-(a-(*p)));
	return ((b-a)*((*p)-a));
}


foo:
	pushl %ebx				//guarda o valor de ebx
	movl 8(%esp), %ecx		//pega a e coloca em ecx
	movl 12(%esp), %ebx		//pega b e coloca em ebx
	cmpl %ebx, %ecx			//compara a com b [a-b]
	jge .L2					//se a for maior ou igual a b pula para L2
	movl 16(%esp), %eax		//pega o ponteiro de p e coloca em eax
	movl (%eax), %edx		//pega o valor apontado e coloca em edx
	cmpl %edx, %ecx			//compara *p com a [a-*p]
	jg .L9					//se a for maior que *p pula para L9
	cmpl %edx, %ecx			//compara *p com a [a-*p]
	je .L6					//se *p for igual a b pula para L6
.L10:				
	movl %ebx, %eax			//coloca b em eax
	subl %ecx, %edx			//*p = *p - a
	subl %ecx, %eax			//b = b - a
	imull %edx, %eax		//b = b * (*p)
.L4:
	popl %ebx				//restaura o valor de ebx
	ret						//retorna eax
.L2:
	movl $0, %eax			//carrega 0 em eax [valor retorno]
	je .L4					//pula para L4 se a == b 
	movl 16(%esp), %eax		//pega o ponteiro de p e coloca em eax
	movl (%eax), %edx		//coloca o valor do ponteiro em edx
	cmpl %edx, %ecx			//compara *p com a [*p-a]
	jne .L10				//se *p é diferente de a pula para L10
.L6:
	xorl %eax, %eax			//zera o valor em eax
	popl %ebx				//coloca o valor de ebx de volta 
	ret						//retorna a funcao com 0, de eax 
.L9:
	movl %ecx, %eax			//cria um a temporario: novo a
	subl %edx, %ecx			//a = a - *p
	subl %ebx, %eax			//novo a = novo a - b
	imull %ecx, %eax		//novo a = novo a * a
	popl %ebx				//coloca o valor de ebx de volta
	ret						//retorna esse valor do novo a
