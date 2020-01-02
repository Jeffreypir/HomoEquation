# include <stdio.h>
# include <stdlib.h>
# define N 100
# define A(x) x*x
# define B(x) -x
# define C(x) 4*x*x*x
# define GNUPLOT "gnuplot -persist" 

void edo1(double *Dados){
		float y[N];
		float h = (*(Dados + 1) - (*(Dados)))/N;
		float x[N];
		x[0] = (*(Dados));
		y[0] = (*(Dados + 2));

		for (unsigned int i = 0; i < N-1; i++){
				y[i+1] = y[i] + (h/(A(x[i])))*((C(x[i])) - (B(x[i]))*y[i]);
				x[i+1] = x[i] + h;
		}
		
		FILE *ptg;
		ptg = fopen("plotando3.txt","w");
		for (unsigned int i = 0; i < N;i++){
				fprintf(ptg,"%f  %f\n",x[i],y[i]);
		}
		fclose(ptg);
		}

int main(void){
		double Dados[] = {1,3,1};//x0,xf,y0
		edo1(Dados);
		FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"set title 'Análise da EDO' \n");
		fprintf(gp,"set xlabel 'Eixo x'\n");
		fprintf(gp, "set ylabel 'Eixo y'\n");
		fprintf(gp,"plot 'plotando3.txt' using 1:2 with lines t'EDO\n");
		fclose(gp);

	//	system("zathura plot.pdf & ");

		return 0;
}

