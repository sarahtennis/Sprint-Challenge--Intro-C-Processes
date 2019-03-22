#include <stdio.h>
#include <dirent.h>

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

  while ((dp = readdir(dir)) != NULL)
  {
    printf("%s", dp->d_name);
  }

  // Repeatly read and print entries

  // Close directory

  return 0;
}

/* EXAMPLE
  $ ./lsls
      224  .
      992  ..
      1722  lsls.c
      8952  lsls
*/
