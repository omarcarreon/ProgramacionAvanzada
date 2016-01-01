#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct _persona {
	int id;
	char *name;
	char *last;
	struct _persona *next;
};

struct _persona *list=NULL;

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

void sortByID() {
	struct _persona *newList = NULL;
	struct _persona *largestNode=NULL;
	struct _persona *prevToLargestNode=NULL;
	struct _persona *checkingNode=NULL;
	struct _persona *prevToCheckingNode=NULL;

	while(list != NULL) {
		//Find the largest node of the (original) list
		largestNode=list;
		prevToLargestNode=NULL;
		checkingNode=list->next;
		prevToCheckingNode=list;
		while(checkingNode) {
			if (largestNode->id<checkingNode->id) {
				largestNode=checkingNode;
				prevToLargestNode=prevToCheckingNode;
			}
			prevToCheckingNode=checkingNode;
			checkingNode=checkingNode->next;
			//Why no checkingNode++; ... Eeeeh?
		}
		//Finally I got the largest node in the largestNode variable ... get it to the newList!!!
		if (largestNode!=NULL) {	//Oooh, yes ... just to make sure :)
			if (prevToLargestNode)	//If not NULL ... because if it happens to be NULL AGGGHH!
				prevToLargestNode->next=largestNode->next;
			else
				list=largestNode->next;	//Well is not AGGGHH ... just update the original list correctly!
			largestNode->next=newList;
			newList=largestNode;
		}
	}
	list = newList;
}

void main() {
	int i, j, count=0;
	struct _persona *auxListPtr=NULL;
	struct _persona *node=NULL;
	int auxId=1;

	for (i=0;auxId!=0;i++) {
		printf("Get me the studentList ID: ");
		scanf("%d",&auxId);
		if (auxId!=0) {
			count++;
			node = (struct _persona *) malloc(sizeof(struct _persona));
			node->id = auxId;
			printf("Get me the name: ");
			node->name = getAnArbitraryLargeStringFromTheKeyboard();
			printf("Get me the lastname: ");
			node->last = getAnArbitraryLargeStringFromTheKeyboard();
			if (list==NULL) {
				list=node;
				node->next=NULL;
			} else {
				node->next=list;
				list=node;
			}
		}
	}

	sortByID();

	auxListPtr = list;
	while(auxListPtr) {
		printf("%d\t%s\t%s\n",auxListPtr->id,auxListPtr->name,auxListPtr->last);
		auxListPtr = auxListPtr->next;
	}

	while(list) {
		auxListPtr = list;
		list=list->next;
		free(auxListPtr->name);
		free(auxListPtr->last);
		free(auxListPtr);
	}
}