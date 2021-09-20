--Ejercicio 1
--	Diseñar la funcion facturacion(), la cual admite dos parámetros por entrada (un telefono y un año), y devuelve
--	la facturacion total de ese numero en ese año. La funcion debe controlar 2 tipos de excepciones:
--		-El telefono no existe o el telefono no ha realizado llamadas ese año
--		-La facturacion del telefono es inferior a 1 euro
CREATE OR REPLACE
	FUNCTION facturacion(p_tf_origen MF.LLAMADA.tf_origen%TYPE, p_anno INTEGER) RETURN FLOAT IS --Igual que FLOAT, puedo poner NUMBER(10,2)
	--Zona de declaracion de variables locales
	importe NUMBER(10,2);	--10 numeros, 8 enteros y 2 decimales
	facturacionBaja EXCEPTION
	
	BEGIN
		SELECT SUM(LL.duracion/60*TA.coste) INTO importe	--Guardo la query en una variable
		FROM MF.TELEFONO T INNER JOIN MF.TARIFA Ta USING (TARIFA, COMPAÑIA)
			INNER JOIN MF.LLAMADA LL ON LL.tf_origen=T.numero
		WHERE LL.tf_origen=p_tf_origen AND EXTRACT(year from fecha_hora)=p_anno
		GROUP BY LL.tf_origen;
		
		IF importe<1 THEN
			RAISE facturacionBaja;
		END IF;		
	RETURN importe;
	
	EXCEPTION
		WHEN facturacionBaja THEN
			dbms_output.put_line('Facturacion demasiado baja');
			RETURN -1;
		WHEN NO_DATA_FOUND THEN
			dbms_output.put_line('El telefono no existe o no ha realizado llamadas ese año');
			RETURN -1;
		WHEN OTHERS THEN
			dbms_output.put_line('Ha ocurrido un error');
			RETURN -1;
END;

EXECUTE dbms_output.put_line(facturacion('654123321', 2006));



--Ejercicio 2
--	Diseñar el procedimiento LlamadaFacturacion(año), el cual, para cada telefono de la tabla LLAMADAS, debe realizar
--	una llamada a la funcion facturacion y mostrar la facturacion de dicho telefono en el año que se le pasa como parametro
SET SERVEROUTPUT ON;
CREATE OR REPLACE
	PROCEDURE LlamadaFacturacion(p_anno INTEGER) IS
	
		CURSOR c_telefonos(c_anno INTEGER)
			IS 	SELECT DISTINCT LL.tf_origen 
				FROM MF.LLAMADA LL
				WHERE EXTRACT(YEAR FROM LL.fecha_hora) = c_anno;
		BEGIN
			FOR r_telefonos IN c_telefonos(p_anno) LOOP
				dbms_output.put_line(r_telefono.tf_origen || ' - ' || facturacion(r_telefono.tf_origen, p_anno));
			END LOOP;

		EXCEPTION
			WHEN OTHERS THEN
				dbms_output.put_line('Ha ocurrido un error');
				RETURN -1;
END;


EXECUTE LlamadaFacturacion(2006);



--Ejercicio 3
--	Crear un procedimiento que tenga como parametros de entrada el nombre de una compañia y una fecha. Dicho procedimiento
--	debe realizar las siguientes operaciones:
--		-Comprobar que existen llamadas realizadas en la fecha indicada. En caso contrario, lanzar una excepcion y mostrar
--			el mensaje "No hay llamdas en la fecha <fecha> en la BD"
--		-Para cada telefono de la compañia indicada, mostrar el numero de telefono, numero total de llamdas realizadas en
--			la fecha indicada, numero de llamadas de duracion mayor a 100seg en la fecha y porcentaje que suponen estas ultimas
--			respecto al total de las realizadas
--		-Resumen del numero de llamadas realizadas por todos los telefonos de la compañia indicada en la fecha indicada
SET SERVEROUTPUT ON
CREATE OR REPLACE
	PROCEDURE llamadas_cia(p_nomComp MF.COMPAÑIA.nombre%TYPE, p_fecha DATE) IS
		existe_fecha 			INTEGER;	--Variable que registrará cuantas llamadas hay en esa fecha
		noLlamadas 				EXCEPTION;	--Excepcion que saltará si en una fecha no hay ninguna llamada
		num_llamadas 			INTEGER;	--Variable que guardará el total de llamadas por teléfono
		num_llamadas_mas_100 	INTEGER;	--Variable que guardará cuántas llamadas duran más de 100seg
		num_total_llamadas 		INTEGER;	--Variable que guardará el total de llamadas
		
		CURSOR c_telefonos IS
			SELECT T.numero
			FROM MF.TELEFONO T INNER JOIN MF.COMPAÑIA Comp ON (T.compañia = Comp.CIF)
			WHERE Comp.nombre=p_nomComp;
		
		CURSOR c_llamadas(p_tlf MF.TELEFONO.numero%TYPE) IS
			SELECT LL.tf_destino, LL.duracion
			FROM MF.LLAMADA LL
			WHERE LL.tf_origen=p_tlf AND TO_CHAR(LL.fecha_hora, 'dd/mm/yy')=p_fecha;

	BEGIN
		SELECT COUNT(*) INTO existe_fecha
		FROM MF.LLAMADA LL
		WHERE TO_CHAR(LL.fecha_hora,'dd/mm/yy') = p_fecha;
		
		IF existe_fecha THEN
			RAISE noLlamadas
		END IF;
		
		num_total_llamadas := 0;
		FOR r_telefonos IN c_telefonos LOOP
			dbms_output.put_line(r_telefono.numero);
			num_llamadas := 0;
			num_llamadas_mas_100 := 0;
			FOR r_llamadas IN c_llamadas(r_telefono.numero);
				dmbs_output.put_line(r_llamada.duracion);
				num_llamadas := num_llamadas + 1;
				IF (r_llamada.duracion > 100) THEN
					num_llamadas_mas_100 = num_llamadas_mas_100 + 1;
				END IF;
			END LOOP;
			dbms_output.put_line(num_llamadas || ' ' || num_llamadas_mas_100);
			num_total_llamadas := num_total_llamadas + num_llamadas;
		END LOOP;
		
	EXCEPTION
		WHEN noLlamadas THEN
			dbms_output.put_line('No hay llamadas en la fecha ' || p_fecha || ' en la BD');
			RETURN -1;
	
END;


EXECUTE llamadas_cia('Aotra', '01/10/06');

--Ejercicio 4 (No entra en la prueba de PL/SQL)
--	Crear un disparador que examine la insercion de nuevas llamadas y controle que, en la fecha y hora en la que se produce la
--	nueva llamada, los telefonos origen y destino no estan atendiendo ni realizando ninguna llamada iniciada en esa misma fecha y hora