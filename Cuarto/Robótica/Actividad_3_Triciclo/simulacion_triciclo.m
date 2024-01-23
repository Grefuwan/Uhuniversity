%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simulación del movimiento de un robot móvil
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all
clc

j=1;

global l
global camino
global pose
global punto
%cargamos el camino

camino=load('camino.dat');

l=3.5; %distancia entre rudas delanteras y traseras, tambien definido en modelo
%Condiciones iniciales 

pose0=[0; 0; pi/2];

t0=0;

%final de la simulación
tf=40;

%paso de integracion
h=0.1;
%vector tiempo
t=0:h:tf;
%indice de la matriz
k=0;

%inicialización valores iniciales
pose(:,k+1)=pose0;

t(k+1)=t0;

while (t0+h*k) < tf,
    %actualización
    k=k+1;
    
    Radio_Curvatura = -10;
    rho = 1 / Radio_Curvatura;

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %valores de los parámetros de control
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    %volante = -0.1416;
    volante = atan(l*rho);
    velocidad = 2;
    
    conduccion=[velocidad volante];
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
    %para representar el punto onjetivo sobre la trayectoria
 
    punto=[30 30];

    
    %metodo de integración ruge-kuta

    pose(:,k+1) = kuta_triciclo(t(k),pose(:,k),h,conduccion);

end




