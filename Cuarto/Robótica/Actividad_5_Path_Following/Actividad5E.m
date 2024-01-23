%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simulación del movimiento de un robot móvil
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all
clc
j = 1;

global l
global radio_rueda
global camino
global pose
global punto

%Cargamos el camino
camino=load('camino.dat');

l=3.5; 
radio_rueda=1;

%Condiciones iniciales 
pose0 = [0; 0; 0];
t0 = 0;

%Final de la simulación
tf = 2000;

h = 0.1; %Paso de integracion
t = 0:h:tf; %Vector tiempo
k = 0; %Indice de la matriz

%inicialización valores iniciales
pose(:,k+1) = pose0;
t(k+1) = t0;
%Modificaciones
punto = [0 0];

acaba = 0;
while  (t0+h*k) < tf & acaba ~= 1
    k=k+1;

    orden_minimo = minima_distancia(camino, [pose(1,k) pose(2,k)]);

    lookAhead = 17;

    if(orden_minimo +lookAhead > length(camino)) 
        punto = [camino(1,1) camino(1,2)];
    else 
        punto = [camino(orden_minimo+lookAhead,1) camino(orden_minimo+lookAhead,2)];
    end

    Delta = (pose(1,k)-punto(1))*sin(pose(3,k))-((pose(2,k)-punto(2))*cos(pose(3,k)));
    Lh = sqrt((pose(1,k)-punto(1))^2+(pose(2,k)-punto(2))^2);

    V = 2*Lh;
    radio_curvatura=10;
    rho = 2*Delta/Lh^2;
    W = V*rho;
 
    velocidad_derecha = (V+W*l)/radio_rueda;
    velocidad_izquierda = (V-W*l)/radio_rueda;

    conduccion = [velocidad_derecha velocidad_izquierda];

    pose(:,k+1) = kuta_diferencial(t(k), pose(:,k), h, conduccion);

end