#include <stdio.h>
char verificaOrdinato(int A[],int n);
void chiamaEs12();
void chiamaEs14();
void scambia(int A[],int n,int x,int y,int a, int b);
void stampaArray(int A[],int n);

void main(){
	//chiamaEs12();
	chiamaEs14();
}

void chiamaEs14(){
	int i,n;
	// crea array -------------------
        printf("Inserisci dimensione array\n");
        scanf("%d",&n);
	int A[n];

        for(i=0;i<n;i++){
                printf("valore A[%d]:  ",i);
                scanf("%d",&A[i]);
        }
	// ------------------------------
	stampaArray(A,n);
	scambia(A,n,0,n-1,0,0);
	stampaArray(A,n);
}


void scambia(int A[],int n,int x,int y,int a, int b){
	if(x>n/2-1){
		return;
	}else{
		a=A[x];
		b=A[y];
		A[x]=b;
		A[y]=a;
		scambia(A,n,x+1,y-1,a,b);
	}
}

void stampaArray(int A[],int n){
	int i;
        for(i=0;i<n;i++){
                printf("%d ",A[i]);
        }
        printf("\n");
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
