#include <stdio.h>

void main(){

	//puntatori
	
	int a=19999999, *p;
	p = &a;

	printf("INDIRIZZO di a : %p\n",&a);
	printf("VALORE di a    : %d\n\n",a);

	printf("valore di *&a  : %d\n",*&a);
	
	printf("valore di *p   : %d\n",*p);
	printf("valore di p    : %p\n",p);
	printf("valore di &*p  : %p\n",&*p);
	//---------------------------------------
	printf("\n\n\n\n\n\n\n SIZEOF\n");
	//sizeof
	
	int *pi;

	printf("sizeof(pi)    %lu\n", sizeof(pi));
	printf("sizeof(int *) %lu\n", sizeof(int *)); 
	printf("sizeof(*pi)   %lu\n", sizeof(*pi));
	printf("sizeof(int)   %lu\n", sizeof(int));
	// --------------------------------------

}
