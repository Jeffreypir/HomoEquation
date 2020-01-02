###==================== PROGRAM ============================
# Program:taylor3.m 
# Description: Solve ODE numeric by the Taylor method
# Date of Create: dom 20 out 2019 12:52:05
# Update in: ter 22 out 2019 15:08:15
# Author: Jefferson Bezerra dos Santos
#-----------------------------------------------------------

### ============= Taylor method ============================ 
function [x,y] = taylor3(f,f1,f2,xo,yo,h,N)
	x = xo:h:(xo + h*N);
	y(1) = yo;
	for i = 1:(length(x)-1)
    	y(i+1) = y(i) + h*f(x(i),y(i)) + ((h^2)/2)*f1(x(i),y(i)) + ((h^3)/6)*f2(x(i),y(i));
	endfor
endfunction #------ End of function -----------------------

