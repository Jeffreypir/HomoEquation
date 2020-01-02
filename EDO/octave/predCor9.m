###==================== PROGRAM ============================
# Program:predCor9.m
# Description: Solve ODE numeric by the Previsor Corretor
# Date of Create: qui 31 out 2019 14:19:13 
# Update in:  qui 31 out 2019 14:19:24
# Author:Jefferson Bezerra dos Santos
#-----------------------------------------------------------
### ============================ Clear enviromment ============================
clear
clc
#------------------------------------------------------------------------------

###============ Metodo do Previsor Corretor =================
#================ Parametros ================================
tol = <+defina a tol+>;
h = <+ defina o passo+>;
xo = <+ defina o xo+>;
xf = <+ defina o xf+>;
y(1) = <+ defina o y0+>;
x = xo:h:xf;# Vetor x 
f = @(x,y) y - x + 2;# Derivada
y(2) = y(1)+ h*f(x(1),y(1));# Aproxima de yn+1 por Euler 
#------------------ Fim dos parametros ----------------------
###=============== Funcao anilitica ===========================
anali = @(x) <+ defina a funcao analitica+>;
#--------------------------------------------------------------

###================== Iniciando o loop ========================
i = 0;
while ((++i) < (length(x)-1))
        ym = y(i);#ym variavel auxiliar
        yn = y(i+1);#yn variavel auxiliar
    while (1)
        ymj = yn + (h/2)*((f(x(i),ym)) + 3*f(x(i+1),yn));#Previsor, adams
        aux = f((x(i+1)),ymj);# f
        ynj = ym + (h/3)*(f(x(i),ym) + 4*(f(x(i+1),yn)) + aux);#Corretor,simp
        if(abs(ynj-ymj) < tol)# Verificando tolerancia
            y(i+2) = ynj;
            break;
        else
            ym = yn;# Atualizando para a proxima iteracao
            yn = ynj;# Atualizando para a proxima iteracao 
        endif
    endwhile
endwhile
#-------------------- fim do laco -----------------------------
###============ Preenchimento do vetor y solucao analitica====
i = 0;
while ((++i) <= (length(x)))
    y1(i) = anali(x(i));
endwhile
#------------------------------------------------------------

###================= Aplicando a funcao =====================
[x2,y2] = adamsbs (xo,xf,yo,h,f); 
#-------------------------------------------------------------

###==================== Plotagem ============================
plot(x,y,'b.+',x,y1);
legend("previsor-corretor", "analitica", "adams");
#------------------------------------------------------------
