#include <stdlib.h>
#include <stdio.h>
#include <math.h>
typedef struct ponto Ponto;
struct ponto{
	float x, y;
};

Ponto * alocar(int n){
	Ponto * aux;
	aux = (Ponto*)malloc(n*sizeof(Ponto)); //define aux como um vetor de structs tipo Ponto, com n structs.
	return aux;
}

void preencher(int n, Ponto * p){
	int i;
	float x, y;
	Ponto * aux;
	for(i = 0; i < n; i++){ //pega os valores x e y de cada struct.
		printf("\nDigite x[%d]: ", i);
		scanf("%f", &p[i].x);
		printf("\nDigite y[%d]: ", i);
		scanf("%f", &p[i].y);
	}
}

float area(int n, Ponto * p){
	int i;
	float a = 0;
	for(i = 0; i<n; i++){
		a += (p[i+1].x-p[i].x)*(p[i+1].y+p[i].y)/2;
	}
	return fabs(a);
}

int main(){
	int num;
	float A;
	Ponto * p;
	printf("digite o numero de pontos do polígono ");
	scanf("%d", &num);
	p = alocar(num);
	preencher(num, p);
	A = area(num, p);
	printf("\narea = %0.2f", A);
}
