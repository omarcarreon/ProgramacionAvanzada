#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <string.h>

FILE *ptrFile;
char chr;

char *getLineFromFile(FILE *f) {
	char *elString,*elStringAuxiliar;
	int incrementoEspacio=10;
	int espacioActual=10;
	int tamanioActual=0;
	char chr=0;

	elString = (char *)malloc(espacioActual);
	*elString='\0';
	while ( (!feof(f)) && (chr!=13) ) {
		chr=fgetc(f);
		printf("%c",chr);

		*(elString+tamanioActual)=chr;
		tamanioActual++;
		if (tamanioActual>=espacioActual) {
			elStringAuxiliar=(char *)malloc(espacioActual+incrementoEspacio);
			memcpy(elStringAuxiliar,elString,espacioActual);
			espacioActual += incrementoEspacio;
			free(elString);
			elString=elStringAuxiliar;
		}
		*(elString+tamanioActual)='\0';
	}
	if (chr==13)
		fgetc(f);	
	return(elString);
}


 

int main(int argc, char *argv[]) {
	char *fname = argv[1];
	char *word = argv[2];
	char *line = NULL;
	char *auxline = NULL;
	char *find = NULL;
	int size;
	int num;

	ptrFile=fopen(fname,"r");
	if (ptrFile!=NULL) {
		line = getLineFromFile(ptrFile);
		size = strlen(line);
		if (fclose(ptrFile) == 0){
            printf("Archivo cerrado\n");
		}else{
            printf("Error al cerrar el archivo\n");
		}
	} else {
		printf("Error al abrir el archivo \n");
	}

	ptrFile = fopen(fname, "w");
	if (ptrFile!=NULL) {
		find = strstr(line,word);
		if(find!=NULL){
			strcpy (find,find + strlen(word));
		}
		
		fwrite(line,sizeof(char),strlen(line),ptrFile);

		 if (fclose(ptrFile) == 0)
            printf("Archivo cerrado\n");
        else
            printf("Error al cerrar el archivo\n");
	} else {
		printf("Error al abrir el archivo \n");
	}
	printf("\n");
	fclose(ptrFile);
	
}
