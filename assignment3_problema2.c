#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int asciiHEXToInt(char *s);
int stringLengthModified(char *s);

void main(){
	char ascii[50] = "";
	scanf("%s",&ascii);
	printf("%d\n",asciiHEXToInt(ascii));
}
int stringLengthModified(char *s){
	int acum=0;
	while (*s!='\0' && ( (*s>='0' && *s<='9') || (*s>='A' && *s<='F') || (*s>='a' && *s<='f'))){
		acum++;
		s++;
	}
	return acum;
}

int asciiHEXToInt(char *s){
	int dec = 0;
	int value = 0;
	int i, length=stringLengthModified(s);
	if (length<=8){
		for (i=length-1;i>=0;i--){
			switch(*s){
				case '0':
					dec += 0 * pow(16,i);
					break;
				case '1':
					dec += 1 * pow(16,i);
					break;
				case '2':
					dec += 2 * pow(16,i);
					break;
				case '3':
					dec += 3 * pow(16,i);
					break;
				case '4':
					dec += 4 * pow(16,i);
					break;
				case '5':
					dec += 5 * pow(16,i);
					break;
				case '6':
					dec += 6 * pow(16,i);
					break;
				case '7':
					dec += 7 * pow(16,i);
					break;
				case '8':
					dec += 8 * pow(16,i);
					break;
				case '9':
					dec += 9 * pow(16,i);
					break;
				case 'A':
					dec += 10 * pow(16,i);
					break;
				case 'a':
					dec += 10 * pow(16,i);
					break;
				case 'B':
					dec += 11 * pow(16,i);
					break;
				case 'b':
					dec += 11 * pow(16,i);
					break;
				case 'C':
					dec += 12 * pow(16,i);
					break;
				case 'c':
					dec += 12 * pow(16,i);
					break;
				case 'D':
					dec += 13 * pow(16,i);
					break;
				case 'd':
					dec += 13 * pow(16,i);
					break;
				case 'E':
					dec += 14 * pow(16,i);
					break;
				case 'e':
					dec += 14 * pow(16,i);
					break;
				case 'F':
					dec += 15 * pow(16,i);
					break;
				case 'f':
					dec += 15 * pow(16,i);
					break;
				default:
					dec = -1;
					break;
			}
			s++;
		}
	} else {
		printf("%s\n","ERROR. The maximum string length is 8 characters");
		dec = -1;
	}
	
	return dec;
}