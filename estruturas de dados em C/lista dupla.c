#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
typedef struct lista{
	int qtd;
	struct elemento * inicio;
	struct  elemento * fim;
}lista;
typedef struct elemento{
	int item;
	struct elemento * prox;
	struct elemento * ant;
}elemento;

lista * alocar(){
	lista *aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->inicio = NULL;
	aux->fim = NULL;
	aux->qtd = 0;
	return aux;
}
elemento * alc_elemento(){
	elemento * aux;
	aux = (elemento*)malloc(sizeof(elemento));
	aux->item=0;
	aux->ant=NULL;
	aux->prox=NULL;
	return aux;
}

int inserir_fim(lista * l, int num){
	elemento *aux; 
	elemento *insrt;
	insrt = alc_elemento();
	insrt->item = num;
	if(l->qtd == 0){
		l->inicio = insrt;
		l->fim = insrt;
	}
	else{
		aux = l->fim;
		insrt->ant = aux;
		aux->prox = insrt;
		l->fim = insrt;
	}
	l->qtd++;
}
int inserir_inicio(lista * l, int num){
	elemento * aux; 
	elemento * insrt;
	insrt = alc_elemento();
	insrt->item = num;
	if(l->qtd == 0){
		l->inicio = insrt;
		l->fim = insrt;
	}
	else{
		aux = l->inicio;
		insrt->prox = aux;
		aux->ant = insrt;
		l->inicio = insrt;
	}
	l->qtd++;
}
elemento * buscar(lista * l, int num){
	elemento * aux;
	aux = l->inicio;
	while(aux->item != num && aux->prox != NULL){
		aux = aux->prox;
	}
	if(aux->item != num){
		return NULL;
	}
	else{
		return aux;
	}
}
int remover(lista * l, int num){
	elemento *aux, *aux2, *aux3;
	if(l->qtd == 0){
		return 0; //lista vazia
	}
	else{
		aux = buscar(l, num);
		if(aux == NULL){
			printf("\nItem não encontrado.");
		}
		else{
			if(aux->prox == NULL){
				l->fim = aux->ant;
			}
			else{
				aux3 = aux->ant;
				aux2 = aux->prox;
				aux2->ant = aux3;
				aux3->prox = aux2;
			}
			printf("\nItem removido: %d", aux->item);
			free(aux);
			l->qtd--;
			getch();
		}
	}
}
void mostrar(lista * l){
	elemento * aux;
	aux = l->inicio;
	if(l->qtd == 0){
		printf("\nLista vazia.");
		getch();
	}
	else{
		printf("\n%d", aux->item);
		while(aux->prox != NULL){
			printf("\n%d", aux->item);
			aux = aux->prox;
		}
		getch();
	}
}
void bubblesort(lista * l){
	elemento * aux, *aux2, *aux3;
	while(aux = l->inicio, aux->prox != NULL, aux = aux->prox){
		while(aux2 = aux->prox, aux2!= NULL, aux2 = aux2->prox){
			if(aux->item > aux2->item){
				aux3 = aux2;
				aux2 = aux;
				aux = aux3;
			}
		}
	}
	printf("\nLista ordenada.");
	getch();
}
elemento * maioritem(lista * l){
	elemento *aux1, *aux2, *maior;
	if(l->qtd == 0){
		printf("\nLista vazia.");
		getch();
	}
	else{
		aux1 = l->inicio;
		aux2 = aux1->prox;
		maior = aux1;
		while(aux1->prox != NULL){
			if(aux1->item < aux2->item){
				maior = aux2;
			}
				aux1 = l->inicio;
				aux2 = aux1->prox;
		}
		printf("\nMaior item na lista: %d", maior->item);
	}
	getch();
}
void menu(lista * l){
	int opt; 
	int num;
	elemento * aux;
	do{
		fflush(stdin);
		system("cls");
		printf("(1)Inserir item no inicio\n(2)Buscar item\n(3)Mostrar lista\n(4)Inserir item no fim\n(5)maior item\n(6)Remover item\n(7)Ordenar por valor\n(8)Sair\n---------------------------\nDigite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_inicio(l,num);
				break;
			case 2:
				if(l->qtd == 0){
					printf("\nLista vazia.");
					getch();
				}
				else{
					printf("\nDigite o valor a ser buscado: ");
					scanf("%d", &num);
					aux = buscar(l, num);
					if(aux == NULL){
						printf("\nItem não encontrado e/ou lista vazia.");
						getch();
					}
					else{
						printf("\nItem encontrado: %d", aux->item);
						getch();
					}
				}
				break;
			case 3:
				mostrar(l);
				break;
			case 4:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d", &num);
				inserir_fim(l,num);
				break;
			case 5:
				maioritem(l);
				break;
			case 6:
				if(l->qtd == 0){
					printf("\nLista vazia.");
					getch();
				}
				else{
					printf("\nDigite o valor a ser removido: ");
					scanf("%d", &num);
					remover(l, num);
				}
				break;
			case 7:
				if(l->qtd == 0){
					printf("\nLista vazia.");
					getch();
				}
				else{
					bubblesort(l);
				}
				break;
			case 8:
				printf("\nEncerrando");
				getch();
				break;
			default:
				printf("\nOpção inválida.");
				getch();
				break;
		}
	}while(opt != 8);
}


int main(){
	setlocale(LC_ALL, "portuguese");
	lista * l;
	l = alocar();
	menu(l);
}



