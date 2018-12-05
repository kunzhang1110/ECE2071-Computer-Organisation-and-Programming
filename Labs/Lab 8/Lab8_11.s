# Laboratory Exercise 8_1 
# Based on code written by Jan Eric Larsson, 27 October 1998 

.set noreorder 			# Avoid reordering instructions 
.text 				# Start generating instructions 
.globl start 			# This label should be globally known 
.ent start 			# This label marks an entry point 

start: 	li $8, 0x1 		# Load the value 1 
	li $9, 0x2 		# Load the value 2 
	add $10, $8, $9 	# Add the values 
infinite:
	b infinite		# an infinite loop so that the
				# computer will not execute code
				# past the end of the program
	nop			# all branch and lw, sw must
				# be followed by a nop
.end start 			# Marks the end of the program 