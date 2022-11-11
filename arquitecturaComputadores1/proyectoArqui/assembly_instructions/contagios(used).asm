;////////////////
;//////dmem/////
;00000000
;004f0000
;00000010
;00000018
;00000038
;0000003C
;0000007C
;0000007E
;000000FE
;000000FF
;000000EF
;000000E7
;000000C7
;000000C3
;00000083
;00000081
;00000001
;00000000
SUB R0,R15,R15
ADD R3,R0,#16
ADD R2,R0,#8
LDR R4,[R2]
STR R4,[R0,#0x800]
LDR R5,[R0,#0x4]
SUBS R5,R5,#1
BNE 0x18
ADD R2,R2,#4
SUBS R3,R3,#1
BNE 0xc

;//////////
ldr r5, [r0, #4] //secuencia3
add r7, r0, #44
add r8,r0,#17
ldr r9, [r7]
str r9, [r0, #0x800]
add r6,r0,r5
subs r6, r6, #1
bne #0x120
add r7, r7, #4
subs r8,r8,#1
addeq r7,r0,#8
addeq r8,r8,#8
ADD R3,R0,#0x2 ////boton
SUBS R3,R3,#1   
LDR R1,[R0,#0x800]
BNE #0x13C
ANDS R1,R1,#0x04
BEQ #0x4
BNE #0x114
b 0x4