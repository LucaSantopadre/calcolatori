.data
	A: .word 1 2 3 4 5 7 8 9

.text
.globl main

main:	addi $sp, $sp, -4 	# alloco 1 parola
	sw $ra, 0($sp)
	
	la $a0, A		# a0 = &(A[0])
	addi $a1, $0, 7		# a1 =  n-1 = 7
	addi $a2, $0, 3		# a2 = n-1/2 = 3
	mul $t0, $a1, 4
	add $a3, $a0, $t0	# a3 = &(A[n-1])  ultimo indice
	jal scambia
	
	
	

scambia:addi $s0, $0, 0		# s0 = 0 = i (indice termine loop)
	addi $s3, $a0, 0	# s3 = &(A[0]) = x (indice scorri memoria)
	addi $s4, $a3, 0	# s4 = &(A[last]) = y (indice scorri reverse)

loop:	lw $t0, 0($s3)		# t0 = A[x]
	lw $t1, 0($s4)		# t1 = A[y]

	sw $t1, 0($s3)		# scambia
	sw $t0, 0($s4)
	
	slt $t5, $s0, $a2	# t5 = 1 if i<n/2
	beq $t5, 0, end 	# if t5 = 0 --> end
	
	addi $s0, $s0, 1	# i = i+1
	addi $s3, $s3, 4	# s3 = &(A[i+1])
	addi $s4, $s4, -4	# s4 = &(A[last-1])
	j loop

end:	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra
