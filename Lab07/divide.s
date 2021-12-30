      .data
# create prompts and feedback 
prompt1:		.asciiz "Enter an integer: "
prompt2:		.asciiz "Enter a second integer: "
feedback1:	.asciiz "The quotient of "
feedback2:	.asciiz " divided by "
feedback3:	.asciiz " is "
feedback4:	.asciiz " remainder "
feedback5:	.asciiz ".\n"

	.globl main
	.text

main:
	
	li	$t0, 0		# count = 0    
	li	$v0, 4		# print(prompt1) -- syscall #4
	la	$a0, prompt1	# 
	syscall			#
    li	$v0, 5		# remainder = input() -- syscall #5, result in $v0
	syscall			#
	move	$t1, $v0	#
    move	$t4, $v0	# set numerator = reaminder 
    li	$v0, 4		# print(prompt2) -- syscall #4
	la	$a0, prompt2	# 
	syscall			#
	li	$v0, 5		# divisor = input() -- syscall #5, result in $v0
	syscall			#
	move	$t2, $v0	#
    
	
loop:	
	blt	$t1, $t2, done  # if numerator < divisor goto done
	subu	$t1, $t1, $t2   # remainder = remainder - divisor
    addiu	$t0, $t0, 1   # count += 1
	b	loop

done:
	li	$v0, 4		# print(feedback1)
	la	$a0, feedback1	# 
	syscall			#

	li	$v0, 1		# print(numerator)
	move	$a0, $t4	# 
	syscall			#

	li	$v0, 4		# print(feedback2)
	la	$a0, feedback2	# 
	syscall			#
	
	li	$v0, 1		# print(divisor)
	move	$a0, $t2	# 
	syscall			#

	li	$v0, 4		# print(feedback3)
	la	$a0, feedback3	# 
	syscall			#

    li	$v0, 1		# print(count)
	move	$a0, $t0	# 
	syscall			#

    li	$v0, 4		# print(feedback4)
	la	$a0, feedback4	# 
	syscall			#

    li	$v0, 1		# print(remainder)
	move	$a0, $t1	# 
	syscall			#

    li	$v0, 4		# print(feedback5)
	la	$a0, feedback5	# 
	syscall			#
	
	li	$v0, 0		# return 0
	jr	$ra		#
	
