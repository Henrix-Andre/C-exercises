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
	elemento * fim;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();
void push( lista * l, int x);
void mostrar(lista * l);
int buscar(lista * l,int x);
void menu(lista * l);
int pop(lista *  l);
int main()
{


	lista * l1;
	l1 = aloca_lista();
	menu(l1);
	
	return 0;
}

void menu(lista * l)
{
	int opcao;
	int numero;
	elemento * aux;
	do
	{
		system("cls");
		numero=0;
		printf("\n1 - push");
		printf("\n2 - pop");
		printf("\n3 - Empty");
		printf("\n4 - Size");
		printf("\n5 - Mostrar Pilha");
		printf("\n6 - stackpop");
		printf("\n7 - Sair");
		printf("\n Qtd: %d\n",l->qtd);
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:	
				printf("Digite o numero que deseja inserir");
				scanf("%d",&numero);
				push(l,numero);	
					
				break;
			case 2:
				numero = pop(l);
				
				if (numero!=0)
				{
					printf("Removido da pilha: %d",numero);	
				}


						
				break;
			case 3:
				if (l->qtd==0)
				{
					printf("\n Lista vazia");
				}
				else
				{
					printf("\n Lista nao esta vazia");
				}
			
				break;
			case 4:	
				printf("\n Existem %d elementos", l->qtd);			
				break;
			case 5:
				mostrar(l);
				
				break;
			case 6:
				if(l->qtd>0)
				{
					aux = l->fim;
					printf("\nElemento no topo da pilha: %d",aux->valor);	
				}
				else
				{
					printf("\n Lista vazia");
				}

				break;
			case 7:
				printf("\n saindo...");
				break;
			default:
				printf("opcao invalida;");
				break;
		}
		
		printf("\n\n");
		system("pause");
	}while(opcao!=7);
}


lista * aloca_lista()
{
	lista * novo;
	
	novo = (lista*)malloc(sizeof(lista));
	novo->qtd=0;
	novo->fim=NULL;
	return novo;
}

void push( lista * l, int x)
{
	elemento * novo;
	novo = aloca_elemento();
	novo->valor = x;
	
	
	if (l->qtd==0)
	{
		l->fim = novo;
	}
	else
	{
		novo->prox = l->fim;
		l->fim = novo;
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
		printf("\n\n Mostrando Pilha: \n\n");
		aux = l->fim;
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
		aux = l->fim;
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

int pop(lista *  l)
{
	int numero;
	elemento * aux;
	if (l->qtd==0)
	{
		
		printf("\n Lista vazia");
		return 0;
	}
	else
	{
		aux=l->fim;
		l->fim=aux->prox;
		numero = aux->valor;		
		free(aux);
		l->qtd--;
		return numero;
	}
}
