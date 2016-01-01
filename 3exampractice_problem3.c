#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

HINSTANCE hCodigoDll;
FILE *ptrFile;
FILE *ptrOutput;

typedef char* (getLineFromFile)(FILE);
typedef char* (readAnySizeString)();
getLineFromFile* ptrGetLineFromFile=NULL;
readAnySizeString* ptrReadAnySizeString=NULL;

void main() {
	//Explicit inclusion: Upload the DLL from disk to memory
	if (hCodigoDll = LoadLibrary("file.dll")) {
		ptrGetLineFromFile=(getLineFromFile *)GetProcAddress(hCodigoDll ,"getLineFromFile");
		ptrReadAnySizeString =(readAnySizeString *)GetProcAddress(hCodigoDll ,"readAnySizeString");
		if (ptrGetLineFromFile && ptrReadAnySizeString) {
			char *line = NULL;
			ptrFile=fopen("C:\\Users\\Omar\\Desktop\\file.txt","r");
			ptrOutput=fopen("C:\\Users\\Omar\\Desktop\\file2.txt","a");
		
			line=(*ptrGetLineFromFile)(ptrFile);
			fprintf(ptrOutput, "%s",line);
			

		

		} else
			printf("ERROR: Routine not found!\n");
	} else
		printf("ERROR: Library not found!\n");
	FreeLibrary(hCodigoDll);

	getchar();
}
