###===================== PROGRAM =============================
# Program: teste.m
# Description: Plot of solutions analytic and numeric
# Date of Create: dom 20 out 2019 13:41:49 -03
# Update in: dom 20 out 2019 13:43:51 -03
# Author:Jefferson Bezerra dos Santos
#-------------------------------------------------------------

###============= Clear enviromment ===========================
clc
clear
#-------------------------------------------------------------

###================ Defining auxiliary functions =============
f  = @(x,y) y - x + 2;#Order derivative 0
f1 = @(x,y) y - x + 1;#Order derivative 1
f2 = @(x,y) y - x + 1;#Order derivative 2
#-------------------------------------------------------------

### ===== Taylor method, paramenters(f,f1,f2,x0,y0,h,N) ======
[x,y] = taylor3(f,f1,f2,0, 2,0.1,50);
#-------------------------------------------------------------

###===== Solution analytic, paramenters(x0,y0,h,N) ===========
[x1,y1] = analitica(0,2,0.1,50);

### =========== Plotting =====================================
#color b for blue, '.' for point, + is type of symbol   
plot(x,y,'b.+',x1,y1,'r.x'); 
title('Solution of ODE');
xlabel('Axis (x)');
ylabel('Axis (y)');
h = legend("Taylor method","Analytic solution","location","northwest");
set(h,"fontsize",11);
legend("boxoff");
grid on
print -depsc plot1.eps #Figure in color eps format 
#-------------------------------------------------------------
