#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

extern int nuke_remove(const char** const files, unsigned nfiles, unsigned short recursive, unsigned reps);

void show_usage(const char* const program_name) {
  fprintf(stdout, "Usage: %s [-h] | [-n number] [-r] FILE...\n", program_name);
  fprintf(stdout, "Seriously remove (unlink) the FILE(s) from the filesystem. No trace.\n");
  fprintf(stdout, "\n");
  fprintf(stdout, "  -n <number>\ttimes which each file is overwritten before removing\n");
  fprintf(stdout, "  -h         \tshows this help menu\n");
  fprintf(stdout, "  -r         \trecursive mode (required when removing directory)\n");
}

int main(int argc, char ** argv) {
  const char* const program_name = argv[0];

  unsigned short recursive = 0;
  unsigned reps = 1;

  char opt;
  while ((opt = getopt(argc, argv, "hrn:")) > 0) {
    switch (opt) {
      case 'n':
        reps = atoi(optarg);
        break;

      case 'r':
        recursive=1;
        break;

      case 'h':
        show_usage(program_name);
        return EXIT_SUCCESS;

      default:
        show_usage(program_name);
        return EXIT_FAILURE;
    }
  }

  unsigned nfiles = argc - optind;
  if (!nfiles) {
    fprintf(stderr, "FILE is mandatory. Use \"%s -h\" to see the program usage.\n", program_name);
    return EXIT_FAILURE;
  }

  const char** const files = (const char** const) &argv[optind];

  return nuke_remove(files, nfiles, recursive, reps);
}
