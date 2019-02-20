#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>
typedef struct ponto Ponto;
struct ponto{
	float x, y;
};

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

Ponto * alocar(int n){
	Ponto * aux; //define uma variável aux do tipo Ponto.
	aux = (Ponto*)malloc(n*sizeof(Ponto)); //define aux como um vetor de structs tipo Ponto, com n structs.
	return aux; //retorna aux.
}

void preencher(int n, Ponto * p){
	int i;
	float x, y;
	for(i = 0; i < n; i++){ //pega os valores x e y de cada struct, que representa os pontos de um polígono.
		printf("\nDigite x[%d]: ", i);
		scanf("%f", &p[i].x); //p[i].x representa cada x de cada ponto, de n 0 até o final do vetor.
		printf("\nDigite y[%d]: ", i);
		scanf("%f", &p[i].y); //o mesmo se aplica a y.
	}
}

float area(int n, Ponto * p){
	int i, j;
	float a = 0;
	for(i = 0; i<n; i++){
		j = (i+1)%n;
		a += (p[j].x-p[i].x)*(p[i].y+p[j].y)/2;
	}
	return fabs(a);
}

int main(){
	pthue();
	int num;
	float A;
	Ponto * p;
	printf("digite o numero de pontos do polígono ");
	scanf("%d", &num);
	p = alocar(num); //p vai ser igual a aux, que por sí é um vetor de structs de tamanho num.
	preencher(num, p); //chama a função pra preencher p
	A = area(num, p); //calcula a área do polígono P
	printf("\narea = %f", A); //por alguma razão jogar area(num,p) no lugar de criar uma variável pra mostrar não funcionou.
}
