CREATE OR REPLACE
  PROCEDURE PRUEBA2BD1 (p_num_telefono TELEFONO.NUMERO%TYPE) IS
    --Variables
    nollamadas EXCEPTION;
    n_llamadas_nivel_uno INTEGER;
    n_llamadas_nivel_dos INTEGER;
    c_llamadas_nivel_uno CURSOR;
    c_llamadas_nivel_dos CURSOR;
    niv1_numero TELEFONO.NUMERO%TYPE;
    niv1_cliente TELEFONO.CLIENTE%TYPE;
    niv1_tarifa TELEFONO.TARIFA%TYPE;
    niv2_numero TELEFONO.NUMERO%TYPE;
    niv2_ciudad CLIENTE.CIUDAD%TYPE;
    niv2_tarifa TELEFONO.TARIFA%TYPE;
    niv2_duracion LLAMADA.DURACION%TYPE;
    
    CURSOR c_llamadas_nivel_uno(pc_num1 TELEFONO.NUMERO%TYPE) IS
        SELECT LL.tf_destino,  TEL.cliente, TEL.tarifa INTO niv1_numero, niv1_cliente, niv1_tarifa
        FROM LLAMADA LL INNER JOIN TELEFONO TEL ON (LL.tf_origen=TEL.numero)
        WHERE tf_origen=p_num_telefono;
        LOOP 
        dbms_output.put_line('--> ' || niv1_numero || ' - ' || niv1_cliente || ' - ' || niv1_tarifa );
        END LOOP;
        
      CURSOR c_llamadas_nivel_dos(pc_num2 TELEFONO.NUMERO%TYPE) IS
        SELECT LL.tf_destino, CLI.ciudad, TEL.tarifa, LL.duracion INTO niv2_numero, niv2_ciudad, niv2_tarifa, niv2_duracion
        FROM CLIENTE CLI INNER JOIN TELEFONO TEL ON (TEL.cliente=CLI.dni)
          INNER JOIN LLAMADA LL ON (LL.tf_destino=TEL.numero)
        WHERE tf_origen=pc_num2;
        LOOP
          dbms_output.put_line('( ' || pc_num2 || ' --> ' || niv2_numero || ')- ' || niv2_ciudad || ' - ' || niv2_tarifa || ' - ' || niv2_duracion);
        END LOOP;



    BEGIN
      SELECT COUNT(tf_destino) INTO n_llamadas_nivel_uno
      FROM LLAMADA LL INNER JOIN TELEFONO TEL ON (LL.tf_origen=TEL.numero)
      WHERE LL.tf_origen=p_num_telefono;
      
      IF (n_llamadas_nivel_uno=0) THEN
        RAISE nollamadas;
      END IF;
      
      dbms_output.put_line('Rastreando llamadas del numero ' || p_num_telefono);
      
     LOOP
      c_llamadas_nivel_uno(p_num_telefono);
      END LOOP;
      
    EXCEPTION
      WHEN nollamadas THEN
        dbms_output.put_line('No hay ninguna llamada realizada por el numero de telefono ' || p_num_telefono);
    END PRUEBA2BD1;
    