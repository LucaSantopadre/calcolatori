#include <stdio.h>
#include <stdlib.h>
char verificaOrdinato(int A[],int n);
void chiamaEs12();
void chiamaEs14();
void chiamaES16();
void chiamaEs18();
void scambia(int A[],int n,int x,int y,int a, int b);
void stampaArray(int A[],int n);
void chiamaEs20();
void chiamaEs24();
void verificaDetPos(int **A,int i,int j);

void main(){
	//chiamaEs12();
	//chiamaEs14();
	//chiamaES16();
	//chiamaEs18();
	//chiamaEs20();
	chiamaEs24();
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
// --------------------------------------------------------------

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

// ------------------------------------------------------------

void chiamaES16(){
	int v[6]={10,12,20,5,84,9};
	int *u[6];
	
	int min,i,j,*pmin;
	min=v[0];
	pmin = &v[0];
	for(i=1;i<6;i++){
		for(j=0;j<6;j++){
			printf("pmin : %p\n",pmin);
			if(v[j]<min && u[i-1]!=u[i] ){
				printf("u[i-1]!=u[i] , %p != %p\n",u[i-1],u[i]);
				min = v[j];
				pmin=&v[i];
			}
		}
		printf("minimo: %d\n",min);
		u[i-1]=pmin;
		min = v[i];
	}
		
}
				
// ---------------------------------------------------------------------

void chiamaEs18(){
	int i,j,n,temp;
	// dimensione matrice
	printf("Inserisci la dimensione N della matrice NxN\n");
	scanf("%d",&n);

	int A[n][n];
	// inserisco la matrice
	for(i=0;i<n;i++){
		printf("Inserisci la %d riga\n",i);
		for(j=0;j<n;j++){
			scanf("%d",&A[i][j]);
		}
	}
	// stampo la matrice
	printf("matrice inserita:\n");
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        printf("%d  ",A[i][j]);
                }
                printf("\n");
        }
	// controllo se è diagonale
	printf("controllo se è diagonale...\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				continue;
			}else{
				if(A[i][j]!=0){
					printf("NON è una matrice diagonale\n");
					printf("Problema sull' elemento in pos: %d  %d\n",i,j);
					return;
				}
			}
		}
	}
	printf("E' una matrice diagonale");
	return;
}

// ------------------------------------------------------------

void chiamaEs20(){
	int M,N,P;
	// dimensione matrici
	M=2;
	N=3;
	P=2;
	// inserisco le 2 matrici
	int A[2][3]={{1,0,2},{0,3,-1}};
	int B[3][2]={{4,1},{-2,2},{0,3}};
	
	// stampo le matrici
	int i,j;
	printf("matrice A:\n");
        for(i=0;i<M;i++){
                for(j=0;j<N;j++){
                        printf("%d  ",A[i][j]);
                }
                printf("\n");
        }
        printf("matrice B:\n");
        for(i=0;i<N;i++){
                for(j=0;j<P;j++){
                        printf("%d  ",B[i][j]);
                }
                printf("\n");
        }
	// prodotto 
	printf("calcolo prodotto\n");
	int k,prodotto=0,sum=0;
	int C[2][2];

	for(i=0;i<M;i++){
		for(k=0;k<P;k++){
			prodotto=0;
			for(j=0;j<N;j++){
				printf("A[i][j] * B[j][k] :  %d * %d\n",A[i][j],B[j][k]);
				prodotto=prodotto+A[i][j]*B[j][k];
				printf("prodotto: %d\n",prodotto);
			}
			C[i][k]=prodotto;
			printf("-----------------------\n");

		}
		printf("*************-----------------------\n");
	}
	
	printf("MATRICE PRODOTTO:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}

}
// --------------------------------------------------------

void chiamaEs24(){
	int **A[4][3]={{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	int i,j,M,N;
	M=4;
	N=3;

	printf("MATRICE: \n");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<M-1;i++){
		for(j=0;j<N-1;j++){
			verificaDetPos(A,i,j);
		}
	}
}

void verificaDetPos(int **A,int i,int j){
	int a,b,c,d;
	a=A[i][j];
	b=A[i][j+1];
	c=A[i+1][j];
	d=A[i+1][j+1];

	printf("%d %d \n %d %d",a,b,c,d);


}



