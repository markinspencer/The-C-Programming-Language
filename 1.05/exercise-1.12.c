// Exercise 1.12
// Write a program that prints its input one word per line.

#include <stdio.h>

#define IN 1
#define OUT 0 

int main(void) {
  int c, state;
  while((c = getchar()) != EOF) {
    if(c == ' ' || c == '\t') {
      if(state == IN) {
        putchar('\n');
      }
      state = OUT;
    } else {
      putchar(c);
      state = IN;
    }
  }
}