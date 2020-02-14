// Exercise 1.04
// Write a program to print the corresponding Celsius to Fahrenheit table.

#include <stdio.h>

int main()
{
	int temp = 0; 

  printf("Celcius to Fahrenheit \n");
	while (temp <= 300)
	{
		printf("%3d %6.0f \n", temp, temp * (9.0 / 5.0) + 32);
		temp += 20;
	}
}
