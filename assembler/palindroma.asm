.data
	s:	.asciiz "abc cba"

.text 
.globl main

main:
	addi $sp,$sp, -4
	sw $ra, 0($sp)

	# calcolo lunghezza stringa
	la $a0, s		# carico indirizzo stringa
	jal lunghezza
	
	la $a0, s		# ricarico l'indirizzo !!! senza stack
	add $a1, $0, $v0 	# a1 = lunghezza
	jal palindroma


	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra

# $a0 =...
# $a1 = lunghezza
# $v0 <- palindroma? 1:0
palindroma:
	addi $v0, $zero, 1	# palindroma = 1
	slti $t0, $a1, 2	# $t0 = (1<2)? 1 : 0
	beq  $t0, $v0, ret	# se t0 = 1  => return 1 (palindroma!!!)	

	# verifico il primo e l'ultimo carattere
	lb $t0, 0($a0)		# t0 = s[0]
	# ultimo carattere
	add $t1, $a1, -1	# t1 = l-1
	add $t1 , $a0, $t1 	# t1=&s[l-1]
	lb $t2, 0($t1)		# t2 = s[l-1]
	
	# confronto e se diversi restituisco 0
	# mi preparo v0 = 0
	add $v0, $zero, $zero
	bne $t0, $t2, ret

	# se arrivo qui allora sono uguali e faccio chiamata ricorsiva
	# salvo i registri adesso perche controlli prima non erano necessari
	# non salvo a0 e a1 perche non mi interessano salvarli
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	addi $a0, $a0, 1	# s++
	addi $a1, $a1, -2	# l-=2
	jal palindroma
	
	lw $ra, 0($sp)
	addi $sp, $sp, 4



ret:
	jr $ra


# $a0 = indirizzo stringa
# $v0 <- lunghezza stringa
lunghezza:
	add $v0, $0, $0			# v0 = count = 0

loop_lunghezza:
	# SCORRO LISTA FINCHE NON TROVO \0
	# confronto il primo carattere innanzitutto
	# per caratteri utilizzo lb
	lb $t0, 0($a0)			# t0 = s[i]
	beq $t0, $zer0 , retlunghezza	# confronto il primo carattere se è 0 esci
	addi $v0, $v0, 1		# count ++

	addi $a0, $a0, 1		# s++ aumento 1 perche è 1 solo byte non intero!!
	# !!! quando torno nel main a0 (indirizzo) viene modificato => lo salvo nello stack
	
retlunghezza:
	jr $ra
	
