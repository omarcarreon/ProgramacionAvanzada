1. Double pointers are useful to pass a reference of the list that contains elements for a routine to work with, with the option to modify the original reference to the list


2.

createNewNode(struct _persona **l){
	struct _persona *list = *l;
	struct _persona = *newNode;

	newNode = (struct persona *) malloc (sizeof (struct _persona));
	newNode -> ID = getID();
	newNode -> FName = getFirstName();
	newNode -> LName = getLastName();
	newNode -> next = list;
	list = newNode;
	*l = list;
}


void main(){
	char *myString = (char *) malloc(20);
	.
	.
	.
	IncreaseAllocatedSpaceForMyString(&myString,20);
	.
	.
	.
	free(myString);
}

void IncreaseAllocatedSpaceForMyString(char *str, int extraSpace){
	char *auxS = NULL;
	char *s = *str;
	if (s){
		auxS = (char *)malloc (strlen(s) + extraSpace);
		strcpy (auxS, s);
		free (s);
		*str = auxS;
	}
}


3.
		
				Static														Dynamic
	- Require it at compile time							- Require it at execution time.
	- Cal the routines from your source code 				- Need to upload the library and locate the routines
	  without the need of locating the library				  you need to call (code overhead)
	  														- Good option for the automatic updates

5.
soname: implementation of Dynamic libraries en linux
Dynamic linker for? For you to not worry about to upload your libraries in application neither to locate the function. Don't need to explicity locate the library
