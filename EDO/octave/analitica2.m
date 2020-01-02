###==================== PROGRAM ============================
# Program:analitica2.m
# Description: Solve ODE numeric by the Taylor method
# Date of Create: dom 20 out 2019 12:52:05 -03
# Update in: seg 21 out 2019 15:25:01 -03
# Author:Jeffrey
#-----------------------------------------------------------

### =============== Solution analytic ======================
function [x,y] = analitica2(xo,yo,h,N)
	x = xo:h:(xo + h*N);
	y(1) = yo;
	for i = 1:(length(x)-1)
    	y(i+1) = 2*((1 + 3*x(i+1))^(1/3));
	endfor
endfunction # --- End of function --------------------------
