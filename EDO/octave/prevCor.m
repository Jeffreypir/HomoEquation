###========================== clear ennviromment =======================
clear
clc
#-----------------------------------------------------------------------

###=============== Parameters ==========================================
tol = 1e-3;
h = 0.01;
xo = 0.2;
xf = 0.3;
y(1) = 2;
x = xo:h:xf; 
f = @(x,y) -y + x + 2;
y(2) = 2.0048;  
#----------------------------------------------------------------------------------

### ======================== function ============================
anali = @(x) exp(-x) + x + 1;
#------------------------------ End function ---------------------

# loop 
i = 0;
while ((++i) < (length(x)-1))
        ym = y(i);
        yn = y(i+1);
    while (1)
        ymj = yn + (h/2)*((3*f(x(i+1),yn)) + f(x(i),ym));
        aux = f((x(i+1)),ymj);
        ynj = ym + (h/3)*(f(x(i),ym) + 4*(f(x(i+1),yn)) + aux);
        if(abs(ynj-ymj) < tol)
            y(i+2) = ynj;
            break;
        else
            ym = yn;
            yn = ynj;
        endif
    endwhile
endwhile
i = 0;
while ((++i) <= (length(x)))
    y1(i) = anali(x(i));
endwhile

#plotagem 
plot(x,y,'b.+',x,y1,'r.x');
legend("num, ana");
