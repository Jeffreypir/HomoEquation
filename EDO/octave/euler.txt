
###==================== PROGRAM ============================
# Program: euler.m 
# Date of Create:Solve ODE the Euler method  
# Update in: ter 22 out 2019 15:05:48 
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------

### =============== Euler method =========================== 
function [x,y] = euler(f,xo,yo,h,N)
	x = xo:h:(xo + h*N);
	y(1) = yo;
	for i = 1:(length(x)-1)
    	y(i+1) = y(i) + h*f(x(i),y(i)); 
	endfor
endfunction #--- End of function ---------------------------

