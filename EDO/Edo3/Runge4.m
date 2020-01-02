
###==================== PROGRAM ============================
# Program: Runge4.m
# Description: Method of Runge Kutta 4 
# Date of Create: sex 29 nov 2019 18:02:52 
# Update in: sex 29 nov 2019 18:03:00 
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------

function [x y] = Runge4(f,x0,y0,h,N)
    x(1) = x0;
    y(:,1) = y0;
    c = [1/6;1/3;1/3;1/6];
    a = [0;1/2;1/2;1];
    B = [0 0 0 0;1/2 0 0 0; 0 1/2 0 0 ;0 0 1 0];
    for n = 1:N
        y(:,n+1) = RungeKuttaR(f,x(n),y(:,n),h,c,a,B);
        x(n+1) = x(n) + h;
    endfor
endfunction
