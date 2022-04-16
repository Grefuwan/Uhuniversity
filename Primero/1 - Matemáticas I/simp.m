function s=simp(f,a,b,M)
%
% Los datos son:
% f es el integrando.
% a y b son los extremos del intervalo.
% 2M es el n´umero de subintervalos.
% s es la aproximaci´on obtenida con la regla de Simpson compuesta.
%
h=(b-a)/(2*M);
s_pares=0;
s_impares=0;
    for k=1:(M-1)
        x=a+h*2*k;
        fx_pares=subs(f,x);
        s_pares=s_pares+fx_pares;
    end

    for k=1:M
        x=a+h*(2*k-1);
        fx_impares=subs(f,x);
        s_impares=s_impares+fx_impares;
    end
s=h*(subs(f,a)+subs(f,b)+2*s_pares+4*s_impares)/3;
s=vpa(s,10);
fprintf(' El valor aproximado de la integral es ')
s
end