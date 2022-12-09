#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE * fp;
  char * line1 = NULL;
  char * line2 = NULL;
  char * line3 = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    return 0;
  }

  int sum = 0;
  char result;
  while ((read = getline(&line1, &len, fp)) != -1) {
    getline(&line2, &len, fp);
    getline(&line3, &len, fp);

    char *result1;
    if ((result1 = strpbrk(line1, line2)) != NULL) {
      
      char *result2;
      if ((result2 = strpbrk(result1, line3)) != NULL) {
        result = result2[0];
      }
    }

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
