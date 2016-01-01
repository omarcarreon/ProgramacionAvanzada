#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double asciiToDouble(char *s);
int asciiToInt(char *s);
int stringLength(char *s);
int auxValidateDouble(char *s);
void main(){
	char *input = malloc(sizeof(char));
	char *auxfirstpart;
	int indexDot,iCheck=0;
	double acum=0.0;
	while (1){
		printf("%s\n","Enter number");
		scanf("%s",input);

		// find decimal point
		auxfirstpart =strchr(input,'.');
		// index of decimal point
		indexDot = (int)(auxfirstpart - input);
		if (auxfirstpart=='\0'){
			iCheck = asciiToInt(input) * 1.0;
			if (iCheck != -1){
				acum += iCheck;
			} else{
				printf("%s\n","Wrong input");
			}
		} else{
			if (auxValidateDouble(input)){
				acum += asciiToDouble(input);
			} else{
				printf("%s\n","Wrong input");
			}
			
		}
		printf("Accumulated= %f\n",acum );
	}
	
	

}
int auxValidateDouble(char *s){
	int valid=0;
	while (*s!='\0'){
		if ((*s=='.') || ((*s>='0') && (*s<='9'))){
			valid = 1;
		} else{
			return 0;
		}
		s++;
	}
	return valid;
}
int stringLength(char *s){
	int acum=0;
	while (*s!='\0'){
		acum++;
		s++;
	}
	return acum;
}
double asciiToDouble(char *s){
	 double answer = 0.0;
	 char *auxfirstpart;
	 int indexDot,i,iAcum=0, iSecondAcum=0;
	 double decimalindex= 1,decimalacum=0;
	 int isNegative = 0;
	 // checks symbol and checks if the input is invalid
	 if (*s=='-'){
	 	isNegative = 1;
	 	s++;
	 } else if (*s=='+'){
	 	s++;
	 } else if (!(*s>='0' && *s<='9')){
	 	return answer;
	 }
	 // finds the decimal point
	 auxfirstpart =strchr(s,'.');
	 // index of decimal point
	 indexDot = (int)(auxfirstpart - s);
	 if (indexDot<0){
	 	indexDot = stringLength(s);
	 }
	 // convert integer part of input to integer
	 for (i=0;i<indexDot;i++){
	 	if (*s>='0' && *s<='9'){
	 		iAcum = (iAcum * 10) +(*s - '0');
	 		s++;
	 	} else{
	 		return iAcum * 1.0;
	 	}
	 }
	 // integer part to double
	 answer = iAcum * 1.0;
	 // moves one position because of decimal point
	 s++;

	 // decimal part string to decimal number
	 while (*s!='\0'){
	 	if (*s>='0' && *s<='9'){
	 		iSecondAcum = (iSecondAcum * 10) +(*s - '0');
	 		decimalindex = decimalindex / 10.0;
	 		decimalacum = (iSecondAcum*1.0) * decimalindex;
	 		s++;
	 	} else{
	 		return answer + decimalacum;
	 	}
	 	
	 }
	 //
	 answer = answer + decimalacum;
	if (isNegative){
		answer = answer * -1.0;
	}

    return answer;

}

int asciiToInt(char *s){
	int iAcum=0,i;
	int length=stringLength(s);
	for (i=0;i<length;i++){
	 	if (*s>='0' && *s<='9'){
	 		iAcum = (iAcum * 10) +(*s - '0');
	 		s++;
	 	} else{
	 		return -1;
	 	}
	 }
	 return iAcum;
}
