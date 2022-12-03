#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    return 0;
  }

  int max = 0;
  int current = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    if ((int)read == 1) {
      if (max < current) {
	max = current;
      }
      
      current = 0;
    }

    current += atoi(line);
  }

  printf("Max %d", max);

  fclose(fp);
  return 0;
}
