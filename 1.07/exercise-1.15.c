// Exercise 1.15
// Rewrite the temperature conversion program of Section 1.2 to use a function 
// for conversion.

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fahr_to_celcius(int);

int main(void) 
{
  int i;
  
  printf("Fahrenheit to Celcius\n");
  for(i = LOWER; i <= UPPER; i += STEP) 
    printf("%3d %6.1f\n", i, fahr_to_celcius(i));
}

float fahr_to_celcius(int fahr) 
{
  return (5.0/9.0)  * (fahr - 32);
}