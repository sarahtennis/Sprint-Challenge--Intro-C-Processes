#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

/**
 * Prints out a directory listing for the directory the user specifies on the command line,
 * including both file names and sizes. If the user does not specify a directory, print out
 * the contents of the current directory.
 */
int main(int argc, char **argv)
{
  // Parse command line
  char *directory;

  if (argc >= 2)
  {
    directory = argv[1];
  }
  else
  {
    directory = ".";
  }

  // Open directory
  DIR *dir = opendir(directory);
  struct dirent *dp;

  if (dir == NULL)
  {
    perror("Cannot open directory");
    exit(1);
  }

  // Repeatly read and print entries
  // int longest_size = 5;

  while ((dp = readdir(dir)) != NULL)
  {
    struct stat get_size;

    char path[256];
    // int snprintf(char *str, size_t size, const char *format, ...);
    snprintf(path, 256, "%s/%s", directory, dp->d_name);
    stat(path, &get_size);

    // int size_chars = snprintf(NULL, 0, "%lli", get_size.st_size);
    // if (size_chars > longest_size)
    // {
    //   longest_size = size_chars;
    //   printf("new size: %d\n", longest_size);
    // }

    printf("%*lli %s\n", 10, get_size.st_size, dp->d_name);
  }

  // Close directory
  closedir(dir);

  return 0;
}

/* EXAMPLE
  $ ./lsls
      224  .
      992  ..
      1722  lsls.c
      8952  lsls
*/
