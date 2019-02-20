#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int valor;
	struct elemento * prox;
}elemento;

typedef struct
{
	int qtd;
	elemento * inicio;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();
void incluir_lista(lista * l, int x);
void mostrar_lista (lista * l);
int buscar_lista(lista * l, int x);
void remover(lista * l,int x);

int main()
{
	lista * l1;
	
	l1 = aloca_lista();

	printf("Quantide de elementos na lista: %d",l1->qtd);
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

void incluir_lista(lista * l, int x)
{
	elemento * aux;
	elemento * novo;
	int retorno;
	
	retorno = buscar_lista(l,x);
	
	if (retorno==1)
	{
		printf("\n Ja existe na lista");
	}
	else
	{
		novo = aloca_elemento();
		novo->valor=x;
		
		if (l->qtd==0)
		{
			l->inicio = novo;	
		}
		else
		{
			aux = l->inicio;
			while(aux->prox!=NULL)
			{
				aux = aux->prox;
			}
			aux->prox = novo;
		}
		l->qtd++;		
	}
		
}


elemento * aloca_elemento()
{
	elemento * novo;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor = 0;
	novo->prox = NULL;
	return novo;
}

void mostrar_lista (lista * l)
{
	elemento * aux;
	if (l->qtd==0)
	{
		printf("\n lista vazia");	
	}	
	else
	{
		printf("\n\n Mostrando lista: \n\n");
		aux = l->inicio;
		printf("\n %d ",aux->valor);
		while(aux->prox!=NULL)
		{
			aux=aux->prox;
			printf("\n %d ",aux->valor);
		}
		
	}
}

int buscar_lista(lista * l, int x)
{
	elemento * aux;
	
	if (l->qtd==0)
	{
		return 0;
	}
	else
	{
		aux = l->inicio;
		while(1)
		{
			if (aux->valor == x)
			{
				return 1;
			}
			else
			{
				aux=aux->prox;
				if (aux==NULL)
				{
					
					return 0;	
				}	
			}	
		}
		
		
	}
}

void remover(lista * l,int x)
{
	elemento * aux1=NULL, *ant=NULL , *aux2=NULL;
	
	if (l->qtd==0)
	{
		printf("\n Lista Vazia");
	}
	else
	{
		aux1 = l->inicio;
		while((aux1->valor != x) && (aux1->prox!=NULL))
		{
			ant = aux1;
			aux1 = aux1->prox;
		}
		
		if (aux1->valor == x)
		{
			aux2=aux1->prox;
			free (aux1);
			if (ant == NULL)
			{
				l->inicio = aux2;
			}
			else
			{
				ant->prox = aux2;
			}
			l->qtd--;
		}
				
	}
}
