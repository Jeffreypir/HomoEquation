#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define GNUPLOT "gnuplot -persist" 
#define EXIT_SUCESS 0

/*===========================================================
 * Function: fatorial()
 * Description: Fatorial de um número sem recursividade usando
 * decremento
 *===========================================================
 */
unsigned long long int fatorial(unsigned int n){
	unsigned long long int i = ++n,fator = 1;
   	while (--i) {fator *= i;} return fator;
}/*---------End of function-------------*/

/*============================================================
 * Function:OneDer()
 * Description: Primeira derivada
 *============================================================
 */
float OneDer(float x, float y){ 
		 return (-y + x + 2) ;
}/*---------End of function-------------*/

/*============================================================
 * Function:TwoDer()
 * Description: Segunda derivada
 *============================================================
 */
float TwoDer(float x, float y){ 
		 return (y - x - 1) ;
}/*---------End of function-------------*/

/*============================================================
 * Function:TwoDer()
 * Description: Terceira derivada
 *============================================================
 */

float ThreeDev(float x, float y){ 
		 return (-y + x + 1) ;
}/*---------End of function-------------*/


/*=============================================================
 * Function:EdoAna
 * Description: edo analitica
 *=============================================================
 */

void EdoAna(double *dados){
	 int N = dados[3];
	 float x[N+1],y[N+1];
	 float h = (dados[1]-dados[0])/(float) N;
	 x[0] = dados[0]; y[0] = dados[2];
	 for (int i = 0; i < N; i++){
		 x[i+1] = x[i] + h; 
		 y[i+1] = (1/exp(x[i+1])) + x[i+1] + 1;  
	 }

	 FILE *ptg;
	 ptg = fopen("analitica5.txt","w");
		 for (int i = 0; i <= N; i++){
			 fprintf(ptg,"%f   %f\n",x[i],y[i]);
		 }
	 fclose(ptg);
}/*---------End of function-------------*/

void EdoNum(double *dados){
	 int N = dados[3];
	 float x[N+1],y[N+1],h = (dados[1]-dados[0])/(float) N;
	 x[0] = dados[0]; y[0] = dados[2];
	 for (int i = 0; i < N; i++){
		 x[i+1] = x[i] + h; 
		 y[i+1] = y[i] + h*(OneDer(x[i],y[i])) + ((h*h)/fatorial(2))*(TwoDer(x[i],y[i])) + ((h*h*h)/fatorial(3))*(ThreeDev(x[i],y[i]));  
	 }

	 FILE *ptg;
	 ptg = fopen("numerica5.txt","w");
		 for (int i = 0; i <= N; i++){
			 fprintf(ptg,"%f   %f\n",x[i],y[i]);
		 }
	 fclose(ptg);
}/*---------End of function-------------*/


/*===========================================================
 * Function: main()
 * Description: Solução da EDO 
 * ==========================================================
 */

int main(int argc, char *argv[]){
	double dados[4];
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
		fprintf(gp,"set output 'plot5.pdf'\n");
		fprintf(gp,"plot 'analitica5.txt' using 1:2 with points lc 6 pt 6 ps 0.4 t'Analitic solution','numerica5.txt' using 1:2  with points lc 7 pt 6 ps 0.4 t'Numeric solution \n");
		fclose(gp);
		
		system("zathura plot5.pdf & ");
		return EXIT_SUCESS;
}/*----------End of function-----------------*/
