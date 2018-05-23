	# standard Decaf preamble 
	  .text
	  .align 2
	  .globl main
  f_main:
  main:
	# BeginFunc 8
	  subu $sp, $sp, 8	# decrement sp to make space to save ra, fp
	  sw $fp, 8($sp)	# save fp
	  sw $ra, 4($sp)	# save ra
	  addiu $fp, $sp, 8	# set up new fp
	  subu $sp, $sp, 8	# decrement sp to make space for locals/temps
	# _tmp0 = 10
	  li $t0, 10		# load constant value 10 into $t0
	# x = _tmp0
	  move $t1, $t0		# copy value
	# EndFunc
	# (below handles reaching end of fn body with no explicit return)
	  move $sp, $fp		# pop callee frame off stack
	  lw $ra, -4($fp)	# restore saved ra
	  lw $fp, 0($fp)	# restore saved fp
	  jr $ra		# return from function
