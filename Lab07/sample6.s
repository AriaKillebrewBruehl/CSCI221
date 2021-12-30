	# sample MIPS32 assembly program
	#
	# CSCI 221 F19
	#
	# This counts up to 100, summing each of
	# those counted integers that are even.
	#
	# It uses
	#  * bitwise AND immediate to compute "mod 2"
	#
	
        .data
prompt:		.asciiz "Enter an integer: "
feedback1:	.asciiz "The sum of the even numbers from 1 to "
feedback2:	.asciiz " is "
feedback3:	.asciiz ".\n"

	.globl main
	.text

main:

get_top_value:	
	li	$v0, 4		# print(prompt) -- syscall #4
	la	$a0, prompt	# 
	syscall			#
	li	$v0, 5		# last = input() -- syscall #5, result in $v0
	syscall			#
	move	$t3, $v0	# 

loop_head:		
	li	$t0, 0		# sum = 0    
	move	$t2, $t3	# count = last
loop:	
	beqz	$t2, done  	# if count == 0 goto done

	andi	$t4, $t2, 0x1	# tmp = count % 2
	bgtz	$t4, skip_add	# if tmp > 0 go to skip_add
	addu	$t0, $t0, $t2   # sum += count
skip_add:	
	addiu	$t2, $t2, -1   	# count -= 1
	b	loop

done:
	li	$v0, 4		# print(feedback1)
	la	$a0, feedback1	# 
	syscall			#

	li	$v0, 1		# print(last)
	move	$a0, $t3	# 
	syscall			#

	li	$v0, 4		# print(feedback2)
	la	$a0, feedback2	# 
	syscall			#
	
	li	$v0, 1		# print(sum)
	move	$a0, $t0	# 
	syscall			#

	li	$v0, 4		# print(feedback3)
	la	$a0, feedback3	# 
	syscall			#
	
	li	$v0, 0		# return 0
	jr	$ra		#
	
