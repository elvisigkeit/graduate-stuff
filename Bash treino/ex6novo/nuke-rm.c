#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/random.h>
#include <sys/stat.h>
#include <unistd.h>

int is_file_valid(const char* const file) {
  struct stat status;
  return stat(file, &status);
}

int get_file_size(const char* const file) {
  struct stat status;
  return stat(file, &status) ? -1 : status.st_size;
}

int is_directory(struct stat* status) {
  return S_ISDIR(status->st_mode);
}

int is_link(struct stat* status) {
  return S_ISLNK(status->st_mode);
}

int is_regular_file(struct stat* status) {
  return S_ISREG(status->st_mode);
}

int overwrite_file(const char* const file, unsigned reps) {
  for (unsigned i=0; i < reps; i++) {
    int file_size = get_file_size(file);
    if (file_size < 0) {
      return EXIT_FAILURE;
    }

    FILE* f = fopen(file, "w");
    if (f == NULL) {
      perror("could not open the file");
      return EXIT_FAILURE;
    }

    char* buffer = calloc(file_size, sizeof(char));
    if (buffer == NULL) {
      fclose(f);
      perror("could not allocate memory to use in buffer");
      return EXIT_FAILURE;
    }

    getrandom(buffer, file_size, 0);
    fwrite(buffer, file_size, 1, f);

    free(buffer);
    fclose(f);
  }
  return EXIT_SUCCESS;
}

int nuke_remove_r(const char* const file, unsigned short recursive, unsigned reps) {
  if (is_file_valid(file)) {
    perror("could not validate the file");
    return EXIT_FAILURE;
  }

  struct stat status;
  stat(file, &status);

  // when file is a symlink, just unlink;
  if (is_link(&status))
    return remove(file);

  // when removing a regular file, first overwrite then removes properly;
  if (is_regular_file(&status))
    return !overwrite_file(file, reps)
      ? remove(file) 
      : EXIT_FAILURE;

  if (is_directory(&status) && !recursive) {
    fprintf(stderr, "Could not remove directory without recursive mode.\n");
    return EXIT_FAILURE;
  }

  if (is_directory(&status) && recursive) {
    DIR* dir = opendir(file);
    if (dir == NULL)
      return EXIT_FAILURE;

    char filename[256];
    struct dirent* dir_entry;
    while ((dir_entry = readdir(dir)) != NULL) {
      strcpy(filename, file);
      strcat(filename, "/");
      strcat(filename, dir_entry->d_name);

      if (!strcmp(dir_entry->d_name, ".") || !strcmp(dir_entry->d_name, ".."))
        continue;

      nuke_remove_r((const char* const) &filename, recursive, reps);
    }

    closedir(dir);
    return rmdir(file);
  }

  return EXIT_SUCCESS;
}

int nuke_remove(const char** const files, unsigned nfiles, unsigned short recursive, unsigned reps) {
  for (unsigned i = 0; i < nfiles; i++)
    if (nuke_remove_r(files[i], recursive, reps))
      return EXIT_FAILURE;

  return EXIT_SUCCESS;
}
