// Exercise 1.18
// Write a program to remove all trailing blanks and tabs from each line of 
// input, and to delete entirely blank lines.

#include <stdio.h>

#define MAX_LINE 1000

int get_line(char[]);
int trim(char []);

int main(void) 
{
  int len;
  char c;
  char line[MAX_LINE];

  while (1) {
    
    len = get_line(line);
    if(len == -1) { break; }
    if(len > 0) {
      printf("string: %s, length: %d\n", line, len);
      int trim_len = trim(line);    
      printf("string: %s, length: %d\n", line, trim_len);
    }   
  }
}

int get_line(char line[]) 
{
  int i, c;
  for (i=0; i < MAX_LINE && (c=getchar()) != EOF && c!='\n'; ++i) {
    line[i] = c;
  }

  if(c == EOF) {
    return -1;
  }

  line[i] = '\0';

  return i;
}

int trim(char line[]) 
{
  int i, j;
  char c;

  i=0;
  while ((c = line[i]) != '\0') {
    if(c != ' ' && c != '\t') {
      j = i;
    }
    ++i;
  }
    
  line[++j] = '\0';

  return j;
}
