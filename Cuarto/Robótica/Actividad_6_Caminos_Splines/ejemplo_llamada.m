%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Ejemplo de la llamada a la función 
% funcion_spline_cubica_varios_puntos.m
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all


%xc=[0 10 40 80 80 80];
%yc=[0 0 40 40 100 120];
ds=1; %distancia entre puntos en cm.

puntoPartida = [2 2]
anguloPartida = pi/4
puntoLlegada = [80 75]
anguloLlegada = -pi/4

waypoint1 = [49 08]
waypoint2 = [07 45]


dd = 5;
da = dd;

Pdx=puntoPartida(1)+dd*cos(anguloPartida) ; Pdy=puntoPartida(2)+dd*sin(anguloPartida)
Pax=puntoLlegada(1) - da*cos(anguloLlegada) ; Pay=puntoLlegada(2) - da*sin(anguloLlegada)

xc = [puntoPartida(1) Pdx waypoint1(1) waypoint2(1) Pax puntoLlegada(1)]
yc = [puntoPartida(2) Pdy waypoint1(2) waypoint2(2) Pay puntoLlegada(2)]

camino=funcion_spline_cubica_varios_puntos(xc,yc,ds)';


 plot(camino(:,1),camino(:,2),'or','LineWidth',3)
 hold on
 plot(xc,yc,'*g')