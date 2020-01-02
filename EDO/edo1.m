% Testando EDO
% a(x)y'(x) + b(x)y(x) = c(x)

% Funcoes auxiliares
a = @(x) x.^2;
b = @(x) -x;
c = @(x) 4*x.^3;

n = 10;

% Valor inicial de x0, final xf e y0
x0 = 1;
xf = 3;
y0 = 1;

% Valor de n
n = 10;

% Valor para y0
y(1) = 1;

% Definido o passo h
h = (xf - x0)/n;

% Definindo o vetor x
x = x0:h:xf;

% Iniciando o loop 
for k = 1:n
		y(k+1)= y(k) + (h/a(x(k)))*(c(x(k)) - b(x(k))*y(k));
endfor
y'
