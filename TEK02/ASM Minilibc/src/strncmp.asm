BITS 64

section .text
global strncmp:function

strncmp:
        XOR RAX, RAX ; set output to 0
        XOR RCX, RCX ; set incrementer to 0

.loop:
        CMP RDX, RCX
        JE .at_length
        MOV AL, BYTE [RDI + RCX] ; set temp register to char of the first str
        MOV R8B, BYTE [RSI + RCX] ; set other temp register to char of the second str
        CMP R8B, 0x00
        JE .not_same ; if one str is empty then end
        CMP AL, 0x00
        JE .not_same
        CMP AL, R8B
        JNE .not_same ; if registers are not the same then end prog
        INC RCX ; increase the increment
        JMP .loop

.not_same:
        SUB AL, R8B ; see the difference between the chars (0 if the same)
        MOVSX RAX, AL ; set the output to the temp register (result of difference)
        JMP .end ; end prog

.at_length:
        MOV RAX, 0x00
        JMP .end

.end:
        RET
