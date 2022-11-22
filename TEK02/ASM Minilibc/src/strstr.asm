BITS 64

section .text
global strstr:function

strstr:
    XOR RAX, RAX
    XOR R9, R9
    JMP .loop

.loop:
    XOR RCX, RCX
    MOV AL, BYTE [RSI + RCX]
    CMP AL, 0x00
    JE .end_0
    MOV R8B, BYTE [RDI + R9]
    CMP R8B, 0x00
    JE .end_0
    CMP R8B, AL
    JE .find
    JMP .loop_2

.loop_2:
    INC R9
    JMP .loop

.loop_3:
    MOV AL, BYTE [RSI + RCX]
    CMP AL, 0x00
    JE .end
    MOV R8B, BYTE [RDI + R9]
    CMP R8B, 0x00
    JE .end_0
    CMP AL, R8B
    JE .find
    JMP .loop

.find:
    INC R9
    INC RCX
    JMP .loop_3

.end:
    SUB R9, RCX
    ADD RDI, R9
    MOV RAX, RDI
    RET

.end_0:
    MOV RAX, 0x00
    RET