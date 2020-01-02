#include <stdio.h>

//Definindo funcoes auxiliares

float a(float x){
		return (x*x);
}

float b(float x){
		return -x;
}

float c(float x){
		return 4*x*x*x;
}

void edo1(int n, float x0, float xf, float y0){
		float y[10];
		float h = (xf - x0)/n;
		float x[10];
		x[0] = x0;
		y[0] = y0;

		for (int i = 0; i<= 10; i++){
				x[i+1] = x[i] + h;
		}

		for (int k = 0; k<= 10; k++){
				y[k+1] = y[k] + (h/a(x[k]))*(c(x[k]) - b(x[k])*y[k]);

		}
		for (int j = 0; j <= 10; j++){
				printf("%f\n",y[j]);
		}
		}


int main(void){
		edo1(10,1,3,1);
		return 0;
}


