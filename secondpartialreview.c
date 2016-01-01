char *strikeThroughInTheString (char *string, char *word){
	char *match = NULL, *returning = NULL;
	int length;
	int i;
	match = strstr(string , word);
	returning = match;
	if (match == NULL){
		return NULL;
		length = strlen(word);
		for (i=0; i< length; i++){
			*match = '-';
		}
		return returning;	
	}
}

void numberToText (int n, char *text){
	char *units[] = {"zero","one","two","three","four", "five","six","seven","eight", "nine"};
	char *decimals[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eigthy","ninety"};
	char *exacts[] = {"zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eigthy","ninety"};
	char *others[] = {"","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eigtheen","nineteen"};
	if (n<10){
		strcpy (text,units[n]);
	} else if (n%10==0){
		strcpy(text,exacts[n/10]);
	} else if ( n<20){
		strcpy(text,others[n-10]);
	} else {
		strcpy(text,decimals[n/10]);
		strcat(text,units[n%10]);xº
	}
}