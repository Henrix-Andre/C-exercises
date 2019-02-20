#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
typedef struct elemento{
	int valor;
	struct elemento * prox;
}elemento;
typedef struct lista{
	int qtd;
	struct elemento * fim;
}lista;

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

lista * alocar_lista(){
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->fim = NULL;
	aux->qtd = 0;
	return aux;
}

void push(lista * l, int x){
	elemento *novo, *aux;
	aux = l->fim;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->prox = NULL;
	novo->valor = x;
	if(l->qtd == 0){
		l->fim = novo;
	}
	else{
		novo->prox = l->fim;
		l->fim = novo;
	}
	l->qtd++;
}

int pop(lista * l){
	elemento * aux;
	if(l->qtd == 0){
		printf("\nPilha vazia.");
		getch();
		return 0;
	}
	else{
		aux = l->fim;
		l->fim = aux->prox;
		printf("\nValor removido: %d", aux->valor);
		free(aux);
		l->qtd--;
		getch();
	}
}

void mostrar(lista * l){
	elemento * aux;
	if(l->qtd == 0){
		printf("\nPilha vazia.");
		getch();
	}
	else{
		aux = l->fim;
		while(aux != NULL){
			printf("\nValor: %d\n", aux->valor);
			aux = aux->prox;
		}
		getch();
	}
}

void menu(lista * l){
	int opt, num;
	elemento * i;
	do{
		system("cls");
		printf("(1)Inserir elemento na pilha\n(2)Remover elemento\n(3)Mostrar lista\n(4)Sair\n---------------------------\nDigite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d",&num);
				push(l,num);
				break;
			case 2:
				pop(l);
				break;
			case 3:
				mostrar(l);
				break;
			case 4:
				printf("\nEncerrando");
				getch();
				break;
		}
	}while(opt != 4);
}

int main(){
	pthue();
	lista *l1;
	l1 = alocar_lista();
	menu(l1);
}

