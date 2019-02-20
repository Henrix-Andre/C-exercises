#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
	int valor;
	struct elemento * prox;
}elemento;

typedef struct lista
{
	int qtd;
	elemento * inicio;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();
void inserir( lista * l, int x);
void mostrar(lista * l);
int buscar(lista * l,int x);

int main()
{


	lista * l1;
	l1 = aloca_lista();
	printf("\nQuantidade de elementos na lista: %d",l1->qtd);
	inserir(l1,123);	
	inserir(l1,445);	
	inserir(l1,38756);	
	inserir(l1,999);	
	inserir(l1,7272);	
	inserir(l1,6);	
	inserir(l1,7);	
	inserir(l1,10);
	printf("\nQuantidade de elementos na lista: %d",l1->qtd);
	
	printf("\n\n Busca 1: \n\n");
	if (buscar(l1,7272))
	{
		printf("\nelemento 7272 esta na lista");
	}
	else
	{
		printf("\nelemento 7272 nao esta na lista");
	}
	
	if (remover(l1,7272))
	{
		printf("\nElemento 7272 removido");
	}
	else
	{
		printf("\nElemento 72727 nao esta na lista");
	}
	
	
	printf("\n\n Busca 2: \n\n");
	if (buscar(l1,7272))
	{
		printf("\nelemento 7272 esta na lista");
	}
	else
	{
		printf("\nelemento 7272 nao esta na lista");
	}
	
	
	return 0;
}


lista * aloca_lista()
{
	lista * novo;
	
	novo = (lista*)malloc(sizeof(lista));
	novo->qtd=0;
	novo->inicio=NULL;
	return novo;
}

void inserir( lista * l, int x)
{
	elemento * novo;
	novo = aloca_elemento();
	novo->valor = x;
	elemento * aux;
	
	if (l->qtd==0)
	{
		l->inicio = novo;
	}
	else
	{
		aux = l->inicio;
		while(aux->prox!=NULL)
		{
			aux=aux->prox;	
		}	
		aux->prox = novo;
	}
	l->qtd++;
}

elemento * aloca_elemento()
{
	elemento * novo;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor =0;
	novo->prox=NULL;
	return novo;
}


void mostrar(lista * l)
{
	elemento * aux;
	
	printf("\n\n");
	
	
	if (l->qtd==0)
	{
		printf("\n Lista vazia");
	}
	else
	{
		printf("\n\n Mostrando lista: \n\n");
		aux = l->inicio;
		printf("\n%d",aux->valor);
		while(aux->prox!=NULL)
		{
			aux = aux->prox;
			printf("\n%d",aux->valor);
		}
	}
}

int buscar(lista * l,int x)
{
	elemento * aux;
	if (l->qtd==0)
	{
		return 0;
	}
	else
	{
		aux = l->inicio;
		if (aux->valor == x)
		{
			return 1;	
		}
	
		while(aux->prox!=NULL)
		{
			aux=aux->prox;
			if (aux->valor == x)
			{
				return 1;	
			}
		}
		return 0;
	}
}

int remover(lista * l, int x)
{
	elemento * aux1, *aux2, *ant;
	if (l->qtd==0)
	{
		printf("\n Lista vazia");
	}
	else
	{
		aux1=l->inicio;
		while(1)
		{
			if (aux1->valor == x)
			{
				aux2=aux1->prox;
				free(aux1);
				if (ant==NULL)
				{
					l->inicio = aux2;
				}
				else
				{
					ant->prox = aux2;
				}
				
				return 1;
			}
			else
			{
				ant = aux1;
				aux1 = aux1->prox;
				if (aux1 == NULL)
				{
					return 0;	
				}	
			}
		}	
	}
}
