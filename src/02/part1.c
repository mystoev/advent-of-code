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

  int score = 0;
  char oponent, me;
  while ((oponent = fgetc(fp)) != EOF) {
    fgetc(fp); //for the space
    me = fgetc(fp);
    fgetc(fp); //for the new line

    if (me == 'X') { //rock
      score += 1;

      if (oponent == 'A') {
	score += 3;
      } else if (oponent == 'C') {
	score += 6;
      }

    } else if (me == 'Y') { //paper
      score += 2;

      if (oponent == 'A') {
	score += 6;
      } else if (oponent == 'B') {
	score += 3;
      }
    } else { //scissors
      score += 3;

      if (oponent == 'B') {
	score += 6;
      } else if (oponent == 'C') {
	score += 3;
      }
    }
  }

  printf("Score: %d", score);


  fclose(fp);
 
  return 0;
}
