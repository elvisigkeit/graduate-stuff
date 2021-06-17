#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPT_A	"OPTION A\n"
#define OPT_B	"OPTION B\n"
#define OPT_C	"OPTION C\n"
#define	PADRAO	"abc:"

int main (int argc, char **argv) 
{
	int option;
	opterr = 0;
	int index;

	/*Its not safe to put the data manipulation (in this case the printfs)
	 * inside the while of the getopt, because it passes through all the options
	 * that was given before passing through an error.
	 * The expected behavior of a function that receives wrong arguments is
	 * just doing nothing.
	 *
	 * Another interesting thing is that the arguments are saved in the
	 * order that they were given.
	 */
	while((option = getopt(argc, argv, PADRAO)) != -1)
		switch (option)
		{
			case 'a':
				printf(OPT_A);
				break;
			case 'b':
				printf(OPT_B);
				break;
			case 'c':
				printf(OPT_C);
				printf("And the -c argument is: %s\n", optarg);
				break;
			case '?':
				if (optopt == 'c')
					fprintf(stderr, "Option -%c requires an argument. \n", optopt);
				else if (isprint(optopt))
					fprintf(stderr, "Unknown option -%c. \n", optopt);
				else 
					fprintf(stderr, "Unknown option character \\x%x. \n", optopt);
				return 1;
			default:
				abort();
		}

	/*There is yet, a way to deal with arguments that aren't in the 
	 * pattern stablished. It is a awesome way to return to 
	 * the user that he may be doing something wrong
	 * VALUABLE WARNING
	 */
	for (index = optind; index < argc; index++)
		printf("Non-option argument %s\n", argv[index]);


	return 0;
}
