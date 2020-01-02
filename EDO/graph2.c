#include <stdio.h>
#include <stdlib.h>
#define GNUPLOT "gnuplot -persist" 

int main (void){
		FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"set title 'Análise da EDO' \n");
		fprintf(gp,"set xlabel 'Eixo x'\n");
		fprintf(gp, "set ylabel 'Eixo y'\n");
		fprintf(gp,"set term pdf \n");
		fprintf(gp,"set output 'saida.pdf'\n");
		fprintf(gp,"plot 'plotando.txt' t'EDO' with lines \n");
		fclose(gp);
		return 0;
}

