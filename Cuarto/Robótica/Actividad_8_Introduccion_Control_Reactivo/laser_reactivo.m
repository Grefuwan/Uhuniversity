clear all
clc
global camino
global MAPA
global ancho
global largo

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Inicializaci�n de las variables fundamentales
% NO TOCAR ESTA PARTE DEL CODIGO
%------------------------------------------------

%-Dimensiones del coche
ancho = 10;
largo = 16;

MAPA = imread('.\cuadro_nuevo3.bmp');

volante = 0;
velocidad = 0;



x0 = [450; 185;0; 0]
tf = 10;
t0 = 0;

%-Paso de integracion 
h = 0.01;;
%-Vector tiempo
t = 0:h:tf;
%-�ndice de la matriz
k = 0;

%-Inicializaci�n valores iniciales
x(:,k+1) = x0;
t(k+1) = t0;
%-------------------------------------------------------

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% ELEMENTOS DE REPRESENTACI�N GR�FICA
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

for numero = 1:(2*8+2)
    handles_coche(numero) = plot(0,'Erasemode','xor');
    hold on
end

for numero=1:10
    handles_plots(numero) = plot(0,'Erasemode','xor');
    hold on
end

handle_vector = plot(0,'Erasemode','xor','LineWidth', 2.0);
%-------------------------------------------------------------------

%-Da valores inciales al estado y a las medidas del laser
[x(:,k+1),laser] = kuta(t(k+1), x, h, 0, 0, handles_plots, handles_coche, handle_vector, [45 45], MAPA);

%--C�lculo del vector percepcion
modulos = laser(:,1);
cosenos = cos(laser(:,2));
senos = sin(laser(:,2));
V1 = [modulos.*cosenos modulos.*senos];

vectorPercepcion = [sum(V1(:,1)) sum(V1(:,2))];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  COMIENZA EL BUCLE DE SIMULACI�N
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

while (t0+h*k) < tf,

    %-Actualizaci�n
    k=k+1;

    componentes_x = 75;
    componentes_y = 30;
  
  
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %-Aqu� hay que definir el controlador
    %------------------------------------
    velocidad=vectorPercepcion(1);
  
    volante=velocidad*vectorPercepcion(2);
    %------------------------------------
  
  
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %-Limitaci�n del �ngulo de conducci�n
    if volante > pi/4 
        volante = pi/4;
    end

    if volante < -pi/4
        volante = -pi/4;
    end
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %-Metodo de integraci�n ruge-kuta, representaci�n gr�fica y simulacion del laser	 
     [x(:,k+1),laser]=kuta(t(k),x,h,volante,velocidad,handles_plots,handles_coche,handle_vector,[componentes_x componentes_y],MAPA);
 end


