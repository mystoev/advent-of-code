#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 256
#define STACKS_NUM 9

int main() {
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    return 0;
  }

  char stacks[STACKS_NUM][MAX_STACK_SIZE] = {
    "PFMQWGRT",
    "HFR",
    "PZRVGHSD",
    "QHPBFWG",
    "PSMJH",
    "MZTHSRPL",
    "PTHNML",
    "FDQR",
    "DSCNLPH"
  };

  // To skip the configuration
  for (int i = 0; i < 10; i++) {
    getline(&line, &len, fp);
  }

  int num, s1, s2;
  char move[4], from[5], to[2];
  char *template = "%s %d %s %d %s %d";
  while (fscanf(fp, template, move, &num, from, &s1, to, &s2) != EOF) {

    for (int i = num -1; i >= 0; i--) {
      int stackLength = strlen(stacks[s1-1]);
      strcat(stacks[s2-1],(char[2]){ (char)stacks[s1-1][stackLength - 1], '\0' });
      stacks[s1-1][strlen(stacks[s1-1]) - 1] = '\0';
    }

  }

  printf("Result: ");
  for (int i = 0; i < STACKS_NUM; i++) {
    printf("%c", stacks[i][strlen(stacks[i])-1]);
  }
  printf("\n");

  fclose(fp);
  return 0;
}
