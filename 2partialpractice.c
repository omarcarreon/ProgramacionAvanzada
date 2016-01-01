#include <stdio.h>
#include <string.h>

char *strikethroughAWordInTheString(char *str, char *sub){
	char *p1, *p2, *p3,*p4=NULL,*p5=NULL;
	int i=0,j=0,k=0,flag=0;

	p1 = str;
	p2 = sub;

	for(i = 0; i<strlen(str); i++)
	{
	if(*p1 == *p2)
	  {
	      p3 = p1;
	      for(j = 0;j<strlen(sub);j++)
	      {
	        if(*p3 == *p2)
	        {
	          p3++;p2++;
	        } 
	        else
	          break;
	      }
	      p2 = sub;
	      if(j == strlen(sub))
	      {
	        flag = 1;
	        printf("\nSubstring found at index : %d\n",i);
	        p4=str;
	        for(k=0;k<i;k++){
	        	p4++;
	        }
	        p5=p4;
	        int length2 = strlen(sub);
	        for (int k=0; k<length2;k++){
	        	*p5='-';
	        	p5++;
	        	p4++;
	        }
	        while (*p4!='\0'){
	        	*p4=*p3;
	        	p4++;
	        	p5++;
	        }
	        while(*p5!='\0'){
	        	printf("%s\n",*p5);
	        	p5++;
	        }
	  		
			break;
	      }
	  }
	p1++; 
	}
	if(flag==0)
	{
	   printf("Substring NOT found");
	   return NULL;
	}
	return (p4);
}
char *getFirstNumber(int number,char *string1){
	switch(number){
		case 1:
			strcat(string1,"one");
			break;
		case 2:
			strcat(string1,"two");
			break;
		case 3:
			strcat(string1,"three");
			break;
		case 4:
			strcat(string1,"four");
			break;
		case 5:
			strcat(string1,"five");
			break;
		case 6:
			strcat(string1,"six");
			break;
		case 7:
			strcat(string1,"seven");
			break;
		case 8:
			strcat(string1,"eight");
			break;	
		case 9:
			strcat(string1,"nine");
			break;
	}
	return string1;
}
char *getSecondNumber(int number,char *string2){
	switch(number){
		case 2:
			strcat(string2,"twenty");
			break;
		case 3:
			strcat(string2,"thirty");
			break;
		case 4:
			strcat(string2,"forty");
			break;
		case 5:
			strcat(string2,"fifty");
			break;
		case 6:
			strcat(string2,"sixty");
			break;
		case 7:
			strcat(string2,"seventy");
			break;
		case 8:
			strcat(string2,"eighty");
			break;	
		case 9:
			strcat(string2,"ninety");
			break;
	}
	return string2;
}
char *getThirdNumber(int number,char *string3){
	switch(number){
		case 11:
			strcat(string3,"eleven");
			break;
		case 12:
			strcat(string3,"twelve");
			break;
		case 13:
			strcat(string3,"thirteen");
			break;
		case 14:
			strcat(string3,"fourteen");
			break;
		case 15:
			strcat(string3,"fifteen");
			break;
		case 16:
			strcat(string3,"sixteen");
			break;
		case 17:
			strcat(string3,"seventeen");
			break;	
		case 18:
			strcat(string3,"eighteen");
			break;
		case 19:
			strcat(string3,"nineteen");
			break;
	}
	return string3;
}
void numberToText(int number,char *text){
	int res, secondres;
	char str1[20]="",firstaux[]="",secondaux[]="",str2[20]="";
	if (number>=0 && number<=9){
		res = number % 10;
	} else if(number>10 && number<20){
		strcpy(str1,getThirdNumber(number,firstaux));
		strcpy(str2,str1);
	} else if (number>20 ){
		res = number % 10;
		strcpy(str1,getFirstNumber(res,firstaux));
		secondres = number /10;
		strcpy(str2,getSecondNumber(secondres,secondaux));
		strcat(str2," ");
		strcat(str2,str1);
	}
	
	printf("%s\n",str2);
}

int validatePassword(char g*password, char *errorMessage){
	int contUpper=0,contDigits=0, contAll=0,size=0;
	while (*password !='\0'){
		if ((*password>='A' && *password <='Z')||(*password>='a' && *password<='z') || (*password>='0' && *password<='9')){
			if (*password>='A' && *password <='Z'){
			contUpper++;
			}
			if (*password>='0' && *password <='9'){
				contDigits++;
			}
			contAll++;
		}
		password++;
	}
	if (contAll<10){
		strcat(errorMessage,"Less than 10");
		size=0;
	} else if (contDigits<4){
		strcat(errorMessage,"Needs 4 digits");
		size=0;
	}else if (contUpper<1){
		strcat(errorMessage,"Needs 1 uppercase");
		size=0;
	}else{
		size=contAll;
	}
	return size;
}
char *reverseString(char *string){
	int length, c;
	char *begin, *end, temp;

	length = strlen(string);

	begin = string;
	end = string;

	for (c=0;c<length-1;c++ )
	  end++;

	for (c=0;c<length/2;c++ ) 
	{        
	  temp = *end;
	  *end = *begin;
	  *begin = temp;

	  begin++;
	  end--;
	}
	return string;
}

int main(){
	char str[] = "String1 subString1";
	char sub[] = "subString";
	char error[]="";
	char text[] = "";
	printf("%s\n",strikethroughAWordInTheString(str,sub));
	//numberToText(17,text);
	//printf("%s\n", text);
	//printf("%s\n",reverseString(sub));
	//printf("%d\n",validatePassword(sub,error));
	//printf("%s\n",error );
	//printf("Reversed string: %s\n",sub );
}









