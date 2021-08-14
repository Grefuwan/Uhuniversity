.MODEL SMALL	;Directiva que indique que el programa no ocupará más de 64K
.CODE			;No habrá .DATA porque se definiran en el mismo Codigo
	
	org 100h	;100h = 256 -- Indica que el programa lo inicie a partir de esa direccion; en la 0 está el S.O.
	
Programa_Int:	;Etiqueta de Direccion de Memoria
	
	JMP Reside		;Bifurcacion Incondicional, Salto a Reside
	CONT 		DB 0		;Contador para las interrupciones. Cuando llegue a 18, será 1 segundo
	MSJ 		DB '00:00'	;Cronometro
	segundos 	DB 0
	minutos 	DB 0
	
Rutina_Servicio PROC	;Conjunto de instrucciones de la Rutina de Atencion de la Interrupcion
	CLI	;Instruccion Clear I, pone a 0 el Biestable I (Inhibicion de Interrupciones). Si está a 0, las peticiones de interrupcion por linea INT no se atienden; si está a 1, sí.
	;Salvar el contenido de los registros implicados en la rutina
	INC CONT		;Incremento contador
	CMP CONT, 18	;Comparo si llego a 18 interrupciones (1seg)
		JB EXIT			;Si no, me salgo
	MOV CONT, 0		;Si llego a 18, reseteo el contador
	
	MOV AX, 0B800h		;Muevo a AX la direccion del segmento de memoria de video
	MOV ES, AX			;Muevo a ES AX, es decir, la direccion del segmento de memoria de video
	MOV AH, 00001111b	;Letras blancas fondo negro
	
	MOV SI, 0		;Contador para MSJ
	MOV DI, 148		;Nos posicionamos en la pantalla justo al final de la primera linea
	
	escritura1:		;Escritura Contador Cronometro
		MOV AL,MSJ[si]
		MOV ES:[DI], AX
		ADD DI,2
		INC SI
	CMP SI, 14
	JBE escritura1
	
	INC segundos		;Incrementa los segundos
	CMP segundos, 60	;Los compara con 60
		JNE sigue		;Si segundos<60 se va a sigue
	MOV segundos, 0		;Si son 60, pone segundos=0 e incrementa 1 minuto
	INC minutos
	
	sigue:				
	CMP minutos, 60		;Compara los minutos con 60
		JNE sigue2		;Si son menores de 60 (1 hora), sale a sigue2
	MOV minutos, 0		;Si es 60, los pone a 0
	
	sigue2:
	MOV AL,minutos		;Muevo a AL los minutos
		MOV AH, 0		;Conversor Binario->ASCII ;AH=0
		MOV DL, 10		;DL=10
		DIV DL			;AX=AX/DL
		OR AX, 3030h	;Converte el binario de AX en ASCII
	MOV MSJ[9], AL		;Decenas de los minutos a AL
	MOV MSJ[10], AH		;Unidades de los minutos a AH
	MOV AL, segundos	;Muevo a AL los segundos
		MOV AH, 0		;Conversor Binario->ASCII ;AH=0
		MOV DL, 10		;DL=10
		DIV DL			;AX=AX/DL
		OR AX, 3030h	;Converte el binario de AX en ASCII
	MOV MSJ[12], AL
	MOV MSJ[13], AH
	
	EXIT:
	
	;Recupera el valor de los registros implicados en la rutina
	STI	;Vuelve a permitir las Interrupciones, poniendo a 1 el Biestable I
	IRET	;Instruccion de Retorno de Interrupcion
ENDP

Reside:	;Etiqueta para determinar la direccion siguiente a la ultima de la rutina que debe quedar residente
		;Define el Vector de Interrupcion
	MOV DX, offset Rutina_Servicio	;Movemos a DX el offset de Rutina_Servicio (Dir Mem)
	MOV AX, 0	;Movemos a AX el valor 0 para luego llevarlo a ES (Extra)
	MOV ES, AX	;Movemos a ES el registro AX. Luego ES será 0
	MOV SI, 1Ch*4	;Muevo a SI el Codigo de Interrupcion * 4 (2 Offset y 2 Segment de la interrupcion 1Ch)
	CLI	;Instruccion Clear I, pone a 0 el Biestable I (Inhibicion de Interrupciones). Si está a 0, las peticiones de interrupcion por linea INT no se atienden; si está a 1, sí.
	MOV ES:[SI], DX	;Ahora, como ES=0 y SI=1C*4, muevo el offset Rutina_Servicio a la direccion de memoria donde comienza la Rutina de Atencion de Interrupcion
	MOV ES:[SI+2], CS	;En las 2 direcciones siguientes meto el Segmento de Codigo
	STI	;Vuelve a permitir las Interrupciones, poniendo a 1 el Biestable I
	MOV DX, offset Reside	;En vez de devolver el control al S.O., hago que quede en memoria Rutina_Servicio
	INT 27h					;Hará que se quede en memoria hasta que salga del emulador del MS-Dos

END Programa_Int