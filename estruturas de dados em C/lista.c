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
	
	if(l->qtd == 0){
		l->inicio = novo;
	}
	else{
		aux = l->inicio; //aqui aux recebe o valor inicial da lista l
		while(aux->prox!=NULL){ //vai verificando cada item pra ver se o pr�ximo est� vazio ou n�o
			aux = aux->prox; //se n�o � nulo, aux vai pro pr�ximo item
		}
		aux->prox = novo; //quando terimina de checar, ele coloca o novo elemento no marcador de pr�ximo.
	}
	l->qtd++;
}

int main(){
	lista *l1;
	l1 = alocar_lista();
}

