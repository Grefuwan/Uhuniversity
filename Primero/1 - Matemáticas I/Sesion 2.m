%Sesion 2

%Polinomio de Taylor
%taylor (f, x, f0)
%taylor (f, variable, x0, 'order', orden+1)

%Si quiero Taylor de log(1+x) centrado en X0=2 de orden 10:
f=log(1+x)
    f =
     
    log(x + 1)
 
T = taylor(f, x, 2, 'order', 11)
 
    T =
 
    x/3 + log(3) - (x - 2)^2/18 + (x - 2)^3/81 - (x - 2)^4/324 + (x - 2)^5/1215 - (x - 2)^6/4374 + (x - 2)^7/15309 - (x - 2)^8/52488 + (x - 2)^9/177147 - (x - 2)^10/590490 - 2/3
 

%Dice que el ejercicio 2 de Taylor es muy de examen
%2. Usa dicho polinomio y la orden subs de MatLab para obtener un valor
%aproximado de ln(1.2)

%Como en el anterior era 1+x, sabemos que x=0.2. Luego sustituyo en la
%funcion anterior las x por 0.2
s= subs(T, 0.2)
 
    s =
 
    log(3) - 2211/2500

vpa(s) %Aproxima/ redondea
 
    ans =
     
    0.21421228866810969139524523692253
 


%Integrales
f=(x^2)*sin(3*x)
 
    f =
     
    x^2*sin(3*x)
 
int (f, 1, 2)   %Integro f entre los puntos 1 y 2
 
    ans =
     
    (7*cos(3))/27 - (34*cos(6))/27 - (2*sin(3))/9 + (4*sin(6))/9
 
vpa(ans)
 
    ans =
     
    -1.6213127129282176557702341432848
 

f=log(abs(((x^2)+1)/((x^2)+4)))
 
    f =
     
    log(abs(x^2 + 1)/abs(x^2 + 4))
 
int(f, inf, -inf)
 
    ans =
     
    2*pi


%Integracion Numerica