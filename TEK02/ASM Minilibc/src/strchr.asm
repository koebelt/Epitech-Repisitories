BITS 64

section .text
global strchr:function

strchr:
        XOR	RAX, RAX ; set output to 0
        JMP .loop

.loop:
        CMP	BYTE [RDI], SIL
        JE .end_found ; if char corresponds, call end fcn
        CMP	BYTE [RDI], 0x00
        JE .end ; if char null end prog
        INC	RDI ; increase ptr
        JMP	.loop

.end_found:
        MOV	RAX, RDI ; set output to pointer on the char in the str
        JMP	.end

.end:
        RET