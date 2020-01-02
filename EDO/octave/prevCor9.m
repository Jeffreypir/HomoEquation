###==================== PROGRAM ============================
# Program:prevCor9.m
# Description: Solve ODE numeric by the Previsor Corretor
# Date of Create: qui 31 out 2019 14:19:13 
# Update in:  qui 31 out 2019 14:19:24
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------
### ============================ Clear enviromment ============================
clear
clc
#------------------------------------------------------------------------------

###========================== Parametros ======================================
tol = 5e-1;
h = 0.01;
xo = 0.0;
xf = 0.3;
yo = 2;
y(1) = 2;
x = xo:h:xf; 
f = @(x,y) y - x + 2;
y(2) = y(1)+ h*f(x(1),y(1));  
#------------------------------------------------------------------------------

###==================== Function Adasm Bashforth ================================
function [x,y] = adamsbs (xo,xf,yo,h,f)
    x = xo:h:xf; 
    y(1)= yo;
    y(2) = y(1)+ h*f(x(1),y(1));  
    i = 0;
    while ((++i) < (length(x)-1))
        y(i+2) = y(i) + (h/2)*((f(x(i),y(i))) + 3*f(x(i+1),y(i+1)));
    endwhile
endfunction
#---------------------- End function ------------------------------

### ================== Solution analytic ==========================
anali = @(x) 3*exp(x) + x - 1;
#-------------------------------------------------------------------

#loop 
i = 0;
while ((++i) < (length(x)-1))
        ym = y(i); # variavel auxiliar
        yn = y(i+1);#variavel auxiliar
    while (1)
        ymj = yn + (h/2)*((f(x(i),ym)) + 3*f(x(i+1),yn));#preditor adasm bashforth
        aux = f((x(i+1)),ymj);# funcao f
        ynj = ym + (h/3)*(f(x(i),ym) + 4*(f(x(i+1),yn)) + aux);#Corretor simpson
        if(abs(ynj-ymj) < tol)# Verificando a tolerancia foi atingida
            y(i+2) = ynj;
            break;
        else
            ym = yn;#Atualizando para proxima iteracao
            yn = ynj;#Atuaizando para proxima iteracao
        endif
    endwhile
endwhile

#loop para prencher solucao analitica
i = 0;
while ((++i) <= (length(x)))
    y1(i) = anali(x(i));
endwhile

###============= Adams bashfort =============================
[x2,y2] = adamsbs (xo,xf,yo,h,f); 
#------------------------------------------------------------

###================= Plotagem ===============================
plot(x,y,'b.+',x,y1,'r.x',x2,y2,'g.o');
title('Solution of ODE');
xlabel('Axis (x)');ylabel('Axis (y)');
legend("previsor-corretor", "analitica", "adams");
legend("boxoff");
grid on
print -depsc plot6.eps #Figure in color eps format 
#-----------------------------------------------------------
