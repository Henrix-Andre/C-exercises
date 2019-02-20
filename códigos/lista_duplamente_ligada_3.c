#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int qtd;
	struct elemento * inicio;
	struct elemento * fim;
}lista;

typedef struct elemento
{
	int valor;
	struct elemento * ant;
	struct elemento * prox;
}elemento;

lista * aloca_lista();
elemento * aloca_elemento();
void inserir_fim(lista * l, int x);
void inserir_inicio(lista * l, int x);
elemento * buscar(lista * l, int x);
int remover ( lista * l, int x);
void mostrar( lista * l);
int main()
{
	lista * l1;
	l1 = aloca_lista();
/*
	inserir_inicio(l1,1);
	inserir_fim(l1,10);
	inserir_inicio(l1,30);
	inserir_inicio(l1,40);
	inserir_fim(l1,50);

	if (remover(l1,30))
	{
		printf("elemento removido com sucesso");
	}
	else
	{
		printf("elemento nao esta na lista");
	}
	*/
/*	remover(l1,30);
	remover(l1,40);
	remover(l1,50);
	remover(l1,10);
	remover(l1,1);
	remover(l1,700); */
	printf("\n Quantidade de elementos: %d",l1->qtd);
	printf("\n");
	mostrar(l1);
	return 0;
}

lista * aloca_lista()
{
	lista * novo;
	novo = (lista*)malloc(sizeof(lista));
	novo->qtd=0;
	novo->inicio=NULL;
	novo->fim=NULL;
	return novo;
}

elemento * aloca_elemento()
{
	elemento * novo;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor=0;
	novo->ant=NULL;
	novo->prox=NULL;
	return novo;
}

void inserir_fim(lista * l, int x)
{
	elemento * novo;
	elemento * aux;
	novo = aloca_elemento();
	novo->valor = x;
	if (l->qtd==0)
	{
		l->inicio = novo;
		l->fim    = novo;
	}
	else
	{
		aux       = l->fim;
		aux->prox = novo;
		novo->ant = aux;
		l->fim    = novo;	
	}
	l->qtd++;
}

void inserir_inicio(lista * l, int x)
{
	elemento * novo;
	elemento * aux;
	novo = aloca_elemento();
	novo->valor = x;
	if (l->qtd==0)
	{
		l->inicio = novo;
		l->fim    = novo;
	}
	else
	{
		aux        = l->inicio;
		aux->ant   = novo;
		novo->prox = aux;
		l->inicio  = novo;	
	}
	l->qtd++;
}

elemento * buscar(lista * l, int x)
{
	elemento * aux;
	if (l->qtd==0)
	{
		return NULL;
	}
	else
	{
		aux = l->inicio;
		while((aux->valor != x) && ( aux->prox!=NULL))
		{
			aux = aux->prox;	
		}	
		if (aux->valor == x)
		{
			return aux;
		}
		else
		{
			return NULL;
		}
	}
}

int remover ( lista * l, int x)
{
	elemento * prev=NULL, * remover = NULL, * next = NULL;
	
	if (l->qtd==0)
	{
		return 0;
	}
	else
	{
		
		remover = buscar(l,x);
		
		if (remover==NULL)
		{
			return 0;	
		}
		else
		{
			prev = remover->ant;
			next = remover->prox;
			
			if (prev!=NULL)
			{
				prev->prox = next;
			}
			else
			{
				l->inicio = next;	
			}
			if (next!=NULL)
			{
				next->ant = prev;	
			}	
			else
			{
				l->fim=prev;
			}
			l->qtd--;
			free(remover);
			return 1;				
		}
	}
}

void mostrar( lista * l)
{
	elemento * aux;
	if (l->qtd==0)
	{
		printf("\n Nao existem elementos na lista");
	}
	else
	{
		aux = l->inicio;
		printf("\n %d",aux->valor);
		while(aux->prox!=NULL)
		{
			aux=aux->prox;
			printf("\n %d",aux->valor);
			
		}
	}
}
