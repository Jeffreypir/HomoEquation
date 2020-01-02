###===================== PROGRAM =============================
# Program: testeEuler.m
# Description: Plot of solutions analytic and numeric
# Date of Create: dom 20 out 2019 13:41:49 
# Update in: dom 20 out 2019 13:43:51 
# Author:Jefferson Bezerra dos Santos
#-------------------------------------------------------------

###============= Clear enviromment ===========================
clc
clear
#-------------------------------------------------------------

###================ Defining auxiliary functions =============
f  = @(x,y) y - x + 2;#Order derivative 0
#-------------------------------------------------------------

### ===== Euler method, paramenters(f,x0,y0,h,N) =============
[x,y] = euler(f,0, 2,0.1,50);
#-------------------------------------------------------------

###===== Solution analytic, paramenters(x0,y0,h,N) ===========
[x1,y1] = analitica(0,2,0.1,50);

### =========== Plotting =====================================
#color b for blue, '.' for point, + is type of symbol   
plot(x,y,'b.+',x1,y1,'r.x'); 
title('Solution of ODE');
xlabel('Axis (x)');
ylabel('Axis (y)');
h = legend("Euler method","Analytic solution","location","northwest");
set(h,"fontsize",11);
legend("boxoff");
grid on
print -depsc plot2.eps #Figure in color eps format 
#-------------------------------------------------------------
