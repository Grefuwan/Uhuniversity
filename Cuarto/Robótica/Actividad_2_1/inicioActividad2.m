% 17/10/2023 (Inicio Actividad 2)
Matriz_4 = Desplazamiento(7,8,9) * Rotacionz(pi/4) * Rotaciony(pi/2) * Rotacionz(pi/4)
pinta_bloque(Matriz_4,'g')

Punto_Local = [1.5 1.5 6 1]'
P_Global = Matriz_4*Punto_Local

plot3(P_Global(1), P_Global(2), P_Global(3), "*k");