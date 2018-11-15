

main:
	addi $s0, $zero, 1  # s0=1
	addi $s1, $zero, 2  # s1=2

	addi $a0, $zero, 5  # g=5
	addi $a1, $zero, 6  # h=6
	addi $a2, $zero, 4  # i=4
	addi $a3, $zero, 3  # j=3
	jal example         #  salta alla procedura example e memorizza $ra!


example:
	addi $sp, $sp, -4     # alloco STACK per memorizzare $s0
	sw $s0, 0($sp)        # push di $s0 nello STACK

	add $t0, $a0, $a1     # $t0 = g+h = 11
	add $t1, $a2, $a3     # $t1 = i+j = 7
	sub $s0, $t0, $t1     # $s0 = (g+h)-(i+j) = 4
	
	add $v0, $zero, $s0   # restituisce f come risultato = 4
	lw $s0, 0($sp)        # pop di $s0 dallo STACK
	addi $sp, $sp, 4      # dealloco lo STACK
	jr $ra                # ritorna alla procedura chiamante(CALLER)
