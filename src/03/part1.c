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

  int sum = 0;
  char *firstHalf, *secondHalf, result;
  while ((read = getline(&line, &len, fp)) != -1) {
    int halfLength = (strlen(line) - 1) / 2;

    firstHalf = (char *)malloc(halfLength);
    strncpy(firstHalf, line, halfLength);

    char secondHalf[halfLength];
    strcpy(secondHalf, &line[halfLength]);

    result = strpbrk(firstHalf, secondHalf)[0];

    if ((int)result > 96) {
      sum += (int)result - 96;
    } else {
      sum += (int)result - 38;
    }
  }

  printf("%d", sum);

  fclose(fp);
  return 0;
}
