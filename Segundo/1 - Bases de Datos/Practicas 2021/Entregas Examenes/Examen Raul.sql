-----ALTER TABLE-----
--1.a) El atributo duracion sea estrictamente mayor que 0
ALTER TABLE LLAMADA
	ADD CONSTRAINT duracionLlamada CHECK (duracion>0);
--1.b) Establecer a nulo los telefonos de los clientes que han recibido llamada cuando se eliminen dichos clientes de la base de datos


--2. Usando las tablas MF
--2.a) Obtener el nombre de las compañias que tengan algun cliente de la provincia de Madrid con un coste en su tarifa inferior a 0,30 (0,35ptos)
	SELECT DISTINCT COMP.nombre
	FROM ((MF.CLIENTE CLI INNER JOIN MF.TELEFONO TEL  ON (CLI.DNI=TEL.CLIENTE))
		INNER JOIN MF.TARIFA TAR USING (tarifa))
		INNER JOIN MF.COMPAÑIA COMP ON (TAR.compañia = COMP.cif)
	WHERE CLI.PROVINCIA = 'Madrid' AND TAR.coste<0,30;
--2.b) Mostrar el total de puntos por cliente y compañia, de aquellos que hayan realizado llamdas entre Junio y Septiembre a numeros de la compañia 'Aotra' (0,6ptos)
	
--2.c) Utilizando Consultas correlacionadas, mostrar los clientes que han realizado y recibido llamadas en el mes de octubre, sin disponer de tarifa de autonomos (0,5ptos)
	SELECT DISTINCT CLI.nombre 
	FROM ((MF.cliente CLI INNER JOIN MF.telefono TEL ON (cli.dni = tel.cliente))
		INNER JOIN MF.LLAMADA ORI ON (tel.numero=ori.tf_origen))
		INNER JOIN MF.LLAMADA DEST ON (tel.numero=dest.tf_destino)
	WHERE (TO_CHAR(ori.fecha_hora, 'mm')=10 AND TO_CHAR(dest.fecha_hora, 'mm')=10 ) AND NOT EXISTS (	SELECT *
																										FROM MF.telefono T
																										WHERE T.tarifa='autonomos' AND T.cliente=CLI.dni);