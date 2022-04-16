function s=trap(f,a,b,M)
%
% Los datos son:
% f es el integrando.
% a y b son los extremos del intervalo.
% M es el numero de subintervalos.
% s es el valor aproximado para la integral definida que obtendremos
% con el metodo de los trapecios.
%
h=(b-a)/M;
s=0;
for k=1:M-1
x=a+h*k;
fx=subs(f,x);
s=s+fx;
end
s=h*(subs(f,a)+subs(f,b))/2+(h*s);
s=vpa(s,10);
fprintf(' El valor aproximado de la integral es ')
s
end