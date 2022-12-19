#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE * fp;
  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    return 0;
  }

  int index = 0;
  char c[4];
  do {
    c[0] = fgetc(fp); index++;
    c[1] = fgetc(fp); index++;
    if (c[1] == c[0]) {
      continue;
    }

    c[2] = fgetc(fp); index++;
    if (c[2] == c[1] || c[2] == c[0]) {
      continue;
    }

    c[3] = fgetc(fp); index++;
    if (c[3] == c[2] || c[3] == c[1] || c[3] == c[0]) {
      continue;
    }

    printf("Index: %d", index - 1);
    break;
  } while (1);

  fclose(fp);
  return 0;
}
