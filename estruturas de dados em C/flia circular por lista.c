#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

typedef struct elemento{
	int valor;
	struct elemento * prox;
}elemento;
typedef struct lista{
	int qtd;
	struct elemento * inicio;
	struct elemento * fim;
}lista;

lista * alocar_lista(){
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->inicio = NULL;
	aux->fim = NULL;
	aux->qtd = 0;
	return aux;
}


void inserir(lista * l, int x){
	elemento *novo, *aux;
	aux = l->inicio;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->prox = NULL;
	novo->valor = x;
	if(l->qtd == 0){
		l->inicio = novo;
		l->fim = l->inicio;
	}
	else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
		l->fim = novo;
	}
	l->qtd++;
}


int remover(lista * l){
	elemento *aux;
	aux = l->inicio;
	if(l->qtd == 0){
		printf("Lista vazia.");
	}
	else{
		aux = l->inicio;
		l->inicio = aux->prox;
		printf("\nValor removido: %d", aux->valor);
		free(aux);
		l->qtd--;
		getch();
	}
}

void mostrar(lista * l){
	elemento * aux;
	if(l->qtd == 0){
		printf("\nLista vazia.");
		getch();
	}
	else{
		aux = l->inicio;
		while(aux != NULL){
			printf("\nValor: %d\n", aux->valor);
			aux = aux->prox;
		}
		getch();
	}
}

void mostrar_fim(lista * l){
	elemento * aux;
	if(l->qtd == 0){
		printf("\nLista vazia");
	}
	else{
		aux = l->fim;
		printf("\nValor: %d\n", aux->valor);
	}
	getch();
}

elemento * buscar(lista * l, int x){
	elemento * aux;
	if(l->qtd == 0){
		return NULL; //se não tem nada na lista, já retorna nulo.
	}
	else{ //se existe algo
		aux = l->inicio; //vai iterando do começo da lista
		while(1){ //enquanto verdade
			if(aux->valor = x){ //se é o valor desejado
				return aux;
			}
			else{
				if(aux->prox == NULL){
					return NULL; //se a lista acabou, retorna nulo.
				}
				else{
					aux = aux->prox; //continua a iteração da lista
				}
			}
		}
	}
}

void menu(lista * l){
	int opt, num;
	elemento * i;
	do{
		system("cls");
		printf("(1)Inserir elemento na fila\n(2)Remover elemento\n(3)Mostrar lista\n(4)Mostrar item no fim da fila\n(5)Sair\n---------------------------\nDigite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d",&num);
				inserir(l,num);
				break;
			case 2:
				remover(l);
				break;
			case 3:
				mostrar(l);
				break;
			case 4:
				mostrar_fim(l);
				break;
			case 5:
				printf("\nEncerrando");
				getch();
				break;
			default:
				printf("\nOpção inválida.");
				getch();
				break;
		}
	}while(opt != 5);
}

int main(){
	pthue();
	lista *l1;
	l1 = alocar_lista();
	menu(l1);
}


