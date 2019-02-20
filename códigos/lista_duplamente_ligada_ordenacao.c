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
elemento * buscar( lista * l, int x);
int remover ( lista * l, int x);
void mostrar(lista * l);
void menu(lista * l);
void ordenar(lista * l);

int main()
{
	lista * l1;
	l1 = aloca_lista();
	menu(l1);

	return 0;
}

lista * aloca_lista()
{
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->qtd=0;
	aux->inicio=NULL;
	aux->fim=NULL;
	return aux;
}

elemento * aloca_elemento()
{
	elemento * aux;
	aux = (elemento*)malloc(sizeof(elemento));
	aux->valor=0;
	aux->ant=NULL;
	aux->prox=NULL;
	return aux;
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
		aux = l->fim;
		novo->ant = aux;
		aux->prox = novo;
		l->fim = novo;
		
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
		aux = l->inicio;
		novo->prox = aux;
		aux->ant = novo;
		l->inicio = novo;
		
	}
	l->qtd++;
}


elemento * buscar( lista * l, int x)
{
	elemento * aux;
	aux = l->inicio;
	if (l->qtd!=0)
	{
			
		while((aux->valor != x) &&(aux->prox!=NULL))
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
	else
	{
		return NULL;
	}

}


int remover ( lista * l, int x)
{
	elemento *remover, *prev, *next;
	remover = buscar(l,x);
	if (remover==NULL)
	{
		
		return 0;
	}
	{
		prev = remover->ant;
		next = remover->prox;
		if (prev!=NULL)
		{
			prev->prox=next;
		}
		else
		{
			l->inicio = next;
		}
		if (next!=NULL)
		{
			next->ant=prev;
		}
		else
		{
			l->fim = prev;
		}
		free(remover);
		l->qtd--;
		return 1;
	}
}

void mostrar(lista * l)
{
	elemento * aux;
	
	if (l->qtd==0)
	{
		printf("\n Nao existem elementos na lista");
	}
	else
	{
		aux = l->inicio;	
		printf("\n%d",aux->valor);
		while(aux->prox!=NULL)
		{
			aux=aux->prox;
			printf("\n%d",aux->valor);
		}
	}

	
}


void menu(lista * l)
{
	int opcao;
	int numero;
	
	do
	{
		system("cls");
		printf("\n 1 - Inserir Inicio");
		printf("\n 2 - Inserir Fim");
		printf("\n 3 - Remover Elemento");
		printf("\n 4 - Mostrar Lista");
		printf("\n 5 - Ordenar Lista");
		printf("\n 6 - Sair");
		scanf("%d",&opcao);
		switch (opcao)
		{
			case 1:
				printf("\n Qual numero deseja inserir");
				scanf("%d",&numero);
				inserir_inicio(l,numero);
				break;
			case 2:
				printf("\n Qual numero deseja inserir");
				scanf("%d",&numero);
				inserir_fim(l,numero);
				
				break;
			case 3:
				printf("\n Qual numero deseja remover");
				scanf("%d",&numero);
				if(remover(l,numero))
				{
					printf("\n Elemento %d removido com sucesso",numero);
				}
				else
				{
					printf("\n Elemento %d nao esta na lista",numero);
				}
				break;
			case 4:
				mostrar(l);
				break;
			case 5:
				ordenar(l);
				break;
			case 6:
				printf("\n Saindo do programa.. \n");
				break;
			default:
				printf("\n Opcao invalida");
				break;
		}
		printf("\n");
		system("pause");
		
		
	}while(opcao!=6);
}


void ordenar(lista * l)
{
	elemento * i, *j;
	int aux;
	
	i=l->inicio;
	while(i->prox!=NULL)
	{
		j=i->prox;
		while(j!=NULL)
		{
			if (i->valor>j->valor)
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


