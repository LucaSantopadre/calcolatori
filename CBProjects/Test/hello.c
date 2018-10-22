#include <stdio.h>

void restoDivisione();
void minMaxMedia();
int minimo(int A[],int i,int n);

int main(void){
	int x;
	printf("Quale esercizio vuoi eseguire?\n");
	scanf("%d",&x);
	switch(x){
		case 1:
		       restoDivisione();
		case 2:
			minMaxMedia();
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
	printf("%d%d%d\n",arr[0],arr[1],arr[2]);

	int n=3,min,i,temp;
	for(i=1;i<n;i++){
		printf("%d\n",i);
		min = minimo(arr,i,n);
		temp=arr[i];
		arr[i]=arr[min];
		arr[min]=temp;
	}

	printf("%d%d%d\n",arr[0],arr[1],arr[2]);
}

int minimo(int A[],int i,int n){
	int min=0,j;
        min=i;
	for(j=i+1;j<n;j++){
		if(A[j]<A[min]){
			min=j;
		}
	}
	return min;
}

