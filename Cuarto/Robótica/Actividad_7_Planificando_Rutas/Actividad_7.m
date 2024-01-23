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

%==Cargamos el MAPA==
MAPA = imread('cuadro4.bmp');
MAPA(1:end,:,:) = MAPA(end:-1:1,:,:);
image(MAPA);
axis xy

ds = 1;
puntoPartida = [2 2];
anguloPartida = pi/4;
puntoLlegada = [350 400];
anguloLlegada = -pi/4;

waypoint1 = [49 04];
waypoint2 = [52 73];

dd = 5;
da = dd;

Pdx = puntoPartida(1) + dd * cos(anguloPartida);
Pdy = puntoPartida(2) + dd * sin(anguloPartida);
Pax = puntoLlegada(1) - da * cos(anguloLlegada);
Pay = puntoLlegada(2) - da * cos(anguloLlegada);

xc = [puntoPartida(1) Pdx waypoint1(1) waypoint2(1) Pax puntoLlegada(1)];
yc = [puntoPartida(2) Pdy waypoint1(2) waypoint2(2) Pay puntoLlegada(2)];

camino = funcion_spline_cubica_varios_puntos(xc,yc,ds)';
l = 3.5; 
radio_rueda = 1;

%Condiciones iniciales 
pose0 = [0; 0; 0];
t0 = 0;
tf = 300; %Final de la simulación
h = 0.1; %Paso de integracion
t = 0:h:tf; %Vector tiempo
k = 0; %Indice de la matriz

%Inicialización valores iniciales
pose(:,k+1) = pose0;
t(k+1) = t0;
punto = [0 0];
acaba = 0;

while  (t0+h*k) < tf & acaba ~= 1
    k = k+1;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %valores de los parámetros de control
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    orden_minimo = minima_distancia(camino, [pose(1,k) pose(2,k)]);

    lookAhead = 5;
    if(orden_minimo +lookAhead >length(camino)) 
        % punto = [camino(1,1) camino(1,2)];
        punto = [camino(end,1) camino(end,2)];
    else 
        punto = [camino(orden_minimo+lookAhead,1) camino(orden_minimo+lookAhead,2)];
    end

    Delta = (pose(1,k)-punto(1))*sin(pose(3,k))-((pose(2,k)-punto(2))*cos(pose(3,k)));
    Lh = sqrt((pose(1,k)-punto(1))^2+(pose(2,k)-punto(2))^2);

    V = 2*Lh;
    if(V < 0.1)
        acaba = 1;
    end

    radio_curvatura = 10;
    rho = 2*Delta/Lh^2;
    W = V*rho;
 
    velocidad_derecha = (V + W*l) / radio_rueda;
    velocidad_izquierda = (V - W*l) / radio_rueda;
    conduccion = [velocidad_derecha velocidad_izquierda];

    pose(:,k+1) = kuta_diferencial_mapa(t(k), pose(:,k), h, conduccion, MAPA);
end