#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct ponto{
	float x,y;
}Ponto;

float distancia(Ponto a, Ponto b);
void troca(int *x, int *y);
void troca2(float *x, float *y);
int fator(int *a, int n);
int somaprod(int *a, int *b, int c, int d);

int somaprod(int *a, int *b, int c, int d){
	*a = c + d;
	*b = c * d;
}

int fator(int *a, int n){
	int i, f = 1;
	for(i = 1; i <= n; i++){
		f *= i;
	}
	*a = f;
}

void troca(int *x, int *y){
	int aux;
	aux = *x;
	*x = *y;
	*y = aux;
}
void troca2(float *x, float *y){
	float aux;
	aux = *x;
	*x = *y;
	*y = aux;
}
float distancia(Ponto a, Ponto b){
	float py, px, c;
	py = pow((b.y - a.y),2);
	px = pow((b.x - a.x), 2);
	c = sqrt(px+py);
	return c;
}


/*
void displayArray(int *q[]){
	int t;
	for(t = 0; t <//tamaho da matriz; t++){
		printf("%d", *q[t]); //imprime o conteúdo de cada item q[]
	}


*/
