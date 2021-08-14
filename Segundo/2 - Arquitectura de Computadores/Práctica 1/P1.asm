.model small

.data
	
	MSJ DB 'KuribohAlado '	;13 caracteres
	CONT DB '000000 '		;7 caracteres (6 numeros + espacio)

.code
	
	
	;Inicializamos el segmento de datos
	MOV AX, SEG MSJ	;Mueve el segmento MSJ al Acumulador
	MOV DS, AX		;Mueve del Acumulador al Segmento Datos
	
	;Establecemos modo texto
	MOV AL, 03h
	MOV AH, 00h
	
	;Ponemos segmento extra en memoria de video
	MOV AX, 0b800h
	MOV ES, AX
	
	;Fondo negro, letra blanca
    MOV AH, 00001111b
	
	
	
	;Empieza el codigo
	MOV SI, 0
	MOV DI, 0
	pinta:
		MOV AL, MSJ[SI]
		MOV ES:[DI], AX
		INC SI
		ADD DI, 2
		CMP SI, 9	
		
		JBE nend
		    MOV SI, 0
		    MOV AL, ' '
		    MOV ES:[DI], AX
		    ADD DI, 2
		
		nend:
		    CMP DI, 80*2*25		;Control de la organizacion de la pantalla en modo texto: 80 columnas * 25 filas
		
    JMP pinta
    JB pinta
		
		
	;Finalizar el programa	
    MOV AH, 4ch
    INT 21h
		
END