#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tamanho 20

char pilha[tamanho];
int pos=0;

void menu();
void push(char x);
char pop();
int empty();
char stackpop();
void mostrar_pilha();

int main()
{
	int i;
	int correta=1;
	char letra;
	char  expressao[50];
	printf("\nDigite a expressao: ");
	fflush(stdin);
	gets(expressao);
	
	
	for(i=0;i<strlen(expressao);i++)
	{
		
		
		if (expressao[i] == '(')
		{
			push(expressao[i]);
		}
		
		if (expressao[i] == ')')
		{
			if (empty())
			{
				correta=0;
			}
			else
			{
				letra = pop();
			}
		}
		
	}
	
	if ((correta==1) && (empty()==1))
	{
		printf("\nexpressao correta");
	}
	else
	{
		printf("\nexpressao incorreta");
	}
	//menu();
	return 0;
}

void menu()
{
	int opcao;
	char letra;
	do
	{
		system("cls");
		printf("\n 1 - Push");
		printf("\n 2 - Pop");
		printf("\n 3 - Empty");
		printf("\n 4 - Stackpop");
		printf("\n 5 - Mostrar Pilha");
		printf("\n 6 - Sair");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1:
				printf("\nDigite o caracter para ser inserido na pilha: ");
				fflush(stdin);
				scanf("%c",&letra);
				push(letra);
				break;
			case 2:
				letra =pop();
				break;
			case 3:
				if (empty())
				{
					printf("\n Nao existem elementos na pilha");
				}
				else
				{
					printf("\n Existem elementos na pilha");
				}
				break;

			case 4:
				letra =stackpop();
				break;
			case 5:
				mostrar_pilha();
				break;
			case 6:
				printf("\nsaindo do programa");
				break;
			default:
				printf("\n opcao invalida");
				break;
				
		}
		printf("\n\n");
		system("pause");
	}while(opcao!=6);
}

void push(char x)
{
	if (pos==tamanho)
	{
		printf("\nElemento nao inserido, pilha cheia");	
	}
	else
	{
		pilha[pos] = x;
		pos++;
		printf("\nElemento %c inserido na pilha",x);
	}	
}
char pop()
{
	char aux=' ';
	
	if (empty())
	{
		printf("\nNao existem elementos na pilha");
	}
	else
	{
		pos--;
		aux = pilha[pos];
		printf("\nElemento %c removido da pilha",aux);
		
	}
	return aux;
}
int empty()
{
	if (pos==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char stackpop()
{
	char aux=' ';
	
	if (empty())
	{
		printf("\nNao existem elementos na pilha");
	}
	else
	{
		
		aux = pilha[pos-1];
		printf("\nElemento %c esta no topo da pilha",aux);
		
	}
	return aux;
}

void mostrar_pilha()
{
	int i;
	if( empty())
	{
		printf("\n Pilha vazia");
	}
	else
	{
		printf("\n\n Mostrando pilha: \n ");
	
		for(i=pos-1;i>=0;i--)
		{
			printf("\n %c",pilha[i]);
		}	
	}
	
}
