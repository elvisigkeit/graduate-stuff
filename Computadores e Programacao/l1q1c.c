#include <stdio.h>

int foo (unsigned int n) 
{
	unsigned int x;
	x = n/7;
	return x;
}

main () 
{
	printf("%d\n", foo(4281111119));
}
