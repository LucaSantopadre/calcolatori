.data
	STR_IN1:  .asciiz "CONVERTITORE\n\nInserisci valore decimale: "
	STR_IN2:  .asciiz "Inserisci la base: "

.text
.globl main

main:	
	addi $v0, $0, 4		# codice print_sting
	la $a0,STR_IN1
	syscall
	
	addi $v0, $0, 5		# codice read_int
	syscall
	add $t0, $0, $v0

	addi $v0, $0, 4		# codice print_tring
	la $a0,STR_IN2	
	syscall
	
	addi $v0, $0, 5		# codice read_int
	syscall
	add $t1, $0, $v0	

	add $a0, $0, $t0	# a0 = n
	add $a1, $0, $t1	# a1 = b

	addi $sp, $sp, -8	# alloco 2 parola in memoria
	sw $ra, 0($sp)
	sw $s0, 4($sp)

	addi $s0, $a0, 0	# s0 = n
	jal converti
	addi $t5, $0, 222

converti:
	addi $sp, $sp, -12	# allloco
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)

	srl $s1, $s0, 1		# s1 = n/2
	slt $t0, $s1, 1		# t0 = 1 if(s1 <=0)
	beq $t0, $zero, else	# if(s1 > 0) -> else
	
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	addi $sp, $sp, 12
	jr $ra
	
	add $t6, $0, 5555
else:
	add $s0, $s1, $zero	# s0 = n/2
	jal converti
	
	div $s0, $a1		# divido n/2 per b
	addi $t3, $a0, 0	# t3 = n
	mfhi $a0		# a0 = s0%b
	
	addi $v0, $zero, 1	# codice print_int
	syscall

	add $a0, $t3, $zero	# a0 = n

	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	addi $sp, $sp, 12
	jr $ra

