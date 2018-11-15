.data
	MAT: .word 66  77  88  99
	     .word 100 200 300 400
	     .word 150 250 350 450
	     .word 11  22  33  44

	NUM_COL: .word 4
	NUM_RIG: .word 4	

	STR_IN:  .asciiz "inserisci la colonna: "
	STR_OUT: .asciiz "la somma e': "

.text
.globl main

main: 
	addi $sp,$sp,8     # alloco spazio per 2 registri
	sw $ra, 4($sp)
	sw $s0, 0($sp)

	
	addi $v0, $zero, 4  # codice print_string
	la $a0, STR_IN
	syscall

	addi $v0, $zero, 5   # codice read_int
	syscall
	add $a2, $zero, $v0  # a2 = i
	
	la $a0,MAT         # a0 = &(MAT[0][0])
        lw $a1,NUM_COL     # a1 = N	
	lw $a3,NUM_RIG	   # a3 = M
		
	jal somma
	add $s0,$zero,$v0  # s0 = risultato

	addi $v0,$zero, 4  # codice print_string
	la $a0, STR_OUT
	syscall

	addi $v0,$zero, 1     # codice print_int
	add $a0, $zero, $s0   # a0 = risultato
	syscall

	lw $ra,4($sp) 
	lw $s0,0($sp)
	addi $sp,$sp,8        # ripristino registro:

somma:
	addi $sp, $sp, -16    	# alloco 4 rergistri
	sw $s0, 0($sp)		# &(MAT[0][0])
	sw $s3, 4($sp)		# sum
	sw $s4, 8($sp)		# i (utente)
	sw $s5, 12($sp)		# j scorre righe

	add $s0, $zero, $a0      # punto alla matrice s0=&(MAT[0][0])
	add $s3, $zero, $zero    # s3 = sum = 0
	add $s4, $zero, $a2      # s4 = i     (colonna inserito dall utente)
	add $s5, $zero, $zero    # s5 = j = 0 (righe)
	
	sll $t5, $s4, 2          # calcolo l'offset colonna
	add $s0, $s0, $t5	 # punto adesso alla colonna MAT[..][i]

	sll $t6, $a1, 2           # shift per cambiare riga

for: 
	slt $t0, $s5, $a3         # j minore M ?
	beq $t0, $zero, end_for
	
	lw $t1, 0($s0) 		  # t1 = MAT[j][i]
	add $s3, $s3, $t1 	  # somma += t1

	add $s0, $s0, $t6	  # punto MAT[j+1][i]

	addi $s5, $s5, 1	  # j = J + 1
	j for
		
end_for:
	add $v0, $zero, $s3      # v0 = sum
	lw $s0, 0($sp)
	lw $s3, 4($sp)
	lw $s4, 8($sp)
	lw $s5, 12($sp)
	addi $sp, $sp, 16
	jr $ra
	
