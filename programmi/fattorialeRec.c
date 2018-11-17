#include <stdio.h>
#include <stdlib.h>

int fattoriale(int n);

int main(){
	int res;
	res = fattoriale(3);
	printf("fattoriale di 3: %d\n",res);
	return 0;
}

int fattoriale(int num){
	if(num == 0){
		return 1;
	}else{
		return num * fattoriale(num-1);
	}
}
