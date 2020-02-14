// Exercise 1.13
// Write a program to print a histogram of the lengths of words in its input. It
// is easy to draw the histogram with the bars horizontal; a vertical 
// orientation is more challenging.

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXWORDLEN 15

int main(void)
{
  int i, j;
  int c, max, len, state;
  int lengths[MAXWORDLEN];

  for (i = 0; i < MAXWORDLEN; i++)
  {
    lengths[i] = 0;
  }

  state = OUT;
  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      if (state == IN)
      {
        state = OUT;
        lengths[len - 1]++;
      }
    }
    else
    {
      if (state == OUT)
      {
        state = IN;
        len = 0;
      }
      len++;
    }
  }

  max = 0;
  for (i = 0; i < MAXWORDLEN; i++)
  {
    if (max < lengths[i])
    {
      max = lengths[i];
    }
  }

  printf("\n");
  for (i = max; i > 0; i--)
  {
    printf("%2d | ", i);
    for (j = 0; j < MAXWORDLEN; j++)
    {
      if (lengths[j] >= i)
      {
        printf("#  ");
      }
      else
      {
        printf("%*c", 3, ' ');
      }
    }
    printf("\n");
  }

  printf("%*c", 4, ' ');
  for (i = 0; i < MAXWORDLEN; i++)
  {
    printf("---");
  }
  printf("\n");

  printf("%*c", 4, ' ');
  for (i = 0; i < MAXWORDLEN; i++)
  {
    printf("%2d ", i + 1);
  }
  printf("\n");
}
