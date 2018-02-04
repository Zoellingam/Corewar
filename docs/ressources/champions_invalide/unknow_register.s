.name		"Octobre Rouge V4.2"
.comment	"And the winner is ..."

l_0:
	st		r0, 19
	ld		%0, r15
	fork	%:l_1, 32
	zjmp	%:l_2

l_1:
	live	%42
	fork	%:l_2
	zjmp	%:l_1

l_9:
	live	%42
	fork	%:l_3
	st		r1, 13
	ld		%0, r15

l_4:
	live	%42
	zjmp	%:l_4

l_3:
	live	%42
	fork	%:l_5
	st		r1, 13
	ld		%0, r15

l_6:
	live	%42
	zjmp	%:l_6

l_5:
	live	%42
	fork	%:l_7
	st		r1, 13
	ld		%0, r15

l_8:
	live	%42
	zjmp	%:l_8

l_7:
	live	%42
	fork	%:l_9
	st		r1, 13
	ld		%0, r15

l_10:
	live	%42
	zjmp	%:l_10

l_11:
	live	%42
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	st		r8, -400
	ld		%0, r15
	zjmp	%:l_11

l_2:
	live	%42
	fork	%:l_12
	live	%42
	fork	%:l_13
	live	%42
	fork	%:l_14
	ld		%57672448, r3
	ld		%:l_12, r6
	ld		%0, r15
	zjmp	%:l_15

l_12:
	live	%42
	fork	%:l_2
	live	%42
	fork	%:l_9
	ld		%251883526, r3
	ld		%386101254, r6
	ld		%0, r15
	ld		%0, r15
	zjmp	%:l_15

l_13:
	live	%42
	fork	%:l_11
	ld		%-65214, r3
	ld		%436432902, r6
	ld		%0, r15
	ld		%0, r15
	ld		%0, r15
	zjmp	%:l_15

l_14:
	st		r1, r3
	ld		%251883526, r6
	ld		%0, r15
	ld		%0, r15
	ld		%0, r15
	ld		%0, r15
	zjmp	%:l_15

l_15:
	st		r3, 15
	st		r6, -1
	live	%42

# generated #
