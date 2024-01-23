%----------- Configuración Pick -----------------
posicion = [30 0 0];
alfa = 0; beta = 0; gamma = 0;
Matriz_Pick_Global = Desplazamiento(posicion(1), posicion(2), posicion(3)) * Rotacionz(alfa) * Rotaciony(beta) * Rotacionz(gamma);
pinta_bloque(Matriz_Pick_Global,'b');

%----------- Configuración Place -----------------
posicion = [20 10 0];
alfa = 0; beta = 0; gamma = 0;
Matriz_Place_Global = Desplazamiento(posicion(1), posicion(2), posicion(3)) * Rotacionz(alfa) * Rotaciony(beta) * Rotacionz(gamma);
pinta_bloque(Matriz_Place_Global,'r');

%----------Definicion de agarre y Conf. Solucion Prob. Cinematico Directo
agarre2 = Desplazamiento(0, 0, 4) * Rotacionx(pi);
agarre3 = Desplazamiento(0, -0.8, 4) * Rotacionx(-pi/2) * Rotacionz(pi/2);

codo = 1; avance = 1; simetrico = 0;


%--------Definicion conf pinza Pick and Place
Matriz_Pick_Pinza_Global = Matriz_Pick_Global * agarre3;
Matriz_Place_Pinza_Global = Matriz_Place_Global * agarre3;

%--------------Definicion de los movimientos

%------------Configuración de agarre claculada PICK
%MOVIMIENTO DE APROXIMACION
[q1 q2 q3 q4 q5 q6] = inv_kinema_ur3_new(Matriz_Pick_Pinza_Global * Desplazamiento(0, 0, -5), codo, avance, simetrico); 
funcion_pinta_UR3_new([q1 q2 q3 q4 q5 q6], Matriz_Pick_Pinza_Global * Desplazamiento(0, 0, -5) );

pause
cla
pinta_pieza

%MOVIMIENTO DE AGARRE
[q1 q2 q3 q4 q5 q6] = inv_kinema_ur3_new(Matriz_Pick_Pinza_Global,codo,avance,simetrico); 
funcion_pinta_UR3_new([q1 q2 q3 q4 q5 q6],Matriz_Pick_Pinza_Global);

pause
cla
pinta_pieza


%MOVIMIENTO DE DESPEGUE
[q1 q2 q3 q4 q5 q6] = inv_kinema_ur3_new(Desplazamiento(0,0,5) * Matriz_Pick_Pinza_Global, codo, avance, simetrico); 
funcion_pinta_UR3_new([q1 q2 q3 q4 q5 q6], Desplazamiento(0, 0, 5) * Matriz_Pick_Pinza_Global);

pause
cla
pinta_pieza


%------------Configuración de agarre calculada PLACE------------
%MOVIMIENTO DE APROXIMACION
[q1 q2 q3 q4 q5 q6]=inv_kinema_ur3_new(Desplazamiento(0,0,5) * Matriz_Place_Pinza_Global,codo,avance,simetrico); 
funcion_pinta_UR3_new([q1 q2 q3 q4 q5 q6], Desplazamiento(0,0,5) * Matriz_Place_Pinza_Global);

pause
cla
pinta_pieza

%MOVIMIENTO
[q1 q2 q3 q4 q5 q6]=inv_kinema_ur3_new(Matriz_Place_Pinza_Global,codo,avance,simetrico); 
funcion_pinta_UR3_new([q1 q2 q3 q4 q5 q6],Matriz_Place_Pinza_Global);

pause
cla
pinta_pieza

%MOVIMIENTO DE DESPEGUE
[q1 q2 q3 q4 q5 q6]=inv_kinema_ur3_new(Matriz_Place_Pinza_Global * Desplazamiento (0, 0, -5), codo, avance, simetrico); 
funcion_pinta_UR3_new([q1 q2 q3 q4 q5 q6], Matriz_Place_Pinza_Global * Desplazamiento (0, 0, -5));