#define M 3
#define N 3


int main(){
	int matrice1[M][N];
	stampa_matrice1(matrice1);

	int matrice2[M][N];
	// si aspetta un puntatore!!! ma quello che passo cosi 
	// è un puntatore ad un array d M elementi
	stampa_matrice2(matrice2);
	// per risolvere il problema metto un cast
	stampa_matrice2((int *)matrice2, M, N);


	// quello del 2 è uno spreco perche è allocata staticamente
	// ALLORA PROVO AD ALLOCARE DINAMICAMENTE
	// r e c   sono VARIABILI e non COSTANTI
	r = 2;
	c = 2;
	int *matrice3 = malloc(sizeof(int) * r * c);
	// posso stampare con stampa 2
	stampa_matrice2(matrice3, r, c);


	return 0;
}

// dichiaro il paramentro allo stesso modo di come ho creato la maytrice
// il numero delle righe puo essere omessa  "M" !
void stampa_matrice1(int mat[M][N]){
	// stampa matrice con 2 cicli for
}


//puntatore al 1 elemento della matrice
//in questo caso la dimensione puo essere variabile, e passo righe e colonne
void stampa_matrice2(int *mat, int righe, int colonne){
	// stampa matrice con 2 cicli for
	// !!!!! CAMBIA IL MODO DI COME ACCEDO A mat[i][j]
	
	for...
		for...			    //riga iesima     colonna
			int elemento = *(mat + i*colonne    +  j)
}


