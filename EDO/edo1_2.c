#include <stdio.h>
# define N 100
# define A(x) x*x
# define B(x) -x
# define C(x) 4*x*x*x

void edo1(float *Dados){
		float y[N];
		float h = (Dados[1] - Dados[0])/N;
		float x[N];
		x[0] = Dados[0];
		y[0] = Dados[2];

		printf("%f\n",y[0]);
		for (unsigned int i = 0; i<= N-1; i++){
				FILE *ptg;
				ptg = fopen("plotando2.txt","a");
				fprintf(ptg,"%f     %f\n",x[i],y[i]);
				fclose(ptg);

				y[i+1] = y[i] + (h/(A(x[i])))*((C(x[i])) - (B(x[i]))*y[i]);
				x[i+1] = x[i] + h;
		}
		printf("%f\n",y[0]);
		}

int main(void){
		float Dados[] = {1,3,1};//x0,xf,y0
		edo1(Dados);
		return 0;
}

