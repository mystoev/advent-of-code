#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    return 0;
  }

  char *token;
  int i = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    token = strtok(line, "$ cd");
    printf("folder: %s\n", token);
    while (token != NULL) {
      token = strtok(NULL, "$ cd");
    }

    i++;

    if (i>20) {
      break;
    }
    
  }

  fclose(fp);
  return 0;
}
