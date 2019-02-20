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

void mostrar (lista * l);
int remover (lista * l, int x);
elemento * buscar(lista * l , int x);
int incluir_inicio(lista * l , int x);
int incluir_fim(lista * l , int x);
elemento * aloca_elemento();
lista * aloca_lista();
void ordenar(lista * l);

int main()
{
	lista * l1;
	elemento * aux;
	l1 = aloca_lista();
	incluir_inicio(l1,1);
	incluir_fim(l1,30);
	incluir_inicio(l1,150);
	incluir_fim(l1,300);	
	incluir_inicio(l1,450);
	
	mostrar(l1);
	ordenar(l1);
	mostrar(l1);
	

	exit(1);
	
	
	
	
	remover(l1,1);
	mostrar(l1);
	if(remover(l1,300))
	{
		printf("\nO elemento 300 foi removido");
	}
	else
	{
		printf("\no elemento 300 nao esta na lista");
	}
	mostrar(l1);
	remover(l1,150);
	mostrar(l1);
	remover(l1,30);
	mostrar(l1);
	if(remover(l1,999))
	{
		printf("\n elemento 999 removido ");
	}
	else
	{
		printf("\n o elemento 999 nao esta na lista");
	}
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
	novo =(elemento*)malloc(sizeof(elemento));
	novo->valor=0;
	novo->ant=NULL;
	novo->prox=NULL;
	return novo;
}

int incluir_fim(lista * l , int x)
{
	elemento * novo;
	elemento * aux;
	novo = aloca_elemento();
	novo->valor=x;
	
	if (l->qtd==0)
	{
		l->inicio = novo;
		l->fim    = novo;
	}
	else
	{
		aux = l->fim;
		aux->prox = novo;
		novo->ant = aux;
		l->fim = novo;
			
	}
	l->qtd++;
	
}

int incluir_inicio(lista * l , int x)
{
	elemento * novo;
	elemento * aux;
	novo = aloca_elemento();
	novo->valor=x;
	
	if (l->qtd==0)
	{
		l->inicio = novo;
		l->fim    = novo;
	}
	else
	{
		aux = l->inicio;
		aux->ant = novo;
		novo->prox = aux;
		l->inicio = novo;
			
	}
	l->qtd++;
	
}


elemento * buscar(lista * l , int x)
{
	elemento * aux;
	if (l->qtd==0)
	{
		return NULL;
	}
	else
	{
		aux = l->inicio;
		while((aux->valor!=x) && (aux->prox!=NULL))
		{
			aux=aux->prox;
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

int remover (lista * l, int x)
{
	elemento *prev, *remover, *next;
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
			if (prev==NULL)
			{
				l->inicio = next;
				
			}
			else
			{
				prev->prox=next;
			}
			if (next==NULL)
			{
				l->fim = prev;
			}
			else
			{
				next->ant=prev;
			}
		}
		free(remover);
		l->qtd--;
		return 1;
	}

	
}


void mostrar (lista * l)
{
	elemento * aux;
	aux = l->inicio;
	if (l->qtd==0)
	{
		printf("\n Nao existem elementos na lista");
	}
	else
	{
		printf("\n Quantidade de elementos: %d\n\n",l->qtd);
		while(aux!=NULL)
		{
			printf("\n %d",aux->valor);
			aux=aux->prox;
		}
	}
}

void ordenar(lista * l)
{
	elemento * i=NULL, *j=NULL;
	int aux;	
	i=l->inicio;	
	while(i->prox!=NULL)
	{
		j=i->prox;
		while(j!=NULL)
		{
			if(i->valor > j->valor)
			{
				aux = i->valor;
				i->valor = j->valor;
				j->valor = aux;
			}
			j=j->prox;
		}
		i=i->prox;
	}	
}
