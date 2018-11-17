.data
	str_in: .asciiz "Inserisci numero per fattoriale: "
	str_out:.asciiz "Il fattoriale e': "

.text
.globl main

main:
	add $v0, $0, 4		# codice print_string
	la $a0, str_in
	syscall

	add $v0, $0, 5		# codice read_int
	syscall

	add $a0, $v0, 0 	# a0 = n
	jal fatt
	
	add $a2, $v0, 0	# risultato in a2
	
	add $v0, $0, 4		# codice print_string
	la $a0, str_out
	syscall

	add $v0, $0, 1		# codice print_int
	add $a0, $a2, 0
	syscall

	addi $v0, $0, 10	# codice_exit
	syscall

fatt:
	addi $sp, $sp, -8	# alloco memoria per 2 parole
	sw $ra, 0($sp)
	sw $s0, 4($sp)

	# --------passo base
	addi $v0, $0, 1		# fatt(0) = 1
	beq $a0, 0, fine	# se n= 0 vai a fine
	
	# --------passo ricorsivo
	addi $s0, $a0, 0	# s0 = n
	addi $a0, $a0, -1	# a0 = n-1
	jal fatt

	# ********ritorno dalla ricorsione
	mul $v0, $s0, $v0	# moltiplica

fine:
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	addi $sp, $sp, 8
	jr $ra
	
