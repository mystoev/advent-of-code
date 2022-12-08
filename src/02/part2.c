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

  // Y = draw
  // X = lose
  // Z = win
  // A = rock
  // B = paper
  // C = scissors

  int score = 0;
  char oponent, strategy;
  while ((oponent = fgetc(fp)) != EOF) {
    fgetc(fp); //for the space
    strategy = fgetc(fp);
    fgetc(fp); //for the new line

    if (strategy == 'Z') {
      score += 6;
      if (oponent == 'A') {
	score += 2;
      } else if (oponent == 'B') {
	score += 3;
      } else {
	score += 1;
      }
    } else if (strategy == 'Y') {
      score += 3;

      if (oponent == 'A') {
	score += 1;
      } else if (oponent == 'B') {
	score += 2;
      } else {
	score += 3;
      }
    } else {
      if (oponent == 'A') {
	score += 3;
      } else if (oponent == 'B') {
        score += 1;
      } else {
        score += 2;
      }
    }
  }

  printf("Score: %d", score);


  fclose(fp);
 
  return 0;
}
