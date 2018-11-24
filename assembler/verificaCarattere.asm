.data
	STR_IN: .asciiz "Inserisci un carattere: "
	STR_OUT:.asciiz "Return: "
	ACCAPO: .asciiz "\n"
	NO_CAR: .asciiz "Il carattere inserito non è una lettera"
	C:      .word ' '

.text
.globl main

main:
	addi $v0,$0,4		# print_string
	la $a0, STR_IN
	syscall
	
	addi $v0, $0, 12	# read_char
	syscall
	sw $v0, C

	addi $v0, $0, 4
	la $a0, ACCAPO
	syscall

	la $a0, STR_OUT		# print string
	syscall	

	lw $a0, C		# a0 = carattere codificato

	addi $t5, $0, 64	# t5 = 64
	slt $t0,$a0, 91		# t0 = 1 if c < 91  (MAIUSCOLO?)
	slt $t1, $t5, $a0 	# t1 = 1 if c > 64  (MAIUSCOLO?)
	and $t2, $t0, $t1	# t2 = 1 if(t0 and t1) (MAIUSCOLO!)
	beq $t2, 1, MAIUSCOLO
	
	addi $t5, $0, 96	# t5 = 96
	slt $t0, $a0, 123	# t0 = 1 if c <122  (minuscolo?)
	slt $t1, $t5, $a0	# t1 = 1 if c > 96  (minuscolo?)
	and $t2, $t0, $t1	# t2 = 1 if(t0 and t1) (minuscolo!)
	beq $t2, 1, minuscolo
		
	addi $v0, $0, 4		# se arrivo qua , non è dell alfabeto
	la $a0, NO_CAR
	syscall

	addi $v0, $0, 10	# esci
	syscall
	
MAIUSCOLO:
	addi $s0, $a0, 32	# s0 = C in minuscolo
	sw $s0, 0($sp)		# carico nello stack s0
	
	la $a0, 0($sp)		# a0 = & carattere minuscolo nello stack
	addi $v0, $0, 4
	syscall

	addi $v0, $0, 10	# esci
	syscall

minuscolo:
	addi $s0, $a0, -32	# s0 = C in MAIUSCOLO
	sw $s0, 0($sp)		# carico s0 nello stack

	la $a0, 0($sp)		# a0 = & carattere MAIUSCOLO nello stack
	addi $v0, $0, 4
	syscall

	addi $v0, $0, 10	# esci
	syscall
