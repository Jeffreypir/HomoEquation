#include "edo2.h"
void EdoNum(double *Dados){
		int N = (*(Dados + 3));
		float y[N+1];
		float x[N+1];
		float h = (*(Dados + 1) - (*Dados))/((float) N);
		x[0] = (*Dados);
		y[0] = (*(Dados + 2));
		float k = (*(Dados + 4));//Constant of proportion
		float g = (*(Dados + 5));//gravity
		float m = (*(Dados + 6));//body mass

		if (k >= 0){
				for (int i = 0;i < N;i++){
						y[i+1] = y[i] + (h/(A(m)))*((C(m*g)) - (B(k))*y[i]);
						x[i+1] = x[i] + h;
				}
		}else{
				printf("Erro fatal k < 0, abortando\n");
				exit(1);
		}
		
		FILE *ptg;
		ptg = fopen("numerico.txt","w");
		for (int i = 0;i <= N;i++){
				fprintf(ptg,"%f  %f\n",x[i],y[i]);
		}
		fclose(ptg);
		}

void EdoAna(double *Dados){
		int N = (*(Dados + 3));
		float y[N+1];
		float x[N+1];
		float h = (*(Dados + 1) - (*Dados))/((float) N);
		x[0] = (*Dados);
		y[0] = (*(Dados + 2));
		float k = (*(Dados + 4));//Constant of proportion
		float g = (*(Dados + 5));//gravity
		float m = (*(Dados + 6));//body mass

		if (k > 0){
				for (int i = 0;i < N;i++){
						x[i+1] = x[i] + h;
						y[i+1] = (m*g/k)*(1 - (exp((-k*(x[i+1]))/m)));
				}
		}else if (k==0){
				for (int i = 0;i < N;i++){
						x[i+1] = x[i] + h;
						y[i+1] = g*(x[i+1]);
				}
		}else{
				printf("Erro fatal k < 0, abortando\n");
				exit(1);
		}	

		FILE *ptg;
		ptg = fopen("analitico.txt","w");
		for (int i = 0;i <= N;i++){
				fprintf(ptg,"%f  %f\n",x[i],y[i]);
		}
		fclose(ptg);
}

void grava(float k){
		FILE *ptk;
		ptk = fopen("k.txt","w");
		fprintf(ptk," k = %.2f\n",k);
		fclose(ptk);


}

int main(int argc, char *argv[]){
		double Dados[7];//x0,xf,y0
		Dados[0] = atof(argv[1]);//x0
		Dados[1] = atof(argv[2]);//xf
		Dados[2] = atof(argv[3]);//y0
		Dados[3] = atoi(argv[4]);//number of elements
		Dados[4] = atof(argv[5]);//k
		Dados[5] = atof(argv[6]);//gravity
		Dados[6] = atof(argv[7]);//Massa do corpo

		grava(Dados[4]);
		EdoNum(Dados);
		EdoAna(Dados);
		FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"terra = 10 \n");
		fprintf(gp,"set title 'ODE solution'\n");
		fprintf(gp,"set xlabel 'Time (t)'\n");
		fprintf(gp,"set ylabel 'Velocity (v)'\n");
		fprintf(gp,"terra = 10\n");
		fprintf(gp,"set label system ('cat k.txt') at graph 0.65,0.225 left \n"); 
		fprintf(gp,"set key right bottom \n");
		fprintf(gp,"set term pdf \n");
		fprintf(gp,"set output 'plot.pdf'\n");
		fprintf(gp,"plot 'numerico.txt' using 1:2 with points lc 6 pt 6 ps 0.4 t'Numeric solution','analitico.txt' using 1:2 with points lc 7 pt 6 ps 0.4 t'Analitic solution' \n");
		fclose(gp);
		
		system("zathura plot.pdf & ");

		return EXIT_SUCCESS;
}

