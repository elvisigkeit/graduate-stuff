#include <stdio.h>
#include <stdlib.h>

#define EVER ;;

int main (int argc, char* argv[]) {
	int n;
	if((n=(argc==1) ? 1 : atol(argv[1])) <= 0){
		fprintf(stderr, "Use: %s [<n>]\n", argv[0]);
		return 1;
	}
	if(fork()) exit(0);
	
	while (n-- > 0) {
		if(!fork())
			exit(0);
	}
	for(EVER)
		pause();
	return 0;
}

