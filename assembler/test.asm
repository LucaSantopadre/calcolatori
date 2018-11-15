main:
	lw $t1,x;
	lw $t2,y;
	add $t0,$t1,$t2;
	sw $t0,z;
	jr $ra;

.data
	x:	.word 5   # variabile x =5
	y:      .word 7   # variabile y =7
	z:	.word 0   # variabile z =0
