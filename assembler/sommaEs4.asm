.data
	A: .word 2 5 8 12 0 6 7 1 3 10
	N: .word 10
.text

.globl main

main:
	la $a0, A               # carico in a0 l'indirizzo di A:  &(A[0])
	lw $a1, N		# carico in a1 il valore N
 
	add $s0, $zero, $zero   # i = 0
	add $s1, $zero, $a0     # s1 = punto a A
	sub $s2, $a1, 1         # s2 = N-2
	add $v0,$zero,$zero	# azzero v0
for:
   	slt $t0, $s0, $s2		# t0 = (i<N)
	beq $t0, $zero, end_for		# t0=0 => end_for ;;  t0=1 => continua   
	lw $t8, 0($s1)			# t8 = A[i]	
	lw $t9, 4($s1)			# t9 = A[i+1]

					# ----controllo A[i] != A[i+1]
	slt $t1, $t8, $t9		# t1 = A[i]<A[i+1]
	slt $t2, $t9, $t8		# t2 = A[i+1]<A[i]
	or $t3, $t1, $t2		# t3 = t1 or t2
					
					# ----controllo A[i+1]+10<A[i]
	addi $t9,$t9,10 # A[i+1]+10 	# t9 = A[i+1]+10
	slt $t6, $t9, $t8		# t6 = A[i+1]+10 < A[i]
  
	and $t4, $t6, $t3		# ----t4 = t6 and t3
	
	add $s1,$s1,4			# s1 punta a A[i+1]
	add $s0,$s0,1			# i=i+1

	beq $t4, 1, for			# ---- t4 = 1 => condizione or falsa!(and vera)
	
	add $v0, $v0, $t8		# RISULTATO:  v0 += A[i]
		
	j for

end_for: 
	
