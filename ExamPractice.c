#include <stdio.h>
#include <stdlib.h>

void convertToUpperCase(char *);
char *string = "Tec de Monterrey";
int setVariableToZero(int *);
int stringLength(char *);

int main(){
	convertToUpperCase(string);
	printf("%s\n", string);

	int len = stringLength(string);
	printf("%d\n", len);
	
	int x= 10;
	x = setVariableToZero(&x);
	printf("%d\n",x );
}

void convertToUpperCase(char *s) {
	while (*s!='\0') {
		if (*s>='a' && *s<='z')  //Is it lowercase?
			*s -= ('a'-'A'); //Get the offset in ASCIIs
		++s;	//Move to the next character
	}
}


int setVariableToZero(int *variable){
	*variable = 0;
	return *variable;
}

int stringLength(char *s){
	int cont=0;
	while (*s!='\0'){
		s += 1;
		cont++;
	}
	return cont;
}

