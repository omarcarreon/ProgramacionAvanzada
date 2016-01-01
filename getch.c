#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void stringCopy(char *destString, char *sourceString){
	while (*sourceString!='\0'){
		*destString = *sourceString;
		destString++;
		sourceString++;
	}
	*destString ='\0';
}
char *getAnArbitraryLargeStringFromTheKeyboard() {
	char *string=NULL;
	int maxSize=5;
	int size=0;
	char chr=0;
	char *auxString=NULL;

	string = (char *)malloc(5);
	*string='\0';
	chr=getch();
	while (chr!=13){ // <ENTER> KEY
		if (chr==8){ // <BACKSPACE> KEY
			if (size!=0){
				printf("%c %c",chr,chr);
				size--;
				string[size]='\0';
				if (maxSize-size == 5){ // Decrease the real size for the string
					.
					.
					.
				}
			}
		} else {
 			if ((size+1)==maxSize) { // Increase the real size of the string
				auxString=(char *)malloc(maxSize+5);
				maxSize+=5;
				stringCopy(auxString,string);
				free(string);
				string=auxString;
			}
			string[size]=chr;
			printf("%c",chr);
			string[++size]='\0';
 		}
		chr=getch();
	}
	return(string);
}

int stringLength(char *s) {
	int acum=0;
	while(*s) {
		acum++;
		s++;
	}
	return(acum);
}

void main() {
	char *string=NULL;
	char name[10];

	name[0]='R';
	name[1]='i';
	name[2]='c';
	name[3]='a';
	name[4]='r';
	name[5]='d';
	name[6]='o';
	name[7]='\0';

	printf("Type a string %s: ",name);
	string = getAnArbitraryLargeStringFromTheKeyboard();

	printf("\n%s you typed: %s (%d)\n",name,string,stringLength(string));

	free(string);
}