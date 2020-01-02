# include "edo4.h"
void edo1(double *Dados){
		float y[N+1];
		float h = (*(Dados + 1) - (*Dados))/((float) N);
		float x[N+1];
		x[0] = (*Dados);
		y[0] = (*(Dados + 2));

		for (int i = 0;i < N;i++){
				y[i+1] = y[i] + (h/(A(x[i])))*((C(x[i])) - (B(x[i]))*y[i]);
				x[i+1] = x[i] + h;
		}
		
		FILE *ptg;
		ptg = fopen("plotando4.txt","w");
		for (int i = 0;i <= N;i++){
				fprintf(ptg,"%f  %f\n",x[i],y[i]);
		}
		fclose(ptg);
		}

int main(int argc, char *argv[]){
		double Dados[3];//x0,xf,y0
		Dados[0] = atof(argv[1]);
		Dados[1] = atof(argv[2]);
		Dados[2] = atof(argv[3]);

		edo1(Dados);
		FILE *gp;
		gp = popen(GNUPLOT, "w");
		fprintf(gp,"set title 'Solution EDO' \n");
		fprintf(gp,"set xlabel 'Axis (x)'\n");
		fprintf(gp,"set ylabel 'Axis (y)'\n");
		fprintf(gp,"set term pdf \n");
		fprintf(gp,"set output 'plot4.pdf'\n");
		fprintf(gp,"plot 'plotando4.txt' using 1:2 with points pt 6 t'EDO");
		fclose(gp);
		
		system("zathura plot4.pdf & ");

		return EXIT_SUCCESS;
}

