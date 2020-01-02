# include <stdio.h>
# include <stdlib.h>
# define GNUPLOT "gnuplot -persist" 

void edo1(float *Dados);
int main(int argc, char *argv[]){
		float Dados[] = {1,3,1};//x0,xf,y0
		edo1(Dados);
		FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"set title 'Análise da EDO' \n");
		fprintf(gp,"set xlabel 'Eixo x'\n");
		fprintf(gp, "set ylabel 'Eixo y'\n");
		fprintf(gp,"set term pdf \n");
		fprintf(gp,"set output 'plot.pdf'\n");
		fprintf(gp,"plot 'plotando3.txt' using 1:2 with lines t'EDO");
		fclose(gp);

		system("zathura plot.pdf & ");

		return 0;
}


