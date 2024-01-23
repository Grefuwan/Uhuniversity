%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Simulación del movimiento de un robot móvil
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all
clc

MAPA = imread('cuadro4.bmp');
MAPA(1:end,:,:) = MAPA(end:-1:1,:,:);
image(MAPA);
axis xy
j=1;

global l
global radio_rueda
global camino
global pose
global punto

ds = 1;
origen = [2 2];
anguloPartida = pi/4;
anguloLlegada = -pi/2;

MAPA = imread('.\cuadro4.bmp');

%Transformación para colocar correctamente el origen del Sistema de referencia 
MAPA(1:end,:,:)=MAPA(end:-1:1,:,:);
delta=25;

%Llamada del algoritmo
Optimal_path = A_estrella(MAPA, delta, origen);

%Dibujo de la ruta
plot(Optimal_path(:,1), Optimal_path(:,2))

puntoLlegada = Optimal_path(end,2);

dd = 5;
da = dd;
xc = Optimal_path(:,1);
yc = Optimal_path(:,2);

camino=funcion_spline_cubica_varios_puntos(xc',yc',ds)';
l=3.5; 
radio_rueda=1;

%Condiciones iniciales 
pose0=[0; 0; 0];
t0=0;
tf=300; %Final de la simulación
h=0.1; %Paso de integracion
t=0:h:tf; %Vector tiempo
k=0; %Indice de la matriz

%Inicialización valores iniciales
pose(:,k+1)=pose0;
t(k+1)=t0;
punto=[0 0];

acaba = 0;
while  (t0+h*k) < tf & acaba ~= 1,
    k=k+1;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %valores de los parámetros de control
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    orden_minimo = minima_distancia(camino, [pose(1,k) pose(2,k)]);
    lookAhead = 5;

    if(orden_minimo +lookAhead >length(camino)) 
        punto = [camino(end,1) camino(end,2)];
    else 
        punto = [camino(orden_minimo+lookAhead,1) camino(orden_minimo+lookAhead,2)];
    end

    Delta = (pose(1,k)-punto(1))*sin(pose(3,k))-((pose(2,k)-punto(2))*cos(pose(3,k)));
    Lh = sqrt((pose(1,k)-punto(1))^2+(pose(2,k)-punto(2))^2);

    V = 9*Lh;
    if(V < 0.1)
        acaba = 1;
    end

    radio_curvatura=10;
    rho = 2*Delta/Lh^2;
    W = V*rho;
 
    velocidad_derecha=(V+W*l)/radio_rueda;
    velocidad_izquierda=(V-W*l)/radio_rueda;
    conduccion=[velocidad_derecha velocidad_izquierda];

    pose(:,k+1)=kuta_diferencial_mapa(t(k),pose(:,k),h,conduccion,MAPA);

end