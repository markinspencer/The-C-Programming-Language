// Exercise 1.22
// Write a program to "fold" long input lines into two or more shorter lines 
// after the last non-blank character that occurs before the n -th column of 
// input. Make sure your program does something intelligent with very long 
// lines, and if there are no blanks or tabs before the specified column. 

#include <stdio.h>

#define MAX_LINE 1000
#define PRINT_WIDTH 80
#define NEW_LINE '\n'
#define SPACE ' '

int get_line(char[]);
void fold(char[]);

int main(void) {
  int len; 
  char c;
  char line[MAX_LINE] = {0};

  while(1) {
    len = get_line(line);

    if(len == -1) {
      break;
    }

    if (len > PRINT_WIDTH) {
      fold(line);
    } else {
      printf("%s", line);
    }
  }
}

int get_line(char line[]) 
{
  int i, c;
  for (i = 0; i < MAX_LINE && (c=getchar()) != EOF && c!='\n'; ++i) {
    line[i] = c;
  }

  if (c == EOF) {
    return -1;
  }

  line[i] = '\0';

  return i;
}

void fold(char line[]) 
{
  char c;
  int i = 0;
  int j = 0;
  int last_space = -1;

  while ((c = line[i]) != '\0') {  

    if (c == SPACE) {
      last_space = i;
    }

    if (j >= PRINT_WIDTH && last_space > 0) {  
      line[last_space] = NEW_LINE;
      j = i - last_space;
      last_space = -1;
    }
    
    j++;
    i++;
  }

  printf("%s", line);
}



