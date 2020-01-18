#include <stdio.h>

#define IN 1
#define OUT 0 

int main(void) {
  int c, nl, nw, nc, state;
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