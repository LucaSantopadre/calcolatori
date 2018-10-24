#include <stdio.h>
char verificaOrdinato(int A[],int n);
void chiamaEs12();

void main(){
	chiamaEs12();
}

void chiamaEs12(){
	int A[5];
        int n,i;
        char result;

        n= sizeof(A)/sizeof(A[0]);
        printf("inserisci %d numeri: \n\n",n);
        for(i=0;i<n;i++){
                printf("inserisci numero in A[%d]\n",i);
                scanf("%d",&A[i]);
        }
        printf("\n");

        result = verificaOrdinato(A,n);
        printf("%c\n",result);

}

char verificaOrdinato(int A[],int n){
	printf("confronto A[n-2] %d > A[n-1] %d\n",A[n-2],A[n-1]);
	if(n<=2){
		return 's';
	}
	
	if(A[n-2]>A[n-1]){
		return verificaOrdinato(A,n-1);
	
	}else{
		return 'n';
	}
}
