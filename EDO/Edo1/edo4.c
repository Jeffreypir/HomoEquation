#include "edo4.h"
void EdoNum(double *Dados){
		int N = (*(Dados + 3));
		float y[N+1];
		float x[N+1];
		float h = (*(Dados + 1) - (*Dados))/((float) N);
		x[0] = (*Dados);
		y[0] = (*(Dados + 2));


		for (int i = 0;i < N;i++){
				y[i+1] = y[i] + (h/(A(x[i])))*((C(x[i])) - (B(x[i]))*y[i]);
				x[i+1] = x[i] + h;
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
		for (int i = 0;i < N;i++){
				x[i+1] = x[i] + h;
				y[i+1] = 4*((x[i+1])*(x[i+1])) - 3*(x[i+1]);
		}	

		FILE *ptg;
		ptg = fopen("analitico.txt","w");
		for (int i = 0;i <= N;i++){
				fprintf(ptg,"%f  %f\n",x[i],y[i]);
		}
		fclose(ptg);
}

int main(int argc, char *argv[]){
		double Dados[4];//x0,xf,y0
		Dados[0] = atof(argv[1]);
		Dados[1] = atof(argv[2]);
		Dados[2] = atof(argv[3]);
		Dados[3] = atof(argv[4]);

		EdoNum(Dados);
		EdoAna(Dados);
		FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"set title 'Solution EDO' \n");
		fprintf(gp,"set xlabel 'Axis (x)'\n");
		fprintf(gp,"set ylabel 'Axis (y)'\n");
		fprintf(gp,"set key right bottom \n");
		fprintf(gp,"set term pdf \n");
		fprintf(gp,"set output 'plot4.pdf'\n");
		fprintf(gp,"plot 'analitico.txt' using 1:2 with points lc 6 pt 6 ps 0.4 t'Analitic solution','numerico.txt' using 1:2  with points lc 7 pt 6 ps 0.4 t'Numeric solution \n");
		fclose(gp);
		
		system("zathura plot4.pdf & ");

		return EXIT_SUCCESS;
}

