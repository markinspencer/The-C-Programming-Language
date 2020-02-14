// Exercise 1.03
// Modify the temperature conversion program to print a heading above the table.

#include <stdio.h>

int main()
{
	int temp = 0; 

  printf("Fahrenheit to Celcius \n");
	while (temp <= 300)
	{
		printf("%3d %6.1f \n", temp, (5.0 / 9.0) * (temp - 32));
		temp += 20;
	}
}
