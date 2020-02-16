// Exercise 1.20
// Write a program detab that replaces tabs in the input with the
// proper number of blanks to space to the next tab stop. Assume a
// fixed set of tab stop, say every n columns. Should n be a variable
// or symbolic parameter?

#include <stdio.h>

#define MAX_LINE 1000
#define SPACE ' '
#define TAB '\t'
#define TAB_SIZE 8

int get_line(char[]);
void detab(char[]);
void copy(char[], char[]);
void debug(char[]);

int main(void) 
{
  int len;
  char line[MAX_LINE];

  while (1) {
		len = get_line(line);

		if(len == -1) { break; }
    
		detab(line);
    printf("%s\n", line);
    //debug(line);
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

void detab(char line[]) 
{
  int i, j;
  char c;  
  char temp[MAX_LINE];
  copy(temp, line);

  i = j = 0;
  while ((c = temp[i]) != '\0') {
    if(c == TAB) {
      int spaces = TAB_SIZE - (j % TAB_SIZE);
      while (spaces != 0) {
        line[j] = SPACE;
        spaces--;
        j++;
      }
    }
    else {
      line[j] = c;
      j++;
    }

    i++;
  }
  line[j] = '\0';
}

void copy(char dest[], char src[])
{
  int i = 0;
  while ((dest[i] = src[i]) != '\0') {
    ++i;
  }
  dest[i] = '\0';
}

void debug(char line[]) {
  char c;
  int i = 0;
  while ((c = line[i]) != '\0') {
    if(c == TAB) {
      printf("\\t\n");
    }
    else if(c == SPACE) {
      printf("\\s\n");
    }
    else if(c == '\n') {
      printf("\\n\n");
    } 
    else {
      printf("%c\n", c);
    }
    i++;
  }
}


