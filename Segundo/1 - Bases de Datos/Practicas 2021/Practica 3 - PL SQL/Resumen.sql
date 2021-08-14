--ESTRUCTURA FUNCIONES
CREATE OR REPLACE
	FUNCTION nombrefuncion (p_parametro BD.Columna%TYPE) RETURN tipoQueDevuelva IS
		--Declaracion de Variables
		variablee NUMBER(10,2);	--Aqui se guarda la query de abajo y se returnea aqui
		excepciones EXCEPTION
		
		CURSOR c_cursor (p_cursor BD.Columna%TYPE) IS
			SELECT
			FROM
			WHERE	;
		
		BEGIN
			SELECT loquesea INTO variablee
			FROM
			WHERE	;
			--GROUP BY
			--HAVING
			
			IF condicion THEN
				RAISE expeciones
			END IF;
		RETURN variablee
		
		EXCEPTION
			WHEN excepciones THEN
				dbms_output.put_line('loquesea' || loquesea);
				RETURN -1;
END;