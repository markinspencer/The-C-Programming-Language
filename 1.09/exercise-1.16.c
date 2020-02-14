// Exercise 1.16
// Revise the main routine of the longest-line program so it will correctly 
// print the length of arbitrarily long input lines, and as much as possible of
// the text.

#include <stdio.h>
#define MAXLINE 10

int get_line(char line[], int maxline);
void copy(char dest[], char src[]);

int main(void)
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while((len = get_line(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }

  if(max > MAXLINE) {
    printf("%s... %d", longest, max);
  } else if (max > 0) {
    printf("%s", longest);
  }

  return 0;
}

int get_line (char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if(i == lim - 1) {
    s[i] = '\0';
    while((c=getchar()) != '\n') {
      ++i;
    }
  } else  {
    if(c == '\n') {
      s[i] = c;
      ++i;
    }

    s[i] = '\0';
  }
  return i;
}

void copy(char dest[], char src[])
{
  int i;
  i=0;
  while ((dest[i] = src[i]) != '\0')
    ++i;
}