#include <stdio.h>
#include <stdlib.h>
#define GNUPLOT "gnuplot -persist"   
#include <math.h> 
#define EXIT_SUCESS 0


/*===========================================================
 * Program: edo.c
 * Description:Problem of value initial
 * Date: 03 de Out 
 * Update in: O3 de Out 17:19
 * Author: Jefferson Bezerra dos Santos
 * Compiler: gcc -lm edo.c -o edo.c
 *===========================================================
 */

/*=================== PVI ===================================
 *                   y' = - y + x +2
 *                   y(0) = 2 
 *                   x in [0, 0.3]
 *
 *                   Analytic solution:
 *                y(x)= exp(-x) + x + 1 
 *
 *                   Aproximation:
 *                f = y' = -y + x + 2 
 *                f'  = y - x - 1
 *                f'' = -y + x + 1
 *                   Taylor:
 *         y(n+1) = yn + h*fn + (h^2/n)*f'n +  (h^3/n)*f''n 
 *===========================================================
 */

/*===========================================================
 * Function: SolAna()
 * Description: Analytic solution
 *===========================================================
 */

/*===========================================================
 * Function: fatorial()
 * Description: Fatorial de um número sem recursividade usando
 * decremento
 *===========================================================
 */
unsigned int fatorial(unsigned int n){
	unsigned int i = ++n,fator = 1;
   	while (--i) {fator *= i;} return fator;
}/*---------End of function-------------*/


float SolAna(float x){  
		 return (exp(-x)+ x + 1);
}/*---------End of function-------------*/


/*============================================================
 * Function:EdoAna()
 * Description:ODE Analytic
 *============================================================
 */
void EdoAna(float *dados){
	 int N = dados[3];
	 float x[N+1], y[N+1],h = (dados[1]-dados[0])/dados[3];
	 x[0] = dados[0], y[0] = dados[2];
	 for (int i = 0; i < N; i++){
		 x[i+1] = x[i] + h;
		 y[i+1] = SolAna(x[i+1]);
	 }

	 FILE *ptg;
	 ptg = fopen("analytic6.txt","w");
	 for (int i = 0; i <= N; i++){
		 fprintf(ptg,"%f   %f\n",x[i],y[i]);
	 }
	 fclose(ptg);
}/*---------End of function-------------*/

/*============================================================
 * Function: OneDev()
 * Description: One derivate (f)
 *============================================================
 */
float OneDev(float x, float y){
		 return (-y + x + 2);
}/*---------End of function-------------*/

/*============================================================
 * Function: TwoDev()
 * Description: Two derivate (f')
 *============================================================
 */
float TwoDev(float x, float y){
		 return (y - x - 1);
}/*---------End of function-------------*/

/*============================================================
 * Function: TreeDev()
 * Description: Tree derivate (f'')
 *============================================================
 */
float TreeDev(float x, float y){
		 return (-y + x + 1);
}/*---------End of function-------------*/

/*============================================================
 * Function:EdoNum()
 * Description:ODE numeric
 *============================================================
 */
void EdoNum(float *dados){
	 unsigned int N = dados[3];
	 float x[N+1], y[N+1],h = (dados[1]-dados[0])/dados[3];
	 x[0] = dados[0], y[0] = dados[2];
	 for (int i = 0; i < N; i++){
		 x[i+1] = x[i] + h;
		 y[i+1] = y[i] + h*OneDev(x[i],y[i]) + ((h*h)/fatorial(2))*TwoDev(x[i],y[i]) + ((h*h*h)/fatorial(3))*(TreeDev(x[i],y[i]));
	 }

	 FILE *ptg;
	 ptg = fopen("numeric6.txt","w");
	 for (int i = 0; i <= N; i++){
		 fprintf(ptg,"%f   %f\n",x[i],y[i]);
	 }
	 fclose(ptg);
}/*---------End of function-------------*/

/*===========================================================
 * Function: main()
 * Description: Call of function EdoAna()
 * ==========================================================
 */
int main(int argc, char *argv[]){
	float dados[4];
	dados[0] = atof(argv[1]);
	dados[1] = atof(argv[2]);
	dados[2] = atof(argv[3]);
	dados[3] = atof(argv[4]);
	EdoAna(dados);
	EdoNum(dados);
	FILE *gp;
	gp = popen(GNUPLOT, "w");
	fprintf(gp,"set title 'Solution EDO' \n");
	fprintf(gp,"set xlabel 'Axis (x)'\n");
	fprintf(gp,"set ylabel 'Axis (y)'\n");
	fprintf(gp,"set key right bottom \n");
	fprintf(gp,"set term pdf \n");
	fprintf(gp,"set output 'plot6.pdf'\n");
	fprintf(gp,"plot 'analytic6.txt' using 1:2 with points lc 6 pt 6 ps 0.4 t'Analitic solution','numeric6.txt' using 1:2  with points lc 7 pt 6 ps 0.4 t'Numeric solution \n");
    fclose(gp);
			
	system("zathura plot6.pdf & ");
	return EXIT_SUCESS;
}/*----------End of function-----------------*/
