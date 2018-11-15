.data
	A: .word 2 5 8 12 0 6 7 1 3 10
	N: .word 10
.text

.globl main

main:
	addi $sp, $sp, -4    # alloco per 1 parola
	sw $ra, 0($sp)

	la $a0, A
	lw $a1, N
 
	add $s0, $zero, $zero   # i = 0
	add $s1, $zero, $a0      # s1 = punto a A
	
	sub $s2, $a1, 1         # s2 = N-2
	add $v0,$zero,$zero
for:
   	slt $t0, $s0, $s2
	beq $t0, $zero, end_for
	
	lw $t8, 0($s1)	# A[i]
	lw $t9, 4($s1)	# A[i+1]

	slt $t1, $t8, $t9
	slt $t2, $t9, $t8
	or $t3, $t1, $t2

	addi $t9,$t9,10 # A[i+1]+10
	slt $t6, $t9, $t8
	and $t4, $t6, $t3
	
	add $s1,$s1,4
	add $s0,$s0,1

	beq $t4, 1, for
	
	add $v0, $v0, $t8
		
	j for

end_for: 
	addi $t0, $t0, 55
