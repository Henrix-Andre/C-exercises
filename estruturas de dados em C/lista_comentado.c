#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
	int valor;
	struct elemento * prox;
}elemento;

typedef struct lista{
	int qtd;
	struct elemento * inicio;
}lista;

lista * alocar_lista(){ //� do tipo 'lista *' pq retorna o endere�o de uma lista
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->qtd = 0;
	aux->inicio = NULL;
	return aux;
}

void inserir(lista * l, int num){ //dentro da fun��o a lista se chama l e vamos repassar as informa��es dela pro local certo ao fim da fun��o.
	elemento *novo, *aux;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor = num; //o valor nesse elemento recebe o valor definido
	novo->prox = NULL; //o pr�ximo define que o pr�ximo elemento � null;
	
	if(l->qtd == 0){ //se a quantidade de elementos na lista � zzero
		l->inicio = novo;
	}
	else{
		aux = l->inicio; //aqui aux recebe o valor inicial da lista l
		while(aux->prox!=NULL){ //vai verificando cada item pra ver se o pr�ximo est� vazio ou n�o, se n�o � nulo, aux vai pro pr�ximo item
			aux = aux->prox; //isso funcioa pois aux recebe o endere�o do in�cio da lista, e vai seguindo cada item da lista at� chegar a um que seja nulo.
		}
		aux->prox = novo; //quando terimina de checar, ele coloca o novo elemento no marcador de pr�ximo.
	}
	l->qtd++;
}

void remover(lista * l, int x){
	elemento *anti, *aux, *aux2; //anti = anterior
	aux = l->inicio;
	while(){
		if(aux->valor != x){ //se o valor que est� em aux for diferente do desejado
			anti = aux //o anterior pega os dados de aux 
			aux = aux->prox; //aux assume os valores do pr�ximo endere�o
		}
		else{
			anti = aux;
			aux = aux->prox;
			if(aux == null){
				return 0;
			}
		}
	}
}

int main(){
	lista *l1;
	l1 = alocar_lista();
}

