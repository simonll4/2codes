/--------------------------------------------------------------------------------/
/------------------------------- Auto Fantastico --------------------------------/
/--------------------------------------------------------------------------------/

sec2:       ADD     R4, R0, #7          ; E2804007 ; Movemos un 7 al registro R4, contador del loop1
            ADD     R8, R0, #0          ; E2808000 ; Movemos un 0 al registro R8, contador de luces encendidas
            ADD     R6, R0, #0x80       ; E2806080 ; Movemos el valor 0x80 al registro R6, este sera nuestro registro de luces

loop1:      STR     R6, [R0, #0x800]    ; E5806800 ; Sacamos la luz de la secuencia al puerto
            ADD     R5, R0, #6          ; E2805006 ; Movemos un 6 al registro R5, contador de la division
            ADD     R7, R0, #1          ; E2807001 ; Movemos un 1 al registro R7, acumulador para division
            SUBS    R5, R5, R8          ; E0555008 ; Corregimos R5 segun la cantidad de luces que hayamos encendido y actualiza banderas
            BEQ     salto               ; 0A000002 ; En caso de ser 0, debemos evitar el loop division

division:   SUBS    R5, R5, #1          ; E2555001 ; Restamos uno al contador y actualizamos banderas
            ADD     R7, R7, R7          ; E0877007 ; Acumulamos R7
            BNE     division            ; 1AFFFFFC ;

salto:      ADD     R8, R8, #1          ; E2888001 ; Sumamos 1 al registro R8, correspondiente a la luz que sacamos
            SUB     R6, R6, R7          ; E0466007 ; Division por 2 de R6
            LDR     R9, [R0, #0x4]      ; E5909004 ; Lectura del delay desde tabla, guardamos en el registro R9

delay       SUBS    R9, R9, #1          ; E2599001 ; Restamos uno al contador y actualizamos banderas
            BNE     delay               ; 1AFFFFFD ;

            SUBS    R4, R4, #1          ; E2544001 ; Restamos uno al contador del loop1
            BNE     loop1               ; 1AFFFFF0 ;

            STR     R6, [R0, 0x800]     ; E5806800 ; Sacamos la ultima luz de la primera mitad de la secuencia (0x01)
            ADD     R4, R0, #7          ; E2804007 ; Reseteamos el contador del loop

            ADD     R3,R0,#0x2          ; E2803002 ; Movemos un 2 al registro R2, contador para el bucle de lectura

lectura:    SUBS    R3,R3,#1            ; E2533001 ; Restamos uno al contador y actualizamos banderas
            LDR     R1,[R0,#0x800]      ; E5901800 ; Leemos el puerto, guardando en R1 los valores de los switches y del key_1
            BNE     lectura             ; 1AFFFFFC ;

            ANDS    R1,R1,#0x02         ; E2111002 ; Primer mascara, verificamos que el pin T8 se haya apagado
            BEQ     inicio              ; 0AFFFF91 ;

loop2:      ADD     R6, R6, R6          ; E0866006 ; Multiplicamos R6 por 2
            LDR     R9, [R0, #0x4]      ; E5909004 ; Lectura del delay desde tabla, guardamos en el registro R9

delay       SUBS    R9, R9, #1          ; E2599001 ; Restamos uno al contador y actualizamos banderas
            BNE     delay               ; 1AFFFFFD ;

            STR     R6, [R0, 0x800]     ; E5806800 ; Sacamos la luz al puerto
            SUBS    R4, R4, #1          ; E2544001 ; Restamos uno al contador del loop2
            BNE     loop2               ; 1AFFFFF8 ;

            ADD     R3,R0,#0x2          ; E2803002 ; Movemos un 2 al registro R2, contador para el bucle de lectura

lectura:    SUBS    R3,R3,#1            ; E2533001 ; Restamos uno al contador y actualizamos banderas
            LDR     R1,[R0,#0x800]      ; E5901800 ; Leemos el puerto, guardando en R1 los valores de los switches y del key_1
            BNE     lectura             ; 1AFFFFFC ;

            ANDS    R1,R1,#0x02         ; E2111002 ; Segunda mascara, verificamos que el pin T8 se haya apagado
            BEQ     inicio              ; 0AFFFF84 ;
            BNE     sec2                ; 1AFFFFD7 ; De no haberse apagado el pin T8, se reinicia la secuencia
