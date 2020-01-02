
###==================== PROGRAM ============================
# Program: Heun.m 
# Description: Method of Heun 
# Date of Create: sex 29 nov 2019 18:02:52 
# Update in: sex 29 nov 2019 18:03:00 
# Author:Jeffrey
#-----------------------------------------------------------

function [x y] = Heun(f,x0,y0,h,N)
    x(1) = x0;
    y(:,1) = y0;
    c = [1/4;0;3/4];
    a = [0;1/3;2/3];
    B = [0 0 0;1/3 0 0; 0 2/3 0];
    for n = 1:N
        y(:,n+1) = RungeKuttaR(f,x(n),y(:,n),h,c,a,B);
        x(n+1) = x(n) + h;
    endfor
endfunction
