#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int frente = -1; //isso aqui vai contar qual vai ser a posi��o no vetor que vai ser a frente atualmente
				 //definido como global pra nao causar treta com as fun��es. n�o � o ideal, mas no nosso caso aqui j� da pro gasto.
				 //come�a como -1 pra fun�ao preencher mover ele pra posi��o zero. 
void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

int preenche(int * x, int max){
	int i;
	frente++;
	for(i = 0; i < max; i++){
		printf("\ndigite o %d� item a ser atendido na fila: ", i);
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
	if(frente == max){ //se o marcador da frente j� chegou no �ltimo elemento da fila, ele te devolve isso.
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
	x = (int*)malloc(i*sizeof(int)); //como vai se criar uma fila nova em cima da antiga, um malloc com o espa�o novo basta, j� que ele sobrep�e o espa�o definido antes.
	preenche(x, i); //usando recursividade, chamamos a fun��o de preencher a fila com o novo x e com o tamanho redefinido.s
	return x;
}

void menu(int * x, int max){
	int opt, i;
	do{
		system("cls");
		printf("\n(1)Mostrar fila\n(2)Atender\n(3)criar nova fila\n(4)Sair\n------------------------------\nDigite sua op��o: ");
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
				scanf("%d", &max); //aqui simplesmente muda o valor de max em seu endere�o.
				x = nova_fila(x,max);
				break;
			case 4:
				printf("At� a pr�xima!\n");
				getch();
				break;
			default:
				printf("Deu pato, digite uma op��o v�lida.");
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
	fila = (int*)malloc(max*sizeof(int)); //ponteiro SEMPRE � UM VETOR, logo pra criar a fila por vetor simples, s� precisamos definir o tamanho dela
	preenche(fila, max); //nesse caso usando o malloc pro tamanho definido pelo usu�rio.
	menu(fila, max);
}

