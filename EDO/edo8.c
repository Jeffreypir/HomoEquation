#include <stdio.h>
#include <stdlib.h>
#define GNUPLOT "gnuplot -persist"   
#include <math.h> 
#define EXIT_SUCESS 0


/*=================== PROGRAM ================================
 * Program: edo8.c
 * Description:Problem of value initial
 * Date: 04 de Out 
 * Update in: O4 de Out 09:24
 * Author: Jefferson Bezerra dos Santos
 * Compiler: gcc -lm edo8.c -o edo8.c
 *============================================================
 */
/*=================== FUNCTION ===============================
 * Function: SolAna()
 * Description: Analytic solution
 *============================================================
 */
float SolAna(float x){  
	float a = ((float)(2))/((float)(3));
		 return (pow(a*x,(((float)(3))/((float)(2)))));
}/*---------End of function-------------*/

/*===================== FUNCTION =============================
 * Function: OneDev()
 * Description: One derivate (f)
 *============================================================
 */
float OneDev(float y){
		 return ((pow(y,(((float)(1))/((float)(3))))));
}/*---------End of function-------------*/

/*======================= FUNCTION ===========================
 * Function:Ode()
 * Description:ODE Analytic and Numeric
 *============================================================
 */
void Ode(float *dados){
	 unsigned int N = dados[3];
	 float x[N+1], y1[N+1],y2[N+1],h = (dados[1]-dados[0])/dados[3];
	 x[0] = dados[0], y1[0] = dados[2],y2[0] = dados[2];
	 for (int i = 0; i < N; i++){
		 x[i+1] = x[i] + h;
		 y1[i+1] = SolAna(x[i+1]);
		 y2[i+1] = y2[i] + h*OneDev(y2[i]);
	 }

	 FILE *ptg;
	 ptg = fopen("dados8.txt","w");
	 for (int i = 0; i <= N; i++){
		 fprintf(ptg,"%f		    %f 		     %f 		  %f\n",x[i],y1[i],x[i],y2[i]);
	 }
	 fclose(ptg);
}/*---------End of function-------------*/

/*====================== FUNCTION MAIN () ====================
 * Function: main()
 * Description: Call of function Ode)
 * ===========================================================
 */
int main(int argc, char *argv[]){
	float dados[4];
	dados[0] = atof(argv[1]);
	dados[1] = atof(argv[2]);
	dados[2] = atof(argv[3]);
	dados[3] = atof(argv[4]);

	Ode(dados);

	FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"set title 'Solution of ODE' \n");
		fprintf(gp,"set xlabel 'Axis (x)'\n");
		fprintf(gp,"set ylabel 'Axis (y)'\n");
		fprintf(gp,"set key right bottom \n");
		fprintf(gp,"plot 'dados8.txt' using 1:2 with points lc 6 pt 1 ps 0.4 t'Analytic solution','dados8.txt' using 3:4  with points lc 7 pt 6 ps 0.4 t'Numeric solution \n");
    fclose(gp);
			
	return EXIT_SUCESS;
}/*----------End of function-----------------*/
