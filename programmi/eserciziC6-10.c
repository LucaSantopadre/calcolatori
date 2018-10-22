#include <stdio.h>
#include <string.h>

void converti(int n ,int b);
void conta();

int main(void){
	/*
	int x,val,b;
	printf("inserisci valore decimale e la base:\n");
	scanf("%d%d",&val,&b);
	converti(val,b);
	printf("\n");
	*/
	
	conta();

}

// converte ricorsivamente un numero da decimale in base b
void converti(int n,int b){
	int r,m;
	r=n/b;
	if(r>0){
		converti(r,b);
	}
	printf("%d",n%b);
}

void conta(){
	FILE *file;
	int i,car=0,par=0,rig=0;
	char nomeFile[100];
	char c;

	printf("Inserisci nome file\n");
	scanf("%s",nomeFile);
	file=fopen(nomeFile,"r");

	if(file == NULL){
		printf("ATTENZIONE nome file non valido");
		return;
	}
	for( c=getc(file) ; c!= EOF ; c=getc(file)){
		
		if(c!=' ' &&  c!='\n'){
			car++;
		}
		if(c==' ' || c=='\n'){
			
			par++;
		}
		if(c=='\n'){
			rig++;
		}
	}
	printf("caratteri: %d\nparole: %d\nrighe: %d\n",car,par,rig);
	

}
