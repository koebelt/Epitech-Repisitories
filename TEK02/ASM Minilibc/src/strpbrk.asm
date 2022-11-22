BITS 64

section .text
global strpbrk:function

strpbrk:
    XOR RAX, RAX
    JMP .next

.back:
    INC RDI
    JMP .next

.next:
    XOR RCX, RCX
    MOV AL, BYTE [RDI]
    CMP AL, 0x00
    JE .end_0
    CMP BYTE [RSI + RCX], AL
    JNE .loop
    JMP .end

.loop:
    MOV R8B, BYTE [RSI + RCX]
    CMP R8B, 0x00
    JE .back
    CMP AL, R8B
    JE .end
    INC RCX
    JMP .loop

.end:
    MOV RAX, RDI
    RET

.end_0:
    MOV RAX, 0x00
    RET