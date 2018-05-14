	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  _offset_Point_0:
	# BeginFunc 4
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 4	# decrement sp to make space for locals/temps
	# _tmp0 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# Return _tmp0
	  move $v0, $t0		# assign return value into $v0
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
	# VTable for class Point
	  .data
	  .align 2
	  Point:		# label for class Point vtable
	  .word _offset_Point_0
	  .word f_Point.Init
	  .word f_Point.PrintSelf
	  .word f_Point.PrintBoth
	  .word f_Point.equals
	  .text
  f_Point.Init:
	# BeginFunc 40
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 40	# decrement sp to make space for locals/temps
	# _tmp1 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp2 = this + _tmp1
	  lw $t1, 4($fp)	# load this from $fp+4 into $t1
	  add $t2, $t1, $t0	
	# _tmp3 = *(_tmp2)
	  lw $t3, 0($t2) 	# load with offset
	# _tmp4 = 4
	  li $t4, 4		# load constant value 4 into $t4
	# _tmp5 = this + _tmp4
	  add $t5, $t1, $t4	
	# *(_tmp5) = x
	  lw $t6, 8($fp)	# load x from $fp+8 into $t6
	  sw $t6, 0($t5) 	# store with offset
	# _tmp6 = 8
	  li $t7, 8		# load constant value 8 into $t7
	# _tmp7 = this + _tmp6
	  add $s0, $t1, $t7	
	# _tmp8 = *(_tmp7)
	  lw $s1, 0($s0) 	# load with offset
	# _tmp9 = 8
	  li $s2, 8		# load constant value 8 into $s2
	# _tmp10 = this + _tmp9
	  add $s3, $t1, $s2	
	# *(_tmp10) = y
	  lw $s4, 12($fp)	# load y from $fp+12 into $s4
	  sw $s4, 0($s3) 	# store with offset
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  f_Point.PrintSelf:
	# BeginFunc 36
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 36	# decrement sp to make space for locals/temps
	# _tmp11 = "["
	  .data			# create string constant marked with label
	  _string1: .asciiz "["
	  .text
	  la $t0, _string1	# load label
	# PushParam _tmp11
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -8($fp)	# spill _tmp11 from $t0 to $fp-8
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp12 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp13 = this + _tmp12
	  lw $t1, 4($fp)	# load this from $fp+4 into $t1
	  add $t2, $t1, $t0	
	# _tmp14 = *(_tmp13)
	  lw $t3, 0($t2) 	# load with offset
	# PushParam _tmp14
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp12 from $t0 to $fp-12
	  sw $t2, -16($fp)	# spill _tmp13 from $t2 to $fp-16
	  sw $t3, -20($fp)	# spill _tmp14 from $t3 to $fp-20
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp15 = ", "
	  .data			# create string constant marked with label
	  _string2: .asciiz ", "
	  .text
	  la $t0, _string2	# load label
	# PushParam _tmp15
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -24($fp)	# spill _tmp15 from $t0 to $fp-24
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp16 = 8
	  li $t0, 8		# load constant value 8 into $t0
	# _tmp17 = this + _tmp16
	  lw $t1, 4($fp)	# load this from $fp+4 into $t1
	  add $t2, $t1, $t0	
	# _tmp18 = *(_tmp17)
	  lw $t3, 0($t2) 	# load with offset
	# PushParam _tmp18
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -28($fp)	# spill _tmp16 from $t0 to $fp-28
	  sw $t2, -32($fp)	# spill _tmp17 from $t2 to $fp-32
	  sw $t3, -36($fp)	# spill _tmp18 from $t3 to $fp-36
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp19 = "]\n"
	  .data			# create string constant marked with label
	  _string3: .asciiz "]\n"
	  .text
	  la $t0, _string3	# load label
	# PushParam _tmp19
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -40($fp)	# spill _tmp19 from $t0 to $fp-40
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  f_Point.PrintBoth:
	# BeginFunc 72
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 72	# decrement sp to make space for locals/temps
	# _tmp20 = *(this)
	  lw $t0, 4($fp)	# load this from $fp+4 into $t0
	  lw $t1, 0($t0) 	# load with offset
	# _tmp21 = *(_tmp20)
	  lw $t2, 0($t1) 	# load with offset
	# _tmp22 = ACall _tmp21
	# (save modified registers before flow of control change)
	  sw $t1, -8($fp)	# spill _tmp20 from $t1 to $fp-8
	  sw $t2, -12($fp)	# spill _tmp21 from $t2 to $fp-12
	  jalr $t2            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp23 = this - _tmp22
	  lw $t1, 4($fp)	# load this from $fp+4 into $t1
	  sub $t2, $t1, $t0	
	# _tmp24 = *(_tmp20 + 8)
	  lw $t3, -8($fp)	# load _tmp20 from $fp-8 into $t3
	  lw $t4, 8($t3) 	# load with offset
	# PushParam _tmp23
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# ACall _tmp24
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp22 from $t0 to $fp-16
	  sw $t2, -20($fp)	# spill _tmp23 from $t2 to $fp-20
	  sw $t4, -24($fp)	# spill _tmp24 from $t4 to $fp-24
	  jalr $t4            	# jump to function
	# _tmp25 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp26 = *(other)
	  lw $t1, 8($fp)	# load other from $fp+8 into $t1
	  lw $t2, 0($t1) 	# load with offset
	# _tmp27 = *(_tmp26)
	  lw $t3, 0($t2) 	# load with offset
	# _tmp28 = ACall _tmp27
	# (save modified registers before flow of control change)
	  sw $t0, -28($fp)	# spill _tmp25 from $t0 to $fp-28
	  sw $t2, -32($fp)	# spill _tmp26 from $t2 to $fp-32
	  sw $t3, -36($fp)	# spill _tmp27 from $t3 to $fp-36
	  jalr $t3            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp29 = other - _tmp28
	  lw $t1, 8($fp)	# load other from $fp+8 into $t1
	  sub $t2, $t1, $t0	
	# _tmp30 = *(_tmp26 + 8)
	  lw $t3, -32($fp)	# load _tmp26 from $fp-32 into $t3
	  lw $t4, 8($t3) 	# load with offset
	# PushParam _tmp29
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# ACall _tmp30
	# (save modified registers before flow of control change)
	  sw $t0, -40($fp)	# spill _tmp28 from $t0 to $fp-40
	  sw $t2, -44($fp)	# spill _tmp29 from $t2 to $fp-44
	  sw $t4, -48($fp)	# spill _tmp30 from $t4 to $fp-48
	  jalr $t4            	# jump to function
	# _tmp31 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp32 = 4
	  li $t1, 4		# load constant value 4 into $t1
	# _tmp33 = this + _tmp32
	  lw $t2, 4($fp)	# load this from $fp+4 into $t2
	  add $t3, $t2, $t1	
	# _tmp34 = *(_tmp33)
	  lw $t4, 0($t3) 	# load with offset
	# PushParam _tmp34
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t4, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -52($fp)	# spill _tmp31 from $t0 to $fp-52
	  sw $t1, -56($fp)	# spill _tmp32 from $t1 to $fp-56
	  sw $t3, -60($fp)	# spill _tmp33 from $t3 to $fp-60
	  sw $t4, -64($fp)	# spill _tmp34 from $t4 to $fp-64
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp35 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp36 = other + _tmp35
	  lw $t1, 8($fp)	# load other from $fp+8 into $t1
	  add $t2, $t1, $t0	
	# _tmp37 = *(_tmp36)
	  lw $t3, 0($t2) 	# load with offset
	# PushParam _tmp37
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -68($fp)	# spill _tmp35 from $t0 to $fp-68
	  sw $t2, -72($fp)	# spill _tmp36 from $t2 to $fp-72
	  sw $t3, -76($fp)	# spill _tmp37 from $t3 to $fp-76
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  f_Point.equals:
	# BeginFunc 60
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 60	# decrement sp to make space for locals/temps
	# _tmp38 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp39 = this + _tmp38
	  lw $t1, 4($fp)	# load this from $fp+4 into $t1
	  add $t2, $t1, $t0	
	# _tmp40 = *(_tmp39)
	  lw $t3, 0($t2) 	# load with offset
	# _tmp41 = 4
	  li $t4, 4		# load constant value 4 into $t4
	# _tmp42 = other + _tmp41
	  lw $t5, 8($fp)	# load other from $fp+8 into $t5
	  add $t6, $t5, $t4	
	# _tmp43 = *(_tmp42)
	  lw $t7, 0($t6) 	# load with offset
	# _tmp44 = _tmp40 == _tmp43
	  seq $s0, $t3, $t7	
	# _tmp45 = 8
	  li $s1, 8		# load constant value 8 into $s1
	# _tmp46 = this + _tmp45
	  add $s2, $t1, $s1	
	# _tmp47 = *(_tmp46)
	  lw $s3, 0($s2) 	# load with offset
	# _tmp48 = 8
	  li $s4, 8		# load constant value 8 into $s4
	# _tmp49 = other + _tmp48
	  add $s5, $t5, $s4	
	# _tmp50 = *(_tmp49)
	  lw $s6, 0($s5) 	# load with offset
	# _tmp51 = _tmp47 == _tmp50
	  seq $s7, $s3, $s6	
	# _tmp52 = _tmp44 && _tmp51
	  and $t8, $s0, $s7	
	# Return _tmp52
	  move $v0, $t8		# assign return value into $v0
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
	# BeginFunc 216
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 216	# decrement sp to make space for locals/temps
	# _tmp53 = 12
	  li $t0, 12		# load constant value 12 into $t0
	# PushParam _tmp53
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# _tmp54 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp53 from $t0 to $fp-16
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp55 = Point
	  la $t1, Point	# load label
	# *(_tmp54) = _tmp55
	  sw $t1, 0($t0) 	# store with offset
	# p = _tmp54
	  move $t2, $t0		# copy value
	# _tmp56 = 5
	  li $t3, 5		# load constant value 5 into $t3
	# PushParam _tmp56
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp57 = 3
	  li $t4, 3		# load constant value 3 into $t4
	# PushParam _tmp57
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t4, 4($sp)	# copy param value to stack
	# _tmp58 = *(p)
	  lw $t5, 0($t2) 	# load with offset
	# _tmp59 = *(_tmp58)
	  lw $t6, 0($t5) 	# load with offset
	# _tmp60 = ACall _tmp59
	# (save modified registers before flow of control change)
	  sw $t0, -20($fp)	# spill _tmp54 from $t0 to $fp-20
	  sw $t1, -24($fp)	# spill _tmp55 from $t1 to $fp-24
	  sw $t2, -8($fp)	# spill p from $t2 to $fp-8
	  sw $t3, -28($fp)	# spill _tmp56 from $t3 to $fp-28
	  sw $t4, -32($fp)	# spill _tmp57 from $t4 to $fp-32
	  sw $t5, -36($fp)	# spill _tmp58 from $t5 to $fp-36
	  sw $t6, -40($fp)	# spill _tmp59 from $t6 to $fp-40
	  jalr $t6            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp61 = p - _tmp60
	  lw $t1, -8($fp)	# load p from $fp-8 into $t1
	  sub $t2, $t1, $t0	
	# _tmp62 = *(_tmp58 + 4)
	  lw $t3, -36($fp)	# load _tmp58 from $fp-36 into $t3
	  lw $t4, 4($t3) 	# load with offset
	# PushParam _tmp61
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# ACall _tmp62
	# (save modified registers before flow of control change)
	  sw $t0, -44($fp)	# spill _tmp60 from $t0 to $fp-44
	  sw $t2, -48($fp)	# spill _tmp61 from $t2 to $fp-48
	  sw $t4, -52($fp)	# spill _tmp62 from $t4 to $fp-52
	  jalr $t4            	# jump to function
	# _tmp63 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 12
	  add $sp, $sp, 12	# pop params off stack
	# _tmp64 = *(p)
	  lw $t1, -8($fp)	# load p from $fp-8 into $t1
	  lw $t2, 0($t1) 	# load with offset
	# _tmp65 = *(_tmp64)
	  lw $t3, 0($t2) 	# load with offset
	# _tmp66 = ACall _tmp65
	# (save modified registers before flow of control change)
	  sw $t0, -56($fp)	# spill _tmp63 from $t0 to $fp-56
	  sw $t2, -60($fp)	# spill _tmp64 from $t2 to $fp-60
	  sw $t3, -64($fp)	# spill _tmp65 from $t3 to $fp-64
	  jalr $t3            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp67 = p - _tmp66
	  lw $t1, -8($fp)	# load p from $fp-8 into $t1
	  sub $t2, $t1, $t0	
	# _tmp68 = *(_tmp64 + 8)
	  lw $t3, -60($fp)	# load _tmp64 from $fp-60 into $t3
	  lw $t4, 8($t3) 	# load with offset
	# PushParam _tmp67
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# ACall _tmp68
	# (save modified registers before flow of control change)
	  sw $t0, -68($fp)	# spill _tmp66 from $t0 to $fp-68
	  sw $t2, -72($fp)	# spill _tmp67 from $t2 to $fp-72
	  sw $t4, -76($fp)	# spill _tmp68 from $t4 to $fp-76
	  jalr $t4            	# jump to function
	# _tmp69 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp70 = 12
	  li $t1, 12		# load constant value 12 into $t1
	# PushParam _tmp70
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# _tmp71 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t0, -80($fp)	# spill _tmp69 from $t0 to $fp-80
	  sw $t1, -84($fp)	# spill _tmp70 from $t1 to $fp-84
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp72 = Point
	  la $t1, Point	# load label
	# *(_tmp71) = _tmp72
	  sw $t1, 0($t0) 	# store with offset
	# q = _tmp71
	  move $t2, $t0		# copy value
	# _tmp73 = 6
	  li $t3, 6		# load constant value 6 into $t3
	# PushParam _tmp73
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp74 = 5
	  li $t4, 5		# load constant value 5 into $t4
	# PushParam _tmp74
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t4, 4($sp)	# copy param value to stack
	# _tmp75 = *(q)
	  lw $t5, 0($t2) 	# load with offset
	# _tmp76 = *(_tmp75)
	  lw $t6, 0($t5) 	# load with offset
	# _tmp77 = ACall _tmp76
	# (save modified registers before flow of control change)
	  sw $t0, -88($fp)	# spill _tmp71 from $t0 to $fp-88
	  sw $t1, -92($fp)	# spill _tmp72 from $t1 to $fp-92
	  sw $t2, -12($fp)	# spill q from $t2 to $fp-12
	  sw $t3, -96($fp)	# spill _tmp73 from $t3 to $fp-96
	  sw $t4, -100($fp)	# spill _tmp74 from $t4 to $fp-100
	  sw $t5, -104($fp)	# spill _tmp75 from $t5 to $fp-104
	  sw $t6, -108($fp)	# spill _tmp76 from $t6 to $fp-108
	  jalr $t6            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp78 = q - _tmp77
	  lw $t1, -12($fp)	# load q from $fp-12 into $t1
	  sub $t2, $t1, $t0	
	# _tmp79 = *(_tmp75 + 4)
	  lw $t3, -104($fp)	# load _tmp75 from $fp-104 into $t3
	  lw $t4, 4($t3) 	# load with offset
	# PushParam _tmp78
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# ACall _tmp79
	# (save modified registers before flow of control change)
	  sw $t0, -112($fp)	# spill _tmp77 from $t0 to $fp-112
	  sw $t2, -116($fp)	# spill _tmp78 from $t2 to $fp-116
	  sw $t4, -120($fp)	# spill _tmp79 from $t4 to $fp-120
	  jalr $t4            	# jump to function
	# _tmp80 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 12
	  add $sp, $sp, 12	# pop params off stack
	# _tmp81 = *(q)
	  lw $t1, -12($fp)	# load q from $fp-12 into $t1
	  lw $t2, 0($t1) 	# load with offset
	# _tmp82 = *(_tmp81)
	  lw $t3, 0($t2) 	# load with offset
	# _tmp83 = ACall _tmp82
	# (save modified registers before flow of control change)
	  sw $t0, -124($fp)	# spill _tmp80 from $t0 to $fp-124
	  sw $t2, -128($fp)	# spill _tmp81 from $t2 to $fp-128
	  sw $t3, -132($fp)	# spill _tmp82 from $t3 to $fp-132
	  jalr $t3            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp84 = q - _tmp83
	  lw $t1, -12($fp)	# load q from $fp-12 into $t1
	  sub $t2, $t1, $t0	
	# _tmp85 = *(_tmp81 + 8)
	  lw $t3, -128($fp)	# load _tmp81 from $fp-128 into $t3
	  lw $t4, 8($t3) 	# load with offset
	# PushParam _tmp84
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# ACall _tmp85
	# (save modified registers before flow of control change)
	  sw $t0, -136($fp)	# spill _tmp83 from $t0 to $fp-136
	  sw $t2, -140($fp)	# spill _tmp84 from $t2 to $fp-140
	  sw $t4, -144($fp)	# spill _tmp85 from $t4 to $fp-144
	  jalr $t4            	# jump to function
	# _tmp86 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam q
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t1, -12($fp)	# load q from $fp-12 into $t1
	  sw $t1, 4($sp)	# copy param value to stack
	# _tmp87 = *(p)
	  lw $t2, -8($fp)	# load p from $fp-8 into $t2
	  lw $t3, 0($t2) 	# load with offset
	# _tmp88 = *(_tmp87)
	  lw $t4, 0($t3) 	# load with offset
	# _tmp89 = ACall _tmp88
	# (save modified registers before flow of control change)
	  sw $t0, -148($fp)	# spill _tmp86 from $t0 to $fp-148
	  sw $t3, -152($fp)	# spill _tmp87 from $t3 to $fp-152
	  sw $t4, -156($fp)	# spill _tmp88 from $t4 to $fp-156
	  jalr $t4            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp90 = p - _tmp89
	  lw $t1, -8($fp)	# load p from $fp-8 into $t1
	  sub $t2, $t1, $t0	
	# _tmp91 = *(_tmp87 + 12)
	  lw $t3, -152($fp)	# load _tmp87 from $fp-152 into $t3
	  lw $t4, 12($t3) 	# load with offset
	# PushParam _tmp90
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# ACall _tmp91
	# (save modified registers before flow of control change)
	  sw $t0, -160($fp)	# spill _tmp89 from $t0 to $fp-160
	  sw $t2, -164($fp)	# spill _tmp90 from $t2 to $fp-164
	  sw $t4, -168($fp)	# spill _tmp91 from $t4 to $fp-168
	  jalr $t4            	# jump to function
	# _tmp92 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 8
	  add $sp, $sp, 8	# pop params off stack
	# PushParam q
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t1, -12($fp)	# load q from $fp-12 into $t1
	  sw $t1, 4($sp)	# copy param value to stack
	# _tmp93 = *(p)
	  lw $t2, -8($fp)	# load p from $fp-8 into $t2
	  lw $t3, 0($t2) 	# load with offset
	# _tmp94 = *(_tmp93)
	  lw $t4, 0($t3) 	# load with offset
	# _tmp95 = ACall _tmp94
	# (save modified registers before flow of control change)
	  sw $t0, -172($fp)	# spill _tmp92 from $t0 to $fp-172
	  sw $t3, -176($fp)	# spill _tmp93 from $t3 to $fp-176
	  sw $t4, -180($fp)	# spill _tmp94 from $t4 to $fp-180
	  jalr $t4            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp96 = p - _tmp95
	  lw $t1, -8($fp)	# load p from $fp-8 into $t1
	  sub $t2, $t1, $t0	
	# _tmp97 = *(_tmp93 + 16)
	  lw $t3, -176($fp)	# load _tmp93 from $fp-176 into $t3
	  lw $t4, 16($t3) 	# load with offset
	# PushParam _tmp96
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# _tmp98 = ACall _tmp97
	# (save modified registers before flow of control change)
	  sw $t0, -184($fp)	# spill _tmp95 from $t0 to $fp-184
	  sw $t2, -188($fp)	# spill _tmp96 from $t2 to $fp-188
	  sw $t4, -192($fp)	# spill _tmp97 from $t4 to $fp-192
	  jalr $t4            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 8
	  add $sp, $sp, 8	# pop params off stack
	# PushParam _tmp98
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintBool
	# (save modified registers before flow of control change)
	  sw $t0, -196($fp)	# spill _tmp98 from $t0 to $fp-196
	  jal _PrintBool     	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam q
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, -12($fp)	# load q from $fp-12 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# _tmp99 = *(q)
	  lw $t1, 0($t0) 	# load with offset
	# _tmp100 = *(_tmp99)
	  lw $t2, 0($t1) 	# load with offset
	# _tmp101 = ACall _tmp100
	# (save modified registers before flow of control change)
	  sw $t1, -200($fp)	# spill _tmp99 from $t1 to $fp-200
	  sw $t2, -204($fp)	# spill _tmp100 from $t2 to $fp-204
	  jalr $t2            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp102 = q - _tmp101
	  lw $t1, -12($fp)	# load q from $fp-12 into $t1
	  sub $t2, $t1, $t0	
	# _tmp103 = *(_tmp99 + 16)
	  lw $t3, -200($fp)	# load _tmp99 from $fp-200 into $t3
	  lw $t4, 16($t3) 	# load with offset
	# PushParam _tmp102
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# _tmp104 = ACall _tmp103
	# (save modified registers before flow of control change)
	  sw $t0, -208($fp)	# spill _tmp101 from $t0 to $fp-208
	  sw $t2, -212($fp)	# spill _tmp102 from $t2 to $fp-212
	  sw $t4, -216($fp)	# spill _tmp103 from $t4 to $fp-216
	  jalr $t4            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 8
	  add $sp, $sp, 8	# pop params off stack
	# PushParam _tmp104
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintBool
	# (save modified registers before flow of control change)
	  sw $t0, -220($fp)	# spill _tmp104 from $t0 to $fp-220
	  jal _PrintBool     	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
