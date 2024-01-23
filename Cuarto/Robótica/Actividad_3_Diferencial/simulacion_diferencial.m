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

l = 3.5; %Distancia entre rudas delanteras y traseras, tambien definido en modelo
radio_rueda = 1;

%Condiciones iniciales 
pose0 = [0; 0; 0];
t0 = 0;

tf = 15; %Tiempo final de la simulación
h=0.1; %Paso de integracion
t=0:h:tf; %Vector tiempo
k=0; %Indice de la matriz

pose(:,k+1) = pose0;

t(k+1) = t0;

while (t0 + h * k) < tf,
    k=k+1;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %valores de los parámetros de control
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    v = 2;
    w = 0.5;

    %velocidad_derecha = 2.1;
    %velocidad_izquierda = 1.5;
    velocidad_derecha = (v + w*l)/radio_rueda;
    velocidad_izquierda = (v - w*l)/radio_rueda;

    R = 10;
    rho = 1/10;
    phi = atan(rho*l);
    volante = -0.1416;
    volante = phi;
    velocidad = 2;

    conduccion = [velocidad_derecha velocidad_izquierda];
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %--Representar el punto objetivo sobre la trayectoria
    punto=[30 30];
    %--Método de integración ruge-kuta
    pose(:,k+1)=kuta_diferencial(t(k),pose(:,k),h,conduccion);
end