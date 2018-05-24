	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  f_SayHi:
	# BeginFunc 28
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 28	# decrement sp to make space for locals/temps
	# _tmp0 = 15
	  li $t0, 15		# load constant value 15 into $t0
	# c = _tmp0
	  move $t1, $t0		# copy value
	# _tmp1 = 0
	  li $t2, 0		# load constant value 0 into $t2
	# IfZ _tmp1 Goto _L0
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp0 from $t0 to $fp-12
	  sw $t1, -8($fp)	# spill c from $t1 to $fp-8
	  sw $t2, -16($fp)	# spill _tmp1 from $t2 to $fp-16
	  beqz $t2, _L0	# branch if _tmp1 is zero 
	# Return 
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  _L0:
	# _tmp2 = c * c
	  lw $t0, -8($fp)	# load c from $fp-8 into $t0
	  mul $t1, $t0, $t0	
	# _tmp3 = c - _tmp2
	  sub $t2, $t0, $t1	
	# c = _tmp3
	  move $t0, $t2		# copy value
	# _tmp4 = 2
	  li $t3, 2		# load constant value 2 into $t3
	# _tmp5 = _tmp4 * c
	  mul $t4, $t3, $t0	
	# PushParam _tmp5
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t4, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -8($fp)	# spill c from $t0 to $fp-8
	  sw $t1, -20($fp)	# spill _tmp2 from $t1 to $fp-20
	  sw $t2, -24($fp)	# spill _tmp3 from $t2 to $fp-24
	  sw $t3, -28($fp)	# spill _tmp4 from $t3 to $fp-28
	  sw $t4, -32($fp)	# spill _tmp5 from $t4 to $fp-32
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam c
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, -8($fp)	# load c from $fp-8 into $t0
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
  f_one:
	# BeginFunc 24
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 24	# decrement sp to make space for locals/temps
	# LCall f_SayHi
	  jal f_SayHi        	# jump to function
	# _tmp6 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# _tmp7 = 1
	  li $t1, 1		# load constant value 1 into $t1
	# _tmp8 = a - _tmp7
	  lw $t2, 4($fp)	# load a from $fp+4 into $t2
	  sub $t3, $t2, $t1	
	# _tmp9 = _tmp8 * b
	  lw $t4, 8($fp)	# load b from $fp+8 into $t4
	  mul $t5, $t3, $t4	
	# _tmp10 = 1
	  li $t6, 1		# load constant value 1 into $t6
	# _tmp11 = _tmp9 + _tmp10
	  add $t7, $t5, $t6	
	# Return _tmp11
	  move $v0, $t7		# assign return value into $v0
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
  f_two:
	# BeginFunc 40
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 40	# decrement sp to make space for locals/temps
	# _tmp12 = 3
	  li $t0, 3		# load constant value 3 into $t0
	# PushParam _tmp12
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# PushParam c
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t1, 4($fp)	# load c from $fp+4 into $t1
	  sw $t1, 4($sp)	# copy param value to stack
	# _tmp13 = LCall f_one
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp12 from $t0 to $fp-12
	  jal f_one          	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 8
	  add $sp, $sp, 8	# pop params off stack
	# c = _tmp13
	  move $t1, $t0		# copy value
	# _tmp14 = 5
	  li $t2, 5		# load constant value 5 into $t2
	# PushParam _tmp14
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# _tmp15 = 4
	  li $t3, 4		# load constant value 4 into $t3
	# PushParam _tmp15
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp16 = LCall f_one
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp13 from $t0 to $fp-16
	  sw $t1, 4($fp)	# spill c from $t1 to $fp+4
	  sw $t2, -20($fp)	# spill _tmp14 from $t2 to $fp-20
	  sw $t3, -24($fp)	# spill _tmp15 from $t3 to $fp-24
	  jal f_one          	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 8
	  add $sp, $sp, 8	# pop params off stack
	# d = _tmp16
	  move $t1, $t0		# copy value
	# PushParam c
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t2, 4($fp)	# load c from $fp+4 into $t2
	  sw $t2, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -28($fp)	# spill _tmp16 from $t0 to $fp-28
	  sw $t1, -8($fp)	# spill d from $t1 to $fp-8
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam d
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, -8($fp)	# load d from $fp-8 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp17 = "\n"
	  .data			# create string constant marked with label
	  _string1: .asciiz "\n"
	  .text
	  la $t0, _string1	# load label
	# PushParam _tmp17
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -32($fp)	# spill _tmp17 from $t0 to $fp-32
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp18 = c < d
	  lw $t0, 4($fp)	# load c from $fp+4 into $t0
	  lw $t1, -8($fp)	# load d from $fp-8 into $t1
	  slt $t2, $t0, $t1	
	# b = _tmp18
	  move $t3, $t2		# copy value
	# IfZ b Goto _L2
	# (save modified registers before flow of control change)
	  sw $t2, -36($fp)	# spill _tmp18 from $t2 to $fp-36
	  sw $t3, 8($fp)	# spill b from $t3 to $fp+8
	  beqz $t3, _L2	# branch if b is zero 
	# _tmp19 = c * d
	  lw $t0, 4($fp)	# load c from $fp+4 into $t0
	  lw $t1, -8($fp)	# load d from $fp-8 into $t1
	  mul $t2, $t0, $t1	
	# Return _tmp19
	  move $v0, $t2		# assign return value into $v0
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
	# Goto _L1
	  b _L1		# unconditional branch
  _L2:
	# _tmp20 = c / d
	  lw $t0, 4($fp)	# load c from $fp+4 into $t0
	  lw $t1, -8($fp)	# load d from $fp-8 into $t1
	  div $t2, $t0, $t1	
	# Return _tmp20
	  move $v0, $t2		# assign return value into $v0
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  _L1:
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  f_three:
	# BeginFunc 44
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 44	# decrement sp to make space for locals/temps
	# _tmp21 = 3
	  li $t0, 3		# load constant value 3 into $t0
	# _tmp22 = _tmp21 * a
	  lw $t1, 4($fp)	# load a from $fp+4 into $t1
	  mul $t2, $t0, $t1	
	# b = _tmp22
	  move $t3, $t2		# copy value
	# _tmp23 = 3
	  li $t4, 3		# load constant value 3 into $t4
	# _tmp24 = b == _tmp23
	  seq $t5, $t3, $t4	
	# PushParam _tmp24
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t5, 4($sp)	# copy param value to stack
	# PushParam b
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t3, 4($sp)	# copy param value to stack
	# _tmp25 = LCall f_two
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp21 from $t0 to $fp-16
	  sw $t2, -20($fp)	# spill _tmp22 from $t2 to $fp-20
	  sw $t3, -8($fp)	# spill b from $t3 to $fp-8
	  sw $t4, -24($fp)	# spill _tmp23 from $t4 to $fp-24
	  sw $t5, -28($fp)	# spill _tmp24 from $t5 to $fp-28
	  jal f_two          	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 8
	  add $sp, $sp, 8	# pop params off stack
	# c = _tmp25
	  move $t1, $t0		# copy value
	# _tmp26 = 3
	  li $t2, 3		# load constant value 3 into $t2
	# _tmp27 = b == _tmp26
	  lw $t3, -8($fp)	# load b from $fp-8 into $t3
	  seq $t4, $t3, $t2	
	# PushParam _tmp27
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t4, 4($sp)	# copy param value to stack
	# PushParam c
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# _tmp28 = LCall f_two
	# (save modified registers before flow of control change)
	  sw $t0, -32($fp)	# spill _tmp25 from $t0 to $fp-32
	  sw $t1, -12($fp)	# spill c from $t1 to $fp-12
	  sw $t2, -36($fp)	# spill _tmp26 from $t2 to $fp-36
	  sw $t4, -40($fp)	# spill _tmp27 from $t4 to $fp-40
	  jal f_two          	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 8
	  add $sp, $sp, 8	# pop params off stack
	# b = _tmp28
	  move $t1, $t0		# copy value
	# PushParam b
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t1, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	# (save modified registers before flow of control change)
	  sw $t0, -44($fp)	# spill _tmp28 from $t0 to $fp-44
	  sw $t1, -8($fp)	# spill b from $t1 to $fp-8
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# PushParam c
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  lw $t0, -12($fp)	# load c from $fp-12 into $t0
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintInt
	  jal _PrintInt      	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp29 = "\n"
	  .data			# create string constant marked with label
	  _string2: .asciiz "\n"
	  .text
	  la $t0, _string2	# load label
	# PushParam _tmp29
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t0, 4($sp)	# copy param value to stack
	# LCall _PrintString
	# (save modified registers before flow of control change)
	  sw $t0, -48($fp)	# spill _tmp29 from $t0 to $fp-48
	  jal _PrintString   	# jump to function
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
  f_main:
  main:
	# BeginFunc 36
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 36	# decrement sp to make space for locals/temps
	# _tmp30 = 0
	  li $t0, 0		# load constant value 0 into $t0
	# i = _tmp30
	  move $t1, $t0		# copy value
	# (save modified registers before flow of control change)
	  sw $t0, -12($fp)	# spill _tmp30 from $t0 to $fp-12
	  sw $t1, -8($fp)	# spill i from $t1 to $fp-8
  _L3:
	# _tmp31 = 4
	  li $t0, 4		# load constant value 4 into $t0
	# _tmp32 = i < _tmp31
	  lw $t1, -8($fp)	# load i from $fp-8 into $t1
	  slt $t2, $t1, $t0	
	# IfZ _tmp32 Goto _L4
	# (save modified registers before flow of control change)
	  sw $t0, -16($fp)	# spill _tmp31 from $t0 to $fp-16
	  sw $t2, -20($fp)	# spill _tmp32 from $t2 to $fp-20
	  beqz $t2, _L4	# branch if _tmp32 is zero 
	# _tmp33 = 10
	  li $t0, 10		# load constant value 10 into $t0
	# _tmp34 = i * _tmp33
	  lw $t1, -8($fp)	# load i from $fp-8 into $t1
	  mul $t2, $t1, $t0	
	# PushParam _tmp34
	  subu $sp, $sp, 4	# decrement sp to make space for param
	  sw $t2, 4($sp)	# copy param value to stack
	# _tmp35 = LCall f_three
	# (save modified registers before flow of control change)
	  sw $t0, -24($fp)	# spill _tmp33 from $t0 to $fp-24
	  sw $t2, -28($fp)	# spill _tmp34 from $t2 to $fp-28
	  jal f_three        	# jump to function
	  move $t0, $v0		# copy function return value from $v0
	# PopParams 4
	  add $sp, $sp, 4	# pop params off stack
	# _tmp36 = 1
	  li $t1, 1		# load constant value 1 into $t1
	# _tmp37 = i + _tmp36
	  lw $t2, -8($fp)	# load i from $fp-8 into $t2
	  add $t3, $t2, $t1	
	# i = _tmp37
	  move $t2, $t3		# copy value
	# Goto _L3
	# (save modified registers before flow of control change)
	  sw $t0, -32($fp)	# spill _tmp35 from $t0 to $fp-32
	  sw $t1, -36($fp)	# spill _tmp36 from $t1 to $fp-36
	  sw $t2, -8($fp)	# spill i from $t2 to $fp-8
	  sw $t3, -40($fp)	# spill _tmp37 from $t3 to $fp-40
	  b _L3		# unconditional branch
  _L4:
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
