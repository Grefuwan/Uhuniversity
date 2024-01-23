%Configuración de la pieza
%---Posición pinza    
posicion = [20 -10 0]; %Con [20 -50] estará fuera del alcance del robot

%---Angulos de giro
alfa=0; beta=pi/4; gamma=0;

%---Valores robot
codo = 1;
avance = 1;
simetrico = 1;
%----------------------------

matriz_pieza = Desplazamiento(posicion(1), posicion(2), posicion(3)) * Rotacionz(alfa) * Rotaciony(beta) * Rotacionx(gamma);


%pinta_pieza_delgada(matriz_pieza)
pinta_bloque(matriz_pieza,'b')




matriz_agarre = Desplazamiento(0,0,4) * Rotaciony(pi) * Rotacionz(-pi/2)
matriz_pinza = matriz_pieza * matriz_agarre
%q = [0 -1.5700 -1.5700 -1.5700 1.5700 0];

[q1 q2 q3 q4 q5 q6] = inv_kinema_ur3_new(matriz_pinza,codo,avance,simetrico); 


matriz = funcion_pinta_UR3_new([q1 q2 q3 q4 q5 q6], matriz_pinza)
 

