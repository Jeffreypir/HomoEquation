#include <stdio.h>
#include <stdlib.h>
#define GNUPLOT "gnuplot -persist"   
#define EXIT_SUCESS 0

/*==================== PROGRAM ==============================
 * Program: <+name+>
 * Description: <+description+>
 * Date of Create: <+date+>
 * Update in: <+update+>
 * Author:Jefferson Bezerra dos Santos
 *===========================================================
 */


/*=================== FUNCTION MAIN () ======================
 * Function: main()
 * Description: <+description+>
 * ==========================================================
 */
int main(void){
		return EXIT_SUCESS;
}/*----------End of function-----------------*/
int main(void){
		FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"set title 'Análise da EDO' \n");
		fprintf(gp,"set xlabel 'Eixo x'\n");
	pfprintf(gp, "set ylabel 'Eixo y'\n");
		fprintf(gp,"plot 'dados.txt' using 1:2 with lines t'EDO\n");
		fclose(gp);

	//	system("zathura plot.pdf & ");


