###===================== PROGRAM =============================
# Program: teste3.m
# Description: Plot of solutions analytic and numeric
# Date of Create: seg 21 out 2019 12:29:08
# Update in: ter 22 out 2019 15:06:37
# Author:Jefferson Bezerra dos Santos
#-------------------------------------------------------------

###============= Clear enviromment ===========================
clc
clear
#-------------------------------------------------------------

###================ Defining auxiliary functions =============
f = @(x,y) y/(1 + 3*x);#Order derivative 0
f1 = @(x,y) -2*y/((1 + 3*x)^2);#Order derivative 1
f2 = @(x,y) 10*y/((1 + 3*x)^3);;#Order derivative 2
#-------------------------------------------------------------

###=== Euler method, paramenters(f,x0,y0,h,N) ===============
[x,y] = euler(f,0, 2,1.0,10);
#-------------------------------------------------------------

### ===== Taylor method, paramenters(f,f1,f2,x0,y0,h,N) ======
[x1,y1] = taylor3(f,f1,f2,0,2,1.0,10);
#-------------------------------------------------------------

###=== Midpoint method, paramenters(f,x0,y0,h,N) =============
[x2,y2] = ponto_medio(f,0, 2,1.0,10);
#-------------------------------------------------------------

###=== Adams method, paramenters(f,x0,y0,h,N) ================
[x3,y3] = adams_bashforth(f,0, 2,1.0,10);
#-------------------------------------------------------------

###===== Solution analytic, paramenters(x0,y0,h,N) ===========
[x4,y4] = analitica2(0, 2,1.0,10);
#-------------------------------------------------------------

### =========== Plotting =====================================
#color b for blue, '.' for point, + is type of symbol   
plot(x,y,'b.+',x1,y1,'r.x',x2,y2,'g.*',x3,y3,'y.r',x4,y4,'m.o'); 
title('Solution of ODE');
xlabel('Axis (x)');ylabel('Axis (y)');
legend("Euler method","Taylor method","Mitpoint method","Adams method","Analytic solution","location","northwest");
legend("boxoff");
text(4,15.5,"y'(x)= y(x)/(1 + 3x)");#Text in plot
text(4,15.0,"Analytic solution is:");
text(4,14.5,'{y(x) = 2(1 + 3x)^{1/3}}');
text(4,14.0,"for y(0) = 2");
grid on
print -depsc plot4.eps #Figure in color eps format 
#-------------------------------------------------------------
