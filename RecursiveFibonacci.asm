;RecursiveFibonacci.asm Nusra Ahmed/Calculates a fibonacci number recursively: Xn = Xn-1 + Xn-2

INCLUDE Irvine32.inc

.data
	; Your data goes here

.code
;----------------------------------------------------
; Calculates a fibonacci number.
; Receives: [ebp+8] = n, the number to calculate
; Returns: eax = the fibonacci of n
;----------------------------------------------------
Fibonacci PROC
	push ebp
	mov ebp, esp
	mov eax, [ebp+8]			; get n
	sub esp, 4					; create local variable
	cmp eax, 1
	jg L1
	je returnOne
	cmp eax, 0
	je returnZero
	jl returnNegative

returnOne:
	mov eax, 1
	jmp L2
returnZero:
	mov eax, 0
	jmp L2
returnNegative:
	mov eax, -1
	jmp L2

L1: 
    dec DWORD PTR [ebp + 8]
    push DWORD PTR [ebp + 8]	; Fibonacci(n-1)
    call Fibonacci
	mov [ebp-4], eax			; store the first result in the local variable
	dec DWORD PTR [ebp + 8]
    push DWORD PTR [ebp + 8]	; Fibonacci(n-2)
    call Fibonacci

ReturnFibonacci:
    add eax, [ebp-4]			; add Xn-1 and Xn-2

L2: 
	mov esp, ebp				; remove local variable from stack
	pop ebp						
	ret 4						; clean up stack
Fibonacci ENDP


main PROC
	push -2
	call Fibonacci
	call WriteInt
	call Crlf

	push 0
	call Fibonacci
	call WriteInt
	call Crlf

	push 1
	call Fibonacci
	call WriteInt
	call Crlf

	push 7
	call Fibonacci
	call WriteInt
	call Crlf

	push 31
	call Fibonacci
	call WriteInt
	call Crlf

	exit
main ENDP
END main