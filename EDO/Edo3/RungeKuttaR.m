
###==================== PROGRAM ============================
# Program: RungeKuttaR.m 
# Description:Method of Runge Kutta R  
# Date of Create:  sex 29 nov 2019 17:51:24 
# Update in:  sex 29 nov 2019 17:51:28 
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------

function ynm1 = RungeKuttaR(f,xn,yn,h,c,a,B)
    R = size(c,1);
    n = size(yn,1);
    k = zeros(n,R);
    k(:,1) = f([xn;yn]);
    phi = c(1)*k(:,1);
    for i = 2:R
        soma = zeros(n,1);
        for j = 1:i-1 
            soma = soma + h*B(i,j)*k(:,j);
        endfor
        k(:,i) = f([xn + a(i)*h;yn + soma]);
        phi = phi + c(i)*k(:,i);
    endfor
    ynm1 = yn + h*phi;
endfunction
