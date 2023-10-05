clc
clear all

Delay = 2;
Periodo = 6;
Amplitud = pi/2;
Tiempo_simulado = 0:0.01:pi*4;
y = signal_vf_v2(Tiempo_simulado, Periodo, Delay, Amplitud);

k = 1;
tiempo_real(k) = 0;

referencia(k) = signal_vf_v2(tiempo_real(k), Periodo, Delay, Amplitud);

mapa = [];
%punto = animatedline('Marker', '.'); % Permite que el punto vaya "moviéndose" sin tener que borrar entero el canvas
tStart = tic;


mi_Robot = legoev3('USB');	%Inicializa el robot por el puerto USB

%---Motor Cabeza---
motor_Cabeza = motor(mi_Robot,'A');	%Asocia el puerto A al motor_Cabeza
resetRotation(motor_Cabeza);	%Resetea el contador de grados girados por el motor_Cabeza
start(motor_Cabeza);	%Inicializa el motor_Cabeza
giro_cabeza(1) = double(readRotation(motor_Cabeza));  %Inicializa el giro_cabeza(1)

%---Sonar---
%Sonar = sonicSensor(mi_Robot,4);	%Asocia el puerto 4 al Sonar
%distancia(1) = double(readDistance(Sonar));	%Guarda en el array "distancia" la 

%---Pulsador---
pulsador = touchSensor(mi_Robot, 1);


while (readTouch(pulsador == 0))
end

while (readTouch(pulsador == 1))
end

while ((tiempo_real(k) < 4*pi) && (readTouch(pulsador == 0)))
	k = k+1;
 	tiempo_real(k) = toc(tStart);
  	referencia(k) = signal_vf_v2(tiempo_real(k), Periodo, Delay, Amplitud);
    
   
	%---Motor Cabeza----------------
 	motor_Cabeza.Speed = 10;	%Establece la velocidad de giro de motor_Cabeza
  	giro_cabeza(k) = double(readRotation(motor_Cabeza));	%Guarda en el array giro_cabeza lo que va rotando
    
	%---Sonar----------------
  	%distancia(k) = double(readDistance(Sonar));	%Guarda en distancia(k) la distancia leida por el Sonar en cada instante k
    
	%---Dibujar gráfica----------------
	%addpoints(punto, tiempo_real(k), distancia(k));	%Añade el siguiente punto a dibujar, sin necesidad de repintar el canvas entero
  	%axis([0 4*pi -Amplitud Amplitud]);	%Establecer las dimensiones de la gráfica a dibujar. Si no se usa, la gráfica crece dinámicamente
  	%drawnow	%Va dibujando constantemente mientras dure el bucle while

    disp 'Salir'

end

stop(motor_Cabeza);	%Hace que la cabeza pare de girar
