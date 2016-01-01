#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

FILE *ptrFile;
char chr;
char* getLineFromFile(FILE *arch){
	char *string=NULL;
	int maxSize=1;
	int size=0;
	char chr=0;
	char *auxString=NULL;

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
	
	return(string);
}

 

int main() {
	char *line = NULL;
	ptrFile=fopen("C:\\Users\\Omar\\Desktop\\file.txt","r");
	if (ptrFile!=NULL) {
		printf("File opened\n");
		line = getLineFromFile(ptrFile);
	} else {
		printf("Error opening file");
	}
	while (*line!='\0'){
		printf("%c",*line);
		line++;
	}
	printf("\n");
	fclose(ptrFile);
}
