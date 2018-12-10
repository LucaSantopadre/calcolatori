/*
 * matrici   2*3   e  3*2
 *
 * int verifica( passo matrici costanti A e B)
 * 	scorro righe
 * 		if(!verifica_riga(A,B,i))
 * 			return 0
 * 1 condizione -------------------------
 * int verifica_riga(A,B,riga di A)
 * 	int finito = 0
 *	scorro su tutte le colonne di B
 *		e confronto con la riga di A
 *			finito = 1
 *			appena ne trovo 1 uguale mi fermo
 *	 
 *	 2 condizione
 *	 for j=0; j<M and !finito
 *	 	for k=j+1 ; k<M and !finito
 *	 		int nuova_col[N]   // vettore temporaneo
 *	 		somma_colonne(B, nuova_col, j, k)
 *			dentro nuova volonna ho la somma che mi interessa
 *			
 *			//confronto con riga di A
 *			confronta_riga_vettore(A, nuova_col, j, k
 *
 *			..........
 *
 *	return finito
 *	
 *
 *
 *
 * int confronta_riga_colonna(A, B, riga di A, colonna di B)
 * 	int uguali = 1
 *	for i < N
 *		uguali &= (A[riga][i] == B[i][col])
 *	return uguali
 * ----------------------------------------
 *
 *  
 *
 *
