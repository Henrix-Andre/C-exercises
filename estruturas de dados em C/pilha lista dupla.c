#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
typedef struct lista{
	struct elemento * inicio;
	struct elemento * fim;
	int qtd;
}lista;
typedef struct elemento{
	struct elemento * prox;
	struct elemento * ant;
	int valor;
}elemento;

lista * alocar_lista(){
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->inicio = NULL;
	aux->fim = NULL;
	aux->qtd = 0;
	return aux;
}

elemento * alocar_elemento(){
	elemento * aux;
	aux = (elemento*)malloc(sizeof(elemento));
	aux->prox = NULL;
	aux->ant = NULL;
	aux->valor = 0;
	return aux;
}

void inserir_inicio(lista * a, int x){
	elemento * novo, * aux;
	novo = alocar_elemento();
	novo->valor = x;
	if(a->qtd == 0){
		a->inicio = novo;
		a->fim = aux;
	}
	else{
		aux = a->inicio;
		novo->prox = a->inicio;
		aux->ant = novo;
		a->inicio = novo;
	}
	a->qtd++;
}

void inserir_fim(lista * a, int x){
	elemento * novo, * aux;
	novo = alocar_elemento();
	novo->valor = x;
	if(a->qtd == 0){
		a->inicio = novo;
		a->fim = novo;
	}
	else{
		aux = a->fim;
		novo->ant = a->fim;
		aux->prox = novo;
		a->fim = novo;
	}
	a->qtd++;
}

int remover_fim(lista * l){
	elemento * remover;
	int x;
	if(l->qtd == 0){
		return 0;
	}
	else{
		remover = l->fim;
		l->fim = remover->ant;
		x = remover->valor;
		free(remover);
		l->qtd--;
		return x;
	}
}

int remover_inicio(lista * l){
	elemento * remover, * retornar;
	int x;
	if(l->qtd == 0){
		return 0;
	}
	else{
		remover = l->inicio;
		l->inicio = remover->prox;
		x = remover->valor;
		free(remover);
		l->qtd--;
		return x;
	}
}

void mostrar(lista * l){
	elemento * aux;
	aux = l->inicio;
	int i;
	if(l->qtd == 0){
		printf("\nLista vazia.");
	}
	else{
		while(aux != NULL){
			printf("\n%d", aux->valor);
			aux = aux->prox;
		}
	}
}

int stackpop(lista * l){
	elemento * retorno;
	if(l->qtd == 0){
		return 0;
	}
	else{
		retorno = l->fim;
		return retorno->valor;
	}
}

int empty(lista * l){
	if(l->qtd == 0){
		return 0;
	}
	else{
		return l->qtd;
	}
}

void menu(lista * p){
	int opt, num;
	do{
		fflush(stdin);
		system("CLS");
		printf("(1)push\n(2)pop\n(3)stackpop\n(4)empty\n(5)mostrar pilha\n(6)sair\n");
		printf("-----------------------------------------------------\n");
		printf("Digite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Digite o número a ser adicionado: ");
				scanf("%d", &num);
				inserir_fim(p, num);
				break;
			case 2:
				num = remover_fim(p);
				if(num == 0 && p->qtd == 0){
					printf("\nStack underflow/pilha vazia.");
					getch();
				}
				else{
					printf("\nNúmero removido: %d", num);
					getch();
				}
				break;
			case 3:
				if(stackpop(p)){
					printf("\nNúmero no topo da pilha: %d", stackpop(p));
					getch();
				}
				else{
					printf("\nStack underflow/pilha vazia.");
					getch();
				}
				break;
			case 4:
				num = empty(p);
				if(num == 0){
					printf("\nPilha vazia.");
					getch();
				}
				else{
					printf("\nExistem itens na pilha.");
					getch();
				}
				break;
			case 5:
				mostrar(p);
				getch();
				break;
			case 6:
				printf("\nEncerrando.");
				getch();
				break;
			default:
				printf("\nOpção inválda");
				getch();
				break;
		}
	}while(opt != 6);
}

int main(){
	setlocale(LC_ALL, "portuguese");
	lista * l;
	l = alocar_lista();
	menu(l);
}

