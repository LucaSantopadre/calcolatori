.data
	A: .word 1 2 3
	B: .word 4 5 6
	n: .word 3

.text
.globl main
main:
	la $a0, A
	la $a1, B
	lw $a2, n

	jal procedura
	addi $v0, $0, 10
	syscall


procedura:
	addi $sp, $sp, -4	# alloco memoria
	sw $ra, 0($sp)	
	
	addi $s2, $0, 0		# i = 0
	
loop:	lw $s0, 0($a0)		# s0 = A[i]
	lw $s1, 0($a1)		# s1 = B[i]

	add $a3, $zero, $s0 	# a3 = m = A[i]
	jal funzione_T

	
	add $s1, $s1, $v0	# s1 = B[i] + funzione_T(A[i])
	sw $s1, 0($a1)		# salvo in memoria s1=B[i]

	addi $a0, $a0, 4	# a0 = A[i+1]
	addi $a1, $a1, 4	# a1 = B[i+1]
	addi $s2, $s2, 1	# i++

	slt $t0, $s2, $a2	# t0 = 1 if i < n
	beq $t0, $zero, end
	j loop

funzione_T:
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	
	slt $t1, $a3, 3		# t1 = 1 if m <=2
	beq $t1, $zero, else	# if t1 = 0 -> else
	addi $v0, $zero, 1	# return 1	

	jr $ra
else:	
	# -----1 chiamata ricorsiva
	srl $a3, $a3, 1		# a3 = m/2
	jal funzione_T
	add $t5, $v0, 0		# t5 = T(m/2)
	lw $ra, 0($sp)
        addi $sp, $sp, 4
		


	# -----2 chiamata ricorsiva
	srl $a3, $a3, 1		# a3 = m/4
	jal funzione_T
	add $t6, $v0, 0		# t6 = T(m/4)
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	
	# calcolo 3*T(m/2)
	add $t7, $t5, 0		# t7 = T(m/2)
	sll $t5, $t5, 1		# t5 = 2*T(m/2)
	add $t5, $t5, $t7	# t5 = 3*T(m/2)
	
	sll $t6, $t6, 1		# t6 = 2*T(m/4)
	add $v0, $t5, $t6	# v0 = 3*T(m/2) + 2*T(m/4)
	
	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra



end:
	lw $ra, 4($sp)
	addi $sp, $sp, 4	# dealloco memoria
	jr $ra
