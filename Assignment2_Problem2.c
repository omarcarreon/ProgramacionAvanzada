#include <stdio.h>

int calculateFactorial(int);

int main(){
	int number;
	printf("Enter number to calculate factorial\n");
	scanf("%d",&number);
	printf("Factorial of %d = %d \n",number,calculateFactorial(number));
}

int calculateFactorial(int number){
	int result = 1;
	if (number > 1)
		result = number * calculateFactorial(number-1);
	return  result;
}