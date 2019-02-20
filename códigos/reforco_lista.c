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

lista * alocar_lista();
int remover (lista * l, int x);
void inserir(lista * l,int x);
void mostrar( lista * l);
elemento * buscar (lista * l, int x);

int main()
{
	lista * l1;
	elemento * buscado;
	l1 = alocar_lista();
	inserir(l1,1);
	inserir(l1,2);
	inserir(l1,3);
	remover(l1,3);
	buscado = buscar(l1,3);
	if (buscado==NULL)
	{
		printf("\n elemento nao esta na lista");
	}
	else
	{
		printf("elemento esta na lista = %d",buscado->valor);
	}


	return 0;
}

lista * alocar_lista()
{
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->qtd=0;
	aux->inicio=NULL;
	return aux;
}

void inserir(lista * l,int x)
{
	elemento * novo,*aux;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor = x;
	novo->prox=NULL;
	
	
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


int remover (lista * l, int x)
{
	elemento * ant=NULL,*atual=NULL,*frente=NULL;	
	if (l->qtd==0)
	{
		return 0;
	}
	else
	{
		atual=l->inicio;
		while(1)
		{
			if (atual->valor != x)
			{
				if (atual->prox==NULL)
				{
					return 0;
				}
				else
				{
					ant = atual;
					atual=atual->prox;	
				}						
			}
			else
			{
				frente = atual->prox;
				if (ant!=NULL)
				{
					ant->prox = frente;
				}
				else
				{
					l->inicio = frente;
				}
				free(atual);
				l->qtd--;
				return 1;
			}	
		}
		
	}
}


void mostrar( lista * l)
{
	elemento * aux;
	if (l->qtd==0)
	{
		printf("\n lista vazia");
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

elemento * buscar (lista * l, int x)
{
	elemento * aux;
	if (l->qtd==0)
	{
		return NULL;
	}
	else
	{
		aux = l->inicio;
		while(1)
		{
			if (aux->valor == x)
			{
				return aux;
			}
			else
			{
				if (aux->prox==NULL)
				{
					return NULL;
				}
				else
				{
					aux=aux->prox;
				}
			}
		}		
	}
}





