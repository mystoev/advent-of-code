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

  int max1 = 0, max2 = 0, max3 = 0, current = 0;
  while ((read = getline(&line, &len, fp)) != -1) {
    if ((int)read == 1) {
      if (current > max1) {
        max3 = max2;
	max2 = max1;
	max1 = current;
      } else if (current > max2 && current != max1) {
        max3 = max2;
	max2 = current;
      } else if (current > max3 && current != max2) {
        max3 = current;
      }

      current = 0;
    }

    current += atoi(line);
  }

  printf("Max 3 %d", max1 + max2 + max3);

  fclose(fp);
  return 0;
}
