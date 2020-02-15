// Exercise 1.21
// Write a program entab that replaces strings of blanks with the minimum number
// of tabs and blanks to achieve the same spacing. Use the same stops as for 
// detab . When either a tab or a single blank would suffice to reach a tab 
// stop, which should be given preference?

#include <stdio.h>

#define MAX_LINE 1000
#define SPACE ' '
#define TAB '\t'
#define TAB_SIZE 8

int get_line(char[]);
void entab(char[]);
void copy(char[], char[]);
void debug(char[]);

int main(void) 
{
  int len;
  char line[MAX_LINE];

  while ((len = get_line(line)) > 0) {
    entab(line);
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

  line[i] = '\0';

  return i;
}

void entab(char line[]) 
{
  int i, j;
  int spaces = 0;
  int insert_tab = -1;
  char c;  
  char temp[MAX_LINE];
  copy(temp, line);

  i = j = 0;
  while ((c = temp[i]) != '\0') { 
    line[j] = c;
    
    if(c == SPACE && insert_tab == -1) {
      insert_tab = TAB_SIZE - (i % TAB_SIZE);  
    }
    
    if(c == SPACE) {
      spaces++;
    }
    else {
      spaces = 0;
      insert_tab = -1;
    }

    if(spaces == insert_tab) {
      j-= (insert_tab - 1);
      line[j] = '\t';
      spaces = 0;
      insert_tab = -1;
    }

    j++;
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


