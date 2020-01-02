#include <stdio.h>
# define N 100000

//Definindo funcoes auxiliares

float a(float x){
		return (x*x);
}

float b(float x){
		return (-x);
}

float c(float x){
		return (4*x*x*x);
}

void edo1(float xo, float xf, float yo){
		float y[N];
		float h = ((xf - xo)/((float) N));
		float x[N];
		x[0] = 1;
		y[0] = 2;

		printf("%f %f\n",x[0],y[0]);
		printf("%f\n",h);
		for (int i = 0; i < N-1; i++){
				x[i+1] = x[i] + h;
				y[i+1] = y[i] + (h/a(x[i]))*(c(x[i]) - b(x[i])*y[i]);
		}
		printf("%f %f\n",x[0],y[0]);

		for (int i = 0; i < N-1; i++){
				FILE *ptg;
				ptg = fopen("plotando.txt","a");
				fprintf(ptg,"%f     %f\n",x[i],y[i]);
				fclose(ptg);
		}

		}


int main(void){
		edo1(1,3,1);
		return 0;
}


