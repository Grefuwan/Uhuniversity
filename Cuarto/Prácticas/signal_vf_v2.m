function [ valor ] = signal_vf_v2( tiempo, periodo, delay, Amplitud )
%--------------------------------------------------------------------------
% Genera un fución de referencia para el movimiento de la cabeza del robot
% Recibe:
% tiempo: la variable temporal que permite evaluar la función
% periodo: periodo de la señal seno
% delay: retraso hasta que se actúa la señal
% Amplitud: La amplitiud d el señal seno
% Devuelve:
% valor: de la señal en el instante temporal entregado (permite evaluar
% array de valores)
%--------------------------------------------------------------------------


valor=Amplitud*sin((2*pi/periodo)*(tiempo-delay));

%Evalúa la función para el vector tiempo, hace cero antes y despues del
%period activo
valor(tiempo<delay)=0;
valor(tiempo>delay+periodo)=0;

end