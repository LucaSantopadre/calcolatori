#scambia diagonali

.data
	M: .word 3
	N: .word 3
	A: .word 4,0,1
	   .word 0,4,1
	   .word 1,0,4

.text
globl main

main:
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	# carico i paramentri  a0 = indir matrice   a1 = righe   a2 = col



	lw $ra, 0($sp)
	addi $sp,$sp, 4
	jr $ra



scambia:
	# se la matrice non è quadrata fine
	add $v0, $zero, $zero
	bne $a1, $a2, ret	

	# indice i = 0
	addi $t0, $zero, 0
	
	addi $t1, $a0, 0	# copio indirizzo matrice  &(A[i][i])
	
	sll $t2, $a2, 2		# t2 = 4 * N     salto alla riga successiva 
	
	# indirizzo elemento iesimo colonna opposta
	add $t3, $a0, $t2
	addi $t3, $t3, -4


# inizia ciclo !!! prima cosa mettere condizione di uscita
loop:	
	slt $t4, 4t0, $a1	# t4 = i<N
	beq $t4, $zero, exit_loop

	# altra iterazione loop, scambia
	lw $t5, 0($t1)	 # t5 = A[i][i]
	lw $t6, 0($t3)	 # t6 = A[i][N-1-j]

	# SCAMBIA
	sw $t5, 0($t3)
	sw $t6, 0($t1)

	# aumento puntatori
	add $t1, $t1, $t2	# salto riga dopo ma senza cambiare colonna &(A[i+1][i])
	addi $t1, $t1, 4	# t1  &(A[i+1][i+1] 

	add $t3, $t3, $t2
	addi $t3, $tr, -4

	addi $t0, $t0, 1	# i++
	j loop

exit_loop:
	addi $v0
	...


ret:
	jr $ra



