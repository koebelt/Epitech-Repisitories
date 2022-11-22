BITS 64

section .text
global strrchr:function

strrchr:
        XOR RAX, RAX ; set output to 0
        JMP .loop

.loop:
        CMP BYTE [RDI], 0x00
        JE .end ; if char is null then return the ptr to the last found char
        CMP BYTE [RDI], SIL
        JE .change_output ;  if char corresponds change output ptr
        INC RDI ; increase str ptr
        JMP .loop

.change_output:
        MOV RAX, RDI ; set output ptr to current found char
        INC RDI ; increase str ptr
        JMP .loop ; re-loop

.end:
        RET