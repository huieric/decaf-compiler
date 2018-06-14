	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  f_main:
  main:
	# BeginFunc 76
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 76	# decrement sp to make space for locals/temps
	# _tmp0 = 2
	  li $t0, 2		# load constant value 2 into $t0
	# i = _tmp0
	  move $t1, $t0		# copy value
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp0 from $t0 to $fp-16
	  sw $t1, -8($fp)	# spill i from $t1 to $fp-8
  _L0:
	# _tmp1 = 7
	  li $t0, 7		# load constant value 7 into $t0
	# _tmp2 = i < _tmp1
	  lw $t1, -8($fp)	# load i from $fp-8 into $t1
	  slt $t2, $t1, $t0	
	# IfZ _tmp2 Goto _L1
	# (save modified registers before flow of control change)
	  sw $t0, -20($fp)	# spill _tmp1 from $t0 to $fp-20
	  sw $t2, -24($fp)	# spill _tmp2 from $t2 to $fp-24
	  beqz $t2, _L1	# branch if _tmp2 is zero 
	# _tmp3 = 2
	  li $t0, 2		# load constant value 2 into $t0
	# j = _tmp3
	  move $t1, $t0		# copy value
	# (save modified registers before flow of control change)
	  sw $t0, -28($fp)	# spill _tmp3 from $t0 to $fp-28
	  sw $t1, -12($fp)	# spill j from $t1 to $fp-12
  _L2:
	# _tmp4 = 6
	  li $t0, 6		# load constant value 6 into $t0
	# _tmp5 = j < _tmp4
	  lw $t1, -12($fp)	# load j from $fp-12 into $t1
	  slt $t2, $t1, $t0	
	# IfZ _tmp5 Goto _L3
	# (save modified registers before flow of control change)
	  sw $t0, -32($fp)	# spill _tmp4 from $t0 to $fp-32
	  sw $t2, -36($fp)	# spill _tmp5 from $t2 to $fp-36
	  beqz $t2, _L3	# branch if _tmp5 is zero 
	# _tmp6 = i * j
	  lw $t0, -8($fp)	# load i from $fp-8 into $t0
	  lw $t1, -12($fp)	# load j from $fp-12 into $t1
	  mul $t2, $t0, $t1	
	# _tmp7 = 10
	  li $t3, 10		# load constant value 10 into $t3
	# _tmp8 = _tmp6 == _tmp7
	  seq $t4, $t2, $t3	
	# IfZ _tmp8 Goto _L4
	# (save modified registers before flow of control change)
	  sw $t2, -40($fp)	# spill _tmp6 from $t2 to $fp-40
	  sw $t3, -44($fp)	# spill _tmp7 from $t3 to $fp-44
	  sw $t4, -48($fp)	# spill _tmp8 from $t4 to $fp-48
	  beqz $t4, _L4	# branch if _tmp8 is zero 
	# Goto _L3
	  b _L3		# unconditional branch
  _L4:
	# PushParam i
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, -8($fp)	# load i from $fp-8 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam j
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, -12($fp)	# load j from $fp-12 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp9 = "\n"
	  .data			# create string constant marked with label
	  _string1: .asciiz "\n"
	  .text
	  la $t0, _string1	# load label
	# PushParam _tmp9
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -52($fp)	# spill _tmp9 from $t0 to $fp-52
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp10 = 1
	  li $t0, 1		# load constant value 1 into $t0
	# _tmp11 = j + _tmp10
	  lw $t1, -12($fp)	# load j from $fp-12 into $t1
	  add $t2, $t1, $t0	
	# j = _tmp11
	  move $t1, $t2		# copy value
	# Goto _L2
	# (save modified registers before flow of control change)
	  sw $t0, -56($fp)	# spill _tmp10 from $t0 to $fp-56
	  sw $t1, -12($fp)	# spill j from $t1 to $fp-12
	  sw $t2, -60($fp)	# spill _tmp11 from $t2 to $fp-60
	  b _L2		# unconditional branch
  _L3:
	# _tmp12 = 5
	  li $t0, 5		# load constant value 5 into $t0
	# _tmp13 = i == _tmp12
	  lw $t1, -8($fp)	# load i from $fp-8 into $t1
	  seq $t2, $t1, $t0	
	# IfZ _tmp13 Goto _L5
	# (save modified registers before flow of control change)
	  sw $t0, -64($fp)	# spill _tmp12 from $t0 to $fp-64
	  sw $t2, -68($fp)	# spill _tmp13 from $t2 to $fp-68
	  beqz $t2, _L5	# branch if _tmp13 is zero 
	# Goto _L1
	  b _L1		# unconditional branch
  _L5:
	# _tmp14 = 1
	  li $t0, 1		# load constant value 1 into $t0
	# _tmp15 = i + _tmp14
	  lw $t1, -8($fp)	# load i from $fp-8 into $t1
	  add $t2, $t1, $t0	
	# i = _tmp15
	  move $t1, $t2		# copy value
	# Goto _L0
	# (save modified registers before flow of control change)
	  sw $t0, -72($fp)	# spill _tmp14 from $t0 to $fp-72
	  sw $t1, -8($fp)	# spill i from $t1 to $fp-8
	  sw $t2, -76($fp)	# spill _tmp15 from $t2 to $fp-76
	  b _L0		# unconditional branch
  _L1:
	# _tmp16 = "done"
	  .data			# create string constant marked with label
	  _string2: .asciiz "done"
	  .text
	  la $t0, _string2	# load label
	# PushParam _tmp16
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -80($fp)	# spill _tmp16 from $t0 to $fp-80
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam i
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, -8($fp)	# load i from $fp-8 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam j
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, -12($fp)	# load j from $fp-12 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
