%Sesión 1
%-----------Introducción-----------
%Realiza las siguientes operaciones usando MATLAB

%	a) 
sqrt((3^2) + 1) - sin(pi)

ans =

    3.1623


%	b)
( ( (3^2) + 5) / 7 ) + (9 / (2 - 5 ^ (-3) ) ) 

ans =

    6.5181


%	c)
%Primero creo la variable "e" y le asigno su valor
e = exp(1)

( log(9) / log(3) ) + log(e) + ( log(0.1) / log(10) )

ans =

    2.0000


%	d)
e = exp(1)

(e^2) + log(7) - ( log(2) / log(10) ) + ( ( cos(pi/3) ) ^2 ) - (sin(pi^2) / 3)

ans =

    9.4274


%	e)
( sqrt(3) + 2 )^1/5

ans =

    0.7464



%-----------Límites, continuidad, asíntotas y gráficas-----------
%Para calcular límites:
%   limit(/funcion/ , /variable/ , /tiende a/)
    limit (sin(x)/x     , x , 0)            %Limite de sin(x)/x cuando X tiende a 0
    limit (x/exp(x^2)   , x , Inf)          %Limite de x/e² cuando X tiende a Infinito
    limit (sin(x)/x^2   , x , 0 ,′ right′)  %Limite de sin(x)/x² cuando X tiende a 0 por la derecha

%AVertical  -   Hago limites laterales donde se anule la funcion
%AHorizontal-   Hago limites de +inf y -inf, y tienen que dar un valor
%entero
%AOblicua   -   y = mx + n
%                   m = limite en +-inf de f(x) / x
%                   n = limite en +-inf de f(x) - m·x


% 1. Estudia los siguientes límites

%a)
>> limit (((x^3)-1)/((x-1)^2), x, 1)

    ans =
     
    NaN


%b)
>> f = 6 / (4 + exp ( -1/x) )
>>pretty(f)
           6
    --------------
       /   1 \
    exp| - - | + 4
       \   x /

>>limit(f, x, 0)
 
    ans =
 
    NaN

%c) 
>>f = (x - sqrt((x^2)+2*x))
 
    f =
 
    x - (x^2 + 2*x)^(1/2)
 
>>limit (f, x, inf)
 
    ans =
 
    -1

%d)
>> f = (1 + 3*(tan(x))^2 )^((cot(x))^2)
 
    f =
     
    (3*tan(x)^2 + 1)^(cot(x)^2)
 
>> pretty (f)
                         2
             2     cot(x)
    (3 tan(x)  + 1)
    
    >> limit (f,x,0)
     
    ans =
     
    exp(3)
	
	
% 3. Determina dominio signo y asintotas
%a)
f=(2*x)/(sqrt((x^2)-1))
 
    f =
     
    (2*x)/(x^2 - 1)^(1/2)
     
pretty(f)
         2 x
    ------------
          2
    sqrt(x  - 1)

>>solve(f)
    ans =
    0
%Dominio: (-inf,-1) U (1, +inf)

%Signo
    ezplot(f)   %Veo cómo es la gráfica
    %Decreciente de -inf a -1 sin incluir
    %Creciente de 1 sin incluir a +inf

%Asíntotas
    %AVertical: 
       limit(f, x, 1, 'left')
     
            ans =
             
            -Inf*1i
         
        limit(f, x, 1, 'right')
             
            ans =
             
            Inf

        limit(f, x, -1, 'left')
 
            ans =
             
            -Inf
 
        limit(f, x, -1, 'right')
 
            ans =
             
            Inf*1i
        
        %Luego tiene AVertical en x = 1 y x = -1

    %AHorizontal:
        >>limit(f, x, -inf)
 
            ans =
             
            -2

       >>limit(f, x, inf)
 
            ans =
             
            2 

        %Luego tiene AHorizontal en y = 2 e y = -2
    %AOblicua:
        %Como tiene AHorizontal, no tiene Oblicua

        
%b)
>>f=log((x+1)/(x-1))
     
    f =
     
    log((x + 1)/(x - 1))
 
>>pretty(f)
       / x + 1 \
    log| ----- |
       \ x - 1 /

%Dominio: (-inf, -1) U (1, +inf)
%Signo: Decrece (-inf, -1)
%       Crece (1, +inf)
%Asintotas
    %AVertical
        %Tiene AVertical en x = -1 y x = 1
    %AHorizontal
        %limit(f, x, +inf) = limit (f, x, -inf) = 0
        %Luego AHorizontal en y=0
    %AOblicua
        %Como tiene AHorizontal, no tiene AOblicua

%c)
f=1/(exp(x)-1)
     
    f =
     
    1/(exp(x) - 1)
 
pretty(f)
         1
    ----------
    exp(x) - 1





solve(exp(x) - 1)	%Me resuelve esa ecuacion y sabremos cuando se anula el denominador
ans =
	0

%Para hacer la gráfica:
ezplot(f), grid on
%Para dibujarla de forma acotada:
ezplot(f, [-25 25]), grid on
%ezplot(f, [xMin xMax yMin yMax]), grid on

%Si quiero que haya 2 graficas en una misma tabla
>>ezplot(sin(x)), grid on, hold on
>>ezplot(cos(x)), grid on, hold on


%--------Ejemplo derivando
>> f = 1/(exp(x)-1)
 
f =
 
1/(exp(x) - 1)

>> f1 = diff(f)
 
f1 =
 
-exp(x)/(exp(x) - 1)^2

>> f4 = diff (f,4)
 
f4 =
 
(14*exp(2*x))/(exp(x) - 1)^3 - (36*exp(3*x))/(exp(x) - 1)^4 + (24*exp(4*x))/(exp(x) - 1)^5 - exp(x)/(exp(x) - 1)^2
 
>> f4 = simplify(f4)
 
f4 =
 
(exp(x)*(11*exp(2*x) + exp(3*x) + 11*exp(x) + 1))/(exp(x) - 1)^5
 
>> pretty(f4)
exp(x) (exp(2 x) 11 + exp(3 x) + 11 exp(x) + 1)
-----------------------------------------------
                             5
                 (exp(x) - 1)





%-----------------Derivadas-----------------
%Para derivar usamos >>diff
%Si queremos derivar la funcion f = (x²+1)/((e^x)-1), usamos
%diff((x²+1)/(exp(x)-1))
%Derivada de orden n de una funcion y=f(x), usamos >>diff(y, x, n)

%1. Valor de a) para que sea continua. ¿Es derivable?


%2.
%Como es una recta bisectriz, la pendiente de la recta en el origen va a ser 1.
%	Luego la f'(x0) = f'(0) = 1
>> syms x h
>> f = exp(x^2 +h*x) - 1
 
f =
 
exp(x^2 + h*x) - 1
 
>> f1 = diff(f,x)
 
f1 =
 
exp(x^2 + h*x)*(h + 2*x)
 
>> pretty(f1)
     2
exp(x  + h x) (h + 2 x)
% exp(x² + h x) (h + 2 x)

%Para sustituir en f1 la x por el valor 0:
>> f11 = subs(f1, x, 0)
 
f11 =
 
	h	%Quiere decir que la pendiente de esa curva en el 0 es h, y tengo que obligarla a que sea 1
			%para que sea la bisectriz del primer cuadrante. 
			% Luego h = 1


%Ejercicio 4
f=(exp(x))/(x-2)
 
    f =
     
    exp(x)/(x - 2)
 
pretty(f)
    exp(x)
    ------
     x - 2


%Dominio
%   Dom = R - {2}
%Asintotas
    %AVertical  
    %AHorizontal
    %AOblicua
%Monotonia
%Puntos Criticos