ainclude <stdio.h>
#include <stdlib.h>
#define GNUPLOT "gnuplot -persist"

/*==================== PROGRAM ==============================
 * Program: plotagem.ci 
 * Description: plot do triângulo e do ponto 
 * Date of Create: ter 12 nov 2019 11:49:50
 * Update in: ter 12 nov 2019 11:49:59 -03
 * Author:Jefferson Bezerra dos Santos
 *===========================================================
 */


/*=================== FUNCTION MAIN () ======================
 * Function: main()
 * Description: Carregar o gnuplot 
 * ==========================================================
 */
int main(void){
		FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"set title 'Ponto interiora ao triângulo \n");
		fprintf(gp,"set xlabel 'Eixo x'\n");
		fprintf(gp, "set ylabel 'Eixo y'\n");
		fprintf(gp, "set xrange [-2:2]\n");
		fprintf(gp, "set yrange [-2:2]\n");
		fprintf(gp, "set style data linespoints\n");
		fprintf(gp, "plot 'dados.txt' using 1:2 title 'Triângulo'\n");
		fprintf(gp, "replot 'dados1.txt' using 1:2 pt 3 title 'ponto P(1,1)'\n");
		fclose(gp);
		return 0;
}

