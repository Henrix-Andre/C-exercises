#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
typedef struct elemento{
	int valor;
	struct elemento * prox;
}elemento;
typedef struct lista{
	int qtd;
	struct elemento * inicio;
}lista;

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

lista * alocar_lista(){
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->inicio = NULL;
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
	}
	else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
	l->qtd++;
}

int remover(lista * l, int x){
	elemento *ant = NULL, *atual = NULL, *frente = NULL;
	if(l->qtd == 0){
		return 0;
	}
	else{
		while(1){
			atual = l->inicio;
			if(atual->valor != x){
				if(atual->prox == NULL){ //aqui significa que nao encontrou o item a ser deletado, e a lista acabou.
					return 0; //aqui é pra escapar do while 
				}
				else{ //aqui continua a iteração pela lista
					ant = atual;
					atual = atual->prox;
				}
			}
			else{ //aqui encontrou o item
				frente = atual->prox; //salva o endereço do item a frente do item a ser deletado
				if(ant != NULL){ //se o anterior nao for nulo
					ant->prox = frente; //o próximo item ao anterior do item a ser deletado vai ser o item depois do item a ser deletado (cacete explicação cagada essa)
				}
				else{
					l->inicio = frente; //se for nulo, então ou não existe porra nenhuma na lista ou você quis deletar o primeiro item da lista
										//então a lista vai começar direto no item depois do item inicial.
				}
				printf("\nItem removido: %d", atual->valor);
				getch();
				free(atual); //libera a memória que o item a ser deletado ocupa
				l->qtd--;
				return 1; //esse return 1 serve pra escapar do while                 
			}
		}
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
		while(aux->prox != NULL){
			printf("\nValor: %d\n", aux->valor);
			aux = aux->prox;
		}
		getch();
	}
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

void inserir_inicio(lista * l, int x){
	elemento *aux, *novo;
	aux = l->inicio;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->prox = NULL;
	novo->valor = x;
	if(l->qtd == 0){ //se não tiver nada na lista, apenas entra o elemento novo.
		l->inicio = novo;
	}
	else{ //já se tiver algo na lista, o novo elemento assume o próximo elemento de aux, e o novo elemento se torna o depois do aux.
		novo->prox = aux->prox;
		aux->prox = novo;
	}
	l->qtd++;
	
}

void menu(lista * l){
	int opt, num;
	elemento * i;
	do{
		system("cls");
		printf("(1)Inserir elemento no fim da lista\n(2)Remover elemento\n(3)Mostrar lista\n(4)Buscar um elemento\n(5)Inserir elemento no inicio da lista\n(6)Sair\n---------------------------\nDigite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d",&num);
				inserir(l,num);
				break;
			case 2:
				printf("\nDigite o valor a ser removido: ");
				scanf("%d",&num);
				remover(l,num);
				break;
			case 3:
				mostrar(l);
				break;
			case 4:
				printf("\nDigite o valor a ser buscado: ");
				scanf("%d",&num);
				i = buscar(l,num);
				printf("\nItem encontrado : %d", i->valor);
				getch();
				break;
			case 5:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d",&num);
				inserir_inicio(l,num);
				break;
			case 6:
				printf("\nEncerrando");
				getch();
				break;
			default:
				printf("\nOpção invália.");
				break;
		}
	}while(opt != 6);
}

int main(){
	pthue();
	lista *l1;
	l1 = alocar_lista();
	menu(l1);
}

