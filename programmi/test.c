#include <stdio.h>
#include <stdlib.h>

int main(){
	int a=9;
	int *p=malloc(sizeof(int));
	*p=a;
	printf("%d\n",*p);
}
