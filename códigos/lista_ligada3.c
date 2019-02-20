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
	struct elemento * inicio;
	
}lista;

lista * aloca_lista();
elemento * aloca_elemento();
void inserir (lista * l, int x);
void mostrar(lista * l);
int remover( lista * l, int x);
int buscar(lista * l, int x);
int main()
{
	lista * l1;
	l1 = aloca_lista();

	//menu(l1);
	
	
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

void inserir (lista * l, int x)
{
	elemento * novo;
	elemento * aux;
	novo = aloca_elemento();
	novo->valor = x;
	
	if(l->qtd==0)
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

elemento * aloca_elemento()
{
	elemento * novo;
	
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor = 0;
	novo->prox = NULL;
	return novo;
}

void mostrar(lista * l)
{
	elemento * aux;
	if (l->qtd==0)
	{
		printf("\n lista vazia");
	}
	else
	{
		printf("\n\n\n Mostrando Lista: \n\n");
		aux = l->inicio;
		printf("\n %d",aux->valor);
		
		while(aux->prox!=NULL)
		{
			aux= aux->prox;
			printf("\n %d",aux->valor);
			
		}
	}
}


int remover( lista * l, int x)
{
	elemento *ant=NULL ,*atual=NULL ,*frente=NULL;
	
	if (l->qtd==0)
	{
		return 0;
	}
	else
	{
		atual = l->inicio;
		
		while(1)
		{
			if (atual->valor == x)
			{
				frente = atual->prox;
				
				if (ant==NULL)
				{
					l->inicio=frente;
				}
				else
				{
					ant->prox = frente;
				}
				l->qtd--;
				free(atual);
				return 1;
			}
			else
			{
				if (atual->prox==NULL)
				{
					return 0;
				}
				else
				{
					ant = atual;
					atual = atual->prox;	
				}
						 
			}
				
		}
		
		
	}
}

int buscar(lista * l, int x)
{
	elemento * aux;
	if (l->qtd==0)
	{
		return 0;
	}
	else
	{
		aux = l->inicio;
		
		while (1)
		{
			if (aux->valor == x)
			{
				return 1;	
			}	
			else
			{
				if (aux->prox == NULL)
				{
					return 0;
				}
				else
				{
					aux = aux->prox;
				}
			}	
		}
	
	}
}
