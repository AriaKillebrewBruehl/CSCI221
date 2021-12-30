       .data
prompt1:		.asciiz "Enter an integer: "
prompt2:		.asciiz "Enter a second integer: "
feedback1:	.asciiz "The product of "
feedback2:	.asciiz " and "
feedback3:	.asciiz " is "
feedback4:	.asciiz ".\n"

	.globl main
	.text

main:
	li	$t0, 0		# product = 0    
	li	$t1, 0		# count = 0    

	li	$v0, 4		# print(prompt1) -- syscall #4
	la	$a0, prompt1	# 
	syscall			#
    li	$v0, 5		# int1 = input() -- syscall #5, result in $v0
	syscall			#
	move	$t2, $v0	#
    li	$v0, 4		# print(prompt2) -- syscall #4
	la	$a0, prompt2	# 
	syscall			#
	li	$v0, 5		# int2 = input() -- syscall #5, result in $v0
	syscall			#
	move	$t3, $v0	#
	
loop:	
	beq	$t1, $t3, done  # if count == int2 goto done

	addu	$t0, $t0, $t2   # product += int1
    addiu	$t1, $t1, 1   # count += 1
	b	loop

done:
	li	$v0, 4		# print(feedback1)
	la	$a0, feedback1	# 
	syscall			#

	li	$v0, 1		# print(int1)
	move	$a0, $t2	# 
	syscall			#

	li	$v0, 4		# print(feedback2)
	la	$a0, feedback2	# 
	syscall			#
	
	li	$v0, 1		# print(int2)
	move	$a0, $t3	# 
	syscall			#

	li	$v0, 4		# print(feedback3)
	la	$a0, feedback3	# 
	syscall			#

    li	$v0, 1		# print(product)
	move	$a0, $t0	# 
	syscall			#

    li	$v0, 4		# print(feedback4)
	la	$a0, feedback4	# 
	syscall			#
	
	li	$v0, 0		# return 0
	jr	$ra		#
	
