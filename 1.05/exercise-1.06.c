#include <stdio.h>

int main() {
  int c = getchar() != EOF;
  printf("the expression \"int c = getchar() != EOF\" is equal to %d\n", c);
}