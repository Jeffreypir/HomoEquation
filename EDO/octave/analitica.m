###==================== PROGRAM ============================
# Program:analitica.m
# Description: Solve ODE numeric by the Taylor method
# Date of Create: dom 20 out 2019 12:52:05 -03
# Update in: dom 20 out 2019 12:52:23 -03
# Author:Jeffrey
#-----------------------------------------------------------

### =============== Solution analytic ======================
function [x,y] = analitica(xo,yo,h,N)
	x = xo:h:(xo + h*N);
	y(1) = yo;
	for i = 1:(length(x)-1)
    	y(i+1) = 3*exp(x(i)) + x(i) - 1;
	endfor
endfunction # --- End of function --------------------------
