%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simulación del movimiento de un robot móvil
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all
clc

j=1;

global l
global radio_rueda
global camino
global pose
global punto
%cargamos el camino

camino=load('camino.dat');

l=3.5; %distancia entre rudas delanteras y traseras, tambien definido en modelo
radio_rueda=1;

%Condiciones iniciales 
pose0=[0; 0; 0]; 
pose_destino1 = [29; 61; 0];
pose_destino2 = [86; 48; 0];

t0=0;

%final de la simulación
tf=35;

%paso de integracion
h=0.1;
%vector tiempo
t=0:h:tf;
%indice de la matriz
k=0;

%inicialización valores iniciales
pose(:,k+1)=pose0;

t(k+1)=t0;

reached_destino1 = false;

while (t0+h*k) < tf,
        %actualización
        k=k+1;
        
        if reached_destino1
            punto_destino = pose_destino1;
        else
            punto_destino = pose_destino2;
        end
    
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        %valores de los parámetros de control
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
       
        radio_curvatura=10;
        
        %Modificaciones
         Delta=((pose(1,k)-punto_destino(1))*sin(pose(3,k)))-((pose(2,k)-punto_destino(2))*cos(pose(3,k)));
         Lh=sqrt((pose(1,k)-punto_destino(1))^2+(pose(2,k)-punto_destino(2))^2);
        
        V=Lh;
        if(V>5)
            V=5;
        end;
    
        rho=2*Delta/Lh^2;
        W=V*rho;
        velocidad_derecha=(V+W*l)/radio_rueda;
        velocidad_izquierda=(V-W*l)/radio_rueda;
         
        phi=atan(rho*l);
         
        volante=-0.1416;
         
        volante=phi;
         
        velocidad=2;
        
        conduccion=[velocidad_derecha velocidad_izquierda];
         
         %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
         
         %para representar el punto onjetivo sobre la trayectoria
         
         punto=[30 30];
    
        
        %metodo de integración ruge-kuta
        
        pose(:,k+1)=kuta_diferencial(t(k),pose(:,k),h,conduccion);
    
        if reached_destino1 && norm(pose(:,k) - pose_destino1) < 1
                reached_destino1 = true;
        end

end