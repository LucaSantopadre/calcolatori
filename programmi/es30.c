#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int verificaStringaMatrice(char *s, int k, int len,  char **mat, int i, int j, int x, int y){
	printf("mat[%d][%d]  == s[%d]   -  %c == %c  \n",x, y, k,      mat[x][y],s[k]);


	if( k >= len - 1){
		return mat[x][y] == s[k];
	}
	

	if( mat[x][y]==s[k]){
		return verificaStringaMatrice(s, k+1, len,  mat, i, j , x, y+1 );// mat[x][y+1]	
	}else{
		return verificaStringaMatrice(s, k, len,  mat, i, j , x+1, y );// mat[x+1][y]
	}
	return 0;
}


void printMat(char **mat, int i, int j){
	int x=0;
	int y=0;
	for(x = 0 ; x<i; x++){
		for(y=0; y<j; y++){
			printf("%c ", mat[x][y]);
		}
		printf("\n");
	}
}



void printMat3(char *mat, int i, int j){
	int x=0;
	int y=0;
	for(x = 0 ; x<i; x++){
		for(y=0; y<j; y++){
			printf("%c ", mat[x*j +  y]);
		}
		printf("\n");
	}
}



int main(){
	// stringa
	char *str = "ciao";
	int len = strlen(str);

	// matrice i*j
	int i = 4;
	int j = 4;

	char **mat;
	mat = (char **) malloc(i *  sizeof(char *));
	
	// ---------- 1 -------------------
	int x;
	for( x = 0; x < j; x++){
		mat[x] = malloc(j * sizeof(char));
	}	
	// ---------------------------------

	/* ---------- 2 --------------
	mat[0] = (char *) malloc(i * j * sizeof(int));
	int x;
	for( x = 1; x < i; x++){
		mat[x] = mat[0] +  x * i;
	}
	-----------------------------*/

	mat[3][0] = 'c';
	mat[3][1] = 'i';
	mat[3][2] = 'a';
	mat[3][3] = 'Y';

	printMat(mat, i, j);


	
	/* ---------- 3 -------------
	 * -------------------------
	char *mat;
	mat = (char *)malloc(i * j * sizeof(int));
	mat[0*j + 0] = 'c';
	mat[0*j + 1] = 'i';
	mat[0*j + 2] = 'a';
	mat[0*j + 3] = 'o';
	printMat3(mat, i, j);
	-----------------------------
	----------------------------*/
	
	
 	

	int b = verificaStringaMatrice(str, 0, len,  mat, i, j, 0, 0);
	
	if(b){
		printf("\nCONTENUTA\n");
	}else{
		printf("\nNON CONTENUTA\n");
	}
	
}

