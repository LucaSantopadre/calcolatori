.data
	str_in: .asciiz "Inserisci un numero n ... "
	str_out:.asciiz "Risultato: "

.text
.globl main

main:	addi $sp, $sp, -8	# salvo 2 registri nello stack
	sw $ra, 0($sp)
	sw $s0, 4($sp)

	li $v0, 4 		# codice print_string
	la $a0, str_in		# in a0 l'indirizzo di str_in
	syscall			# stampa

	li $v0, 5 		# codice read_int
	syscall			# lettura n

	add $a0, $v0, $0	# a0 = n
	jal proc		# jump and link alla procedura
	add $s0, $v0, $0	# RISULTATO in $s0

proc:	addi $sp, $sp, -8 	# salvo 2 registri nello stack
	sw $ra, 0($sp)
	sw $s0, 4($sp)

	add $s0, $0, $a0	# s0 = n
	slti $t0, $s0, 1	# t0 = 1  if n < 1
	beq $t0, $0, ricors	# if t0 = 0  goto ricors

	add $v0, $s0, $zero	# return n
	j end
	
ricors:
	addi $a0, $s0, -1 	# a0 = n-1
	jal proc		# CALCOLA proc(n-1)
	add $s1, $0, $v0	# s1 = proc(n-1)

	addi $s1, $s1, 3	# s1 = proc(n-1) +3
	add $v0, $v0, $s1	# RETURN v0 = s1

end:	lw $s0, 4($sp)
	lw $ra, 0($sp)
	addi $sp, $sp, 8
	jr $ra
	
