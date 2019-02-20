#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>

int gerar(int tamanho){
	int i, x;
	int *y = (int*)malloc(sizeof(int)*tamanho);
	time_t t;
	for(i = 0; i< tamanho; i++){
		x = rand();
		y[i] = x;
	}
	return y;
}

void escrever(FILE *f, int *b, int tamanho){
	f = fopen("rand.txt", "w");
	int i;
	for(i = 0; i < tamanho; i++){
		//fprintf(f, "%d\n", b[i]);
		fwrite(&b[i], 1, sizeof(int), f);
	}
	fclose(f);
}

int main(){
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "portuguese");
	int a, i;
	int *b;
	char nome[20];
	FILE *f;
	printf("\nDigite o número de variáveis: ");
	scanf("%d", &a);
	b = gerar(a);
	printf("\nNúmeros gerados: ");
	for(i = 0; i < a; i++){
		printf("\n%d", b[i]);
	}
	escrever(f,b,a);
	return 0;
}
