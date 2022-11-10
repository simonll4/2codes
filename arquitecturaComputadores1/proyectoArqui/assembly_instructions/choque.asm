;secuencia de luces mediante guardando las salidas en un archivo
;/////////////////////////////////
;////////////dmem////////////////
;00000000
;003f0000
;00000081
;00000042
;00000024
;00000018
;00000018
;00000024
;00000042
;00000081
;/////////////////////////////////
;////////////imem////////////////;algoritmo para obtener las salidas desde tabla
ldr r5, [r0, #4]        ;r5 = delay en tabla ( segunda palabra)
add r7, r0, #8          ;r7 = puntero para recorrer tabla (arranca de la tercer palabra)
add r8,r0,#8            ;r8 = cantidad de palabras a leer en tabla
INICIO:
ldr r9, [r7]            ;lectura de palabra 
str r9, [r0, #0x800]    ;saco al puerto lectura de tabla
add r6,r0,r5            ;r6 = r5 (para usar a r6 como delay)
DELAY1:
subs r6, r6, #1         ;delay
bne DELAY1              ;branch delay
add r7, r7, #4          ;aumento al puntero en una palabra
subs r8,r8,#1           ;contador de iteraciones(cantidad de palabras en tabla)
addeq r7,r0,#8          ;si r8 = 0, asigno r7 = 8 
addeq r8,r8,#8          ;si r8 = 0, asigno r8 = 8
ADD R3,R0,#0x2          ;delay para doble lectura del inport
DL:
SUBS R3,R3,#1           ;delay
LDR R1,[R0,#0x800]      ;lectura inport ()
BNE DL                  ;branch doble lectura (DL)
ANDS R1,R1,#0x01        ;condicion para salir de la secuencia
BEQ FIN                 ;si r1 = 0, branch inicio
BNE INICIO                         ;si r1 != 0, branch secuencia