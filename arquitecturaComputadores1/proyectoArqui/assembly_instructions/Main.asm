﻿SUB R0, R15, R15
ADD R3,R0,#2
SUBS R3,R3,#1
LDR R1, [R0, #0x800]
BNE #0x8
ANDS R2, R1, #0x10
AND R1, R1, #0x0F 
STR R1, [R0, #0x800] 
BNE #0x4
ANDS R2, R1, #0xFE
BEQ #0x54
ANDSNE R2, R1, #0xFD
BEQ OP2
ANDSNE R2, R1, #0xFB
BEQ OP3
ANDSNE R2, R1, #0xF7
BEQ OP4
B #0x5c
//OP2
//OP3
//OP4
ldr r5, [r0, #4]
add r7, r0, #8
add r8,r0,#8
ldr r9, [r7]
str r9, [r0, #0x800]
add r6,r0,r5
subs r6, r6, #1
bne #0x6C
add r7, r7, #4
subs r8,r8,#1
addeq r7,r0,#8
addeq r8,r8,#8
ADD R3,R0,#0x2
SUBS R3,R3,#1   
LDR R1,[R0,#0x800]
BNE #0x88
ANDS R1,R1,#0x01
BEQ #0x4
b #0x60