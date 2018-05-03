	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  f_TakeArray:
	# BeginFunc 116
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 116	# decrement sp to make space for locals/temps
	# _tmp0 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp1 = 0
	  li $t1, 0		# load constant value 0 into $t1
	# _tmp2 = 4
	  li $t2, 4		# load constant value 4 into $t2
	# _tmp3 = *(x)
	  lw $t3, 4($fp)	# load x from $fp+4 into $t3
	  lw $t4, 0($t3) 	# load with offset
	# _tmp4 = _tmp3 == _tmp0
	  seq $t5, $t4, $t0	
	# _tmp5 = _tmp3 < _tmp0
	  slt $t6, $t4, $t0	
	# _tmp6 = _tmp5 || _tmp4
	  or $t7, $t6, $t5	
	# _tmp7 = _tmp0 < _tmp1
	  slt $s0, $t0, $t1	
	# _tmp8 = _tmp7 || _tmp6
	  or $s1, $s0, $t7	
	# IfZ _tmp8 Goto _L0
	# (save modified registers before flow of control change)
	  sw $t0, -8($fp)	# spill _tmp0 from $t0 to $fp-8
	  sw $t1, -12($fp)	# spill _tmp1 from $t1 to $fp-12
	  sw $t2, -16($fp)	# spill _tmp2 from $t2 to $fp-16
	  sw $t4, -20($fp)	# spill _tmp3 from $t4 to $fp-20
	  sw $t5, -24($fp)	# spill _tmp4 from $t5 to $fp-24
	  sw $t6, -28($fp)	# spill _tmp5 from $t6 to $fp-28
	  sw $t7, -32($fp)	# spill _tmp6 from $t7 to $fp-32
	  sw $s0, -36($fp)	# spill _tmp7 from $s0 to $fp-36
	  sw $s1, -40($fp)	# spill _tmp8 from $s1 to $fp-40
	  beqz $s1, _L0	# branch if _tmp8 is zero 
	# _tmp9 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string1: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string1	# load label
	# PushParam _tmp9
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -44($fp)	# spill _tmp9 from $t0 to $fp-44
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L0:
	# _tmp10 = _tmp0 * _tmp2
	  lw $t0, -8($fp)	# load _tmp0 from $fp-8 into $t0
	  lw $t1, -16($fp)	# load _tmp2 from $fp-16 into $t1
	  mul $t2, $t0, $t1	
	# _tmp11 = _tmp10 + _tmp2
	  add $t3, $t2, $t1	
	# _tmp12 = x + _tmp11
	  lw $t4, 4($fp)	# load x from $fp+4 into $t4
	  add $t5, $t4, $t3	
	# _tmp13 = *(_tmp12)
	  lw $t6, 0($t5) 	# load with offset
	# PushParam _tmp13
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t6, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t2, -48($fp)	# spill _tmp10 from $t2 to $fp-48
	  sw $t3, -52($fp)	# spill _tmp11 from $t3 to $fp-52
	  sw $t5, -56($fp)	# spill _tmp12 from $t5 to $fp-56
	  sw $t6, -60($fp)	# spill _tmp13 from $t6 to $fp-60
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp14 = 5
	  li $t0, 5		# load constant value 5 into $t0
	# _tmp15 = 0
	  li $t1, 0		# load constant value 0 into $t1
	# _tmp16 = 4
	  li $t2, 4		# load constant value 4 into $t2
	# _tmp17 = *(x)
	  lw $t3, 4($fp)	# load x from $fp+4 into $t3
	  lw $t4, 0($t3) 	# load with offset
	# _tmp18 = _tmp17 == _tmp14
	  seq $t5, $t4, $t0	
	# _tmp19 = _tmp17 < _tmp14
	  slt $t6, $t4, $t0	
	# _tmp20 = _tmp19 || _tmp18
	  or $t7, $t6, $t5	
	# _tmp21 = _tmp14 < _tmp15
	  slt $s0, $t0, $t1	
	# _tmp22 = _tmp21 || _tmp20
	  or $s1, $s0, $t7	
	# IfZ _tmp22 Goto _L1
	# (save modified registers before flow of control change)
	  sw $t0, -64($fp)	# spill _tmp14 from $t0 to $fp-64
	  sw $t1, -68($fp)	# spill _tmp15 from $t1 to $fp-68
	  sw $t2, -72($fp)	# spill _tmp16 from $t2 to $fp-72
	  sw $t4, -76($fp)	# spill _tmp17 from $t4 to $fp-76
	  sw $t5, -80($fp)	# spill _tmp18 from $t5 to $fp-80
	  sw $t6, -84($fp)	# spill _tmp19 from $t6 to $fp-84
	  sw $t7, -88($fp)	# spill _tmp20 from $t7 to $fp-88
	  sw $s0, -92($fp)	# spill _tmp21 from $s0 to $fp-92
	  sw $s1, -96($fp)	# spill _tmp22 from $s1 to $fp-96
	  beqz $s1, _L1	# branch if _tmp22 is zero 
	# _tmp23 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string2: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string2	# load label
	# PushParam _tmp23
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -100($fp)	# spill _tmp23 from $t0 to $fp-100
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L1:
	# _tmp24 = _tmp14 * _tmp16
	  lw $t0, -64($fp)	# load _tmp14 from $fp-64 into $t0
	  lw $t1, -72($fp)	# load _tmp16 from $fp-72 into $t1
	  mul $t2, $t0, $t1	
	# _tmp25 = _tmp24 + _tmp16
	  add $t3, $t2, $t1	
	# _tmp26 = x + _tmp25
	  lw $t4, 4($fp)	# load x from $fp+4 into $t4
	  add $t5, $t4, $t3	
	# _tmp27 = *(_tmp26)
	  lw $t6, 0($t5) 	# load with offset
	# PushParam _tmp27
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t6, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t2, -104($fp)	# spill _tmp24 from $t2 to $fp-104
	  sw $t3, -108($fp)	# spill _tmp25 from $t3 to $fp-108
	  sw $t5, -112($fp)	# spill _tmp26 from $t5 to $fp-112
	  sw $t6, -116($fp)	# spill _tmp27 from $t6 to $fp-116
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp28 = *(x)
	  lw $t0, 4($fp)	# load x from $fp+4 into $t0
	  lw $t1, 0($t0) 	# load with offset
	# PushParam _tmp28
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t1, -120($fp)	# spill _tmp28 from $t1 to $fp-120
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  f_MakeArray:
	# BeginFunc 144
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 144	# decrement sp to make space for locals/temps
	# _tmp29 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# _tmp30 = 4
	  li $t1, 4		# load constant value 4 into $t1
	# _tmp31 = _tmp29 < size
	  lw $t2, 4($fp)	# load size from $fp+4 into $t2
	  slt $t3, $t0, $t2	
	# IfZ _tmp31 Goto _L2
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp29 from $t0 to $fp-12
	  sw $t1, -16($fp)	# spill _tmp30 from $t1 to $fp-16
	  sw $t3, -20($fp)	# spill _tmp31 from $t3 to $fp-20
	  beqz $t3, _L2	# branch if _tmp31 is zero 
	# Goto _L3
	  b _L3		# unconditional branch
  _L2:
	# _tmp32 = "Decaf runtime error: Array size is <= 0\n"
	  .data			# create string constant marked with label
	  _string3: .asciiz "Decaf runtime error: Array size is <= 0\n"
	  .text
	  la $t0, _string3	# load label
	# PushParam _tmp32
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -24($fp)	# spill _tmp32 from $t0 to $fp-24
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L3:
	# _tmp33 = size * _tmp30
	  lw $t0, 4($fp)	# load size from $fp+4 into $t0
	  lw $t1, -16($fp)	# load _tmp30 from $fp-16 into $t1
	  mul $t2, $t0, $t1	
	# _tmp34 = _tmp33 + _tmp30
	  add $t3, $t2, $t1	
	# PushParam _tmp34
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp35 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t2, -28($fp)	# spill _tmp33 from $t2 to $fp-28
	  sw $t3, -32($fp)	# spill _tmp34 from $t3 to $fp-32
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# *(_tmp35) = size
	  lw $t1, 4($fp)	# load size from $fp+4 into $t1
	  sw $t1, 0($t0) 	# store with offset
	# b = _tmp35
	  move $t2, $t0		# copy value
	# _tmp36 = 0
	  li $t3, 0		# load constant value 0 into $t3
	# _tmp37 = 0
	  li $t4, 0		# load constant value 0 into $t4
	# _tmp38 = 4
	  li $t5, 4		# load constant value 4 into $t5
	# _tmp39 = *(b)
	  lw $t6, 0($t2) 	# load with offset
	# _tmp40 = _tmp39 == _tmp36
	  seq $t7, $t6, $t3	
	# _tmp41 = _tmp39 < _tmp36
	  slt $s0, $t6, $t3	
	# _tmp42 = _tmp41 || _tmp40
	  or $s1, $s0, $t7	
	# _tmp43 = _tmp36 < _tmp37
	  slt $s2, $t3, $t4	
	# _tmp44 = _tmp43 || _tmp42
	  or $s3, $s2, $s1	
	# IfZ _tmp44 Goto _L4
	# (save modified registers before flow of control change)
	  sw $t0, -36($fp)	# spill _tmp35 from $t0 to $fp-36
	  sw $t2, -8($fp)	# spill b from $t2 to $fp-8
	  sw $t3, -40($fp)	# spill _tmp36 from $t3 to $fp-40
	  sw $t4, -44($fp)	# spill _tmp37 from $t4 to $fp-44
	  sw $t5, -48($fp)	# spill _tmp38 from $t5 to $fp-48
	  sw $t6, -52($fp)	# spill _tmp39 from $t6 to $fp-52
	  sw $t7, -56($fp)	# spill _tmp40 from $t7 to $fp-56
	  sw $s0, -60($fp)	# spill _tmp41 from $s0 to $fp-60
	  sw $s1, -64($fp)	# spill _tmp42 from $s1 to $fp-64
	  sw $s2, -68($fp)	# spill _tmp43 from $s2 to $fp-68
	  sw $s3, -72($fp)	# spill _tmp44 from $s3 to $fp-72
	  beqz $s3, _L4	# branch if _tmp44 is zero 
	# _tmp45 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string4: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string4	# load label
	# PushParam _tmp45
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -76($fp)	# spill _tmp45 from $t0 to $fp-76
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L4:
	# _tmp46 = _tmp36 * _tmp38
	  lw $t0, -40($fp)	# load _tmp36 from $fp-40 into $t0
	  lw $t1, -48($fp)	# load _tmp38 from $fp-48 into $t1
	  mul $t2, $t0, $t1	
	# _tmp47 = _tmp46 + _tmp38
	  add $t3, $t2, $t1	
	# _tmp48 = b + _tmp47
	  lw $t4, -8($fp)	# load b from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# _tmp49 = *(_tmp48)
	  lw $t6, 0($t5) 	# load with offset
	# _tmp50 = 5
	  li $t7, 5		# load constant value 5 into $t7
	# _tmp51 = 0
	  li $s0, 0		# load constant value 0 into $s0
	# _tmp52 = 0
	  li $s1, 0		# load constant value 0 into $s1
	# _tmp53 = 4
	  li $s2, 4		# load constant value 4 into $s2
	# _tmp54 = *(b)
	  lw $s3, 0($t4) 	# load with offset
	# _tmp55 = _tmp54 == _tmp51
	  seq $s4, $s3, $s0	
	# _tmp56 = _tmp54 < _tmp51
	  slt $s5, $s3, $s0	
	# _tmp57 = _tmp56 || _tmp55
	  or $s6, $s5, $s4	
	# _tmp58 = _tmp51 < _tmp52
	  slt $s7, $s0, $s1	
	# _tmp59 = _tmp58 || _tmp57
	  or $t8, $s7, $s6	
	# IfZ _tmp59 Goto _L5
	# (save modified registers before flow of control change)
	  sw $t2, -80($fp)	# spill _tmp46 from $t2 to $fp-80
	  sw $t3, -84($fp)	# spill _tmp47 from $t3 to $fp-84
	  sw $t5, -88($fp)	# spill _tmp48 from $t5 to $fp-88
	  sw $t6, -92($fp)	# spill _tmp49 from $t6 to $fp-92
	  sw $t7, -96($fp)	# spill _tmp50 from $t7 to $fp-96
	  sw $s0, -100($fp)	# spill _tmp51 from $s0 to $fp-100
	  sw $s1, -104($fp)	# spill _tmp52 from $s1 to $fp-104
	  sw $s2, -108($fp)	# spill _tmp53 from $s2 to $fp-108
	  sw $s3, -112($fp)	# spill _tmp54 from $s3 to $fp-112
	  sw $s4, -116($fp)	# spill _tmp55 from $s4 to $fp-116
	  sw $s5, -120($fp)	# spill _tmp56 from $s5 to $fp-120
	  sw $s6, -124($fp)	# spill _tmp57 from $s6 to $fp-124
	  sw $s7, -128($fp)	# spill _tmp58 from $s7 to $fp-128
	  sw $t8, -132($fp)	# spill _tmp59 from $t8 to $fp-132
	  beqz $t8, _L5	# branch if _tmp59 is zero 
	# _tmp60 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string5: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string5	# load label
	# PushParam _tmp60
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -136($fp)	# spill _tmp60 from $t0 to $fp-136
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L5:
	# _tmp61 = _tmp51 * _tmp53
	  lw $t0, -100($fp)	# load _tmp51 from $fp-100 into $t0
	  lw $t1, -108($fp)	# load _tmp53 from $fp-108 into $t1
	  mul $t2, $t0, $t1	
	# _tmp62 = _tmp61 + _tmp53
	  add $t3, $t2, $t1	
	# _tmp63 = b + _tmp62
	  lw $t4, -8($fp)	# load b from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# *(_tmp63) = _tmp50
	  lw $t6, -96($fp)	# load _tmp50 from $fp-96 into $t6
	  sw $t6, 0($t5) 	# store with offset
	# Return b
	  move $v0, $t4		# assign return value into $v0
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  f_main:
  main:
	# BeginFunc 348
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 348	# decrement sp to make space for locals/temps
	# _tmp64 = 10
	  li $t0, 10		# load constant value 10 into $t0
	# _tmp65 = 0
	  li $t1, 0		# load constant value 0 into $t1
	# _tmp66 = 4
	  li $t2, 4		# load constant value 4 into $t2
	# _tmp67 = _tmp65 < _tmp64
	  slt $t3, $t1, $t0	
	# IfZ _tmp67 Goto _L6
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp64 from $t0 to $fp-16
	  sw $t1, -20($fp)	# spill _tmp65 from $t1 to $fp-20
	  sw $t2, -24($fp)	# spill _tmp66 from $t2 to $fp-24
	  sw $t3, -28($fp)	# spill _tmp67 from $t3 to $fp-28
	  beqz $t3, _L6	# branch if _tmp67 is zero 
	# Goto _L7
	  b _L7		# unconditional branch
  _L6:
	# _tmp68 = "Decaf runtime error: Array size is <= 0\n"
	  .data			# create string constant marked with label
	  _string6: .asciiz "Decaf runtime error: Array size is <= 0\n"
	  .text
	  la $t0, _string6	# load label
	# PushParam _tmp68
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -32($fp)	# spill _tmp68 from $t0 to $fp-32
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L7:
	# _tmp69 = _tmp64 * _tmp66
	  lw $t0, -16($fp)	# load _tmp64 from $fp-16 into $t0
	  lw $t1, -24($fp)	# load _tmp66 from $fp-24 into $t1
	  mul $t2, $t0, $t1	
	# _tmp70 = _tmp69 + _tmp66
	  add $t3, $t2, $t1	
	# PushParam _tmp70
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp71 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t2, -36($fp)	# spill _tmp69 from $t2 to $fp-36
	  sw $t3, -40($fp)	# spill _tmp70 from $t3 to $fp-40
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# *(_tmp71) = _tmp64
	  lw $t1, -16($fp)	# load _tmp64 from $fp-16 into $t1
	  sw $t1, 0($t0) 	# store with offset
	# y = _tmp71
	  move $t2, $t0		# copy value
	# _tmp72 = 4
	  li $t3, 4		# load constant value 4 into $t3
	# _tmp73 = 0
	  li $t4, 0		# load constant value 0 into $t4
	# _tmp74 = 4
	  li $t5, 4		# load constant value 4 into $t5
	# _tmp75 = *(y)
	  lw $t6, 0($t2) 	# load with offset
	# _tmp76 = _tmp75 == _tmp72
	  seq $t7, $t6, $t3	
	# _tmp77 = _tmp75 < _tmp72
	  slt $s0, $t6, $t3	
	# _tmp78 = _tmp77 || _tmp76
	  or $s1, $s0, $t7	
	# _tmp79 = _tmp72 < _tmp73
	  slt $s2, $t3, $t4	
	# _tmp80 = _tmp79 || _tmp78
	  or $s3, $s2, $s1	
	# IfZ _tmp80 Goto _L8
	# (save modified registers before flow of control change)
	  sw $t0, -44($fp)	# spill _tmp71 from $t0 to $fp-44
	  sw $t2, -8($fp)	# spill y from $t2 to $fp-8
	  sw $t3, -48($fp)	# spill _tmp72 from $t3 to $fp-48
	  sw $t4, -52($fp)	# spill _tmp73 from $t4 to $fp-52
	  sw $t5, -56($fp)	# spill _tmp74 from $t5 to $fp-56
	  sw $t6, -60($fp)	# spill _tmp75 from $t6 to $fp-60
	  sw $t7, -64($fp)	# spill _tmp76 from $t7 to $fp-64
	  sw $s0, -68($fp)	# spill _tmp77 from $s0 to $fp-68
	  sw $s1, -72($fp)	# spill _tmp78 from $s1 to $fp-72
	  sw $s2, -76($fp)	# spill _tmp79 from $s2 to $fp-76
	  sw $s3, -80($fp)	# spill _tmp80 from $s3 to $fp-80
	  beqz $s3, _L8	# branch if _tmp80 is zero 
	# _tmp81 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string7: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string7	# load label
	# PushParam _tmp81
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -84($fp)	# spill _tmp81 from $t0 to $fp-84
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L8:
	# _tmp82 = _tmp72 * _tmp74
	  lw $t0, -48($fp)	# load _tmp72 from $fp-48 into $t0
	  lw $t1, -56($fp)	# load _tmp74 from $fp-56 into $t1
	  mul $t2, $t0, $t1	
	# _tmp83 = _tmp82 + _tmp74
	  add $t3, $t2, $t1	
	# _tmp84 = y + _tmp83
	  lw $t4, -8($fp)	# load y from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# _tmp85 = *(_tmp84)
	  lw $t6, 0($t5) 	# load with offset
	# _tmp86 = 3
	  li $t7, 3		# load constant value 3 into $t7
	# _tmp87 = 4
	  li $s0, 4		# load constant value 4 into $s0
	# _tmp88 = 0
	  li $s1, 0		# load constant value 0 into $s1
	# _tmp89 = 4
	  li $s2, 4		# load constant value 4 into $s2
	# _tmp90 = *(y)
	  lw $s3, 0($t4) 	# load with offset
	# _tmp91 = _tmp90 == _tmp87
	  seq $s4, $s3, $s0	
	# _tmp92 = _tmp90 < _tmp87
	  slt $s5, $s3, $s0	
	# _tmp93 = _tmp92 || _tmp91
	  or $s6, $s5, $s4	
	# _tmp94 = _tmp87 < _tmp88
	  slt $s7, $s0, $s1	
	# _tmp95 = _tmp94 || _tmp93
	  or $t8, $s7, $s6	
	# IfZ _tmp95 Goto _L9
	# (save modified registers before flow of control change)
	  sw $t2, -88($fp)	# spill _tmp82 from $t2 to $fp-88
	  sw $t3, -92($fp)	# spill _tmp83 from $t3 to $fp-92
	  sw $t5, -96($fp)	# spill _tmp84 from $t5 to $fp-96
	  sw $t6, -100($fp)	# spill _tmp85 from $t6 to $fp-100
	  sw $t7, -104($fp)	# spill _tmp86 from $t7 to $fp-104
	  sw $s0, -108($fp)	# spill _tmp87 from $s0 to $fp-108
	  sw $s1, -112($fp)	# spill _tmp88 from $s1 to $fp-112
	  sw $s2, -116($fp)	# spill _tmp89 from $s2 to $fp-116
	  sw $s3, -120($fp)	# spill _tmp90 from $s3 to $fp-120
	  sw $s4, -124($fp)	# spill _tmp91 from $s4 to $fp-124
	  sw $s5, -128($fp)	# spill _tmp92 from $s5 to $fp-128
	  sw $s6, -132($fp)	# spill _tmp93 from $s6 to $fp-132
	  sw $s7, -136($fp)	# spill _tmp94 from $s7 to $fp-136
	  sw $t8, -140($fp)	# spill _tmp95 from $t8 to $fp-140
	  beqz $t8, _L9	# branch if _tmp95 is zero 
	# _tmp96 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string8: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string8	# load label
	# PushParam _tmp96
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -144($fp)	# spill _tmp96 from $t0 to $fp-144
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L9:
	# _tmp97 = _tmp87 * _tmp89
	  lw $t0, -108($fp)	# load _tmp87 from $fp-108 into $t0
	  lw $t1, -116($fp)	# load _tmp89 from $fp-116 into $t1
	  mul $t2, $t0, $t1	
	# _tmp98 = _tmp97 + _tmp89
	  add $t3, $t2, $t1	
	# _tmp99 = y + _tmp98
	  lw $t4, -8($fp)	# load y from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# *(_tmp99) = _tmp86
	  lw $t6, -104($fp)	# load _tmp86 from $fp-104 into $t6
	  sw $t6, 0($t5) 	# store with offset
	# _tmp100 = 5
	  li $t7, 5		# load constant value 5 into $t7
	# _tmp101 = 0
	  li $s0, 0		# load constant value 0 into $s0
	# _tmp102 = 4
	  li $s1, 4		# load constant value 4 into $s1
	# _tmp103 = *(y)
	  lw $s2, 0($t4) 	# load with offset
	# _tmp104 = _tmp103 == _tmp100
	  seq $s3, $s2, $t7	
	# _tmp105 = _tmp103 < _tmp100
	  slt $s4, $s2, $t7	
	# _tmp106 = _tmp105 || _tmp104
	  or $s5, $s4, $s3	
	# _tmp107 = _tmp100 < _tmp101
	  slt $s6, $t7, $s0	
	# _tmp108 = _tmp107 || _tmp106
	  or $s7, $s6, $s5	
	# IfZ _tmp108 Goto _L10
	# (save modified registers before flow of control change)
	  sw $t2, -148($fp)	# spill _tmp97 from $t2 to $fp-148
	  sw $t3, -152($fp)	# spill _tmp98 from $t3 to $fp-152
	  sw $t5, -156($fp)	# spill _tmp99 from $t5 to $fp-156
	  sw $t7, -160($fp)	# spill _tmp100 from $t7 to $fp-160
	  sw $s0, -164($fp)	# spill _tmp101 from $s0 to $fp-164
	  sw $s1, -168($fp)	# spill _tmp102 from $s1 to $fp-168
	  sw $s2, -172($fp)	# spill _tmp103 from $s2 to $fp-172
	  sw $s3, -176($fp)	# spill _tmp104 from $s3 to $fp-176
	  sw $s4, -180($fp)	# spill _tmp105 from $s4 to $fp-180
	  sw $s5, -184($fp)	# spill _tmp106 from $s5 to $fp-184
	  sw $s6, -188($fp)	# spill _tmp107 from $s6 to $fp-188
	  sw $s7, -192($fp)	# spill _tmp108 from $s7 to $fp-192
	  beqz $s7, _L10	# branch if _tmp108 is zero 
	# _tmp109 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string9: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string9	# load label
	# PushParam _tmp109
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -196($fp)	# spill _tmp109 from $t0 to $fp-196
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L10:
	# _tmp110 = _tmp100 * _tmp102
	  lw $t0, -160($fp)	# load _tmp100 from $fp-160 into $t0
	  lw $t1, -168($fp)	# load _tmp102 from $fp-168 into $t1
	  mul $t2, $t0, $t1	
	# _tmp111 = _tmp110 + _tmp102
	  add $t3, $t2, $t1	
	# _tmp112 = y + _tmp111
	  lw $t4, -8($fp)	# load y from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# _tmp113 = *(_tmp112)
	  lw $t6, 0($t5) 	# load with offset
	# _tmp114 = 4
	  li $t7, 4		# load constant value 4 into $t7
	# _tmp115 = 5
	  li $s0, 5		# load constant value 5 into $s0
	# _tmp116 = 0
	  li $s1, 0		# load constant value 0 into $s1
	# _tmp117 = 4
	  li $s2, 4		# load constant value 4 into $s2
	# _tmp118 = *(y)
	  lw $s3, 0($t4) 	# load with offset
	# _tmp119 = _tmp118 == _tmp115
	  seq $s4, $s3, $s0	
	# _tmp120 = _tmp118 < _tmp115
	  slt $s5, $s3, $s0	
	# _tmp121 = _tmp120 || _tmp119
	  or $s6, $s5, $s4	
	# _tmp122 = _tmp115 < _tmp116
	  slt $s7, $s0, $s1	
	# _tmp123 = _tmp122 || _tmp121
	  or $t8, $s7, $s6	
	# IfZ _tmp123 Goto _L11
	# (save modified registers before flow of control change)
	  sw $t2, -200($fp)	# spill _tmp110 from $t2 to $fp-200
	  sw $t3, -204($fp)	# spill _tmp111 from $t3 to $fp-204
	  sw $t5, -208($fp)	# spill _tmp112 from $t5 to $fp-208
	  sw $t6, -212($fp)	# spill _tmp113 from $t6 to $fp-212
	  sw $t7, -216($fp)	# spill _tmp114 from $t7 to $fp-216
	  sw $s0, -220($fp)	# spill _tmp115 from $s0 to $fp-220
	  sw $s1, -224($fp)	# spill _tmp116 from $s1 to $fp-224
	  sw $s2, -228($fp)	# spill _tmp117 from $s2 to $fp-228
	  sw $s3, -232($fp)	# spill _tmp118 from $s3 to $fp-232
	  sw $s4, -236($fp)	# spill _tmp119 from $s4 to $fp-236
	  sw $s5, -240($fp)	# spill _tmp120 from $s5 to $fp-240
	  sw $s6, -244($fp)	# spill _tmp121 from $s6 to $fp-244
	  sw $s7, -248($fp)	# spill _tmp122 from $s7 to $fp-248
	  sw $t8, -252($fp)	# spill _tmp123 from $t8 to $fp-252
	  beqz $t8, _L11	# branch if _tmp123 is zero 
	# _tmp124 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string10: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string10	# load label
	# PushParam _tmp124
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -256($fp)	# spill _tmp124 from $t0 to $fp-256
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L11:
	# _tmp125 = _tmp115 * _tmp117
	  lw $t0, -220($fp)	# load _tmp115 from $fp-220 into $t0
	  lw $t1, -228($fp)	# load _tmp117 from $fp-228 into $t1
	  mul $t2, $t0, $t1	
	# _tmp126 = _tmp125 + _tmp117
	  add $t3, $t2, $t1	
	# _tmp127 = y + _tmp126
	  lw $t4, -8($fp)	# load y from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# *(_tmp127) = _tmp114
	  lw $t6, -216($fp)	# load _tmp114 from $fp-216 into $t6
	  sw $t6, 0($t5) 	# store with offset
	# PushParam y
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t4, 4($sp)	# copy param value to stack
	# LCall f_TakeArray
	# (save modified registers before flow of control change)
	  sw $t2, -260($fp)	# spill _tmp125 from $t2 to $fp-260
	  sw $t3, -264($fp)	# spill _tmp126 from $t3 to $fp-264
	  sw $t5, -268($fp)	# spill _tmp127 from $t5 to $fp-268
	  jal f_TakeArray    	# jump to function
	# _tmp128 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp129 = 10
	  li $t1, 10		# load constant value 10 into $t1
	# PushParam _tmp129
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# _tmp130 = LCall f_MakeArray
	# (save modified registers before flow of control change)
	  sw $t0, -272($fp)	# spill _tmp128 from $t0 to $fp-272
	  sw $t1, -276($fp)	# spill _tmp129 from $t1 to $fp-276
	  jal f_MakeArray    	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# b = _tmp130
	  move $t1, $t0		# copy value
	# _tmp131 = 0
	  li $t2, 0		# load constant value 0 into $t2
	# _tmp132 = 0
	  li $t3, 0		# load constant value 0 into $t3
	# _tmp133 = 4
	  li $t4, 4		# load constant value 4 into $t4
	# _tmp134 = *(b)
	  lw $t5, 0($t1) 	# load with offset
	# _tmp135 = _tmp134 == _tmp131
	  seq $t6, $t5, $t2	
	# _tmp136 = _tmp134 < _tmp131
	  slt $t7, $t5, $t2	
	# _tmp137 = _tmp136 || _tmp135
	  or $s0, $t7, $t6	
	# _tmp138 = _tmp131 < _tmp132
	  slt $s1, $t2, $t3	
	# _tmp139 = _tmp138 || _tmp137
	  or $s2, $s1, $s0	
	# IfZ _tmp139 Goto _L12
	# (save modified registers before flow of control change)
	  sw $t0, -280($fp)	# spill _tmp130 from $t0 to $fp-280
	  sw $t1, -12($fp)	# spill b from $t1 to $fp-12
	  sw $t2, -284($fp)	# spill _tmp131 from $t2 to $fp-284
	  sw $t3, -288($fp)	# spill _tmp132 from $t3 to $fp-288
	  sw $t4, -292($fp)	# spill _tmp133 from $t4 to $fp-292
	  sw $t5, -296($fp)	# spill _tmp134 from $t5 to $fp-296
	  sw $t6, -300($fp)	# spill _tmp135 from $t6 to $fp-300
	  sw $t7, -304($fp)	# spill _tmp136 from $t7 to $fp-304
	  sw $s0, -308($fp)	# spill _tmp137 from $s0 to $fp-308
	  sw $s1, -312($fp)	# spill _tmp138 from $s1 to $fp-312
	  sw $s2, -316($fp)	# spill _tmp139 from $s2 to $fp-316
	  beqz $s2, _L12	# branch if _tmp139 is zero 
	# _tmp140 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string11: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string11	# load label
	# PushParam _tmp140
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -320($fp)	# spill _tmp140 from $t0 to $fp-320
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L12:
	# _tmp141 = _tmp131 * _tmp133
	  lw $t0, -284($fp)	# load _tmp131 from $fp-284 into $t0
	  lw $t1, -292($fp)	# load _tmp133 from $fp-292 into $t1
	  mul $t2, $t0, $t1	
	# _tmp142 = _tmp141 + _tmp133
	  add $t3, $t2, $t1	
	# _tmp143 = b + _tmp142
	  lw $t4, -12($fp)	# load b from $fp-12 into $t4
	  add $t5, $t4, $t3	
	# _tmp144 = *(_tmp143)
	  lw $t6, 0($t5) 	# load with offset
	# PushParam _tmp144
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t6, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t2, -324($fp)	# spill _tmp141 from $t2 to $fp-324
	  sw $t3, -328($fp)	# spill _tmp142 from $t3 to $fp-328
	  sw $t5, -332($fp)	# spill _tmp143 from $t5 to $fp-332
	  sw $t6, -336($fp)	# spill _tmp144 from $t6 to $fp-336
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp145 = *(b)
	  lw $t0, -12($fp)	# load b from $fp-12 into $t0
	  lw $t1, 0($t0) 	# load with offset
	# PushParam _tmp145
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t1, -340($fp)	# spill _tmp145 from $t1 to $fp-340
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp146 = 5
	  li $t0, 5		# load constant value 5 into $t0
	# PushParam _tmp146
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# _tmp147 = LCall f_MakeArray
	# (save modified registers before flow of control change)
	  sw $t0, -344($fp)	# spill _tmp146 from $t0 to $fp-344
	  jal f_MakeArray    	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp148 = *(_tmp147)
	  lw $t1, 0($t0) 	# load with offset
	# PushParam _tmp148
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -348($fp)	# spill _tmp147 from $t0 to $fp-348
	  sw $t1, -352($fp)	# spill _tmp148 from $t1 to $fp-352
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
