#include <stdio.h>

int main() {
  int c, t, s, nl;
  t = s = nl = 0;
  while ((c = getchar()) != EOF) {
    if(c == '\t') {
      ++t;
    }

    if(c == ' ') {
      ++s;
    }

    if(c == '\n') {
      ++nl;
    }
  }

  printf("input containted %ld tabs.\n", t);
  printf("input containted %ld spaces.\n", s);
  printf("input containted %ld newlines.\n", nl);
}