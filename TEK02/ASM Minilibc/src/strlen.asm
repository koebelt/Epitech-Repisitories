BITS 64

section .text
global strlen:function

strlen:
        XOR EAX, EAX ; set output to 0
        CMP BYTE [RDI], 0x00
        JE .end ; end prog if first char is null
        JMP .loop ; go to loop

.loop:
        INC RDI ; increase str ptr
        INC EAX ; increase output
        CMP BYTE [RDI], 0x00
        JNE .loop ; loop again if NOT char nul
        JMP .end ; end prog

.end:
        RET