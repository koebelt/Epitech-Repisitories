BITS 64

section .text
global memcpy:function

memcpy:
	XOR RCX, RCX ; set incrementer to 0
	MOV RAX, RDI ; set output to the first arg
        JMP .loop

.loop:
	CMP RCX, RDX
	JE .end ; if incrementer is equal to third arg then end prog
	MOV R8B, BYTE [RSI + RCX] ; set temp register to the current char of the second str
	MOV BYTE [RAX + RCX], R8B ; set the current char of the first str to the temp register
	INC RCX ; increase the increment
	JMP .loop

.end:
        RET