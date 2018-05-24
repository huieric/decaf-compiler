	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  f_main:
  main:
	# BeginFunc 512
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 512	# decrement sp to make space for locals/temps
	# _tmp0 = 10
	  li $t0, 10		# load constant value 10 into $t0
	# _tmp1 = 0
	  li $t1, 0		# load constant value 0 into $t1
	# _tmp2 = 4
	  li $t2, 4		# load constant value 4 into $t2
	# _tmp3 = _tmp1 < _tmp0
	  slt $t3, $t1, $t0	
	# IfZ _tmp3 Goto _L0
	# (save modified registers before flow of control change)
	  sw $t0, -24($fp)	# spill _tmp0 from $t0 to $fp-24
	  sw $t1, -28($fp)	# spill _tmp1 from $t1 to $fp-28
	  sw $t2, -32($fp)	# spill _tmp2 from $t2 to $fp-32
	  sw $t3, -36($fp)	# spill _tmp3 from $t3 to $fp-36
	  beqz $t3, _L0	# branch if _tmp3 is zero 
	# Goto _L1
	  b _L1		# unconditional branch
  _L0:
	# _tmp4 = "Decaf runtime error: Array size is <= 0\n"
	  .data			# create string constant marked with label
	  _string1: .asciiz "Decaf runtime error: Array size is <= 0\n"
	  .text
	  la $t0, _string1	# load label
	# PushParam _tmp4
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -40($fp)	# spill _tmp4 from $t0 to $fp-40
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L1:
	# _tmp5 = _tmp0 * _tmp2
	  lw $t0, -24($fp)	# load _tmp0 from $fp-24 into $t0
	  lw $t1, -32($fp)	# load _tmp2 from $fp-32 into $t1
	  mul $t2, $t0, $t1	
	# _tmp6 = _tmp5 + _tmp2
	  add $t3, $t2, $t1	
	# PushParam _tmp6
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp7 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t2, -44($fp)	# spill _tmp5 from $t2 to $fp-44
	  sw $t3, -48($fp)	# spill _tmp6 from $t3 to $fp-48
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# *(_tmp7) = _tmp0
	  lw $t1, -24($fp)	# load _tmp0 from $fp-24 into $t1
	  sw $t1, 0($t0) 	# store with offset
	# b = _tmp7
	  move $t2, $t0		# copy value
	# _tmp8 = 20
	  li $t3, 20		# load constant value 20 into $t3
	# _tmp9 = 0
	  li $t4, 0		# load constant value 0 into $t4
	# _tmp10 = 4
	  li $t5, 4		# load constant value 4 into $t5
	# _tmp11 = _tmp9 < _tmp8
	  slt $t6, $t4, $t3	
	# IfZ _tmp11 Goto _L2
	# (save modified registers before flow of control change)
	  sw $t0, -52($fp)	# spill _tmp7 from $t0 to $fp-52
	  sw $t2, -8($fp)	# spill b from $t2 to $fp-8
	  sw $t3, -56($fp)	# spill _tmp8 from $t3 to $fp-56
	  sw $t4, -60($fp)	# spill _tmp9 from $t4 to $fp-60
	  sw $t5, -64($fp)	# spill _tmp10 from $t5 to $fp-64
	  sw $t6, -68($fp)	# spill _tmp11 from $t6 to $fp-68
	  beqz $t6, _L2	# branch if _tmp11 is zero 
	# Goto _L3
	  b _L3		# unconditional branch
  _L2:
	# _tmp12 = "Decaf runtime error: Array size is <= 0\n"
	  .data			# create string constant marked with label
	  _string2: .asciiz "Decaf runtime error: Array size is <= 0\n"
	  .text
	  la $t0, _string2	# load label
	# PushParam _tmp12
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -72($fp)	# spill _tmp12 from $t0 to $fp-72
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L3:
	# _tmp13 = _tmp8 * _tmp10
	  lw $t0, -56($fp)	# load _tmp8 from $fp-56 into $t0
	  lw $t1, -64($fp)	# load _tmp10 from $fp-64 into $t1
	  mul $t2, $t0, $t1	
	# _tmp14 = _tmp13 + _tmp10
	  add $t3, $t2, $t1	
	# PushParam _tmp14
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp15 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t2, -76($fp)	# spill _tmp13 from $t2 to $fp-76
	  sw $t3, -80($fp)	# spill _tmp14 from $t3 to $fp-80
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# *(_tmp15) = _tmp8
	  lw $t1, -56($fp)	# load _tmp8 from $fp-56 into $t1
	  sw $t1, 0($t0) 	# store with offset
	# c = _tmp15
	  move $t2, $t0		# copy value
	# _tmp16 = 3
	  li $t3, 3		# load constant value 3 into $t3
	# _tmp17 = 0
	  li $t4, 0		# load constant value 0 into $t4
	# _tmp18 = 4
	  li $t5, 4		# load constant value 4 into $t5
	# _tmp19 = _tmp17 < _tmp16
	  slt $t6, $t4, $t3	
	# IfZ _tmp19 Goto _L4
	# (save modified registers before flow of control change)
	  sw $t0, -84($fp)	# spill _tmp15 from $t0 to $fp-84
	  sw $t2, -12($fp)	# spill c from $t2 to $fp-12
	  sw $t3, -88($fp)	# spill _tmp16 from $t3 to $fp-88
	  sw $t4, -92($fp)	# spill _tmp17 from $t4 to $fp-92
	  sw $t5, -96($fp)	# spill _tmp18 from $t5 to $fp-96
	  sw $t6, -100($fp)	# spill _tmp19 from $t6 to $fp-100
	  beqz $t6, _L4	# branch if _tmp19 is zero 
	# Goto _L5
	  b _L5		# unconditional branch
  _L4:
	# _tmp20 = "Decaf runtime error: Array size is <= 0\n"
	  .data			# create string constant marked with label
	  _string3: .asciiz "Decaf runtime error: Array size is <= 0\n"
	  .text
	  la $t0, _string3	# load label
	# PushParam _tmp20
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -104($fp)	# spill _tmp20 from $t0 to $fp-104
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L5:
	# _tmp21 = _tmp16 * _tmp18
	  lw $t0, -88($fp)	# load _tmp16 from $fp-88 into $t0
	  lw $t1, -96($fp)	# load _tmp18 from $fp-96 into $t1
	  mul $t2, $t0, $t1	
	# _tmp22 = _tmp21 + _tmp18
	  add $t3, $t2, $t1	
	# PushParam _tmp22
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp23 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t2, -108($fp)	# spill _tmp21 from $t2 to $fp-108
	  sw $t3, -112($fp)	# spill _tmp22 from $t3 to $fp-112
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# *(_tmp23) = _tmp16
	  lw $t1, -88($fp)	# load _tmp16 from $fp-88 into $t1
	  sw $t1, 0($t0) 	# store with offset
	# s = _tmp23
	  move $t2, $t0		# copy value
	# _tmp24 = 3
	  li $t3, 3		# load constant value 3 into $t3
	# _tmp25 = 0
	  li $t4, 0		# load constant value 0 into $t4
	# _tmp26 = 4
	  li $t5, 4		# load constant value 4 into $t5
	# _tmp27 = *(b)
	  lw $t6, -8($fp)	# load b from $fp-8 into $t6
	  lw $t7, 0($t6) 	# load with offset
	# _tmp28 = _tmp27 == _tmp24
	  seq $s0, $t7, $t3	
	# _tmp29 = _tmp27 < _tmp24
	  slt $s1, $t7, $t3	
	# _tmp30 = _tmp29 || _tmp28
	  or $s2, $s1, $s0	
	# _tmp31 = _tmp24 < _tmp25
	  slt $s3, $t3, $t4	
	# _tmp32 = _tmp31 || _tmp30
	  or $s4, $s3, $s2	
	# IfZ _tmp32 Goto _L6
	# (save modified registers before flow of control change)
	  sw $t0, -116($fp)	# spill _tmp23 from $t0 to $fp-116
	  sw $t2, -20($fp)	# spill s from $t2 to $fp-20
	  sw $t3, -120($fp)	# spill _tmp24 from $t3 to $fp-120
	  sw $t4, -124($fp)	# spill _tmp25 from $t4 to $fp-124
	  sw $t5, -128($fp)	# spill _tmp26 from $t5 to $fp-128
	  sw $t7, -132($fp)	# spill _tmp27 from $t7 to $fp-132
	  sw $s0, -136($fp)	# spill _tmp28 from $s0 to $fp-136
	  sw $s1, -140($fp)	# spill _tmp29 from $s1 to $fp-140
	  sw $s2, -144($fp)	# spill _tmp30 from $s2 to $fp-144
	  sw $s3, -148($fp)	# spill _tmp31 from $s3 to $fp-148
	  sw $s4, -152($fp)	# spill _tmp32 from $s4 to $fp-152
	  beqz $s4, _L6	# branch if _tmp32 is zero 
	# _tmp33 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string4: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string4	# load label
	# PushParam _tmp33
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -156($fp)	# spill _tmp33 from $t0 to $fp-156
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L6:
	# _tmp34 = _tmp24 * _tmp26
	  lw $t0, -120($fp)	# load _tmp24 from $fp-120 into $t0
	  lw $t1, -128($fp)	# load _tmp26 from $fp-128 into $t1
	  mul $t2, $t0, $t1	
	# _tmp35 = _tmp34 + _tmp26
	  add $t3, $t2, $t1	
	# _tmp36 = b + _tmp35
	  lw $t4, -8($fp)	# load b from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# _tmp37 = *(_tmp36)
	  lw $t6, 0($t5) 	# load with offset
	# _tmp38 = 5
	  li $t7, 5		# load constant value 5 into $t7
	# _tmp39 = 3
	  li $s0, 3		# load constant value 3 into $s0
	# _tmp40 = 0
	  li $s1, 0		# load constant value 0 into $s1
	# _tmp41 = 4
	  li $s2, 4		# load constant value 4 into $s2
	# _tmp42 = *(b)
	  lw $s3, 0($t4) 	# load with offset
	# _tmp43 = _tmp42 == _tmp39
	  seq $s4, $s3, $s0	
	# _tmp44 = _tmp42 < _tmp39
	  slt $s5, $s3, $s0	
	# _tmp45 = _tmp44 || _tmp43
	  or $s6, $s5, $s4	
	# _tmp46 = _tmp39 < _tmp40
	  slt $s7, $s0, $s1	
	# _tmp47 = _tmp46 || _tmp45
	  or $t8, $s7, $s6	
	# IfZ _tmp47 Goto _L7
	# (save modified registers before flow of control change)
	  sw $t2, -160($fp)	# spill _tmp34 from $t2 to $fp-160
	  sw $t3, -164($fp)	# spill _tmp35 from $t3 to $fp-164
	  sw $t5, -168($fp)	# spill _tmp36 from $t5 to $fp-168
	  sw $t6, -172($fp)	# spill _tmp37 from $t6 to $fp-172
	  sw $t7, -176($fp)	# spill _tmp38 from $t7 to $fp-176
	  sw $s0, -180($fp)	# spill _tmp39 from $s0 to $fp-180
	  sw $s1, -184($fp)	# spill _tmp40 from $s1 to $fp-184
	  sw $s2, -188($fp)	# spill _tmp41 from $s2 to $fp-188
	  sw $s3, -192($fp)	# spill _tmp42 from $s3 to $fp-192
	  sw $s4, -196($fp)	# spill _tmp43 from $s4 to $fp-196
	  sw $s5, -200($fp)	# spill _tmp44 from $s5 to $fp-200
	  sw $s6, -204($fp)	# spill _tmp45 from $s6 to $fp-204
	  sw $s7, -208($fp)	# spill _tmp46 from $s7 to $fp-208
	  sw $t8, -212($fp)	# spill _tmp47 from $t8 to $fp-212
	  beqz $t8, _L7	# branch if _tmp47 is zero 
	# _tmp48 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string5: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string5	# load label
	# PushParam _tmp48
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -216($fp)	# spill _tmp48 from $t0 to $fp-216
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L7:
	# _tmp49 = _tmp39 * _tmp41
	  lw $t0, -180($fp)	# load _tmp39 from $fp-180 into $t0
	  lw $t1, -188($fp)	# load _tmp41 from $fp-188 into $t1
	  mul $t2, $t0, $t1	
	# _tmp50 = _tmp49 + _tmp41
	  add $t3, $t2, $t1	
	# _tmp51 = b + _tmp50
	  lw $t4, -8($fp)	# load b from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# *(_tmp51) = _tmp38
	  lw $t6, -176($fp)	# load _tmp38 from $fp-176 into $t6
	  sw $t6, 0($t5) 	# store with offset
	# _tmp52 = 6
	  li $t7, 6		# load constant value 6 into $t7
	# _tmp53 = 0
	  li $s0, 0		# load constant value 0 into $s0
	# _tmp54 = 4
	  li $s1, 4		# load constant value 4 into $s1
	# _tmp55 = *(c)
	  lw $s2, -12($fp)	# load c from $fp-12 into $s2
	  lw $s3, 0($s2) 	# load with offset
	# _tmp56 = _tmp55 == _tmp52
	  seq $s4, $s3, $t7	
	# _tmp57 = _tmp55 < _tmp52
	  slt $s5, $s3, $t7	
	# _tmp58 = _tmp57 || _tmp56
	  or $s6, $s5, $s4	
	# _tmp59 = _tmp52 < _tmp53
	  slt $s7, $t7, $s0	
	# _tmp60 = _tmp59 || _tmp58
	  or $t8, $s7, $s6	
	# IfZ _tmp60 Goto _L8
	# (save modified registers before flow of control change)
	  sw $t2, -220($fp)	# spill _tmp49 from $t2 to $fp-220
	  sw $t3, -224($fp)	# spill _tmp50 from $t3 to $fp-224
	  sw $t5, -228($fp)	# spill _tmp51 from $t5 to $fp-228
	  sw $t7, -232($fp)	# spill _tmp52 from $t7 to $fp-232
	  sw $s0, -236($fp)	# spill _tmp53 from $s0 to $fp-236
	  sw $s1, -240($fp)	# spill _tmp54 from $s1 to $fp-240
	  sw $s3, -244($fp)	# spill _tmp55 from $s3 to $fp-244
	  sw $s4, -248($fp)	# spill _tmp56 from $s4 to $fp-248
	  sw $s5, -252($fp)	# spill _tmp57 from $s5 to $fp-252
	  sw $s6, -256($fp)	# spill _tmp58 from $s6 to $fp-256
	  sw $s7, -260($fp)	# spill _tmp59 from $s7 to $fp-260
	  sw $t8, -264($fp)	# spill _tmp60 from $t8 to $fp-264
	  beqz $t8, _L8	# branch if _tmp60 is zero 
	# _tmp61 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string6: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string6	# load label
	# PushParam _tmp61
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -268($fp)	# spill _tmp61 from $t0 to $fp-268
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L8:
	# _tmp62 = _tmp52 * _tmp54
	  lw $t0, -232($fp)	# load _tmp52 from $fp-232 into $t0
	  lw $t1, -240($fp)	# load _tmp54 from $fp-240 into $t1
	  mul $t2, $t0, $t1	
	# _tmp63 = _tmp62 + _tmp54
	  add $t3, $t2, $t1	
	# _tmp64 = c + _tmp63
	  lw $t4, -12($fp)	# load c from $fp-12 into $t4
	  add $t5, $t4, $t3	
	# _tmp65 = *(_tmp64)
	  lw $t6, 0($t5) 	# load with offset
	# _tmp66 = 1
	  li $t7, 1		# load constant value 1 into $t7
	# _tmp67 = 6
	  li $s0, 6		# load constant value 6 into $s0
	# _tmp68 = 0
	  li $s1, 0		# load constant value 0 into $s1
	# _tmp69 = 4
	  li $s2, 4		# load constant value 4 into $s2
	# _tmp70 = *(c)
	  lw $s3, 0($t4) 	# load with offset
	# _tmp71 = _tmp70 == _tmp67
	  seq $s4, $s3, $s0	
	# _tmp72 = _tmp70 < _tmp67
	  slt $s5, $s3, $s0	
	# _tmp73 = _tmp72 || _tmp71
	  or $s6, $s5, $s4	
	# _tmp74 = _tmp67 < _tmp68
	  slt $s7, $s0, $s1	
	# _tmp75 = _tmp74 || _tmp73
	  or $t8, $s7, $s6	
	# IfZ _tmp75 Goto _L9
	# (save modified registers before flow of control change)
	  sw $t2, -272($fp)	# spill _tmp62 from $t2 to $fp-272
	  sw $t3, -276($fp)	# spill _tmp63 from $t3 to $fp-276
	  sw $t5, -280($fp)	# spill _tmp64 from $t5 to $fp-280
	  sw $t6, -284($fp)	# spill _tmp65 from $t6 to $fp-284
	  sw $t7, -288($fp)	# spill _tmp66 from $t7 to $fp-288
	  sw $s0, -292($fp)	# spill _tmp67 from $s0 to $fp-292
	  sw $s1, -296($fp)	# spill _tmp68 from $s1 to $fp-296
	  sw $s2, -300($fp)	# spill _tmp69 from $s2 to $fp-300
	  sw $s3, -304($fp)	# spill _tmp70 from $s3 to $fp-304
	  sw $s4, -308($fp)	# spill _tmp71 from $s4 to $fp-308
	  sw $s5, -312($fp)	# spill _tmp72 from $s5 to $fp-312
	  sw $s6, -316($fp)	# spill _tmp73 from $s6 to $fp-316
	  sw $s7, -320($fp)	# spill _tmp74 from $s7 to $fp-320
	  sw $t8, -324($fp)	# spill _tmp75 from $t8 to $fp-324
	  beqz $t8, _L9	# branch if _tmp75 is zero 
	# _tmp76 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string7: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string7	# load label
	# PushParam _tmp76
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -328($fp)	# spill _tmp76 from $t0 to $fp-328
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L9:
	# _tmp77 = _tmp67 * _tmp69
	  lw $t0, -292($fp)	# load _tmp67 from $fp-292 into $t0
	  lw $t1, -300($fp)	# load _tmp69 from $fp-300 into $t1
	  mul $t2, $t0, $t1	
	# _tmp78 = _tmp77 + _tmp69
	  add $t3, $t2, $t1	
	# _tmp79 = c + _tmp78
	  lw $t4, -12($fp)	# load c from $fp-12 into $t4
	  add $t5, $t4, $t3	
	# *(_tmp79) = _tmp66
	  lw $t6, -288($fp)	# load _tmp66 from $fp-288 into $t6
	  sw $t6, 0($t5) 	# store with offset
	# d = b
	  lw $t7, -8($fp)	# load b from $fp-8 into $t7
	  move $s0, $t7		# copy value
	# _tmp80 = 2
	  li $s1, 2		# load constant value 2 into $s1
	# _tmp81 = 0
	  li $s2, 0		# load constant value 0 into $s2
	# _tmp82 = 4
	  li $s3, 4		# load constant value 4 into $s3
	# _tmp83 = *(s)
	  lw $s4, -20($fp)	# load s from $fp-20 into $s4
	  lw $s5, 0($s4) 	# load with offset
	# _tmp84 = _tmp83 == _tmp80
	  seq $s6, $s5, $s1	
	# _tmp85 = _tmp83 < _tmp80
	  slt $s7, $s5, $s1	
	# _tmp86 = _tmp85 || _tmp84
	  or $t8, $s7, $s6	
	# _tmp87 = _tmp80 < _tmp81
	  slt $t9, $s1, $s2	
	# _tmp88 = _tmp87 || _tmp86
	  or $t0, $t9, $t8	
	# IfZ _tmp88 Goto _L10
	# (save modified registers before flow of control change)
	  sw $t0, -376($fp)	# spill _tmp88 from $t0 to $fp-376
	  sw $t2, -332($fp)	# spill _tmp77 from $t2 to $fp-332
	  sw $t3, -336($fp)	# spill _tmp78 from $t3 to $fp-336
	  sw $t5, -340($fp)	# spill _tmp79 from $t5 to $fp-340
	  sw $s0, -16($fp)	# spill d from $s0 to $fp-16
	  sw $s1, -344($fp)	# spill _tmp80 from $s1 to $fp-344
	  sw $s2, -348($fp)	# spill _tmp81 from $s2 to $fp-348
	  sw $s3, -352($fp)	# spill _tmp82 from $s3 to $fp-352
	  sw $s5, -356($fp)	# spill _tmp83 from $s5 to $fp-356
	  sw $s6, -360($fp)	# spill _tmp84 from $s6 to $fp-360
	  sw $s7, -364($fp)	# spill _tmp85 from $s7 to $fp-364
	  sw $t8, -368($fp)	# spill _tmp86 from $t8 to $fp-368
	  sw $t9, -372($fp)	# spill _tmp87 from $t9 to $fp-372
	  beqz $t0, _L10	# branch if _tmp88 is zero 
	# _tmp89 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string8: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string8	# load label
	# PushParam _tmp89
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -380($fp)	# spill _tmp89 from $t0 to $fp-380
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L10:
	# _tmp90 = _tmp80 * _tmp82
	  lw $t0, -344($fp)	# load _tmp80 from $fp-344 into $t0
	  lw $t1, -352($fp)	# load _tmp82 from $fp-352 into $t1
	  mul $t2, $t0, $t1	
	# _tmp91 = _tmp90 + _tmp82
	  add $t3, $t2, $t1	
	# _tmp92 = s + _tmp91
	  lw $t4, -20($fp)	# load s from $fp-20 into $t4
	  add $t5, $t4, $t3	
	# _tmp93 = *(_tmp92)
	  lw $t6, 0($t5) 	# load with offset
	# _tmp94 = "hello"
	  .data			# create string constant marked with label
	  _string9: .asciiz "hello"
	  .text
	  la $t7, _string9	# load label
	# _tmp95 = 2
	  li $s0, 2		# load constant value 2 into $s0
	# _tmp96 = 0
	  li $s1, 0		# load constant value 0 into $s1
	# _tmp97 = 4
	  li $s2, 4		# load constant value 4 into $s2
	# _tmp98 = *(s)
	  lw $s3, 0($t4) 	# load with offset
	# _tmp99 = _tmp98 == _tmp95
	  seq $s4, $s3, $s0	
	# _tmp100 = _tmp98 < _tmp95
	  slt $s5, $s3, $s0	
	# _tmp101 = _tmp100 || _tmp99
	  or $s6, $s5, $s4	
	# _tmp102 = _tmp95 < _tmp96
	  slt $s7, $s0, $s1	
	# _tmp103 = _tmp102 || _tmp101
	  or $t8, $s7, $s6	
	# IfZ _tmp103 Goto _L11
	# (save modified registers before flow of control change)
	  sw $t2, -384($fp)	# spill _tmp90 from $t2 to $fp-384
	  sw $t3, -388($fp)	# spill _tmp91 from $t3 to $fp-388
	  sw $t5, -392($fp)	# spill _tmp92 from $t5 to $fp-392
	  sw $t6, -396($fp)	# spill _tmp93 from $t6 to $fp-396
	  sw $t7, -400($fp)	# spill _tmp94 from $t7 to $fp-400
	  sw $s0, -404($fp)	# spill _tmp95 from $s0 to $fp-404
	  sw $s1, -408($fp)	# spill _tmp96 from $s1 to $fp-408
	  sw $s2, -412($fp)	# spill _tmp97 from $s2 to $fp-412
	  sw $s3, -416($fp)	# spill _tmp98 from $s3 to $fp-416
	  sw $s4, -420($fp)	# spill _tmp99 from $s4 to $fp-420
	  sw $s5, -424($fp)	# spill _tmp100 from $s5 to $fp-424
	  sw $s6, -428($fp)	# spill _tmp101 from $s6 to $fp-428
	  sw $s7, -432($fp)	# spill _tmp102 from $s7 to $fp-432
	  sw $t8, -436($fp)	# spill _tmp103 from $t8 to $fp-436
	  beqz $t8, _L11	# branch if _tmp103 is zero 
	# _tmp104 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string10: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string10	# load label
	# PushParam _tmp104
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -440($fp)	# spill _tmp104 from $t0 to $fp-440
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L11:
	# _tmp105 = _tmp95 * _tmp97
	  lw $t0, -404($fp)	# load _tmp95 from $fp-404 into $t0
	  lw $t1, -412($fp)	# load _tmp97 from $fp-412 into $t1
	  mul $t2, $t0, $t1	
	# _tmp106 = _tmp105 + _tmp97
	  add $t3, $t2, $t1	
	# _tmp107 = s + _tmp106
	  lw $t4, -20($fp)	# load s from $fp-20 into $t4
	  add $t5, $t4, $t3	
	# *(_tmp107) = _tmp94
	  lw $t6, -400($fp)	# load _tmp94 from $fp-400 into $t6
	  sw $t6, 0($t5) 	# store with offset
	# _tmp108 = 3
	  li $t7, 3		# load constant value 3 into $t7
	# _tmp109 = 0
	  li $s0, 0		# load constant value 0 into $s0
	# _tmp110 = 4
	  li $s1, 4		# load constant value 4 into $s1
	# _tmp111 = *(b)
	  lw $s2, -8($fp)	# load b from $fp-8 into $s2
	  lw $s3, 0($s2) 	# load with offset
	# _tmp112 = _tmp111 == _tmp108
	  seq $s4, $s3, $t7	
	# _tmp113 = _tmp111 < _tmp108
	  slt $s5, $s3, $t7	
	# _tmp114 = _tmp113 || _tmp112
	  or $s6, $s5, $s4	
	# _tmp115 = _tmp108 < _tmp109
	  slt $s7, $t7, $s0	
	# _tmp116 = _tmp115 || _tmp114
	  or $t8, $s7, $s6	
	# IfZ _tmp116 Goto _L12
	# (save modified registers before flow of control change)
	  sw $t2, -444($fp)	# spill _tmp105 from $t2 to $fp-444
	  sw $t3, -448($fp)	# spill _tmp106 from $t3 to $fp-448
	  sw $t5, -452($fp)	# spill _tmp107 from $t5 to $fp-452
	  sw $t7, -456($fp)	# spill _tmp108 from $t7 to $fp-456
	  sw $s0, -460($fp)	# spill _tmp109 from $s0 to $fp-460
	  sw $s1, -464($fp)	# spill _tmp110 from $s1 to $fp-464
	  sw $s3, -468($fp)	# spill _tmp111 from $s3 to $fp-468
	  sw $s4, -472($fp)	# spill _tmp112 from $s4 to $fp-472
	  sw $s5, -476($fp)	# spill _tmp113 from $s5 to $fp-476
	  sw $s6, -480($fp)	# spill _tmp114 from $s6 to $fp-480
	  sw $s7, -484($fp)	# spill _tmp115 from $s7 to $fp-484
	  sw $t8, -488($fp)	# spill _tmp116 from $t8 to $fp-488
	  beqz $t8, _L12	# branch if _tmp116 is zero 
	# _tmp117 = "Decaf runtime error: Array subscript out of bound..."
	  .data			# create string constant marked with label
	  _string11: .asciiz "Decaf runtime error: Array subscript out of bounds\n"
	  .text
	  la $t0, _string11	# load label
	# PushParam _tmp117
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -492($fp)	# spill _tmp117 from $t0 to $fp-492
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# LCall _Halt
	  jal _Halt          	# jump to function
  _L12:
	# _tmp118 = _tmp108 * _tmp110
	  lw $t0, -456($fp)	# load _tmp108 from $fp-456 into $t0
	  lw $t1, -464($fp)	# load _tmp110 from $fp-464 into $t1
	  mul $t2, $t0, $t1	
	# _tmp119 = _tmp118 + _tmp110
	  add $t3, $t2, $t1	
	# _tmp120 = b + _tmp119
	  lw $t4, -8($fp)	# load b from $fp-8 into $t4
	  add $t5, $t4, $t3	
	# _tmp121 = *(_tmp120)
	  lw $t6, 0($t5) 	# load with offset
	# PushParam _tmp121
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t6, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t2, -496($fp)	# spill _tmp118 from $t2 to $fp-496
	  sw $t3, -500($fp)	# spill _tmp119 from $t3 to $fp-500
	  sw $t5, -504($fp)	# spill _tmp120 from $t5 to $fp-504
	  sw $t6, -508($fp)	# spill _tmp121 from $t6 to $fp-508
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp122 = *(b)
	  lw $t0, -8($fp)	# load b from $fp-8 into $t0
	  lw $t1, 0($t0) 	# load with offset
	# PushParam _tmp122
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t1, -512($fp)	# spill _tmp122 from $t1 to $fp-512
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp123 = "\n"
	  .data			# create string constant marked with label
	  _string12: .asciiz "\n"
	  .text
	  la $t0, _string12	# load label
	# PushParam _tmp123
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -516($fp)	# spill _tmp123 from $t0 to $fp-516
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
