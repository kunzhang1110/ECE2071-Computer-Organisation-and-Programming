# Laboratory Exercise 3 for lab 9 
# Written by Andy russell 20/03/2009 

	.set noreorder 
	.text 
	.globl start 
	.ent start 
	
start: 	lui $29, 0x8001 	# Load $sp with upper half of stack address 
							# Lower half is filled with zeros 
		ori $29, 0xFFF8		# Now load the lower 16 bits					
		li  $4, 0x0003      # load argument register $a0 with number to be squared					
		jal square      	# call the recursive function to calculate the square
		nop
infinite: b infinite 		# wait here when the calculation has finished 
							# $v0 = $2 contains the result
		nop 				# Needed after branch  

#---------------------------------------------------------------
#square - input parameter $a0 contains number to be squared
#         result returned in register $v0
#---------------------------------------------------------------		
square: sub $29, $29, 8		# decrement the stack pointer $sp
		sw  $31, 4($29)		# push the return address register $ra
		nop					# another nop
		sw  $4, 0($29)		# push argument register $a0
		nop					# yet another nop
		li  $8, 0x0001		# load $t0 with 1 as part of test for base case
		bne $4, $8,notbase	# branch if not the base case
		nop
		li	$2, 0x0001		# return base result in $v0
		add $29, $29, 8		# recover stack space (Note: did not corrupt registers)
		jr	$31				# jump to return address in $ra
		nop
notbase: 	#*****************************************
			#your code for the non-base case goes here 
			#*****************************************
		jr  $31				# jump to contents of return address register $ra
		nop		
.end start 					# Marks the end of the program 