--EI 01 - Obtener el codigo, nombre y especialidad de las asignaturas de tercero que tengan más de 4.5 creditos
SELECT A.idAsig AS código, A.nombre, esp AS Especialidad --Si quiero que modifique cómo muestra la salida, le pongo un AS para renombrarlo SOLO a la salida
FROM EI.ASIGNATURA A
WHERE A.curso=3 AND créditos > 4.5;
--Si no le pongo la A del FROM, al resto de la consulta tendria que ir poniendole EI.ASIGNATURA.idAsig 

--EI 02 - Obtener toda la informacion disponible de todos los profesores
SELECT *
FROM EI.PROFESOR;
--Si no pongo WHERE, muestra todas las tuplas. Si pongo * en el SELECT, muestra todos los atributos

--EI 03 - Obtener los distintos tipos de ordenadores que existen en la Escuela
SELECT DISTINCT tipo --Con el DISTINCT en el SELECT me mostrará los distintos tipos que hay
FROM EI.ORDENADOR; 

--EI 04 - Mostrar el nombre de los alumnos, el numero de hermanos y el descuento que le corresponde (300€ por hermano), ordenados de mayor a menor segun el descuento, 
--		  y en caso de igualdad, ordenados alfabeticamente por nombre
SELECT nombre, nH, nH*300 AS descuento
FROM EI.ALUMNO
ORDER BY descuento DESC, nombre ASC; --Al poner 2 criterios en el ORDER BY, el segundo se ejecuta si en el primero hay caso de igualdad

--EI 05 - Obtener el dni y nombre de los alumnos nacidos entre 1970 y 1974 y cuya localidad de nacimiento sea Huelva o Cadiz
SELECT dni, nombre
FROM EI.ALUMNO
WHERE fechaNac BETWEEN '1/1/70' AND '31/12/74' AND lugar IN ('Huelva', 'Cadiz');
--Otra forma
WHERE EXTRACT(year FROM fechaNac)>=1970 AND EXTRACT(year FROM fechaNac)<=1974 AND lugar IN ('Cadiz','Huelva');

--EI 06 - Obtener el nombre de todos los alumnos cuyo nombre empiece por la letra M y hayan nacido en una ciudad cuyo nombre tenga, al menos, 
--		  6 caracteres pero no comience por la letra P
SELECT NOMBRE
FROM EI.ALUMNO
WHERE nombre LIKE 'M%' AND lugar LIKE '______%' AND lugar NOT LIKE 'P%';
--Para buscar asi, el % es n-caracteres, y el _ es 1-caracter
--Por ejemplo, en el lugar LIKE, le pongo 6_ y 1% para que sea de 6 caracteres en adelante

--EI 07 - Obtener un listado de los años de nacimiento de los alumnos, ordenados crecientemente
SELECT DISTINCT EXTRACT (YEAR FROM fechaNac) AS años
FROM EI.ALUMNO
ORDER BY años;
--El EXTRACT extrae lo que le pongas detrás de una fecha: EXTRACT ({YEAR|MONTH|DAY} FROM fecha)

-- MF 01 - Obtener el nombre de las compañias cuya direccion web contenga el caracter 'et' y acabe en 'com'
SELECT c.nombre
FROM MF."COMPAÑIA" C
WHERE c.web LIKE '%et%' AND c.web LIKE '%com'

--MF 02 - Obtener el nombre y direccion de los clientes nacidos en 1973 o 1985 y cuyo codigo postal comience por 15, ordenado ascendentemente por
--		  el nombre y, en caso de igualdad, descendentemente por la direcccion
SELECT c.nombre, c.direccion
FROM MF.CLIENTE C
WHERE c.f_nac BETWEEN '1/1/73' AND '31/12/73' OR c.f_nac BETWEEN '1/1/85' AND '31/12/85' AND c.cp LIKE '15%'
ORDER BY c.nombre ASC, c.direccion DESC;

--MF 03 - Obtener el telefono de destino de las llamadas realizadas desde el numero "666010101" en el año 2006
SELECT l.tf_destino
FROM MF.LLAMADA L
WHERE l.tf_origen IN '666010101';

