#include <stdio.h>
#include <time.h>

int fibonacci2(int var);
int fibonacci3(int var);
int main(void){
	clock_t start,end;
	double tempo;		

	int f,n;

	printf("inserisci il numero di fibonacci che vuoi calcolare:\n");
	scanf("%d",&n);

	start = clock();
	f=fibonacci2(n);
	end=clock();
	tempo = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("%d fibonacci2 è: %d\n",n,f);
	printf("tempo clock impiegato : %f\n",tempo);

	printf("-------------------------\n");
	tempo=0;
	start = clock();
        f=fibonacci3(n);
        end=clock();
        tempo = ((double)(end-start))/CLOCKS_PER_SEC;
        printf("%d fibonacci3 è: %d\n",n,f);
        printf("tempo clock impiegato : %f\n",tempo);

	return 0;
}

int fibonacci2(int n){
	if(n<=2)
		return 1;
	else return fibonacci2(n-1) + fibonacci2(n-2);
}


int fibonacci3(int n){
	int a=1,b=1,c,i;
	for(i=3;i<n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}

