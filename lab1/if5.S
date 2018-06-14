	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  f_main:
  main:
	# BeginFunc 60
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 60	# decrement sp to make space for locals/temps
	# _tmp0 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# i = _tmp0
	  move $t1, $t0		# copy value
	# _tmp1 = 12
	  li $t2, 12		# load constant value 12 into $t2
	# _tmp2 = _tmp1 < i
	  slt $t3, $t2, $t1	
	# _tmp3 = 12
	  li $t4, 12		# load constant value 12 into $t4
	# _tmp4 = i < _tmp3
	  slt $t5, $t1, $t4	
	# _tmp5 = _tmp2 || _tmp4
	  or $t6, $t3, $t5	
	# _tmp6 = 3
	  li $t7, 3		# load constant value 3 into $t7
	# _tmp7 = 5
	  li $s0, 5		# load constant value 5 into $s0
	# _tmp8 = _tmp6 == _tmp7
	  seq $s1, $t7, $s0	
	# _tmp9 = 1
	  li $s2, 1		# load constant value 1 into $s2
	# _tmp10 = _tmp8 && _tmp9
	  and $s3, $s1, $s2	
	# _tmp11 = _tmp5 || _tmp10
	  or $s4, $t6, $s3	
	# IfZ _tmp11 Goto _L0
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp0 from $t0 to $fp-12
	  sw $t1, -8($fp)	# spill i from $t1 to $fp-8
	  sw $t2, -16($fp)	# spill _tmp1 from $t2 to $fp-16
	  sw $t3, -20($fp)	# spill _tmp2 from $t3 to $fp-20
	  sw $t4, -24($fp)	# spill _tmp3 from $t4 to $fp-24
	  sw $t5, -28($fp)	# spill _tmp4 from $t5 to $fp-28
	  sw $t6, -32($fp)	# spill _tmp5 from $t6 to $fp-32
	  sw $t7, -36($fp)	# spill _tmp6 from $t7 to $fp-36
	  sw $s0, -40($fp)	# spill _tmp7 from $s0 to $fp-40
	  sw $s1, -44($fp)	# spill _tmp8 from $s1 to $fp-44
	  sw $s2, -48($fp)	# spill _tmp9 from $s2 to $fp-48
	  sw $s3, -52($fp)	# spill _tmp10 from $s3 to $fp-52
	  sw $s4, -56($fp)	# spill _tmp11 from $s4 to $fp-56
	  beqz $s4, _L0	# branch if _tmp11 is zero 
	# _tmp12 = 1
	  li $t0, 1		# load constant value 1 into $t0
	# PushParam _tmp12
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -60($fp)	# spill _tmp12 from $t0 to $fp-60
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
  _L0:
	# _tmp13 = 2
	  li $t0, 2		# load constant value 2 into $t0
	# PushParam _tmp13
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -64($fp)	# spill _tmp13 from $t0 to $fp-64
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