--MF 04 - Obtener los numeros de telefono que han llamado alguna vez al "666010101" entre las 10:00 y las 12:00
SELECT l.tf_origen
FROM MF.LLAMADA L
WHERE l.tf_destino IN '666010101' AND 

--EI 08 - Obtener los nombres de las asignaturas junto con el nombre del profesor responsable
SELECT A.nombre AS NomAsig, P.nombre AS NomProf
FROM EI.ASIGNATURA A, EI.PROFESOR P
WHERE A.prof = p.nPr;
--Igual pero usando el INNER JOIN
SELECT A.nombre AS NomAsig, P.nombre AS NomProf
FROM EI.ASIGNATURA A INNER JOIN EI.PROFESOR P ON A.prof = P.nPr;

--EI 09 - Obtener los numeros de los alumnos que se han matriculado en Base de Datos I en el curso 2002-03
SELECT alum
FROM EI.MATRICULA M INNER JOIN EI.ASIGNATURA A USING (idAsig)
WHERE A.nombre = 'Bases de Datos I' AND año = 2002;

--EI 10 - Obtener los nombres de los alumnos que han aprobado la asignatura Algoritmos y Estructuras de Datos I en la convocatoria de febrero_junio de 2001
SELECT A.nombre
FROM (EI.ASIGNATURA ASIG INNER JOIN EI.MATRICULA M USING (idAsig)) INNER JOIN EI.ALUMNO A ON M.alum = A.nAl
WHERE ASIG.nombre = 'Algoritmos y Estructuras de Datos I' AND año = 2001 AND feb_jun >=5;

--EI 11 - Obtener un listado con el numero de despacho, pero solo de aquellos donde hay al menos 2 profesores
SELECT DISTINCT despacho
FROM EI.PROFESOR P1 INNER JOIN EI.PROFESOR P2 USING (despacho)
WHERE P1.nombre <> P2.nombre;

--EI 12 - Obtener una lista con todas las asignaturas de las que es responsable o docente la profesora Dolores Toscano Barriga
(	SELECT A.nombre
	FROM EI.ASIGNATURA A INNER JOIN EI.PROFESOR P ON P.nPr = A.prof
	WHERE P.nombre = 'Dolores Toscano Barriga')
UNION
(	SELECT A.nombre
	FROM (EI.ASIGNATURA A INNER JOIN EI.MATRICULA M USING (idAsig)) INNER JOIN EI.PROFESOR P ON M.prof=P.nPr
	WHERE P.nombre = 'Dolores Toscano Barriga');

--EI 13 - Obtener los nombres de los alumnos que no se han presentado a 'Bases de Datos I' en diciembre de 2002 por haberla aprobado en una convocatoria
--		  anterior del mismo año
SELECT A.nombre
FROM (EI.ALUMNO A INNER JOIN EI.MATRICULA M ON A.nAl = M.alum) INNER JOIN EI.ASIGNATURA ASIG USING (idAsig)
WHERE ASIG.nombre = 'Bases de Datos I' AND año = 2002 AND dic IS NULL AND (jeb_jun>=5 OR sep >=5);

--MF 05 - Mostrar el código y coste de las tarifas junto con el nombre de la compañia que las ofrecen, de aquellas tarifas cuya descripcion indique que
--		  otras personas deben estar tambien en la misma compañia
SELECT Tar.tarifa AS Tarifa, Tar.coste AS Coste, Comp.nombre AS 
FROM MF.TARIFA Tar INNER JOIN MF.COMPAÑIA Comp ON Tar.Compañia = Comp.Compañia
WHERE  T.Descripcion like '% compañia';

--MF 06 - Nombre y número de telefono de aquellos abonados con contrato que tienen tarifas inferiores a 0.20€
SELECT Cli.nombre, Tel.numero
FROM (MF.TELEFONO Tel INNER JOIN MF.TARIFA Tal USING (tarifa, compañia)) INNER JOIN MF.CLIENTE Cli on TF.Cliente = Cli.dni
WHERE Tel.tipo = 'C' AND Tel.coste < 0.2;

