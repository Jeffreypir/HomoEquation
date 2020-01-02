
###==================== PROGRAM ============================
# Program:euler.m 
# Description: Method of Euler 
# Date of Create: sex 29 nov 2019 16:42:51
# Update in: sex 29 nov 2019 16:46:19 -03
# Author:Jeffrey
#-----------------------------------------------------------

function [x y] = euler (f,x0,y0,h,N)
    x(1) = x0;
    y(:,1) = y0;
    for n = 1:N;
        y(:,n+1) = y(:,n) + h*f([x(n);y(:,n)]);
        x(n+1) = x(n) + h;
    endfor
endfunction

