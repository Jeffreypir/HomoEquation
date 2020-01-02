###===================== PROGRAM =============================
# Program: teste2.m
# Description: Plot of solutions analytic and numeric
# Date of Create: dom 20 out 2019 13:41:49 -03
# Update in: dom 20 out 2019 13:43:51 -03
# Author:Jeffrey
#-------------------------------------------------------------

###============= Clear enviromment ===========================
clc
clear
#-------------------------------------------------------------

###================ Defining auxiliary functions =============
f = @(x,y) y - x + 2;#Order derivative 0
f1 = @(x,y) y - x + 1;#Order derivative 1
f2 = @(x,y) y - x + 1;#Order derivative 2
#-------------------------------------------------------------

###=== Euler method, paramenters(f,x0,y0,h,N) ================
[x,y] = euler(f,0, 2,0.1,50,f1);
#-------------------------------------------------------------

### ===== Taylor method, paramenters(f,f1,f2,x0,y0,h,N) ======
[x1,y1] = taylor3(f,f1,f2,0, 2,0.1,50);
#-------------------------------------------------------------

###=== Midpoint method, paramenters(f,x0,y0,h,N) =============
[x2,y2] = ponto_medio(f,0, 2,0.1,50);
#-------------------------------------------------------------

###=== Adams method, paramenters(x0,y0,h,N,f1) ===============
[x3,y3] = adams_bashforth(f,0, 2,0.1,50);
#-------------------------------------------------------------

###===== Solution analytic, paramenters(x0,y0,h,N) ===========
[x4,y4] = analitica(0, 2,0.1,50);

### =========== Plotting =====================================
#color b for blue, '.' fir point, + is type of symbol   
plot(x,y,'b.+',x1,y1,'r.x',x2,y2,'g.*',x3,y3,'y.r',x4,y4,'m.o'); 
title('Solution of ODE');
xlabel('Axis (x)');
ylabel('Axis (y)');
h = legend("Euler method","Taylor method","Midpoint method","Adams method","Analytic solution","location","northwest");
set(h,"fontsize",11);
legend("boxoff");
text(2,480,"y'(x)= y(x) - x + 2");
grid on
print -depsc plot2.eps #Figure in color eps format 
#-------------------------------------------------------------
