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

  getline(&line, &len, fp);

  char target[15];
  for (int i = 0; i < strlen(line) - 1; i++) {
    
    for (int j = i; j < i + 14; j++) {
      target[j-i] = line[j];
    }
    target[14] = '\0';

    int isFound = 1;
    for (int k = 0; k < 13; k++) {
      for (int n = k + 1; n < 14; n++) {
        if (target[k] == target[n]) {
          isFound = 0;
	  break;
	}
      }
    }

    if (isFound == 1) {
      printf("Target: %s at index: %d\n", target, i + 14);
      return 0;
    } else {
      for (int m = 0; m < 15; m++) {
	target[m] = '\0';
      }
    }
  }
  

  fclose(fp);
  return 0;
}
