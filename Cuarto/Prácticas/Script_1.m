clear all 

tiempo_virtual = 0:0.01:pi*2;

y = signal_v0(tiempo_virtual);

plot(tiempo_virtual, y)

%Arranca cronometro

n=1;
tStart = tic;

tiempoReal(n) = toc(tStart);

while tiempoReal<2*pi
    n=n+1;
    tiempoReal(n) = toc(tStart);
    tiempoReal(n);
    salida=signal_v0(tiempoReal);
end

hold on
plot (tiempoReal, salida, '-')
