#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Faça um programa que receba uma string com uma expressao
//numerica e diga se ela é valida.
// Uma expressão é dada como válida, quando para cada parentes
//aberto existe um fechado, e nunca existe um parente fechando
//sem que exista um aberto anteriormente;

typedef struct
{
	int qtd;
	char * elemento;
}pilha;

pilha * alocar ();
void push(pilha * p, char x);
char pop(pilha * p);
char stackpop(pilha * p);
int empty(pilha *p);
void mostrar_pilha(pilha * p);


void menu(pilha * p);
int main ()
{
	pilha * p;
	char letra;
	int i;
	int correta=1;
	char expressao[100];
	
	p = alocar();
	
	printf("Digite a expressao");
	fflush(stdin);
	gets(expressao);
	
	for(i=0;i<strlen(expressao);i++)
	{
		if (expressao[i]=='(')
		{
			printf("a");
			push(p,expressao[i]);
			printf("b");
		}
		if (expressao[i]==')')
		{
			
			if (empty(p))
			{
				correta=0;
			}
			else
			{
				letra=pop(p);
			}
		}
	}
	
	if ((empty(p) && correta))
	{
		printf("\nExpressao correta");
	}
	else
	{
		printf("\nExpressao incorreta");
	}
	
	
	
	

//	menu(p);

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
				fflush(stdin);
				scanf("%c",&numero);
				push(p,numero);
				break;
			case 2:
				numero=pop(p);
				printf("\n Numero removido da pilha: %c",numero);
				break;
			case 3:
				mostrar_pilha(p);
				break;
			case 4:
				if (stackpop(p))
				{
					printf("\nelemento no topo da pilha: %c",stackpop(p));
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

void push(pilha * p, char x)
{
	char * aux;
	if (p->qtd==0)
	{
		p->elemento=(char*)malloc(sizeof(char));
	}	
	else
	{
		aux = (char*)realloc(p->elemento,(p->qtd+1)*sizeof(char));	
		p->elemento=aux;
	}

	p->elemento[p->qtd] = x;
	p->qtd++;
}

char pop(pilha * p)
{
	char retorno;
	char * aux;
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
			
			aux =(char*)realloc(p->elemento,(p->qtd-1)*sizeof(char));
			
			p->elemento=aux;
			
			
		}
		p->qtd--;		
	}
	return retorno;

}

char stackpop(pilha * p)
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
			printf("\n %c",p->elemento[i]);
		}	
	}

}