--MF 07 - Obtener el código de las tarifas, el nombre de las compañias, los numeros de telefono y los puntos, de aquellos telefonos que se contrataron en
--		  el año 2006 y que hayan obtenido más de 200 puntos
SELECT Tar.tarifa, Comp.nombre, Tel.numero, Tel.puntos
FROM (MF.TARIFA Tar INNER JOIN MF.TELEFONO Tel USING (tarifa, compañia)) INNER JOIN MF.COMPAÑIA Comp ON Compañia = Comp.cif
WHERE  EXTRACT (YEAR FROM f_contrato) = 2006 AND puntos > 200;

--MF 08 - Obtener los numeros de telefono (origen y destino), asi como el tipo de contrato, de los clientes que alguna vez hablaron por telefono entre las
--		  8 y las 10 de la mañana
SELECT Tfo.numero AS Numero_origen, Tfo.tipo AS Tipo_Origen, Tfd.numero AS Numero_destino, Tfd.tipo AS Tipo_destino
FROM (MF.TELEFONO Tfo INNER JOIN MF.LLAMADA Ll ON Tel.Numero = Ll.tf_origen) INNER JOIN MF.TELEFONO Tfd ON Tfd.numero = Ll.tf_destino
WHERE EXTRACT (HOUR FROM Ll.fecha_hora) >= 8 AND EXTRACT (HOUR FROM Ll.fecha_hora) < 10;

--MF 09 - Interesa conocer los nombres y numeros de telefono de los clientes (origen y destino) que, perteneciendo a compañias distintas, mantuvieron llamadas
--		  que superaron los 15 minutos. Se desea conocer, tambien, la fecha y la hora de dichas llamadas, asi como la duracion de esas llamadas.
SELECT Comp.nombre 'Cliente Origen', Tel.tf_origen, 
FROM (((MF.CLIENTE Co INNER JOIN MF.Telefono Tfo ON Co.dni=Tfo.cliente)
		INNER JOIN MF.Llamada Ll ON Tfo.Numero = Ll.tf_origen)
		INNER JOIN MF.Telefono Tfd ON Tfd.Numero = Ll.tf_destino)
		INNER JOIN MF.Cliente Cd ON Cd.dni = Tfd.cliente
WHERE Tfo.compañia <> Tfd.compañia AND Ll.duracion>900;

--EI 14 - Obtener una lista de los alumnos que hayan nacido en la misma ciudad que Samuel Toscano Villegas y tengan el mismo numero de hermanos que Beatriz Rico Vazquez
SELECT nombre
FROM EI.ALUMNO
WHERE lugar = (	SELECT lugar
				FROM EI.ALUMNO
				WHERE nombre = 'Samuel Toscano Villegas')
	AND nH = (	SELECT nH
				FROM EI.ALUMNO
				WHERE nombre = 'Beatriz Rico Vazquez');

--EI 15 - Obtener una lista con los alumnos matriculados en BDII y no en BDI
SELECT nombre
FROM EI.ALUMNO
WHERE nAl IN (			SELECT M.alum
						FROM EI.ASIGNATURA A INNER JOIN EI.MATRICULA M USING (idAsig)
						WHERE A.nombre = 'Bases de Datos II')
	AND nAl NOT IN (	SELECT M.alum
						FROM EI.ASIGNATURA A INNER JOIN EI.MATRICULA M USING (idAsig)
						WHERE A.nombre = 'Bases de Datos I');
--EI 16 - Obtener una lista de los profesores que tienen más antigüedad que alguno de los profesores del despacho FC-7366 (sin contar los del propio despacho FC-7366)
SELECT nombre
FROM EI.PROFESOR
WHERE despacho <> 'FC-7366' AND
		ant < ANY (	SELECT ant
					FROM EI.PROFESOR
					WHERE despacho = 'FC-7366')

