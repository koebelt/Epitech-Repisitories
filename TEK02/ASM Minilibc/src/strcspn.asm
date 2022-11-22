BITS 64

section .text
global strcspn:function

strcspn:
    XOR RAX, RAX
    XOR R10, R10
    JMP .next

.back:
    INC RDI
    INC R10
    JMP .next

.next:
    XOR RCX, RCX
    MOV AL, BYTE [RDI]
    CMP AL, 0x00
    JE .end
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
    MOV RAX, R10
    RET