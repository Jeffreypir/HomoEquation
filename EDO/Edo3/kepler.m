
###==================== PROGRAM ============================
# Program:kepler.m 
# Description: Solve Kepler 
# Date of Create:  sex 29 nov 2019 16:49:23 
# Update in: sex 29 nov 2019 16:49:27 -03
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------

###================= Clean enviromment =====================
clc
clear
#----------------------------------------------------------- 

G = 1;
M = 1;


f=@(x) [x(4);x(5);(((x(2)^2 + x(3)^2)^(-3/2)))*[-x(2);-x(3)]];
y0=[0;1;0;0];
x0=0;
h = 0.1;
N = 100;

[x y] = Runge4(f,x0,y0,h,N);

### =========== Plotting =====================================
#color b for blue, '.' for point, + is type of symbol   
plot(y(1,:),y(2,:))
title('Kepler');
xlabel('Axis (x)');
ylabel('Axis (y)');
h = legend("Metodo de Runge Kutta 4");
set(h,"fontsize",11);
legend("boxoff");
grid on
#print -depsc k3.eps #Figure in color eps format 
#-------------------------------------------------------------

