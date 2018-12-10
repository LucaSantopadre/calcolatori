#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lunghezza(char *s);

int main(){
	char *s=malloc(20*sizeof(char));
       	s="prova";	
	//s[0]='X';
	//strcat(s,"ciao");
	//
	char b = getchar();
	int l;
	l=strlen(s);
	//l=sizeof(s)/sizeof(char);

	printf("STRINGA: %s\nLUNGHEZZA:%d\n",s,l);
	printf("---------------------\n\n\n");

	//--------------------------

	char *p="popopopopopo";
	int n = sizeof(p);
	printf("NO:dimensione con sizeof(p): %d\n",n);

	n= lunghezza(p);
	printf("OK:dimensione con lunghezza(p): %d\n",n);
	//------------------------
	
	char *pointer;
	pointer = malloc(sizeof(char));

	pointer[0]='s';
	pointer[1]='a';
	pointer[5]='t';

	char *prova = "text";

	printf("stringa: %s\n",pointer);

	strncat(pointer,prova,4);
	
	printf("stringa: %s\n",pointer);

	int len;
	len = lunghezza(pointer);
	printf("lunghezza : %d\n",len);

	int sizePoint = sizeof(pointer);
        printf("dimensione con sizeof(pointer): %d\n",sizePoint);

}

int lunghezza(char *s){
	int l =0;
	while(s[l] != '\0'){
		l++;
	}

	return l;
}
