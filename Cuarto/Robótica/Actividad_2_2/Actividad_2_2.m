%===========POSICIONES Y ÁNGULOS===========
%--Posicion Global [X Y Z]
posicion_global = [20 10 0];

%--Ángulos de Giro (Radianes)
alfa = 0;
beta = 0;
gamma = 0;


%===========BLOQUES===========
%--Matriz Construccion
Matriz_construccion_global = Desplazamiento(posicion_global(1), posicion_global(2), posicion_global(3));

%--Calculos Bloque Rojo
Matriz_rojo_en_Construccion = Desplazamiento (-1.5, 0, 0);
Matriz_rojo_en_Global = Matriz_rojo_en_Construccion * Matriz_construccion_global;

%--Calculos Bloque Azul
Matriz_azul_en_Construccion = Desplazamiento (1.5, 0, 0);
Matriz_azul_en_Global = Matriz_azul_en_Construccion * Matriz_construccion_global;

%--Calculos Bloque Verde
Matriz_verde_en_Construccion = Desplazamiento (0, 0, 6);
Matriz_verde_en_Global = Matriz_verde_en_Construccion * Matriz_construccion_global;


%===========ROBOT===========
%--Valores Robot
codo = 1;
avance = 1;
simetrico = 1;

%--Agarre
matriz_agarre = Desplazamiento(0, -0.8, 4) * Rotacionx(-pi/2) * Rotacionz(-pi/2);
matriz_pinza = Matriz_verde_en_Global * matriz_agarre * Desplazamiento(0,0,-5);

[q1, q2, q3, q4, q5, q6] = inv_kinema_ur3_new(matriz_pinza,codo,avance,simetrico); 

matriz = funcion_pinta_UR3_new([q1 q2 q3 q4 q5 q6], matriz_pinza);

%===========DIBUJAR===========
%--Dibujar bloques
pinta_bloque(Matriz_rojo_en_Global, 'r');
pinta_bloque(Matriz_azul_en_Global, 'b');
pinta_bloque(Matriz_verde_en_Global, 'g');



