.model small
.data

    ;Juan Garcia Villagran
    
    ;--Declaraciones--
    cadena          db 5,0, 0,0,0,0,0
    peso            db 1000b, 100b, 10b 1b ;Binario
    valor_cmp1      db 0
    valor_cmp2      db 0
    sig_comp1       db ' ', '$'
    sig_comp2       db ' ', '$'  
    
       
.code

    ;--Inicializamos segmento de datos
    mov ax, seg cadena
    mov ds, ax
    ;--
    
    ;--Lectura por teclado
    mov dx, offset cadena
    mov ah, 0Ah
    int 21h
    ;--
    
    ;--Cambio de ASCII a Binario
    sub cadena[2], 48       ;Les voy restando 48 a todos para obtenerlos en decimal
    sub cadena[3], 48
    sub cadena[4], 48
    sub cadena[5], 48
    ;cadena[6]: contiene el codigo ASCII del Return
    ;--
    
    mov ah,0
    
        
    ;--Complemento a 1--
        cmp cadena[2], 1        ;Mira si el valor es un 1, para pasar a parte negativa o positiva
        je Negativo_cmp1
        
        ;--Parte positiva (cadena[2]==0) --
            mov bx,0            ;El primer valor de la parte positiva es 0
            
            mov sig_comp1, '+'
            
            mov al, cadena[3]   ;Pasamos al acumulador lo que hay en la posicion 3, 2do bit de mayor peso
            mul peso[1]         ;Multiplica por el peso 1: 1000b
            add bx, ax
            
            mov al, cadena[4]
            mul peso[2]
            add bx, ax     
            
            mov al, cadena[5]
            mul peso[3]
            add bx, ax     
            
            jmp fin_cmp1
        ;--Parte negativa (cadena[2]==1) --
            Negativo_cmp1:
            
            mov sig_comp1, '-'    
            
            mov bx,1   
             
            mov al, cadena[3]
            not al
            and al,00000001b
            mul peso[1]
            add bx,ax    
            
            mov al, cadena[4]
            not al
            and al,00000001b,
            mul peso[2]
            add bx,ax   
            
            mov al, cadena[5]
            not al
            and al,00000001b,
            mul peso[3]
            add bx,ax
        
        fin_cmp1:
        mov valor_cmp1, bl    
    
     
     
    ;--Complemento a 2--
        cmp cadena[2], 1
        je Negativo_cmp2
        
        ;--Parte positiva--
            mov bx,0            ;El primer valor de la parte positiva es 0
            
            mov sig_comp2, '+'
            
            mov al, cadena[3]   ;Pasamos al acumulador lo que hay en la posicion 3, 2do bit de mayor peso
            mul peso[1]         ;Multiplica por el peso 1: 1000b
            add bx, ax
            
            mov al, cadena[4]
            mul peso[2]
            add bx, ax     
            
            mov al, cadena[5]
            mul peso[3]
            add bx, ax   
            
            jmp fin_comp2       ;Salta al final del CompA2
             
             
             
        ;--Parte negativa
            Negativo_cmp2:
            
            mov sig_comp2, '-'    
            
            mov bx,1   
            
            mov al, cadena[3]   ;Movemos al acumulador el bit
            not al              ;Lo negamos
            and al,00000001b    ;"Protege" un bit para que no se niegue todo
            mul peso[1]         ;Multiplicamos por el peso
            add bx,ax           ;Lo movemos
            
            mov al, cadena[4]
            not al
            and al,00000001b,
            mul peso[2]
            add bx,ax   

            mov al, cadena[5]
            not al
            and al,00000001b,
            mul peso[3]
            add bx,ax
                          
            
            fin_comp2:
        
        
        add valor_cmp2, bl ;Copiamos el valor
    
    
    
    ;--Representacion pantalla--   
    ;--Memoria de video--
    mov ax, 0b800h     
    mov es, ax
    
    ;--Fondo negro, letra blanca
    mov ah, 00011111b
    
    ;--Resultados
        ;--CompA1
        mov al, 'C'
        mov es:[160], ax  
        mov al, 'O'
        mov es:[162], ax
        mov al, 'M'
        mov es:[164], ax
        mov al, 'P'
        mov es:[166], ax
        mov al, '1'
        mov es:[168], ax
        mov al, ':'
        mov es:[170], ax   
        
        mov al, sig_comp1
        mov es:[172], ax
        add valor_cmp1, 48
        mov al, valor_cmp1
        mov es:[174], ax
        
        ;--CompA2
        mov al, 'C'
        mov es:[320], ax  
        mov al, 'O'
        mov es:[322], ax
        mov al, 'M'
        mov es:[324], ax
        mov al, 'P'
        mov es:[326], ax
        mov al, '2'
        mov es:[328], ax
        mov al, ':'
        mov es:[330], ax   
        
        mov al, sig_comp2
        mov es:[332], ax
        add valor_cmp2, 48
        mov al, valor_cmp2
        mov es:[334], ax          
        
        
        
        
;--Fin de programa
mov ah, 4ch
int 21h             