function mapa_out=pinta_robot_v3(x,y,theta,alfa,distancia,mapa)


%-----------------------------------------------------
% Función para pintar el robot y el mapa versión final
%               19/10/22 FGB
%-----------------------------------------------------


% X,Y - Posicion del Robot
% Theta - Orientación del Robot
% Alfa - Orientación de la cabeza del Robot
% Distancia - Punto frente a la cabeza a la distancia dada por el sensor
%                   ultrasonido


persistent robot cabeza

if isempty(robot)
    robot = hgtransform; %definida fuera
end

if isempty(cabeza)
    cabeza = hgtransform('Parent',robot);
end


R=rectangle('Position',[-1.5 -1.5 3 3],'Parent',robot);
R.LineWidth=2;
M = makehgtform('translate',[x y 0], 'zrotate',theta);
robot.Matrix=M;

rueda_derecha=hgtransform('Parent',robot);
rd=rectangle('Position',[-0.5 -0.1 1 0.2],'Parent',rueda_derecha);
M = makehgtform('translate',[0 1 0]);
rueda_derecha.Matrix=M;

rueda_izquierda=hgtransform('Parent',robot);
ri=rectangle('Position',[-0.5 -0.1 1 0.2],'Parent',rueda_izquierda);
M = makehgtform('translate',[0 -1 0]);
rueda_izquierda.Matrix=M;

%angulo de la cabeza

%cabeza=hgtransform('Parent',robot);%definida fuera
ca=rectangle('Position',[-0.25 -0.5 0.5 1],'Parent',cabeza);
M = makehgtform('translate',[1 0 0],'zrotate',alfa);
cabeza.Matrix=M;

%Calcula  la posición del objeto detectado en el sistema de refeencia
%global y pinta el mapa

Mt=robot.Matrix*cabeza.Matrix;

punto=Mt*[double(distancia) 0 0 1]';

axis([-10 10 -10 10]);

mapa_out=[mapa; punto(1) punto(2)];

d=animatedline(double(mapa_out(:,1)),double(mapa_out(:,2)),'Marker','*','LineStyle','none', 'Color',[0 0 1]);

end
