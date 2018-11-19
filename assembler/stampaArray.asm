.data 
	A:	.word 1 2 3 4 5 6 7 8 
	str_in: .asciiz "array inserito: "

.text
.globl main

main:
	addi $sp, $sp, -4	# alloco memoria
	sw $ra, 0($sp)	
	
	addi $v0, $0, 4		# codice print_string
	la $a0, str_in
	syscall

	la $a0, A
	addi $a1, $0, 7		# a1 = n-1
	jal stampa

stampa:
	addi $s0, $0, 0		# i = 0
	add $s1, $0, $a0	# s1 = &(A[0])

loop:	addi $v0, $0, 1		# codice print_int
	lw $a0, 0($s1)
	syscall

	slt $t5, $s0, $a1 	# t5 = 1 if i < n
	beq $t5, 0, end		# if t5 = 0 -> end

	addi $s0, $s0, 1	# i = i +1
	addi $s1, $s1, 4	# s1 = &(A[+1])
	j loop

end:	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra
