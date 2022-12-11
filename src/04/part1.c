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

  int fullUnions = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    char *firstPair = strtok(line, ",");
    char *secondPair = strtok(NULL, ",");

    int a1 = atoi(strtok(firstPair, "-"));
    int a2 = atoi(strtok(NULL, "-"));

    int b1 = atoi(strtok(secondPair, "-"));
    int b2 = atoi(strtok(NULL, "-"));

    if ((a1 >= b1 && a2 <= b2) || (b1 >= a1 && b2 <= a2)) {
	fullUnions++;
    }
  }

  printf("Full unions: %d\n", fullUnions);

  fclose(fp);
  return 0;
}
