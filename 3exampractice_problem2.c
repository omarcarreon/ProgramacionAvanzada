#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

FILE *ptrFile;

char* getLineFromFile(FILE *arch){
	char chr=0;
	char *string=NULL;
	int maxSize=1;
	int size=0;
	char *auxString=NULL;
	
	if (ptrFile!=NULL) {
		string = (char *)malloc(1);
		*string='\0';
		chr = (char)(getc(arch));

		while (chr!=10 && !feof(arch)) {
			if ((size+1)==maxSize) {
				auxString=(char *)malloc(maxSize+1);
				maxSize+=1;
				strcpy(auxString,string);
				free(string);
				string=auxString;
			}
		
			string[size]=chr;
			string[++size]='\0';
			chr = (char)(getc(arch));
		}
	}
	
	return(string);
}

char *readAnySizeString() {
	char *string=NULL;
	int maxSize=5;
	int size=0;
	char chr=0;
	char *auxString=NULL;

	string = (char *)malloc(5);
	*string='\0';
	chr=getch();
	while (chr!=13) {
		if (chr==8) {
			if (size!=0) {
				printf("%c %c",chr,chr);
				size--;
				string[size]='\0';
			}
		} else {
			if ((size+1)==maxSize) {
				auxString=(char *)malloc(maxSize+5);
				maxSize+=5;
				strcpy(auxString,string);
				free(string);
				string=auxString;
			}
			string[size]=chr;
			printf("%c",chr);
			string[++size]='\0';
		}
		chr=getch();
	}
	printf("\n");
	return(string);
}

 

int main() {
	
	char *line = NULL;
	ptrFile=fopen("C:\\Users\\Omar\\Desktop\\file.txt","r");
	if (ptrFile!=NULL){
			line = getLineFromFile(ptrFile);
	}
	fclose(ptrFile);
	system("pause");
}
