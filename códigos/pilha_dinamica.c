#include <stdio.h>
#include <stdlib.h>

// Faça um programa que receba uma string com uma expressao
//numerica e diga se ela é valida.
// Uma expressão é dada como válida, quando para cada parentes
//aberto existe um fechado, e nunca existe um parente fechando
//sem que exista um aberto anteriormente;

typedef struct
{
	int qtd;
	int * elemento;
}pilha;

pilha * alocar ();
void push(pilha * p, int x);
int pop(pilha * p);
int stackpop(pilha * p);
int empty(pilha *p);
void mostrar_pilha(pilha * p);


void menu(pilha * p);
int main ()
{
	pilha * p;
	
	
	p = alocar();
	menu(p);

	return 0;
	
}

pilha * alocar ()
{
	pilha * aux;
	aux = (pilha*)malloc(sizeof(pilha));
	aux->qtd=0;
	aux->elemento = NULL;
	return aux;
		
} 


void menu(pilha * p)
{
	int opcao;
	int numero;
	do
	{
		system("cls");
		printf("\n Quantidade de elementos na pilha : %d",p->qtd);
		printf("\n 1 - Push");
		printf("\n 2 - Pop");
		printf("\n 3 - Mostrar Pilha");
		printf("\n 4 - Stackpop");
		printf("\n 5 - Empty");
		printf("\n 6 - Sair");
		scanf("%d",&opcao);
	
		switch(opcao)
		{
			case 1:
				printf("\nDigite um numero");
				scanf("%d",&numero);
				push(p,numero);
				break;
			case 2:
				numero=pop(p);
				printf("\n Numero removido da pilha: %d",numero);
				break;
			case 3:
				mostrar_pilha(p);
				break;
			case 4:
				if (stackpop(p))
				{
					printf("\nelemento no topo da pilha: %d",stackpop(p));
				}
				break;
			case 5:
				if(empty(p))
				{
					printf("\n Pilha vazia");
				}
				else
				{
					printf("\n Existem elementos na pilha");
				}
				
				break;
			case 6:
				printf("\n Saindo do programa ");
				break;
			default:
				printf("\n Opcao invalida");
				break;
		}
		printf("\n\n");
		system("pause");
	}while(opcao !=6);
	
	
}

void push(pilha * p, int x)
{
	int * aux;
	if (p->qtd==0)
	{
		p->elemento=(int*)malloc(sizeof(int));
	}	
	else
	{
		aux = (int*)realloc(p->elemento,(p->qtd+1)*sizeof(int));	
		p->elemento=aux;
	}

	p->elemento[p->qtd] = x;
	p->qtd++;
}

int pop(pilha * p)
{
	int retorno;
	int * aux;
	if (p->qtd==0)
	{
		printf("\n Pilha vazia");
		retorno = 0;
	}
	else
	{
		retorno = p->elemento[p->qtd-1];	
		if (p->qtd==1)
		{
			
			free(p->elemento);	
		}
		else
		{
			
			aux =(int*)realloc(p->elemento,(p->qtd-1)*sizeof(int));
			
			p->elemento=aux;
			
			
		}
		p->qtd--;		
	}
	return retorno;

}

int stackpop(pilha * p)
{
	if (p->qtd==0)
	{
		printf("\n Pilha vazia");
		return 0;
	}
	else
	{
		return p->elemento[p->qtd-1];	
	}
	
}

int empty(pilha *p)
{
	if (p->qtd==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void mostrar_pilha(pilha * p)
{
	int i;
	if (p->qtd==0)
	{
		printf("\n Pilha vazia");
	}
	else
	{
		printf("\n\n Mostrando Pilha:  \n\n");
	
		for(i=p->qtd-1;i>=0;i--)
		{
			printf("\n %d",p->elemento[i]);
		}	
	}

}
