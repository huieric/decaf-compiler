	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  _offset_B_0:
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
	# VTable for class B
	  .data
	  .align 2
	  B:		# label for class B vtable
	  .word _offset_B_0
	  .word f_B.GetZ
	  .text
  f_B.GetZ:
	# BeginFunc 12
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 12	# decrement sp to make space for locals/temps
	# _tmp1 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp2 = this + _tmp1
	  lw $t1, 4($fp)	# load this from $fp+4 into $t1
	  add $t2, $t1, $t0	
	# _tmp3 = *(_tmp2)
	  lw $t3, 0($t2) 	# load with offset
	# Return _tmp3
	  move $v0, $t3		# assign return value into $v0
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
  f_binky:
	# BeginFunc 32
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 32	# decrement sp to make space for locals/temps
	# _tmp4 = "x = "
	  .data			# create string constant marked with label
	  _string1: .asciiz "x = "
	  .text
	  la $t0, _string1	# load label
	# PushParam _tmp4
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -8($fp)	# spill _tmp4 from $t0 to $fp-8
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp5 = *(x)
	  lw $t0, 4($fp)	# load x from $fp+4 into $t0
	  lw $t1, 0($t0) 	# load with offset
	# _tmp6 = *(_tmp5)
	  lw $t2, 0($t1) 	# load with offset
	# _tmp7 = ACall _tmp6
	# (save modified registers before flow of control change)
	  sw $t1, -12($fp)	# spill _tmp5 from $t1 to $fp-12
	  sw $t2, -16($fp)	# spill _tmp6 from $t2 to $fp-16
	  jalr $t2            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp8 = x - _tmp7
	  lw $t1, 4($fp)	# load x from $fp+4 into $t1
	  sub $t2, $t1, $t0	
	# _tmp9 = *(_tmp5 + 4)
	  lw $t3, -12($fp)	# load _tmp5 from $fp-12 into $t3
	  lw $t4, 4($t3) 	# load with offset
	# PushParam _tmp8
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# _tmp10 = ACall _tmp9
	# (save modified registers before flow of control change)
	  sw $t0, -20($fp)	# spill _tmp7 from $t0 to $fp-20
	  sw $t2, -24($fp)	# spill _tmp8 from $t2 to $fp-24
	  sw $t4, -28($fp)	# spill _tmp9 from $t4 to $fp-28
	  jalr $t4            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam _tmp10
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -32($fp)	# spill _tmp10 from $t0 to $fp-32
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp11 = "\n"
	  .data			# create string constant marked with label
	  _string2: .asciiz "\n"
	  .text
	  la $t0, _string2	# load label
	# PushParam _tmp11
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -36($fp)	# spill _tmp11 from $t0 to $fp-36
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  _offset_X_0:
	# BeginFunc 4
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 4	# decrement sp to make space for locals/temps
	# _tmp12 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# Return _tmp12
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
	# VTable for class X
	  .data
	  .align 2
	  X:		# label for class X vtable
	  .word _offset_X_0
	  .word f_X.GetZ
	  .word f_X.f
	  .word f_X.compare
	  .text
  f_X.f:
	# BeginFunc 28
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 28	# decrement sp to make space for locals/temps
	# _tmp13 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp14 = this + _tmp13
	  lw $t1, 4($fp)	# load this from $fp+4 into $t1
	  add $t2, $t1, $t0	
	# _tmp15 = *(_tmp14)
	  lw $t3, 0($t2) 	# load with offset
	# _tmp16 = 3
	  li $t4, 3		# load constant value 3 into $t4
	# _tmp17 = 4
	  li $t5, 4		# load constant value 4 into $t5
	# _tmp18 = this + _tmp17
	  add $t6, $t1, $t5	
	# *(_tmp18) = _tmp16
	  sw $t4, 0($t6) 	# store with offset
	# PushParam this
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall f_binky
	# (save modified registers before flow of control change)
	  sw $t0, -8($fp)	# spill _tmp13 from $t0 to $fp-8
	  sw $t2, -12($fp)	# spill _tmp14 from $t2 to $fp-12
	  sw $t3, -16($fp)	# spill _tmp15 from $t3 to $fp-16
	  sw $t4, -20($fp)	# spill _tmp16 from $t4 to $fp-20
	  sw $t5, -24($fp)	# spill _tmp17 from $t5 to $fp-24
	  sw $t6, -28($fp)	# spill _tmp18 from $t6 to $fp-28
	  jal f_binky        	# jump to function
	# _tmp19 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  f_X.compare:
	# BeginFunc 4
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 4	# decrement sp to make space for locals/temps
	# _tmp20 = this == other
	  lw $t0, 4($fp)	# load this from $fp+4 into $t0
	  lw $t1, 8($fp)	# load other from $fp+8 into $t1
	  seq $t2, $t0, $t1	
	# Return _tmp20
	  move $v0, $t2		# assign return value into $v0
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
  f_X.GetZ:
	# BeginFunc 12
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 12	# decrement sp to make space for locals/temps
	# _tmp21 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp22 = this + _tmp21
	  lw $t1, 4($fp)	# load this from $fp+4 into $t1
	  add $t2, $t1, $t0	
	# _tmp23 = *(_tmp22)
	  lw $t3, 0($t2) 	# load with offset
	# Return _tmp23
	  move $v0, $t3		# assign return value into $v0
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
	# BeginFunc 72
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 72	# decrement sp to make space for locals/temps
	# _tmp24 = 8
	  li $t0, 8		# load constant value 8 into $t0
	# PushParam _tmp24
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# _tmp25 = LCall _Alloc
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp24 from $t0 to $fp-12
	  jal _Alloc         	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp26 = X
	  la $t1, X	# load label
	# *(_tmp25) = _tmp26
	  sw $t1, 0($t0) 	# store with offset
	# d = _tmp25
	  move $t2, $t0		# copy value
	# _tmp27 = *(d)
	  lw $t3, 0($t2) 	# load with offset
	# _tmp28 = *(_tmp27)
	  lw $t4, 0($t3) 	# load with offset
	# _tmp29 = ACall _tmp28
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp25 from $t0 to $fp-16
	  sw $t1, -20($fp)	# spill _tmp26 from $t1 to $fp-20
	  sw $t2, -8($fp)	# spill d from $t2 to $fp-8
	  sw $t3, -24($fp)	# spill _tmp27 from $t3 to $fp-24
	  sw $t4, -28($fp)	# spill _tmp28 from $t4 to $fp-28
	  jalr $t4            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp30 = d - _tmp29
	  lw $t1, -8($fp)	# load d from $fp-8 into $t1
	  sub $t2, $t1, $t0	
	# _tmp31 = *(_tmp27 + 8)
	  lw $t3, -24($fp)	# load _tmp27 from $fp-24 into $t3
	  lw $t4, 8($t3) 	# load with offset
	# PushParam _tmp30
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# ACall _tmp31
	# (save modified registers before flow of control change)
	  sw $t0, -32($fp)	# spill _tmp29 from $t0 to $fp-32
	  sw $t2, -36($fp)	# spill _tmp30 from $t2 to $fp-36
	  sw $t4, -40($fp)	# spill _tmp31 from $t4 to $fp-40
	  jalr $t4            	# jump to function
	# _tmp32 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam d
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t1, -8($fp)	# load d from $fp-8 into $t1
	  sw $t1, 4($sp)	# copy param value to stack
	# _tmp33 = *(d)
	  lw $t2, 0($t1) 	# load with offset
	# _tmp34 = *(_tmp33)
	  lw $t3, 0($t2) 	# load with offset
	# _tmp35 = ACall _tmp34
	# (save modified registers before flow of control change)
	  sw $t0, -44($fp)	# spill _tmp32 from $t0 to $fp-44
	  sw $t2, -48($fp)	# spill _tmp33 from $t2 to $fp-48
	  sw $t3, -52($fp)	# spill _tmp34 from $t3 to $fp-52
	  jalr $t3            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# _tmp36 = d - _tmp35
	  lw $t1, -8($fp)	# load d from $fp-8 into $t1
	  sub $t2, $t1, $t0	
	# _tmp37 = *(_tmp33 + 12)
	  lw $t3, -48($fp)	# load _tmp33 from $fp-48 into $t3
	  lw $t4, 12($t3) 	# load with offset
	# PushParam _tmp36
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# _tmp38 = ACall _tmp37
	# (save modified registers before flow of control change)
	  sw $t0, -56($fp)	# spill _tmp35 from $t0 to $fp-56
	  sw $t2, -60($fp)	# spill _tmp36 from $t2 to $fp-60
	  sw $t4, -64($fp)	# spill _tmp37 from $t4 to $fp-64
	  jalr $t4            	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 8
	  add $sp, $sp, 8	# pop params off stack
	# IfZ _tmp38 Goto _L1
	# (save modified registers before flow of control change)
	  sw $t0, -68($fp)	# spill _tmp38 from $t0 to $fp-68
	  beqz $t0, _L1	# branch if _tmp38 is zero 
	# _tmp39 = "Same"
	  .data			# create string constant marked with label
	  _string3: .asciiz "Same"
	  .text
	  la $t0, _string3	# load label
	# PushParam _tmp39
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -72($fp)	# spill _tmp39 from $t0 to $fp-72
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# Goto _L0
	  b _L0		# unconditional branch
  _L1:
	# _tmp40 = "Different"
	  .data			# create string constant marked with label
	  _string4: .asciiz "Different"
	  .text
	  la $t0, _string4	# load label
	# PushParam _tmp40
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -76($fp)	# spill _tmp40 from $t0 to $fp-76
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
  _L0:
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
