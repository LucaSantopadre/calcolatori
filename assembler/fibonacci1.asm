#
#Procedura ricorsiva per il calcolo del numero di Fibonacci
#

.data
prompt:	.asciiz "Inserisci un numero intero n... "
output:	.ascii "Il fib(n)=: "
.text
        .globl main

main:	addi $sp, $sp, -8	# per salvare 2 registri nello stack
	sw $ra, 4($sp)		# push di $ra nello stack
	sw $s0, 0($sp)		# push di $s0 nello stack
	
	li $v0, 4		# carica in $v0 il codice della print_string
	la $a0, prompt		# carica in $a0 l'indirizzo della stringa
	syscall 		# stampa la stringa

	li $v0, 5		# carica in $vo0 il codice della read_int
	syscall			# legge l'intero e lo carica in $v0

	add $a0, $v0, $0	
	jal fib
	add $s0, $v0, $0

	# Stampa il risultato
	li $v0, 4		# carica in $v0 il codice della print_string
	la $a0, output		# carica in $a0 l'indirizzo della stringa
	syscall 		# stampa la stringa
	li $v0, 1		# carica in $v0 il codice della print_int
	add $a0, $s0, $0	# carica in $a0 il risultato salvato in $s0
	syscall			# stampa il risultato	

	lw  $s0, 0($sp)		# pop di $s0 dallo stack
	lw  $ra, 4($sp) 	# pop di $ra dallo stack
	addi $sp, $sp, 8	# 
	jr $ra	


fib:	addi 	$sp, $sp, -12
	sw 	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	
	add	$s0, $0, $a0	# $s0=n
	slti	$t0, $s0, 2	# $t0=1 iff n<2
	beq	$t0, $0, Else	# if n>=2 goto Else
	add	$v0, $0, $s0	# return n
	j	End
Else:	addi 	$a0, $s0, -1	# $a0=n-1
	jal 	fib		# calcola fib(n-1)
	add 	$s1, $0, $v0	# $s1=fib(n-1)
	addi 	$a0, $s0, -2	# $a0=n-2
	jal 	fib		# calcola fib(n-2)
	add 	$v0, $v0, $s1	# $v0=fib(n-1)+fib(n-2)

End:	lw	$s1, 8($sp)
	lw 	$s0, 4($sp)
	lw	$ra, 0($sp)
	addi	$sp, $sp, 12
	jr	$ra
