
###==================== PROGRAM ============================
# Program: adams_bashforth.m 
# Date of Create:Solve ODE the Euler method  
# Update in: dom 20 out 2019 12:56:45 -03
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------

### =============== adams bashfort =========================
function [x,y] = adams_bashforth(f,xo,yo,h,N)
	x = xo:h:(xo + h*N);
	y(1) = yo;
    y(2) = yo + h*f(x(1),y(1));
	for i = 1:(length(x)-2)
    	y(i+2) = y(i+1) + (h/2)*((-f(x(i),y(i))) + 3*(f(x(i+1),y(i+1)))); 
	endfor
endfunction #--- End of function ---------------------------

