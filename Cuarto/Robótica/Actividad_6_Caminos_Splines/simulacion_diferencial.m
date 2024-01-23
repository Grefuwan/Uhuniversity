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
%camino = load('camino.dat');

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


while (t0 + h*k) < tf
    
    k = k + 1;
   
    orden_minimo = minima_distancia(camino, [pose(1,k), pose(2,k)]);

    look_ahead = 15; %--Esto permite que el robot siga el punto de forma más precisa. Cuanto mayor el número, mayor precisión

    if (orden_minimo + look_ahead > length(camino))
        break
    end
    % Hacerlo que recorra sin parar con módulo (PCD)

    punto = [ camino(orden_minimo + look_ahead, 1) camino(orden_minimo + look_ahead, 2) ];
    Delta = ((pose(1, k) - punto(1)) * sin(pose(3, k))) - ((pose(2, k) - punto(2)) * cos(pose(3, k)));
    Lh = sqrt((pose(1, k) - punto(1)) ^ 2+(pose(2, k) - punto(2))^2);

    distancia_alfinal = sqrt((pose(1,k) - camino(end, 1))^2 + (pose(2,k) - camino(end,2))^2);

    %--Valores de los parámetros de control
    radio_curvatura = 1;
    R = 1;
    rho = 2 * Delta/Lh^2;
    phi = atan(rho * l);

    Kp = 1;
    
    v = Kp * distancia_alfinal; %Velocidad. Cuanto menor sea, más preciso sigue el * moviéndose

    w = v * rho;

    velocidad_derecha = (v + w*l)/radio_rueda;
    velocidad_izquierda = (v - w*l)/radio_rueda;

    conduccion = [velocidad_derecha velocidad_izquierda];

    %--Método de integración ruge-kuta
    pose(:,k+1) = kuta_diferencial(t(k), pose(:,k), h, conduccion);

end




