#include <stdio.h>
#include <ctype.h>

void restoDivisione();
void minMaxMedia();
void insertionSort(int A[],int n);
void fibonacci();
void verificaCarattere();

int main(void){
	int x;
	printf("Quale esercizio vuoi eseguire?\n");
	scanf("%d",&x);
	switch(x){
		case 1:
		       restoDivisione();
		case 2:
			minMaxMedia();
	 	case 3:
			fibonacci();
		case 4:
			verificaCarattere();		
	}
        return 0;
}


void restoDivisione(){
        int resto=0,M,N,i;
        printf("inserisci 2 numeri:\n");
        scanf("%d%d",&M,&N);

        for(i=0;i<N;i++){
                resto=i%M;
                printf("%d mod %d = %d\n",i,N,resto);
        }
}

void minMaxMedia(){
	int arr [3];
	printf("Inserisci 3 numeri:\n");
	scanf("%d%d%d",&arr[0],&arr[1],&arr[2]);
	
	insertionSort(arr,3);

	printf("minimo : %d\n",arr[0]);
	printf("massimo : %d\n",arr[2]);

	float m;
	m=((float)arr[0]+(float)arr[1]+(float)arr[2])/3;
	printf("media : %f\n",m);
}

void insertionSort(int A[],int n){
	int k,i,x,j;
	for(k=1;k<n;k++){
		x=A[k];
		
		for(i=k;i>-1;i--){
			j=i;
			if(x<A[i-1]){
				A[i]=A[i-1];
			}
		}
		A[j]=x;
	}	
}


void fibonacci(){
	int n;
	printf("fibonacci:inserisci 1 numero:\n");
        scanf("%d",&n);
	int a=1,b=1,c,i;
	for(i=2;i<n;i++){
		c=a+b;
		a=b;
		b=c;
		printf("%d\n",b);
	}	
}

void verificaCarattere(){
	int a;
	printf("verificaCarattere:inserisci 1 carattere\n");
        scanf("%d",&a);

	if(isalpha(a)){
		printf("SI\n");
	}
}