--EI 17 - Obtener una lista con los nombres de los alumnos que hayan sacado una nota más alta en septiembre que la más alta de las notas de febrero/junio, en el año
--		  2002 y en la asignatura Bases de Datos I
SELECT AL.nombre
FROM (EU.MATRICULA M INNER JOIN EI.ASIGNATURA A USING (idAsig)) INNER JOIN EI.ALUMNO AL ON AL.nAL = alum
WHERE A.nombre = 'Bases de Datos I' AND año = 2002
	AND sep> ALL (	SELECT feb_jun
					FROM EI.MATRICULA M INNER JOIN EI.ASIGNATURA A USING (idAsig)
					WHERE nombre = 'Bases de Datos I' AND año = 2002 AND feb_jun IS NOT NULL);

--MF 10 - Obtener la fecha (dia-mes-año) en la que se realizó la llamada de mayor duración
SELECT TO_CHAR (fecha_hora, 'dd/mm/yy') Fecha
FROM MF.LLAMADA
WHERE duracion >= ALL (SELECT duracion FROM LLAMADA); --Tengo que poner >= para que coincida con el máximo

--MF 11 - Obtener el nombre de los abonados de la compañia 'Aotra' con el mismo tipo de tarifa que la del telefono "654123321"
SELECT C.nombre
FROM (MF.CLIENTE C INNER JOIN MF TELEFONO T ON C.dni=T.cliente) INNER JOIN MF.COMPAÑIA CO 
WHERE 

--MF 12 - Mostrar, utilizando para ello una subconsulta, el numero de telefono, la fecha de contrato y tipo de los abonados que han llamado a telefonos de clientes
--		  de fuera de la provincia de La Coruña durante el mes de octubre de 2006
SELECT DISTINCT T.numero, T.f_contrato, T.tipo
FROM MF.TELEFONO T INNER JOIN MF.LLAMADA LL ON T.numero=LL.tf_origen
WHERE TO_CHAR (LL.fecha_hora, 'mm/yy') = '10/06'
		AND LL.tf_destino not in (	SELECT T.numero
									FROM MF.TELEFONO T INNER JOIN MF.CLIENTE C ON C.dni = T.cliente
									WHERE provincia = 'La Coruña');

--MF 13 - Se necesita conocer el nombre de los clientes que tienen telefonos con tarifa "duo" pero no "autonomos". Utiliza subconsultas para obtener la solucion
SELECT nombre
FROM MF.CLIENTE
WHERE dni IN (	SELECT cliente
				FROM MF.TELEFONO
				WHERE TARIFA = 'duo')
AND dni NOT IN(	SELECT cliente
				FROM MF.TELEFONO
				WHERE TARIFA = 'autonomos');

--MF 14 - Obtener mediante subconsultas los nombres de clientes y números de teléfono de aquellos que hicieron llamadas a teléfonos de la compañía Petafón pero no Aotra
SELECT Cl.Nombre, Tf.Numero
FROM MF CLIENTE Cl INNER JOIN MF.TELEFONO TF ON Cl.dni=Tf.cliente
WHERE TF.NUMERO IN 		(	SELECT Ll.Tf_origen
							FROM (MF.LLAMADA Ll INNER JOIN MF.TELEFONO Tf ON Ll.Tf_destino = Tf.Numero)
									INNER JOIN MF.COMPAÑIA C ON C.Cif = Tf.Compañia
							WHERE C.Nombre = 'Petafon')
	AND TF.NUMERO NOT IN(	SELECT Ll.Tf_origen
							FROM (MF.LLAMADA Ll INNER JOIN MF.TELEFONO Tf ON Ll.Tf_Destino = Tf.Numero)
									INNER JOIN MF.COMPAÑIA C ON C.Cif = TF.Compañia
							WHERE C.Nombre = 'Aotra');

--MF 15 - Nombre de los clientes de la compañía Kietostar que hicieron las llamadas de mayor duración en septiembre de 2006
SELECT 	c.nombre
FROM ((	MF.CLIENTE C INNER JOIN MF.TELEFONO T ON C.dni = T.cliente)
		INNER JOIN MF.COMPAÑIA CO ON T.compañia = CO.cif)
		INNER JOIN MF.LLAMADA LL ON T.numero = LL.tf_origen
