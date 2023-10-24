clc
clear all

%Delay = 2;
%Periodo = 6;
%Amplitud = pi/2;
%Tiempo_simulado = 0:0.01:pi*4;
%y = signal_vf_v2(Tiempo_simulado, Periodo, Delay, Amplitud);

mi_Robot = legoev3('USB');%Inicializa el robot por el puerto USB

%---Motor Cabeza---
motor_Cabeza = motor(mi_Robot,'A');%Asocia el puerto A al motor_Cabeza
resetRotation(motor_Cabeza);%Resetea el contador de grados girados por el motor_Cabeza
start(motor_Cabeza);%Inicializa el motor_Cabeza
giro_cabeza(1) = double(readRotation(motor_Cabeza));  %Inicializa el giro_cabeza(1)

%---Sonar---
%Sonar = sonicSensor(mi_Robot,4);   %Asocia el puerto 4 al Sonar
%distancia(1) = double(readDistance(Sonar));    %Guarda en el array "distancia" la

%---Pulsador---
pulsador = touchSensor(mi_Robot, 1);


while (readTouch(pulsador) == 0)
 disp   'Pulsa'
end

while (readTouch(pulsador) == 1)
end

%Valores iniciales
tStart = tic;
desfase = toc(tStart)+0.2;
Periodo = 10;
Amplitud = 90;
k = 1;
I(k)=0;
kp=0.8;
ki=1*1.5;
kd=1*0.7;
tiempo_real(1) = 0; 
                                                        %referencia(1)=200*tiempo_real(1);   %Angulo girado
          
%Valores referencia

%valor_deseado=signal_vf_v2(tiempo_real(k),Periodo,desfase,Amplitud);
valor_deseado = 90;

referencia(k)=valor_deseado;
error(k) = referencia(k) - giro_cabeza(k);    



controlador(k)=kp*error(k)+ki*i()

while ( (readTouch(pulsador) == 0))
k = k+1;
tiempo_real(k) = toc(tStart);

referencia(k)=valor_deseado;
%referencia(k) = signal_vf_v2(tiempo_real(k),Periodo,desfase,Amplitud);
%referencia(k) = 200*tiempo_real(k);
   
%---Motor Cabeza----------------
%motor_Cabeza.Speed = 10;     %Establece la velocidad de giro de motor_Cabeza
giro_cabeza(k) = double(readRotation(motor_Cabeza));%Guarda en el array giro_cabeza lo que va rotando
   
error(k) = referencia(k) - giro_cabeza(k);
dt=(tiempo_real(k)-tiempo_real(k-1));

D(k)=(error(k)-error(k-1))/dt;
I(k)=I(k-1)+error(k)*dt;

%Velocidad cabeza/ Power
controlador=kp*error(k)+ki*I(k)+kd*D(k);
   
   
%---Sonar----------------
%distancia(k) = double(readDistance(Sonar));    %Guarda en distancia(k) la distancia leida por el Sonar en cada instante k
   
   
    %---Power---
    
    
   
    Power=int8(controlador);
    if Power>100
        Power=100;
    end
    if Power<-100
        Power=-100;
    end
   
%---Dibujar gráfica----------------
%addpoints(punto, tiempo_real(k), distancia(k));      %Añade el siguiente punto a dibujar, sin necesidad de repintar el canvas entero
%axis([0 4*pi -Amplitud Amplitud]); %Establecer las dimensiones de la gráfica a dibujar. Si no se usa, la gráfica crece dinámicamente
 %drawnow    %Va dibujando constantemente mientras dure el bucle while
       
    motor_Cabeza.Speed = Power;
    %disp 'Salir'

end

stop(motor_Cabeza);

plot(tiempo_real,referencia, 'r');
hold on;
plot(tiempo_real, giro_cabeza);
plot(tiempo_real, error);
%Esto plotea la gráfica de la evolución del ángulo y el error con respecto
%a 90º

grid on