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

lista * alocar_lista(){ //é do tipo 'lista *' pq retorna o endereço de uma lista
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->qtd = 0;
	aux->inicio = NULL;
	return aux;
}

void inserir(lista * l, int num){ //dentro da função a lista se chama l e vamos repassar as informações dela pro local certo ao fim da função.
	elemento *novo, *aux;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor = num; //o valor nesse elemento recebe o valor definido
	novo->prox = NULL; //o próximo define que o próximo elemento é null;
	
	if(l->qtd == 0){
		l->inicio = novo;
	}
	else{
		aux = l->inicio; //aqui aux recebe o valor inicial da lista l
		while(aux->prox!=NULL){ //vai verificando cada item pra ver se o próximo está vazio ou não
			aux = aux->prox; //se não é nulo, aux vai pro próximo item
		}
		aux->prox = novo; //quando terimina de checar, ele coloca o novo elemento no marcador de próximo.
	}
	l->qtd++;
}

int main(){
	lista *l1;
	l1 = alocar_lista();
}