WHERE 	CO.nombre = 'Kietostar'
		AND TO_CHAR(LL.fecha_hora, 'mm/yy') = '09/06'
		AND LL.duracion >= ALL(	SELECT duracion
								FROM (MF.TELEFONO T INNER JOIN MF.COMPAÑIA CO ON T.compañia = CO.cif)
										INNER JOIN MF.LLAMADA LL ON T.numero=LL.tf_origen
								WHERE CO.nombre = 'Kietostar' AND TO_CHAR(LL.fecha_hora, 'mm/yy') = '09'06);

--MF 16 - Se necesita conocer el nombre de los clientes que tienen teléfonos con fecha de contratación anterior a alguno de los teléfonos de Ramón Martínez Sabina, excluido,
--		  claro, el propio Ramón Martínez Sabina
SELECT DISTINCT C.nombre
FROM MF.CLIENTE C INNER JOIN MF.TELEFONO T ON C.dni = T.cliente
WHERE C.nomre <> 'Ramón Martínez Sabina'
	AND T.f_contrado < ANY (	SELECT T.f_contrato
								FROM MF.CLIENTE C INNER JOIN MF.TELEFONO T ON C.dni=T.cliente
								WHERE C.nombre = 'Ramón Martínez Sabina');

--EI 18 - Listado de los despachos donde hay profesores que no son responsables de ninguna asignatura
SELECT DISTINCT P.despacho
FROM EI.PROFESOR P
WHERE NOT EXISTS(	SELECT *
					FROM EI.ASIGNATURA A
					WHERE P.nPr = A.prof);
--Abajo una forma incorrecta:
SELECT DISTINCT P.despacho
FROM EI.PROFESOR P
WHERE P.despacho NOT IN(	SELECT P.despacho
							FROM EI.PROFESOR P INNER JOIN EI.ASIGNATURA A ON P.nPr = A.prof);

--EI 19 - Listado de los alumnos que se han matriculado de alguna asignatura en el año 2000 o 2002, y de ninguna asignatura en el año 2001
SELECT A.nombre
FROM EI.ALUMNO A
WHERE EXISTS 	(	SELECT *
					FROM EI.MATRICULA M
					WHERE (año=2000 OR año=2002) AND A.nAl = M.alum)
AND NOT EXISTS 	(	SELECT *
					FROM EI.MATRICULA M
					WHERE año=2001 AND A.nAl = M.alum);

--EI 20 - Obtener el nombre de los profesores y los números de sus despachos de aquellos profesores que no comparten despacho
SELECT nombre, despacho
FROM EI.PROFESOR P1
WHERE despacho NOT IN(	SELECT despacho
						FROM EI.PROFESOR P2
						WHERE P2.nPr <> P1.nPr);
--Equivalente usando NOT EXISTS
SELECT nombre, despacho
FROM EI.PROFESOR P1
WHERE NOT EXISTS (	SELECT *
					FROM EI.PROFESOR P2
					WHERE P2.despacho = P1.despacho AND P2.nPr <> P1.nPr);

--MF 17 - Utilizando consultas correlacionadas, mostrar el nombre de los abonados que han llamado el dia '16/10/06'
SELECT C.nombre
FROM MF.CLIENTE C INNER JOIN MF.TELEFONO T ON C.dni=T.cliente
WHERE EXISTS (	SELECT *
				FROM MF.LLAMADA Ll
				WHERE TO_CHAR (Ll.fecha_hora, 'dd/mm/yy')='16/10/06' AND T.numero = Ll.tf_origen);

--MF 18 - Utilizando consultas correlacionadas, obtener el nombre de los abonados que han realizado llamadas de menos de 1 minuto y medio
SELECT C.nombre
FROM MF.CLIENTE C INNER JOIN MF.TELEFONO T ON C.dni=T.cliente
WHERE EXISTS(	SELECT *
				FROM MF.LLAMADA Ll
				WHERE T.numero = Ll.tf_origen AND duracion<90);

