#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct _persona {
	int id;
	char *name;
	char *last;
};

char *getAnArbitraryLargeStringFromTheKeyboard() {
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
			if ((size+1)==maxSize) {	//Increase the real size of the string
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

void sortByID(struct _persona *list, int size) {
	int i, j;
	struct _persona temporal;

	for (i=0; i<size-1; i++) {
		for (j=i+1; j<size; j++) {
			if (list[i].id > list[j].id) {
				memcpy(&temporal,&list[i],sizeof(struct _persona));
				memcpy(&list[i],&list[j],sizeof(struct _persona));
				memcpy(&list[j],&temporal,sizeof(struct _persona));
			}
		}
	}
}

void main() {
	int i, j, count=0;
	struct _persona *studentList=NULL;
	struct _persona *auxStudentList=NULL;
	int maxCount=5;
	int auxId=1;

	studentList = (struct _persona *) malloc(maxCount*sizeof(struct _persona));
	for (i=0;auxId!=0;i++) {
		printf("Get me the studentList ID: ");
		scanf("%d",&auxId);
		if (auxId!=0) {
			count++;
			if (count==maxCount) {
				auxStudentList = (struct _persona *) malloc((maxCount+5)*sizeof(struct _persona));
				for (j=0;j<count;j++) {
					auxStudentList[j].id = studentList[j].id;
					strcpy(auxStudentList[j].name,studentList[j].name);
					strcpy(auxStudentList[j].last,studentList[j].last);
				}
				maxCount+=5;
				free(studentList);
				studentList = auxStudentList;
			}
			studentList[i].id=auxId;
			printf("Get me the name: ");
			studentList[i].name = getAnArbitraryLargeStringFromTheKeyboard();
			printf("Get me the lastname: ");
			studentList[i].last = getAnArbitraryLargeStringFromTheKeyboard();
		}
	}

	sortByID(studentList,count);

	for (i=0;i<count;i++) {
		printf("%d\t%s\t%s\n",studentList[i].id,studentList[i].name,studentList[i].last);
	}

	for (i=0;i<count;i++) {
		free(studentList[i].name);
		free(studentList[i].last);
	}
	free(studentList);
}