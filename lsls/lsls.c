#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

DIR *dir;
struct dirent *dp;
struct stat buf;


/**
 * Main
 */
int main(int argc, char **argv)
{
 
  // Parse command line
  char dot[] = ".";
  char *path = &dot[0];
  if (argc == 2) {
    path = argv[1];
  } else if (argc > 2) {
    printf("Only using first argument.\n");
    path = argv[1];
  } 

  // Open directory
  // printf("Path: %s\n", path);
  if ((dir = opendir(path)) == NULL) {
    perror("opendir");
    exit(1);
  }


  // printf("Path: %s\n", path);
  char *full_str = strcat(path, "/");
  // printf("full string: %s\n", full_str);
  char *loop_str = malloc(strlen(full_str));
  strcpy(loop_str, full_str);
  // printf("loop_string: %s\n", loop_str);

  printf("\n");

  // Repeatly read and print entries
  while ((dp = readdir(dir)) != NULL) {
    strcat(loop_str, dp->d_name);
    // printf("%s\n", loop_str);
    stat(loop_str, &buf);
    printf("%10lld  %s\n", buf.st_size, dp->d_name);
    strcpy(loop_str, full_str);
  
  }
  
  free(loop_str);
  
  // Close directory
  closedir(dir);

  return 0;
}