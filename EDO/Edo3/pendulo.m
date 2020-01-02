
###==================== PROGRAM ============================
# Program:pendulo.m 
# Description: Solve Pendulum  
# Date of Create:  sex 29 nov 2019 16:49:23 
# Update in: sex 29 nov 2019 16:49:27 -03
# Author:Jeffrey
#-----------------------------------------------------------

###================= Clean enviromment =====================
clc
clear
#----------------------------------------------------------- 

g=9.81;
d=1;

f=@(x) [x(3); -g/d*sin(x(2))];
y0=[pi/3;0];
x0=0;
h = 0.01;
N = 100;

[x y] = Runge4(f,x0,y0,h,N);

plot(x,y(1,:))

