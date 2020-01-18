#include <stdio.h>

int main()
{
	int temp = 0; 

  //Exercise 1.3
  printf("Fahrenheit to Celcius \n");
	while (temp <= 300)
	{
		printf("%3d %6.1f \n", temp, (5.0 / 9.0) * (temp - 32));
		temp += 20;
	}
}
