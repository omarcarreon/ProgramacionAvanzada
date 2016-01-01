#include <stdio.h>
#include <stdlib.h>

char *getSubstring(char *, int, int);
char string[] = "Tec de Monterrey, campus Cancun";
char *findSubstring(char *, char *s);

int main(){
	char *auxString = NULL;
	printf("I study ITC/ISD at %s\n",string);
	auxString = getSubstring(&string[0],7,9);
	printf("And I live in %s city\n", auxString);
	printf("... as i told you before, I study at %s\n",string);

	if(findSubstring(string,"rey")){
		printf("Match\n");
	}else{
		printf("No Match\n");
	}

	free(auxString);
}
//No hay manera de obtener de nuevo el string original ya que lo modifica permanentemente.
/*
char *getSubstring(char *s, int offset, int size){
	*(s+offset+size)='\0';
	return(s+offset);
}
*/
char *getSubstring(char *s, int offset, int size){
	char *subS = NULL;
	subS = (char *)malloc(size+1);
	int i;
	for (i=0;i<size;i++){
		*(subS+i)=*(s+offset+i);
	}
	*(subS+i) = '\0';
	return (subS);
}

/*
	3 types of memory to use:
	-> Statically allocated
	->STACK (local variables and parameters)
	-> HEAP

*/
 char *findSubstring(char *s, char *ss){
 	char *auxS = NULL;
 	char *auxSs = NULL;
 	while (*s!='\0'){
 		auxS = s;
 		auxSs = ss;
 		while ((*auxSs != '\0') && (*auxSs==*auxSs)){
 			auxS++;
 			auxSs++;
 		}
 		if (*auxSs=='\0'){
 			//MATCH
 			return(s);
 		}
 		s++-; 	
	 }
 }
