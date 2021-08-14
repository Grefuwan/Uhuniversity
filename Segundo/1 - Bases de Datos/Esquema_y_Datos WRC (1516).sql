drop table PARTICIPA CASCADE CONSTRAINT;
drop table CORRE CASCADE CONSTRAINT;
drop table PILOTO CASCADE CONSTRAINT;
drop table TRAMO CASCADE CONSTRAINT;
drop table RALLY CASCADE CONSTRAINT;
drop table COCHE CASCADE CONSTRAINT;


create table RALLY (
codRally char(4),
nombre varchar(50) not null,
pais varchar(20) not null,
fecha date not null,
CONSTRAINT rallyClave PRIMARY KEY (codRally),
CONSTRAINT nombreUnico UNIQUE (nombre),
CONSTRAINT fechaValida CHECK (fecha >= to_date('01/01/2009','dd/mm/yyyy') AND 
fecha <= to_date('31/12/2009','dd/mm/yyyy')) );


create table TRAMO (
codRally char(4),
numeroTramo integer,
totalKms numeric (5,2) not null,
dificultad char(1) DEFAULT 'B',
CONSTRAINT tramosClave PRIMARY KEY (codRally,numeroTramo),
CONSTRAINT valorDificultad CHECK (dificultad IN ('A','B','C')),
CONSTRAINT tramoAjena FOREIGN KEY (codRally) REFERENCES Rally (codRally) on 
delete cascade,
CONSTRAINT veinteKms CHECK (totalKms>=20));



create table COCHE (
codCoche char(4),
marca char(10),
modelo char(20),
cilindrada integer,
CONSTRAINT cochesClave PRIMARY KEY (codCoche),
CONSTRAINT valoresCilindrada CHECK (cilindrada >=2000 AND cilindrada <=3000));

create table PILOTO (
codPiloto char (4),
nombreP char(50) not null,
grupoS char(2),
rh char(1),
nombreCop char(50) not null,
coche char(4) not null,
puntos integer default 0,
CONSTRAINT pilotosClave PRIMARY KEY (codPiloto),
CONSTRAINT pilotosAjena FOREIGN KEY (coche) REFERENCES Coche (codCoche),
CONSTRAINT valorGrupoS CHECK (grupoS IN ('A','B','0','AB')),
CONSTRAINT valorRh CHECK (rh IN ('+','-')),
CONSTRAINT pilotoUnico UNIQUE (nombreP),
CONSTRAINT copilotoUnico UNIQUE (nombreCop),
CONSTRAINT puntosPositivo CHECK (puntos>=0),
CONSTRAINT nombresDistintos CHECK (nombreP <> nombreCop),
CONSTRAINT cocheUnico UNIQUE (coche));

create table PARTICIPA(
codRally char(4),
codPiloto char(4),
penalizacion integer default 0 not null,
tiempoRally integer default 0 not null,
CONSTRAINT participanClave PRIMARY KEY (codRally,codPiloto),
CONSTRAINT participanAjena1 FOREIGN KEY (codRally) REFERENCES Rally(codRally),
CONSTRAINT participanAjena2 FOREIGN KEY (codPiloto) REFERENCES 
Piloto(codPiloto),
CONSTRAINT tiempoRallyPositivo CHECK (tiempoRally>=0),
CONSTRAINT penalizacionPositivo CHECK (penalizacion>=0)
);

create table CORRE (
codPiloto char(4),
codRally char(4),
numeroTramo integer,
tiempo integer not null,
CONSTRAINT correnClave PRIMARY KEY (codPiloto,codRally,numeroTramo),
CONSTRAINT correnAjena1 FOREIGN KEY (codRally,numeroTramo) REFERENCES Tramo 
(codRally,numeroTramo),
CONSTRAINT correnAjena2 FOREIGN KEY (codPiloto) REFERENCES Piloto (codPiloto),
CONSTRAINT tiempoPositivo CHECK (tiempo>=0));


commit;

