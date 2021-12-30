	# sample MIPS32 assembly program
	#
	# CSCI 221 F19
	#
	# This counts up to 100, summing each of
	# those counted integers.
	#
	# It uses
	#  * system call #4 to print strings
	#  * the data segment to store strings
	#  * 'load address' to load the start of a string
	#  * system call #1 to print an integer
	#

        .data
fdbk:	.asciiz "The sum from 1 to 100 is "
eoln:	.asciiz "\n"

	.globl main
	.text

main:
	li	$t0, 0		# sum = 0    
	li	$t1, 1		# inc = 1    
	li	$t2, 0          # count = 0  
	li 	$t3, 100        # last = 100 
loop:	
	beq	$t3, $t2, done  # if last == count goto done

	addu	$t2, $t2, $t1   # count += inc
	addu	$t0, $t0, $t2   # sum += count
	b	loop

done:
	li	$v0, 4		# print(fdbk) -- syscall #4
	la	$a0, fdbk	# 
	syscall			#
	
	li	$v0, 1		# print(sum)  -- syscall #1
	move	$a0, $t0	# 
	syscall			#

	li	$v0, 4		# print(eoln) -- syscall #4
	la	$a0, eoln	# 
	syscall			#
	
	li	$v0, 0		# return 0
	jr	$ra		#
	
