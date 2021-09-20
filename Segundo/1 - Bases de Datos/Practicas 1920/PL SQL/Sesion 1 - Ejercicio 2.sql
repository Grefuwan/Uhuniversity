create or replace PROCEDURE mejor_piloto_tramo (v_nombrePBuscado PILOTO.NOMBREP%TYPE) IS

--Variables
v_nombreRally RALLY.NOMBRE%TYPE;
v_mejorTiempo CORRE.TIEMPO%TYPE;
v_numeroTramo TRAMO.NUMEROTRAMO%TYPE;

existe_piloto INTEGER;

no_existe_piloto EXCEPTION;

--Cursores
CURSOR c_RallyCorrido IS
  SELECT NOMBRE
  FROM (Rally INNER JOIN PARTICIPA USING (codRally)) INNER JOIN PILOTO USING (codPiloto)
  WHERE NOMBREP=v_nombrePBuscado;
  
CURSOR c_mejorTiempo IS
    SELECT numeroTramo, MIN(tiempo) AS mejorTiempo
    FROM CORRE INNER JOIN PILOTO USING (codPiloto)
    WHERE  PILOTO.NOMBREP = v_nombrePBuscado
    GROUP BY numeroTramo
    ORDER BY mejorTiempo;

BEGIN
--Abrir Cursor
open c_RallyCorrido;

SELECT COUNT(*) INTO existe_piloto
FROM PILOTO
WHERE NOMBREP = v_nombrePBuscado;

IF existe_piloto = 0 THEN
RAISE no_existe_piloto;
END IF;

DBMS_OUTPUT.PUT_LINE('Mejores tiempos por tramo en los rallies en los que ha participado ' || v_nombrePBuscado);
LOOP --vc_numeroTramo vc_mejorTiempo 
  FETCH c_RallyCorrido  INTO v_nombreRally; 
  DBMS_OUTPUT.PUT_LINE ('-----------------');
  DBMS_OUTPUT.PUT_LINE (v_nombreRally);
  DBMS_OUTPUT.PUT_LINE ('-----------------');
  open c_mejorTiempo;
  LOOP
  FETCH c_mejorTiempo   INTO v_numeroTramo, v_mejorTiempo;
  EXIT WHEN c_mejorTiempo%notfound;
  DBMS_OUTPUT.PUT_LINE (v_numeroTramo || ' - ' || v_mejorTiempo);
  END LOOP;
  close c_mejorTiempo;
END LOOP;

--Cerrar cursores
close c_RallyCorrido;
close c_mejorTiempo;
--Excepciones
EXCEPTION
  WHEN no_existe_piloto THEN
  DBMS_OUTPUT.PUT_LINE(' ERROR: No existe el piloto ' || v_nombrePBuscado);
END;