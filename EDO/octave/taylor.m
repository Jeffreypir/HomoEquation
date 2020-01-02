###==================== PROGRAM ============================
# Program:taylor.m 
# Description: Solve ODE numeric by the Taylor method
# Date of Create: dom 20 out 2019 12:52:05 -03
# Update in: dom 20 out 2019 12:52:23 -03
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------

### ============= Taylor method ============================ 
function [x,y] = taylor(xo,yo,h,N,f1,f2,f3)
	x = xo:h:(xo + h*N);
	y(1) = yo;
	for i = 1:(length(x)-1)
    	y(i+1) = y(i) + h*f1(x(i),y(i)) + ((h^2)/2)*f2(x(i),y(i)) + ((h^3)/6)*f3(x(i),y(i));
	endfor
endfunction #------ End of function -----------------------

