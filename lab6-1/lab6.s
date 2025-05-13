/* BY SUBMITTING THIS FILE TO CARMEN, I CERTIFY THAT I HAVE PERFORMED ALL OF
THE WORK TO CREATE THIS FILE AND/OR DETERMINE THE ANSWERS FOUND WITHIN
THIS FILE MYSELF WITH NO ASSISTANCE FROM ANY PERSON (OTHER THAN THE
INSTRUCTOR OR GRADERS OF THIS COURSE) AND I HAVE STRICTLY ADHERED TO THE
TENURES OF THE OHIO STATE UNIVERSITY'S ACADEMIC INTEGRITY POLICY.
*/

.file "sum.s"

.section	.rodata.str1.1,"aMS",@progbits,1
PR_1:
	.string "\nSize of the array: %i\n"
Result:
	.string "\nThe sum is: %i\n"
	
PInt: #not used
	.string "%i "
	
.data
.align 8
array:
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0
	.quad 0

.globl sum
	.type	sum, @function
.text
sum:
	pushq %rbp		# stack frame management
	movq %rsp, %rbp	# stack frame management
	
	pushq %rsi
	pushq %rdi
	
	movq $PR_1,%rdi	
	movq $0,%rax
	call printf
	
	popq %rdi
	popq %rsi

	#set up loop and jump to finsh if array is empty
	xorq %rax, %rax  
	testq %rsi, %rsi
	jz .Ldone

	movq %rsi, %rcx #loop counter
.Lloop:
	
	addq (%rdi), %rax #add current index 
	addq $8, %rdi #move to next num in array
	loop .Lloop # loop

.Ldone:
	#set up printf
	pushq %rax #save before print
	
	movq $Result, %rdi #format string
	movq %rax, %rsi #int arg
	movq $0,%rax #no vector args
	call printf
	popq %rax #pop to return as sum is type long

  
		
	leave
	ret
.size sum,.-sum
