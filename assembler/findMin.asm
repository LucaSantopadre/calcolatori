.data
	A: .word 5 2 4
	STR_IN:	.asciiz "MINIMO:  \n"

.text
.globl main

main:

	addi $sp, $sp, -8	# alloco 2 parole di memoria
	sw $ra, 0($sp)
	sw $s0, 4($sp)

	la $a0, A		# a0 = &(A[0])
	jal findMin

findMin:
	addi $sp, $sp, -8	# alloco 2 parole
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	

	lw $s0, 0($a0)		# s0 = A[i]


for:


	lw $ra, 0($sp)
	lw $s0, 4($sp)
	addi $sp, $sp, 8
	jr $ra
		
		




end:	lw $ra, 0($sp)
	lw $s0, 4($sp)
	addi $sp, $sp, 8
	jr $ra


	
	
