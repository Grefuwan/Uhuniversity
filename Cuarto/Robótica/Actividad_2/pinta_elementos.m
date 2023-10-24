
%configuración de la pieza
posicion = [20 -10 0];
alfa=0; beta=pi/4; gamma=0;
  
matriz_pieza = Desplazamiento(posicion(1), posicion(2), posicion(3)) * Rotacionz(alfa) * Rotaciony(beta) * Rotacionx(gamma);


%pinta_pieza_delgada(matriz_pieza)
pinta_bloque(matriz_pieza,'b')



matriz_agarre = Desplazamiento(0,0,4) * Rotaciony(pi) * Rotacionz(-pi/2)
matriz_pinza = matriz_pieza * matriz_agarre
q = [0 -1.5700 -1.5700 -1.5700 1.5700 0];
matriz = funcion_pinta_UR3_new(q, matriz_pinza)
 

