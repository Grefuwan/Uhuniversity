--MF.Compañia
CIF       NOMBRE               WEB                           
--------- -------------------- ------------------------------
A00000001 Kietostar            http://wwww.kietostar.com     
B00000002 Aotra                http://wwww.aotra.com         
C00000003 Petafón              http://wwww.petafon.com     


--MF.Cliente
DNI       NOMBRE                           F_NAC     DIRECCION                                CP     CIUDAD                      PROVINCIA
--------- -------------------------------- --------  ---------------------------------------  ------ --------------------------  --------------
35000001P Ramón Martínez Sabina            12/02/69  C/ Melancolía nº 7                       23400  Úbeda                       Jaén
42000002C José García Márquez              19/04/87  Avda. de Macondo nº 82                   11900  San Román                   Cádiz
59000003T Ricardo Reyes Neruda             10/01/73  Carretera de Isla Negra Km. 20           15704  Santiago de Compostela      La Coruña
17000004W Antonio Hierro Santander         15/03/85  Avda. Ciudad de Barcelona                28015  Madrid                      Madrid
56000002M Juan Jiménez Platero             23/12/81  C/ Ribera nº 2                           21800  Moguer                      Huelva
67000002A María Machado Ruiz               26/07/75  C/ Campos de Castilla nº 12              41004  Sevilla                     Sevilla
12000002Q Jesús Ríos Lorca                 19/09/90  Camino de Bernarda Alba nº 36            18340  Fuente Vaqueros             Granada
89000002Z Rita Martínez de Castro          15/07/85  C/ Sar nº 84                             15900  Padrón                      La Coruña


--MF.Llamada

TF_ORIGEN TF_DESTIN FECHA_HORA                    DURACION
--------- --------- --------------------------- ----------
654123321 654345345 26/09/06 23:05:55,000000000        921
654123321 654345345 16/10/06 18:45:35,000000000        785
654123321 654345345 16/10/06 19:07:10,000000000         38
654123321 654345345 18/10/06 09:35:50,000000000       1053
654123321 654345345 21/10/06 21:05:13,000000000        257
666010101 666456456 27/10/06 11:11:33,000000000        435
666010101 654234234 01/11/06 10:35:00,000000000        124
666010101 666789789 05/09/06 17:09:01,000000000        210
654789789 654012012 01/10/06 13:55:30,000000000         75
654789789 666456456 05/10/06 17:05:03,000000000        430
654789789 678111222 08/10/06 10:55:15,000000000       1345

TF_ORIGEN TF_DESTIN FECHA_HORA                    DURACION
--------- --------- --------------------------- ----------
678111222 654789789 07/10/06 19:25:51,000000000        553
678111222 654234234 03/11/06 17:45:31,000000000        321
678111222 678234234 12/09/06 11:52:19,000000000        634
678111222 678234234 23/09/06 19:17:44,000000000        101
666789789 666010101 11/09/06 10:19:03,000000000         45
666789789 666456456 15/09/06 14:12:44,000000000        409
666789789 666456456 15/09/06 18:13:24,000000000        105
654012012 678234234 13/09/06 10:32:07,000000000        312
654012012 678111222 01/09/06 21:08:59,000000000         93
654012012 666010101 21/09/06 11:12:13,000000000        501
678234234 666010101 30/09/06 08:49:55,000000000        413

TF_ORIGEN TF_DESTIN FECHA_HORA                    DURACION
--------- --------- --------------------------- ----------
678234234 654123321 01/10/06 13:12:11,000000000       2045
678234234 654789789 01/10/06 19:01:07,000000000        703
678234234 666789789 12/10/06 10:21:02,000000000        827
654345345 654012012 01/11/06 12:01:02,000000000        311
654345345 654012012 03/11/06 10:43:57,000000000        207
654345345 654234234 03/11/06 17:31:09,000000000        421
654345345 654123321 16/10/06 19:07:10,000000000         38
654345345 654123321 21/10/06 21:05:13,000000000        257


--MF.Tarifa
TARIFA     COMPAÑIA  DESCRIPCION                                             COSTE
---------- --------- -------------------------------------------------- ----------
joven      A00000001 menores de 25 años                                 ,25       
dúo        A00000001 la pareja también está en la compañía              ,2        
familiar   A00000001 4 miembros de la familia en la compañía            ,15       
autónomos  B00000002 trabajador autónomo                                ,18       
dúo        B00000002 la pareja también está en la compañía              ,15       
autónomos  C00000003 trabajador autónomo                                ,23       
empresa    C00000003 todos los empleados están en la compañía           ,19      


--MF.Telefono
NUMERO    F_CONTRA T     PUNTOS COMPAÑIA  TARIFA     CLIENTE  
--------- -------- - ---------- --------- ---------- ---------
654123321 14/09/03 C      12750 A00000001 dúo        35000001P
666010101 09/10/05 T       1040 C00000003 empresa    35000001P
654789789 30/05/06 C      24590 A00000001 familiar   42000002C
678111222 02/02/02 T       1010 B00000002 dúo        59000003T
654234234 31/10/06 T        250 A00000001 joven      17000004W
666789789 20/05/99 C      45250 C00000003 autónomos  67000002A
654012012 10/03/05 T       1500 A00000001 joven      12000002Q
678234234 30/08/06 C      15700 B00000002 autónomos  89000002Z
654345345 10/09/06 C        170 A00000001 dúo        89000002Z
666456456 19/07/98 C      56280 C00000003 empresa    56000002M