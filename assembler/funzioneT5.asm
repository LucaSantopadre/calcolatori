.data
	A: .word 1 2 3
	B: .word 7 8 9
	n: .word 3
.text
.globl main
main:
	addi $sp, $sp, -4
	sw $ra, 0($sp)

	la $a0, A
	la $a1, B
	lw $a2, n

	addi $s0, $a0, 0	# s0 = A
	addi $s1, $a1, 0	# s1 = B
	addi $s2, $a2, 0	# s2 = n
	addi $s3, $zero, 0	# i = 0	

	

	jal procedura
	addi $v0, $0, 222
	

	lw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra


procedura:
	addi $sp, $sp, -20
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)	
	sw $ra, 16($sp)

	slt $t0, $s3, $s2	# t0 = 1 if(i<n)
	beq  $t0, 1, else_for
	j end	


else_for:
	lw $s5, 0($s0)		# s5 = A[i]
	lw $s6, 0($s1)		# s6 = B[i] 
	
	
	jal funzT
	sw $v0, 0($s1)		# result in v0

	addi $s3, $s3, 1	# i++
	addi $s0, $s0, 4	# s0 = A[i+1]
	addi $s1, $s1, 4	# s1 = B[i+1]
	jal procedura
	

end:
	lw $s0, 0($sp)
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	lw $ra, 16($sp)
	addi $sp, $sp, 20
	jr $ra
	