--MF 19 - Utilizando consultas correlacionadas, obtener el nombre de los abonados de la compañia 'KietoStar' que no hicieron ninguna llamada el mes de septiembre
SELECT T.numero, C.nombre
FROM (MF CLIENTE C INNER JOIN MF:TELEFONO T ON C.dni=T.cliente) INNER JOIN MF:COMPAÑIA CO ON CO.cif=T.compañia
WHERE CO.nombre = 'Kietostar' AND NOT EXISTS(	SELECT *
												FROM MF.LLAMADA Ll
												WHERE T.numero = Ll.tf_origen AND EXTRACT(month FROM Ll.fecha_hora) = '9');

--MF 20 - Utilizando consultas correlacionadas, mostrar todos los datos de los telefonos que hayan llamado al numero 654234234 pero no al 666789789
SELECT *
FROM MF.telefono T
WHERE EXISTS(	SELECT *
				FROM MF.LLAMADA Ll INNER JOIN MF.TELEFONO Tt ON Ll.tf_origen=Tt.numero
				WHERE Ll.tf_destino='654234234' AND Ll.tf_origen=t.numero)
AND NOT EXISTS(	SELECT *
				FROM MF.LLAMADA Ll INNER JOIN MF.TELEFONO Tt ON Ll.tf_origen=Tt.numero
				WHERE Ll.tf_destino='666789789'AND Ll.tf_origen=t.numero);

--MF 21 - Utilizando consultas correlacionadas, obtener le nombre y numero de telefono de los clientes de la compañia Kietostar que no han hecho llamdas a otros telefonos de la
--		  misma compañia
SELECT C.nombre, T.numero
FROM (MF.CLIENTE C INNER JOIN MF.TELEFONO T ON T.cliente=C.dni) INNER JOIN MF.COMPAÑIA CIA ON CIA.cif = T.compañia
WHERE CIA.nombre = 'Kietostar' AND NOT EXISTS (	SELECT *
												FROM (MF.LLAMADA L INNER JOIN MF.TELEFONO Td ON Td.numero = L.tf_destino) INNER JOIN MF.COMPAÑIA COM ON COM.cif = Td.compañia
												WHERE C.nombre = 'Kietostar' AND T.numero = L.tf_origen);

--EI 21 - Obtener los nombres de todos los profesores junto con las asignaturas de las que son responsables
SELECT P.nombre AS NomProf, A.nombre AS NomAsig
FROM EI.PROFESOR P RIGHT JOIN EI.ASIGNATURA A ON P.nPr = A.prof;

--EI 22 - Se desea saber cuántos despachos ocupan los profesores de la escuela
SELECT COUNT (P.despacho)		--IMPORTANTE PARÉNTESIS
FROM EI.PROFESOR P;

--EI 23 - Obtener el número de matriculados, la nota máxima, la mínima y la nota media de la asignatura 'Bases de Datos I' en la convocatoria de septiembre de 2002
SELECT COUNT (*), MAX (m.sep) AS Maxima, MIN(m.sep) AS Minima, AVG(m.sep) AS Media
FROM EI.MATRICULA M INNER JOIN EI.ASIGNATURA A USING (idAsig)
WHERE M.año='2002' AND A.nombre='Bases de Datos I';

--EI 24 - Obtener, mediante una consulta correlacionada, los nombres de las asignaturas que tienen recomendadas 2 o más asignaturas
SELECT A.nombre
FROM EI.ASIGNATURA A
WHERE (	SELECT COUNT(*)
		FROM EI.RECOMENDACIONES R
		WHERE A.idAsig = R.idAsig) >= 2;

--EI 25 - Obtener, mediante una consulta correlacionada, los nombres de los profesores que tienen más antigüedad que, al menos, otros cinco profesores
SELECT P1.nombre
FROM EI.PROFESOR P1
WHERE (	SELECT COUNT(*)
		FROM EI.PROFESOR P2
		WHERE P1.ant > P2.ant) >= 5;

