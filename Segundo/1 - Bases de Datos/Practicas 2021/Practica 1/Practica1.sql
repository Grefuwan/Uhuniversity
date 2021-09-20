--------LDD--------
--1.Crear las siguientes tablas.
--Tabla Compañia
CREATE TABLE COMPANIA(
	cif char(9),
	nombre varchar(20) NOT NULL,
	web varchar(30),
	CONSTRAINT compaClave PRIMARY KEY (cif),
	CONSTRAINT compaUnica UNIQUE (nombre));

--Tabla Tarifa
CREATE TABLE TARIFA(
	tarifa char(10),
	compania char(9),
	descripcion varchar(50),
	coste number (3,2) NOT NULL,
	CONSTRAINT tarifaClave PRIMARY KEY (tarifa, compania),
	CONSTRAINT tarifaAjena FOREIGN KEY (compania) REFERENCES COMPANIA (cif) ON DELETE CASCADE,
	--La linea superior indica que si borro una compañia, borro todas sus tarifas
	CONSTRAINT tarifaCoste CHECK (coste<=1.50 AND coste>=0.05));
	
--Tabla Cliente
CREATE TABLE CLIENTE(
	dni char(9),
	nombre varchar(50),
	f_nac date,
	direccion varchar(100),
	cp char(6),
	ciudad varchar(50),
	provincia varchar(50),
	CONSTRAINT clienteClave PRIMARY KEY (dni)
	);
	
--Tabla Telefono
CREATE TABLE TELEFONO(
	numero char(9),
	f_contrato date,
	tipo char(1),
	puntos number(6,0),
	compañia char(9),
	tarifa char(10),
	cliente char(9),
	CONSTRAINT telefonoClave PRIMARY KEY (numero),
	CONSTRAINT TelTarAjena FOREIGN KEY (tarifa, compañia) REFERENCES TARIFA (tarifa, compañia),
	CONSTRAINT TelComAjena FOREIGN KEY (compañia) REFERENCES COMPANIA (cif),
	CONSTRAINT TelCliAjena FOREIGN KEY (cliente) REFERENCES CLIENTE (dni),
	CONSTRAINT telTipo CHECK tipo IN ('T', 'C')
);

--Tabla Llamada
CREATE TABLE LLAMADA(
	tf_origen char(9),
	tf_destino char(9),
	fecha_hora timestamp,
	duracion number(5,0),
	CONSTRAINT llamadaClave PRIMARY KEY (tf_origen, fecha_hora),
	CONSTRAINT LlamTelOrigAjena FOREIGN KEY (tf_origen) REFERENCES TELEFONO (numero),
	CONSTRAINT LlamTelDestAjena FOREIGN KEY (tf_destino) REFERENCES TELEFONO (numero),
	CONSTRAINT LlamSimult CHECK UNIQUE (tf_destino, fecha_hora)	
);




--------ALTER TABLE--------
--2.
---No puede haber dos compañias con el mismo nombre
ALTER TABLE COMPAÑIA
	ADD CONSTRAINT NomCompUnica CHECK UNIQUE(nombre);

---Un telefono no puede realizar una llamada a él mismo
ALTER TABLE LLAMADA
	ADD CONSTRAINT tlfDistinto CHECK (tf_origen <> tf_destino)
	
---El coste de las tarifas no puede ser superior a 1,50 e inferior a 0,05
ALTER TABLE TARIFA
	ADD CONSTRAINT TopePrecio CHECK coste<1.50 AND coste>0.05;

---Los atributos nombre de la tabla Compañia, nombre de la relacion Cliente, coste de la relacion Tarifa, compañia y Tarifa de la tabla
---telefono y duracion de la tabla Llamada deben ser obligatorios.
ALTER TABLE T1
	MODIFY atributoX NOT NULL
	
--Al borrar una compañia se deben borrar todas las tarifas de dicha compañia.
ALTER TABLE TARIFA
	DROP CONSTRAINT tarifaAjena
ALTER TABLE TARIFA
	ADD CONSTRAINT tarifaAjena FOREIGN KEY (compañia) REFERENCES COMPAÑIA (cif) ON DELETE CASCADE;
	
--------LMD (Insercion, modificacion y eliminacion de datos)--------
--3.Mediante la sentencia INSERT INTO, introducir los siguientes datos en las tablas
INSERT INTO COMPAÑIA (cif, nombre, web)
VALUES ('A00000001', 'Kietostar', 'kietostar.com');
INSERT INTO COMPAÑIA (cif, nombre, web)
VALUES ('B00000002', 'Aotra', 'aotra.com');

INSERT INTO TARIFA(tarifa, compañia, descripcion, coste)
VALUES ('joven', 'A00000001', 'menores de 25 años', 0.25);
INSERT INTO TARIFA(tarifa, compañia, descripcion, coste)
VALUES ('duo', 'A00000001', 'la pareja tambien está en la compañia', 0.20);
INSERT INTO TARIFA(tarifa, compañia, descripcion, coste)
VALUES ('familiar', 'A00000001', '4 miembros de la familia en la compañia', 0.15);
INSERT INTO TARIFA(tarifa, compañia, descripcion, coste)
VALUES ('autonomos', 'B00000002', 'trabajador autonomo', 0.12);
INSERT INTO TARIFA(tarifa, compañia, descripcion, coste)
VALUES ('duo', 'B00000002', 'la pareja tambien está en la compañía', 0.15);

--4.

--5.Borrar la compañia cuyo CIF es B00000002. Comprobar si se han borrado todas sus tarifas (Deberian, por el DELETE CASCADE)
DELETE FROM COMPAÑIA
WHERE cif='B00000002';

