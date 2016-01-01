#include <stdio.h>
#include <math.h>

int asciiBinaryToInt(char *s);
int stringLength(char *s);

void main(){
	char ascii[50] = "";
	scanf("%s",&ascii);
	printf("%d\n",asciiBinaryToInt(ascii));
}
int stringLength(char *s){
	int acum=0;
	while (*s!='\0' && (*s=='0' || *s=='1')) {
		acum++;
		s++;
	}
	return acum;
}
int asciiBinaryToInt(char *s){
	int length = stringLength(s);
	int answer= 0;
	if (length<=32){
		for (int i=length;i>=1;i--){
			if (*s!='\0' && (*s=='0' || *s=='1')) {
						if (*s=='1'){
							answer += pow(2,i-1);
						}
					
			} else{
				return answer;
			}
			s++;
		}
	} else {
		printf("%s\n","ERROR. The maximum string length is 32 characters");
		answer = -1;
	}
	
	return answer;
}