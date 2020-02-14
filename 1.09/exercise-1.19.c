// Exercise 1.19
// Write a function reverse(s) that reverses the character string s . Use it to
// write a program that reverses its input a line at a time.

#include <stdio.h>

#define MAX_LINE 1000

int get_line(char[]);
void reverse(char[]);
int length(char []);

int main(void) 
{
  int len;
  char line[MAX_LINE];

  while ((len = get_line(line)) > 0) {
    reverse(line);
    printf("%s\n", line);
  }
}

int get_line(char line[]) 
{
  int i, c;
  for (i=0; i < MAX_LINE && (c=getchar()) != EOF && c!='\n'; ++i) {
    line[i] = c;
  }

  line[i] = '\0';

  return i;
}

void reverse(char line[]) 
{
  char c;  
  int i = 0;
  int j = length(line) - 1;
  
  while (i != j && i < j) {
    c = line[i];
    line[i] = line[j];
    line[j] = c;

    i++;
    j--;
  }
}

int length(char s[]) 
{
  int i = 0;
  while (s[i] != '\0') {
    i++;
  }

  return i;
}


