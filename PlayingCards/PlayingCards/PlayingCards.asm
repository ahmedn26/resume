;PlayingCards.asm Nusra Ahmed/Stores and displays a hand of 5 standard playing cards from 
;							  the eax register using bitshifting operations.

INCLUDE Irvine32.inc

.data
	value DWORD 00001000101001110010110111111000b
	bitsToShift BYTE 30
	numCards BYTE 5

	s00 BYTE "HEARTS", 0
	s01 BYTE "DIAMONDS", 0
	s02 BYTE "CLUBS", 0
	s03 BYTE "SPADES", 0

	suits DWORD	OFFSET s00, OFFSET s01, OFFSET s02, OFFSET s03

	r00 BYTE "2 ", 0
	r01 BYTE "3 ", 0
	r02 BYTE "4 ", 0
	r03 BYTE "5 ", 0
	r04 BYTE "6 ", 0
	r05 BYTE "7 ", 0
	r06 BYTE "8 ", 0
	r07 BYTE "9 ", 0
	r08 BYTE "10 ", 0
	r09 BYTE "J ", 0
	r10 BYTE "Q ", 0
	r11 BYTE "K ", 0
	r12 BYTE "A ", 0

	ranks DWORD	OFFSET r00, OFFSET r01, OFFSET r02, OFFSET r03, 
						OFFSET r04, OFFSET r05, OFFSET r06, OFFSET r07, 
						OFFSET r08, OFFSET r09, OFFSET r10, OFFSET r11, OFFSET r12 

.code
main PROC
	mov cl, bitsToShift

	mov bl, numCards ;loop counter
again:
	;print the rank
	mov eax, value
	sub cl, 4 ; cl is used for bitshifting
	shr eax, cl ; shift the bits to clear the other cards and the suit
	and eax, 00001111b ; clear all bits except for the last 4 for the rank
	sub eax, 2 ; subtract 2 to get the index value for the table
	shl eax, 2 ; shift the bits to access the array
	mov edx, ranks[eax] ; move pointer to the array into edx
	call WriteString ; prints the rank

	;print the suit
	mov eax, value 
	sub cl, 2
	shr eax, cl ; shift the bits to clear the other cards
	and eax, 00000011b ; clear all bits except for the last 2 for the suit
	shl eax, 2 ; shift the bits to access the array
	mov edx, suits[eax] ; move pointer to the array into edx
	call WriteString ; prints the suit
	call Crlf

	dec bl ; conditional loop
	cmp bl, 0
	jg again
	
	call WaitMsg
	exit
main ENDP
END main