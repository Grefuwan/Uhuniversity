%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simulación del movimiento de un robot móvil
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all
clc

global l
global radio_rueda
global camino
global pose
global punto

%--Cargamos el camino
camino = load('camino.dat');

%--Inicialización valores
j = 1;
l = 3.5; %-Distancia entre rudas delanteras y traseras, tambien definido en modelo
radio_rueda = 10;

%--Condiciones iniciales 
pose0 = [0; 0; 0];
t0 = 0;

%--Final de la simulación
tf = 100;

%--Paso de integracion
h = 0.1;
%--Vector tiempo
t = 0:h:tf;
%--Indice de la matriz
k = 0;

%--Inicialización valores iniciales
pose(:,k+1) = pose0;

t(k+1) = t0;

%--Puntos a alcanzar
punto_1 = [65 53];
punto_2 = [63 75];

while (t0 + h*k) < tf
    
    punto = punto_1;
    
    %--Como no van a ser iguales iguales, cambiar la condicion por comparar
    %-La distancia entre el punto al que quiero ir y en el que estoy, si es
    % menor que 0,1, cambia al otro punto de destino
    if (pose(1) == punto_1(1) && pose(2) == punto_1(2)) %En ejecución, pose crece
        punto = punto_2;
    end

    k = k + 1;
    
    Delta = ((pose(1, k) - punto(1)) * sin(pose(3, k))) - ((pose(2, k) - punto(2)) * cos(pose(3, k)));
    Lh = sqrt((pose(1, k) - punto(1)) ^ 2+(pose(2, k) - punto(2))^2);

    %--Valores de los parámetros de control
    v = Lh;
    if v > 2
        v = 2;
    end
    %w = 0.1;
    radio_curvatura = 1;
    R = 1;
    rho = 2 * Delta/Lh^2;
    phi = atan(rho * l);

    velocidad = 2;

    w = v * rho;

    velocidad_derecha = (v + w*l)/radio_rueda;
    velocidad_izquierda = (v - w*l)/radio_rueda;

    conduccion = [velocidad_derecha velocidad_izquierda];

    %--Método de integración ruge-kuta
    pose(:,k+1) = kuta_diferencial(t(k), pose(:,k), h, conduccion);

end