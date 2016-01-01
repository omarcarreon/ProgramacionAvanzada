int getStringLength(char *thestring){
	int cont;
	while (*thestring != '\0'){
		thestring++;
		cont++
	}
	return cont;
}

void main() {
	int farenheit;
	float celsius;
	scanf("%d", &farenheit);
	celsius = (farenheit-32.0)/1.8;
	printf("%.2f\n", celsius);
}
char *auxfindsubstring(char *string, char *substring){
	char *auxsub = substring;
	while (*string != '\0'){
		if (*string == *substring){
			string++;
			substring++;
			if (substring == '\0'){
				return string;
			}
		} else {
			string++;
			substring = auxsub;
		}
	}
}

 char *findSubstring(char *string, char *substring){
 	char *found = NULL;
 	while (*string != '\0') {
 		string = auxfindsubstring(&string, &substring);
 		if (string){
 			found = string;

 		}
 	}
 	if (found){
 		return found;
 	}
 	return NULL;
 }
