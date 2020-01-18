#include <stdio.h>

int main() {
  int c; 
  while((c = getchar()) != EOF) {
    switch (c) {
      case '\t': 
        putchar('\\');
        putchar('t');
        break; 
      case '\b': // wont work if terminal is in line mode
        putchar('\\');
        putchar('b');
        break;
      case '\\': 
        putchar('\\');
        break;
      default: 
        putchar(c);
        break;
    }
  }
}