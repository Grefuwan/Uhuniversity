--Cuestion 1 (0.3ptos)
--En el cuadro siguiente se muestra la sentencia LDD para crear la tabla TELEFONO de "MoviFacturas".
--Haciendo uso de sentencias ALTER TABLE, indicar las modificaciones que habria que realizar en esta tabla
--	para permitir que:
--	a) El atributo tipo inicialmente tendrá el valor 'C' por defecto, no pudiendo quedar nulo (0.1 ptos)
ALTER TABLE TELEFONO
MODIFY tipo DEFAULT 'C' NOT NULL

--	b) Se pongan a NULL de forma automatica los atributos compañia y tarifa correspondiente a la tabla
--		TELEFONO al eliminar una tarifa (0.2 ptos)
ALTER TABLE TELEFONO
	MODIFY compañia NULL;
ALTER TABLE TELEFONO
	MODIFY tarifa NULL;
ALTER TABLE TELEFONO
	DROP CONSTRAINT tfTarifaAjena;
ALTER TABLE TELEFONO
	ADD CONSTRAINT tfTarifaAjena foreign key (tarifa, compañia) references tarifa ON DELETE SET NULL;
	

--Cuestion 2
--Utilizando las tablas del usuario MF, realizar las siguientes consultas
--a) Obtener el nombre de la/s compañia/s, número y puntos del telefono, asi como nombre y direccion
--		de los telefonos de clientes asociados a compañias que comiencen por la letra K y los puntos
--		del telefono sean superiores a 1500 (0.35 ptos)
	SELECT C.nombre, T.numero, T.puntos, Cl,nombre, Cl.direccion
	FROM (MF. COMPAÑIA C INNER JOIN MF, TELEFONO T ON (T.Compañia = C.cif))
		INNER JOIN MF.CLIENTE Cl ON Cl.DNI = T.Cliente
	WHERE C.Nombre ='K%' AND T.puntos > 1500;
	
--b) Obtener los numeros de telefonos, duracion y mes de las llamadas de telefonos que no pertenezcan
--		a la compañia 'Aotra' y cuya duracion sea superior a la duracion media más baja de llamadas
--		realizadas por telefonos que pertenezcan a la compañia 'Aotra' (0.6 ptos)
	SELECT LL.tf_origen, EXTRACT (month FROM LL.fecha_hora) as Mes, LL.duracion
	FROM MF.LLAMADA LL INNER JOIN MF.TELEFONO T1 ON LL.tf_origen = T1.numero 
		INNER JOIN MF.COMPAÑIA C1 ON C1.cif = T1.compañia
	WHERE C1.nombre <> 'Aotra' AND LL.Duracion > (	SELECT MIN(AVG(L.Duracion))
													FROM MF.LLAMADA L INNER JOIN MF.TELEFONO T ON L.tf_origen = T.numero
														INNER JOIN MF.COMPAÑIA C ON C.cif = T.compañia
													WHERE C.nombre = 'Aotra'
													GROUP BY L.tf_origen)
--c) Utilizando consultas correlacionadas, devolver el nombre de los clientes, su telefono y nombre
--		de la compañia asociada correspondiente a las llamadas cuyo telefono origen comiencen por
--		'65' pero que no hayan llamado a ningun telefono que comience por '66'
	SELECT DISTINCT Cl.nombre, Ll.tf_origen, C.nombre
	FROM ((MF.CLIENTE Cl INNER JOIN MF.TELEFONO T ON (T.Cliente = Cl.dni) 
		INNER JOIN MF.LLAMADA LL ON (T.Numero = LL.tf_origen)
		INNER JOIN MF.COMPAÑIA C ON (C.cif = T.compañia)))
	WHERE T.Numero LIKE '65%' AND NOT EXISTS (	SELECT *
												FROM MF.Llamadas L1
												WHERE L1.tf_origen = LL.tf_origen AND L1.tf_destino LIKE '66%');
												