;00000001    1   1
;00000011    3   3
;00000111    7   7
;00001111    F   15
;00011111    1F  31
;00111111    3F  63
;01111111    7F  127
;11111111    FF  255 ** 1
;00000011    3   3
;00000111    7   7
;00001111    F   15
;00011111    1F  31
;00111111    3F  63
;01111111    7F  127
;11111111    FF  255 ** 2
;00000111    7   7
;00001111    F   15
;00011111    1F  31
;00111111    3F  63
;01111111    7F  127
;11111111    FF  255 ** 3
;00001111    F   15
;00011111    1F  31
;00111111    3F  63
;01111111    7F  127
;11111111    FF  255 ** 4
;00011111    1F  31
;00111111    3F  63
;01111111    7F  127
;11111111    FF  255 ** 5
;00111111    3F  63
;01111111    7F  127
;11111111    FF  255 ** 6
;01111111    7F  127
;11111111    FF  255 ** 7

;////////////
;//algoritmo
;///////////

INICIO: SUB R0,R15,R15      ;seteo cero
        ADD R1,R0,#1        ;valor inicial de la secuencia = 1
        ADD R2,R0,#2        ;potencia de dos inicial = 2
        ADD R3,R0,#8        ;iteracion inicial loop 1 = 8
        ADD R5,R0,#0        ;indice para determinar el siguiente iterador
        ADD R6,R0,#1        ;auxiliar de R1 para iniciarlizarlo
        ADD R7,R0,#2        ;auxiliar de R2 para iniciarlizarlo
        ADD R8,R0,#7        ;iterador loop 2
LOOP 2: ADD R1,R0,R6        ;se reiniciliza r1
        ADD R2,R0,R7        ;se reiniciliza r2
        ADD R6,R1,R2        ;se busca el proximo valor de R1
        ADD R7,R2,R2        ;proximo valor para R2
LOOP 1: STR R1,[R0,0x800]   ;inicia suencias de luces
        ADD R1,R1,R2        
        ADD R2,R2,R2
        ADD R4,R0,#1
RETARDO 1:SUBS R4,R4,#1
        BNE RETARDO 1       
        ADD R5,R5,#1        ;cuento iteraciones
        SUBS R3,R3,#1       ;condicion para finalizar loop 1
        BNE LOOP 1          ;finaliza secuencia de luces
        SUB R3,R5,#1        ;guardo en el iterador las iteraciones contadas menos 1
        ADD R5,R0,#0        ;vuelvo a cero el contador de iteraciones
        SUBS R8,R8,#1       ;condicion para finalizar loop 2
        BNE LOOP 2
        b INICIO

;////////////
;//algoritmo para implementar en placa 
;///////////
SUB R0,R15,R15
ADD R1,R0,#1
ADD R2,R0,#2
ADD R3,R0,#8
ADD R5,R0,#0
ADD R6,R0,#1
ADD R7,R0,#2
ADD R8,R0,#7
ADD R1,R0,R6
ADD R2,R0,R7
ADD R6,R1,R2
ADD R7,R2,R2
STR R1,[R0,0x800]
ADD R1,R1,R2        
ADD R2,R2,R2
LDR R4,[R0,#0x4]
SUBS R4,R4,#1
BNE #0x40       
ADD R5,R5,#1
SUBS R3,R3,#1
BNE #0x30
SUB R3,R5,#1
ADD R5,R0,#0
SUBS R8,R8,#1
BNE #0x20
b #0x4