#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int frente = -1; //isso aqui vai contar qual vai ser a posição no vetor que vai ser a frente atualmente
				 //definido como global pra nao causar treta com as funções. não é o ideal, mas no nosso caso aqui já da pro gasto.
				 //começa como -1 pra funçao preencher mover ele pra posição zero. 
void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

int preenche(int * x, int max){
	int i;
	frente++;
	for(i = 0; i < max; i++){
		printf("\ndigite o %dº item a ser atendido na fila: ", i);
		scanf("%d", &x[i]);
	}
}

void mostrar(int *x, int max){
	int i;
	if(frente == max){
		printf("\nFila vazia");
	}
	else{
		for(i = frente; i < max; i++){
			printf("%d \n", x[i]);
		}
	}
	getch();
}

void remover(int *x, int max){
	if(frente == max){ //se o marcador da frente já chegou no último elemento da fila, ele te devolve isso.
		printf("\nErro!");
		getch();
	}
	else{
		printf("\nItem removido %d", x[frente]); //mostra o item removido antes de mover o marcador.
		frente++;
		getch();
	}
}

int nova_fila(int *x, int i){
	frente = -1;
	x = (int*)malloc(i*sizeof(int)); //como vai se criar uma fila nova em cima da antiga, um malloc com o espaço novo basta, já que ele sobrepõe o espaço definido antes.
	preenche(x, i); //usando recursividade, chamamos a função de preencher a fila com o novo x e com o tamanho redefinido.s
	return x;
}

void menu(int * x, int max){
	int opt, i;
	do{
		system("cls");
		printf("\n(1)Mostrar fila\n(2)Atender\n(3)criar nova fila\n(4)Sair\n------------------------------\nDigite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				mostrar(x, max);
				break;
			case 2:
				remover(x, max);
				break;
			case 3:
				printf("Digite o tamanho da fila: ");
				scanf("%d", &max); //aqui simplesmente muda o valor de max em seu endereço.
				x = nova_fila(x,max);
				break;
			case 4:
				printf("Até a próxima!\n");
				getch();
				break;
			default:
				printf("Deu pato, digite uma opção válida.");
				getch();
				break;
		}

	}while(opt != 4);
}

int main(){
	pthue();
	int *fila, i, max;
	printf("Digite o tamanho da fila: ");
	scanf("%d", &max);
	fila = (int*)malloc(max*sizeof(int)); //ponteiro SEMPRE É UM VETOR, logo pra criar a fila por vetor simples, só precisamos definir o tamanho dela
	preenche(fila, max); //nesse caso usando o malloc pro tamanho definido pelo usuário.
	menu(fila, max);
}

