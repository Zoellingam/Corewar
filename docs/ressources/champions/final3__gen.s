.name		"Good"
.comment	"So good !"

l_0:
	sti		r1, %:l_3, %1
	sti		r1, %:l_2, %1
	ld		%372, r3
	fork	%:l_1
	ldi		%212, %0, r2
	ldi		%205, %8, r5
	ldi		%198, %16, r7
	ld		%1409614598, r9
	ld		%134960137, r11
	ld		%184749067, r13
	ld		%190058243, r15
	ld		%0, r4
	ld		%3, r6
	ld		%6, r8
	ld		%9, r10
	ld		%12, r12
	ld		%15, r14
	ld		%18, r16
	xor		r1, r1, r1
	zjmp	%:l_2

l_1:
	ldi		%106, %4, r2
	ldi		%99, %12, r5
	ldi		%92, %20, r7
	ld		%190056195, r9
	ld		%50989908, r11
	ld		%1410138894, r13
	ld		%269025630, r15
	ld		%4, r4
	ld		%7, r6
	ld		%10, r8
	ld		%13, r10
	ld		%16, r12
	ld		%19, r14
	ld		%22, r16
	xor		r1, r1, r1
	zjmp	%:l_2
	xor		r1, r1, r1

l_3:
	live	%:l_3
	zjmp	%:l_3

l_2:
	live	%:l_2
	sti		r2, r3, r4
	sti		r5, r3, r6
	sti		r7, r3, r8
	sti		r9, r3, r10
	sti		r11, r3, r12
	sti		r13, r3, r14
	sti		r15, r3, r16
	zjmp	%350

# generated #
