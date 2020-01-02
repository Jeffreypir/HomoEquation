
###==================== PROGRAM ============================
# Program: ponto_medio.m 
# Date of Create:Solve ODE the Euler method  
# Update in: ter 22 out 2019 15:05:04
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------

### =============== Mitpoin method=========================== 
function [x,y] = ponto_medio(f,xo,yo,h,N)
	x = xo:h:(xo + h*N);
	y(1) = yo;
    y(2) = yo + h*f(x(1),y(1));
	for i = 1:(length(x)-2)
    	y(i+2) = y(i) + 2*h*f(x(i+1),y(i+1)); 
	endfor
endfunction #--- End of function ---------------------------

