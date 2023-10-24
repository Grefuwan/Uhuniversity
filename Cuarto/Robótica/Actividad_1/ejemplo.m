%Primer bloque
Matriz_1 = Desplazamiento(5,5,5);
pinta_bloque(Matriz_1, 'r');    %Bloque rojo

%Segundo bloque
Matriz_2 = Desplazamiento(5,5,5)*Rotacionz(pi/4);
pinta_bloque(Matriz_2, 'b');    %Bloque azul

%Tercer bloque
Matriz_3 = Desplazamiento(5,5,5)*Rotacionz(pi/4)*Rotacionx(pi/4);
pinta_bloque(Matriz_3, 'g');    %Bloque verde