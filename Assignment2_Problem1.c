#include <stdio.h>

void fahrenheitToCelsius(int);

int main(){
	int fahrenheit;
	printf("Enter temperature in Fahrenheit\n");
	scanf("%d",&fahrenheit);
	fahrenheitToCelsius(fahrenheit);

}

void fahrenheitToCelsius(int fahrenheit) {
	double celsius;
	celsius = (fahrenheit-32) * (5.0/9.0);
	printf("Temperature in Celsius = %-+.2f\n",celsius);

}