#include <stdio.h>
int atoi(char *s);
int isdigit(int c);
void hello (int num){
	printf("Hello %d\n",num);
}

void bye (int num){
	printf("Bye %d\n",num );
}
int main(){
	void (*routinePtr) (int);

	hello(1);

	routinePtr=hello;
	(*routinePtr)(2);

	routinePtr=bye;
	(*routinePtr)(100);

	int num;
	char string[20];
	printf("%d\n",atoi("456"));
}
int isDigits(int c){
	if ((c>=48) && (c<=57)){
		return(1);
	}
	return (0);
}

int iAlpha(int c){
	if ((c>='A') && (c<='Z')){
		return(1);
	}
	if ((c>='a') && (c<='z')){
		return(1);
	}
	return(0);
}

char *strcpy(char *s1, const char *s2){
	char *aux = s1;
	if (s1==NULL){
		return NULL;
	}
	if (s2==NULL){
		return NULL;
	}
	for (;(*s1 = *s2);s1++,s2++){
		return (aux);
	}
}

char *strncpy(char *s1, const char *s2, size_t n){
	for (;(*s1=*s2) && (n!=0);s1++,s2++,n--){
		if (n==0){
			*s1= '\0';
		}
		return s1;
	}
}

char *strcat (char *s1, char *s2){
	char *aux = s1;
	while (*s1 != '\0')s1++;
	strcpy(s1,s2);
	return aux;
}
int strcmp(char *s1, char *s2){
	while ((*s1 == *s2) && (*s1!='\0') && (*s2 !='\0')){
		s1++;
		s2++;
	}
	if (*s1 == *s2){
		return 0;
	}
	return (*s1 - *s2);
}

int atoi(char *s){
	int accum=0;
	while(isdigit(*s)){
		accum *= 10;
		accum += (*s) - '0';
		s++;
	}
	return accum;
}