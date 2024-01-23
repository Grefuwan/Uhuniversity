clear all
clc
global camino
global MAPA
global ancho
global largo

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Inicialización de las variables fundamentales

%-Dimensiones del coche
ancho = 10;
largo = 16;
MAPA = imread('.\cuadro_nuevo6.bmp');
MAPA(1:end,:,:) = MAPA(end:-1:1,:,:);
volante = 0;
velocidad = 0;
x0 = [450; 185;0; 0];
%---------------------------------------------
% Cálculo del camino mediante una spline
%---------------------------------------------
pose0 = [x0(1); x0(2); x0(3)];
posef = [800; 500; -pi/4]; 
punto_paso = [600 300];

%-Definición de la spline
%-Distancia de despegue y aterriza.
dd = 50;
da = dd;
posicion_despegue = [pose0(1)+(dd*cos(pose0(3))) pose0(2)+(dd*sin(pose0(3)))];
posicion_aterriza = [posef(1)-(da*cos(posef(3))) posef(2)-(da*sin(posef(3)))];

%-Definición del polígono
xc = [pose0(1) posicion_despegue(1) punto_paso(1)  posicion_aterriza(1) posef(1)];
yc = [pose0(2) posicion_despegue(2) punto_paso(2) posicion_aterriza(2) posef(2)];

%-Distancia entre puntos en cm.
ds = 1; 
camino = funcion_spline_cubica_varios_puntos(xc,yc,ds)';

%---------------------
tf = 15;
t0 = 0;
h = 0.01;;%-Paso de integracion 
t = 0:h:tf;%-Vector tiempo
k = 0;%-Índice de la matriz

%-Inicialización valores iniciales
x(:,k+1) = x0;
t(k+1) = t0;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% ELEMENTOS DE REPRESENTACIÓN GRÁFICA
% NO TOCAR ESTA PARTE DEL CODIGO
%------------------------------------------------
%-Crea las figuras
scrsz = get(0,'ScreenSize');
 
figure('Position',[1 scrsz(4)*5/30 scrsz(3)*25/30 scrsz(4)*25/30])
axHndl = gca
set(axHndl,'Userdata',1,'Drawmode','fast', ...
       'Visible','on','NextPlot','add','Userdata',1)
axis([-10 1034 -10 778]);

image(MAPA);

for numero=1:(2*8+2)
    handles_coche(numero) = plot(0,'Erasemode','xor');
    hold on
end

for numero=1:10
    handles_plots(numero) = plot(0,'Erasemode','xor');
    hold on
end

handle_vector = plot(0,'Erasemode','xor','LineWidth', 2.0);
%-------------------------------------------------------------------

%Da valores inciales al estado y a las medidas del laser
[x(:,k+1),laser] = kuta(t(k+1),x,h,0,0,handles_plots,handles_coche,handle_vector,[45 0],MAPA);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%  COMIENZA EL BUCLE DE SIMULACIÓN
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

while (t0+h*k) < tf
    %actualización
    k=k+1;
   

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Aquí hay que se define el controlador reactivo
    %------------------------------------------------
    componentes_x = sum([laser(:,1).*cos(laser(:,2))]);
    componentes_y = sum([laser(:,1).*sin(laser(:,2))]);
  
    modulo=sqrt(componentes_x.^2+componentes_y.^2);
  
    coseno=componentes_x/modulo;
 
    velocidad_reactiva(k) = 1*modulo;  
    volante_reactivo(k) = 8*atan2(componentes_y,componentes_x);
  
    %------------------------------------
    % Controlador p_pursuit
    %------------------------------------
    orden_minimo = minima_distancia_new(camino, [x(1,k) x(2,k)]);
 
 
    look_ahead=10;
 
    if (orden_minimo+look_ahead)<length(camino)
        punto = [camino(orden_minimo+look_ahead,1) camino(orden_minimo+look_ahead,2)]; 
    else
        punto = [camino(end,1) camino(end,2)];
    end
     

    delta = (x(1,k)-punto(1))*sin(x(3,k))-(x(2,k)-punto(2))*cos(x(3,k));
 
    LH = sqrt((x(1,k)-punto(1))^2+(x(2,k)-punto(2))^2);
 
    rho = 2*delta/LH^2;
 
    volante_tracking(k) = atan(largo*rho);
  
    velocidad_traking(k) = 5*sqrt((x(1,k)-camino(end,1))^2+(x(2,k)-camino(end,2))^2);
 
    %------------------------------------
    % Combinación de comportamientos
    %------------------------------------
    coordinador(k) = coseno^2; %---------- CAMBIO_AQUI

    volante(k) = (coordinador(k)*volante_tracking(k)) + 5*((1-coordinador(k))*volante_reactivo(k));
  
    velocidad(k) = 0.2*(coordinador(k)*velocidad_traking(k))+((1-coordinador(k))*velocidad_reactiva(k));
  
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    % Limitación de la velocidad
    %-------------------------------------
    if velocidad(k) > 200
        velocidad(k) = 200;
    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %-Limitación del ángulo de conducción
    if volante(k) > pi/4 
        volante(k) = pi/4;
    end

    if volante(k) < -pi/4 
        volante(k) = -pi/4;
    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    if velocidad(k) < 0.8
        break
    end

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %-Método de integración ruge-kuta, representación gráfica y simulacion del laser	 
    [x(:,k+1),laser] = kuta(t(k),x,h,volante(k),velocidad(k),handles_plots,handles_coche,handle_vector,[componentes_x componentes_y],MAPA);
  
    %-Pinta el camino
    plot(camino(:,1),camino(:,2))  
end