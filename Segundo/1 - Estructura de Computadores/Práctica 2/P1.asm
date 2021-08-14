.model small
.data

    ;Juan Garcia Villagran
    
    ;--Declaraciones--
    cadena      DB 5,0, 0,0,0,0,0  ;Numero maximo de caracteres a teclear + 1 (CR:Retorno de Carro)
    peso        DB 1000b, 100b, 10b, 1b ;Binario
    valor_cmp1  DB 0
    valor_cmp2  DB 0
    sig_cmp1    DB ' ', '$'
    sig_cmp2    DB ' ', '$'
    

.code

    ;--Inicializamos segmento de datos
    MOV AX, seg cadena  ;Mueve el segmento cadena al Acumulador
    MOV DS, AX          ;Mueve del Acumulador al Segmento Datos
    
    ;--Introduccion por teclado
    MOV DX, OFFSET cadena
    MOV AH, 0Ah
    INT 21h
    
    ;--Calculos
        ;--Cambio de ASCII a Binario
        SUB cadena[2], 48
        SUB cadena[3], 48
        SUB cadena[4], 48
        SUB cadena[5], 48
        ;cadena[6] almacena el Return
        
        
        ;--CompA1  
        CMP cadena[2],1 ;Comparo si el bit 1 es 1 o 0, para saber si es positivo o negativo
        JE negativo_cmp1    
            ;--Parte positiva
            MOV sig_cmp1, '+'
            
            MOV BX, 0           ;Pongo el primer bit a 0
            
            MOV AL, cadena[3]   ;Paso al acumulador el valor de cadena[3]
            MUL peso[1]         ;Lo multiplico por el peso[1]
            ADD BX,AX           ;Lo guardo
            
            MOV AL, cadena[4]
            MUL peso[2]
            ADD BX,AX
            
            MOV AL, cadena[5]
            MUL peso[3]
            ADD BX,AX
            
            JMP fin_cmp1
            
            ;--Parte negativa (Invertir 1s por 0s y viceversa)
            negativo_cmp1:
            MOV sig_cmp1, '-' 
            
            MOV BX,0
                      
            MOV AL,cadena[3]    ;Muevo a AL cadena[3]
            NOT AL              ;Lo niego
            AND AL, 00000001b
            MUL peso[1]         ;Multiplico por el peso correspondiente
            ADD BX,AX           ;Lo guardo
            
            MOV AL,cadena[4]    
            NOT AL             
            AND AL, 00000001b
            MUL peso[2]        
            ADD BX,AX           
                      
            MOV AL,cadena[5]    
            NOT AL              
            AND AL, 00000001b
            MUL peso[3]        
            ADD BX,AX         
            
            fin_cmp1:
            MOV valor_cmp1, BL
            
        
        ;--CompA2
        CMP cadena[2],1
        JE negativo_cmp2
            ;--Parte positiva
            MOV sig_cmp2, '+'
            
            MOV BX,0
            
            MOV AL, cadena[3]   ;Paso al acumulador el valor de cadena[3]
            MUL peso[1]         ;Lo multiplico por el peso[1]
            ADD BX,AX           ;Lo guardo
            
            MOV AL, cadena[4]
            MUL peso[2]
            ADD BX,AX
            
            MOV AL, cadena[5]
            MUL peso[3]
            ADD BX,AX
                        
            JMP fin_cmp2 
            
            ;--Parte negativa
            negativo_cmp2:
            MOV sig_cmp2, '-' 
            
            MOV BX, 1  

            MOV AL, cadena[3]
            NOT AL
            AND AL, 00000001b 
            MUL peso[1] 
            ADD BX, AX

            MOV AL, cadena[4]
            NOT AL
            AND AL, 00000001b
            MUL peso[2] 
            ADD BX, AX            
            
            MOV AL, cadena[5]
            NOT AL
            AND AL, 00000001b
            MUL peso[3]  
            ADD BX, AX
                        
            fin_cmp2:
            MOV valor_cmp2, BL
    
    
    ;--Mostrar por pantalla        
    MOV AX, 0b800h ;Lleva el 0 delante para no leerlo como etiqueta
    MOV ES, AX     ;Mueve del Acumulador al Segmento Extra
    
    ;--Fondo negro, letra blanca
    MOV AH, 00001111b
    
    ;--Resultados
        ;--CompA1
        MOV AL, 'C'
        MOV ES:[160], AX  
        MOV AL, 'O'
        MOV ES:[162], AX
        MOV AL, 'M'
        MOV ES:[164], AX
        MOV AL, 'P'
        MOV ES:[166], AX
        MOV AL, '1'
        MOV ES:[168], AX
        MOV AL, ':'
        MOV ES:[170], AX   
        
        MOV AL, sig_cmp1
        MOV ES:[172], AX
        ADD valor_cmp1, 48
        MOV AL, valor_cmp1
        MOV ES:[174], AX
        
        ;--CompA2
        MOV AL, 'C'
        MOV ES:[320], AX  
        MOV AL, 'O'
        MOV ES:[322], AX
        MOV AL, 'M'
        MOV ES:[324], AX
        MOV AL, 'P'
        MOV ES:[326], AX
        MOV AL, '2'
        MOV ES:[328], AX
        MOV AL, ':'
        MOV ES:[330], AX   
        
        MOV AL, sig_cmp2
        MOV ES:[332], AX
        ADD valor_cmp2, 48
        MOV AL, valor_cmp2
        MOV ES:[334], AX          
    
    
    ;--Fin
    MOV AH, 4Ch
    INT 21h    