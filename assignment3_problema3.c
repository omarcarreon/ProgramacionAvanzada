#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double asciiToDouble(char *s);
int stringLength(char *s);

void main(){
	char ascii[50] = "";
	scanf("%s",&ascii);
	//printf("%d\n",asciiBinaryToInt(ascii));
	//printf("%d\n",asciiHEXToInt(ascii));
	printf("%f\n",asciiToDouble(ascii));
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