--EI 26 - Para cada asignatura y año académico, mostrar el nombre de la asignatura, el año, el número de alumnos que se han presentado y la nota media obtenida en la convocatoria
--		  de febrero_junio
SELECT A.nombre AS Nombre, M.año AS Anno, COUNT (M.alum) AS NumAlumnos, AVG (M.feb_jun) AS MediaFebJun
FROM EI.ASIGNATURA A INNER JOIN EI.MATRICULA M ON (idAsig)
GROUP BY A.nombre, M.año;

--EI 27 - Obtener un listado con el nombre del alumno, el nombre de la asignatura y el número de veces que se ha matriculado en esa asignatura, pero sólo cuando se haya
--		  matriculado 3 o más años
SELECT ALU.nombre AS NomAlumno, ASIG.nombre AS NomAsignatura, COUNT(M.alum) AS NumPresentaciones
FROM (EI.ALUMNO ALU INNER JOIN EI.MATRICULA M ON ALU.nAl = M.alum) INNER JOIN EI.ASIGNATURA ASIG USING (idAsig)
GROUP BY ALU.nombre, ASIG.nombre
HAVING COUNT(M.alum) >=3;

--EI 28 - Nombre de los alumnos que hayan sacado más de un 5 de nota media en junio del 2002
SELECT ALU.nombre AS Nombre
FROM EI.ALUMNO ALU INNER JOIN EI.MATRICULA M ON (ALU.nAl = M.alum)
WHERE M.año = '2002'
GROUP BY ALU.nombre
HAVING AVG(M.feb_jun)>5;

--EI 29 - Nombre de las asignaturas y número de alumnos matriculados de las asignaturas donde se hayan matriculado más alumnos en el año 2002
SELECT ASI.nombre, COUNT(M.alum)
FROM EI.ASIGNATURA ASI INNER JOIN EI.MATRICULA M USING (idAsig)
GROUP BY ASI.nombre
HAVING COUNT(*) >= ALL (SELECT COUNT(*)
                        FROM EI.MATRICULA 
                        WHERE año=2002
                        GROUP BY idAsig);

--EI 30 - Obtener el numero total de alumnos que han suspendido en cada asignatura en junio de 2002, pero solo de aquellas asignaturas en las que se hayan matriculado
--		  más de 50 alumnos
--Mio, pero no se si está bien
SELECT ASIG.nombre AS Asignatura, COUNT(M.alum) AS AlumSuspensos
FROM EI.ASIGNATURA ASIG INNER JOIN EI.MATRICULA M USING (idAsig)
WHERE M.año='2002' AND M.feb_jun<5
GROUP BY asig.nombre
HAVING COUNT (M.alum)>=1;
--Borja------------
SELECT count(*)
FROM EI.MATRICULA
WHERE feb_jun < 5 AND año=2002 AND idAsig IN(   SELECT idAsig
                                                FROM EI.MATRICULA
                                                GROUP BY idAsig
                                                HAVING count(*) > 1)
GROUP BY idAsig;

--MF 22 - Mostrar la compañia con la que se realizaron más llamadas durante el dia 16/10/06


--MF 23 - Obtener los numeros de telefono y los nombres de los abonados que han llamado a todos los numeros a los que se llamó desde el 654345345 en octubre de 2006


--MF 24 - Mostrar el nombre de cada cliente junto con el coste total de las llamadas que realiza con cada compañia. El resultado debe mostrarse ordenado
--		  descendientemente por cliente y ascendentemente por compañia


--MF 25 - Para cada cliente residente en la provincia de 'La Coruña', mostrar la duracion de todas las llamadas realizadas a clientes residentes en 'Jaén'


--MF 26 - Mostrar los nombres de todos los clientes que hayan realizado más de 5 llamadas


--MF 27 - Mostrar el nombre de aquellos clientes que hayan contratado con cualquier compañía, de media, una tarifa superior a la tarifa media total


--MF 28 - Mostrar los nombres de los clientes que hayan realizado llamadas a telefonos de la compañia Kietostar por un coste menor de 100€