insert into RALLY values ('R001','Rally de Cataluña','España','05/09/2009');
insert into RALLY values ('R002','Rally 1000 Lagos','Finlandia','03/08/2009');
insert into RALLY values ('R003','Rally San Remo','Italia','18/05/2009');
insert into RALLY values ('R004','Rally RAC de Gran Bretaña','Reino Unido','30/11/2009');
insert into RALLY values ('R005','Rally de Montecarlo','Monaco','19/01/2009');
insert into RALLY values ('R006','Rally de Alemania','Alemania','17/08/2009');

insert into TRAMO values ('R001',1,50,'A');
insert into TRAMO values ('R001',2,40,'B');
insert into TRAMO values ('R001',3,30,'A');

insert into TRAMO values ('R002',1,50,'A');
insert into TRAMO values ('R002',2,40,'B');


insert into TRAMO values ('R003',1,50,'A');
insert into TRAMO values ('R003',2,40,'B');
insert into TRAMO values ('R003',3,40,'B');

insert into TRAMO values ('R004',1,30,'A');
insert into TRAMO values ('R004',2,20,'C');
insert into TRAMO values ('R004',3,50,'A');

insert into TRAMO values ('R005',1,40,'B');
insert into TRAMO values ('R005',2,50,'A');
insert into TRAMO values ('R005',3,40,'B');

insert into TRAMO values ('R006',1,30,'A');
insert into TRAMO values ('R006',2,20,'C');

insert into COCHE values ('C001','Citroen','XSara WRC',2000);
insert into COCHE values ('C002','Subaru','Impreza WRC2004',2000);
insert into COCHE values ('C003','Ford','Focus WRC',2500);
insert into COCHE values ('C004','Peugeot','307 WRC',3000);
insert into COCHE values ('C005','Citroen','XSara WRC',3000);

insert into PILOTO values ('P001','Dani Sordo','0','+','Marc Marti','C001',28);
insert into PILOTO values ('P002','Sebastien Loeb','A','+','Daniel Elena','C005',62);
insert into PILOTO values ('P003','Petter Solberg','B','-','Phil Mills','C002',26);
insert into PILOTO values ('P004','Mikko Hirvonen','AB','+','Jarmo Lehtinen','C003',57);
insert into PILOTO values ('P005','Marcus Gronholm','AB','-','Timo Rautiainen','C004',75);

INSERT INTO CORRE (codRally, codPiloto,  numeroTramo, tiempo) VALUES 
('R001','P001',1,400);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R001','P002',1,1000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R001','P003',1,1200);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R001','P001',2,1400);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R001','P002',2,10000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R001','P003',2,11200);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R001','P001',3,10000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R001','P002',3,145);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R001','P003',3,1200); 



INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R002','P004',1,10388);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R002','P005',1,23000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R002','P004',2,12000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R002','P005',2,34000);


INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R003','P001',1,20000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R003','P002',1,30000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R003','P001',2,40000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R003','P002',2,10000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R003','P002',3,10000);

INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R004','P001',1,23000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R004','P005',1,34800);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R004','P005',2,36000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R004','P005',3,39000);

INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P001',1,23400);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P002',1,60000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P003',1,37000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P005',1,12000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P001',2,33000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P002',2,34000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P005',2,12000);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P002',3,3400);
INSERT INTO CORRE (codRally, codPiloto,  numeroTramo,tiempo) VALUES 
('R005','P003',3,4700);



INSERT INTO PARTICIPA VALUES ('R001','P001',120,11800);
INSERT INTO PARTICIPA VALUES ('R001','P002',60,11145);
INSERT INTO PARTICIPA VALUES ('R001','P003',0,13600);

INSERT INTO PARTICIPA VALUES ('R002','P004',0,22388);
INSERT INTO PARTICIPA VALUES ('R002','P005',0,57000);

INSERT INTO PARTICIPA VALUES ('R003','P001',30,60000);
INSERT INTO PARTICIPA VALUES ('R003','P002',0,50000);

INSERT INTO PARTICIPA VALUES ('R004','P001',0,23000);
INSERT INTO PARTICIPA VALUES ('R004','P005',0,109800);

INSERT INTO PARTICIPA VALUES ('R005','P001',250,56400);
INSERT INTO PARTICIPA VALUES ('R005','P002',0,97400);
INSERT INTO PARTICIPA VALUES ('R005','P003',0,41700);
INSERT INTO PARTICIPA VALUES ('R005','P005',0,24000);
 

commit;
