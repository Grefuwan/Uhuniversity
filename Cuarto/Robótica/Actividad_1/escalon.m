function [salida] = escalon(t)
m = length(t);
salida = zeros(1, m);
  	for i = 1:m
  		if t(i) < 0
  			salida(i) = 0;
  		else
  			salida(i) = 1;
  		end
  	end