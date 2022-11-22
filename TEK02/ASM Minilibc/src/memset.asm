BITS 64

section .text
global memset:function

memset:
        XOR RCX, RCX ; set incrementer to 0
        MOV RAX, RDI ; set output to the first arg
        JMP .loop

.loop:
        CMP RCX, RDX
        JE .end ; if the incrementer is equal to the third arg then end prog
        MOV BYTE [RAX + RCX], SIL ; set the current char to the second arg
        INC RCX ; increase increment
        JMP .loop

.end:
        RET