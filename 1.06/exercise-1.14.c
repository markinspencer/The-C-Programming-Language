// Exercise 1.14
// Write a program to print a histogram of the frequencies of different 
// characters in its input.

#include <stdio.h>

#define ASCII_LENGTH 128

int main(void)
{
  int i, j;
  int c, max;

  int unique[ASCII_LENGTH];

  for (i = 0; i < ASCII_LENGTH; i++)
  {
    unique[i] = 0;
  }

  while ((c = getchar()) != EOF)
  {
    unique[c]++;
  }

  max = 0;
  for (i = 0; i < ASCII_LENGTH; i++)
  {
    if (max < unique[i])
    {
      max = unique[i];
    }
  }

  for (i = ASCII_LENGTH - 1; i >= 0; i--)
  {
    if (unique[i] != 0)
    {
      if (i == '\n')
      {
        printf("\n\\n | ");
      }
      else if (i == '\t')
      {
        printf("\n\\t | ");
      }
      else
      {
        printf("\n%2c | ", i);
      }
      for (j = 0; j < unique[i]; j++)
      {
        printf("# ");
      }
    }
  }

  printf("\n%*c--", 3, ' ');
  for (i = 0; i < max; i++)
  {
    printf("--");
  }

  printf("\n%*c", 5, ' ');
  for (i = 0; i < max; i++)
  {
    printf("%d ", i + 1);
  }

  printf("\n");
}
