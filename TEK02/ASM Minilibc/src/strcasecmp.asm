BITS 64

section .text
global strcasecmp:function

strcasecmp:
        XOR RAX, RAX ;set output to 0
        XOR RCX, RCX ; set incrementer to 0
        JMP .loop


.loop:
        MOV     R8B, BYTE [RDI + RCX] ;put a char of first str to tempo register
        MOV     R9B, BYTE [RSI + RCX] ;put a char of snd str to tempo register
        CMP     R8B, 'A'
        JL      check_upper ;if char smaller than A, do fcn
        CMP     R8B, 'Z'
        JG      check_upper ;if char greater than Z, do fcn
        ADD     R8B, 32 ;add 32 to char -> to make it smallcase

check_upper:
        CMP     R9B, 'A'
        JL      check_same ;if char smaller than A, do fcn
        CMP     R9B, 'Z'
        JG      check_same ;if char greater than Z, do fcn
        ADD     R9B, 32 ;add 32 to char -> to make it smallcase

check_same:
        CMP     R8B, R9B
        JE      increment ; if char same do fnc

increment:
        CMP     R8B, 0x00
        JE      .end ; if char null end prog
        INC     RCX ;increment incrementer

.end:
        MOVZX    RAX, R8B ; set output to first temp register
        MOVZX    RBX, R9B ; set a register to second temp register
        SUB      RAX, RBX ; set the output to difference between the first and snd registers
        RET