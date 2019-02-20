#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pos=0;
char pilha[50];

void push(char x);
char pop();
int empty();
char stackpop();
void mostra_pilha();

void menu();

int main()
{
//	menu();
	int i;
	int correta=1;
	char letra;
	char expressao[500];
	printf("\nDigite a expressao");
	fflush(stdin);
	gets(expressao);
	printf("\n\n Mostrando a expressao lida: \n");
	i=0;
	printf("\ntamanho da string %d",strlen(expressao));
	while((i<strlen(expressao)))

	{
	//	printf("\n Valor de I = %d",i);
		if(expressao[i] == '(')
		{	
			printf("\nachei abre");
			push(expressao[i]);
		}
		if (expressao[i]== ')')
		{
			printf("\n Achei fecha");
			if (empty())
			{
				correta=0;
			}
			else
			{
				letra = pop();
				if (letra != '(')
				{
					correta=0;
				}	
			}
		}
		i++;
	}
	
	if ((correta) && (empty()))
	{
		printf("\n\nexpressao sem erros");
	}
	else
	{
		printf("\n\nexpressao com erros");
	}
	return 0;
}

void menu()
{
	int opcao;
	char letra;
	do
	{
		system("cls");
		printf("\n 1- Push");
		printf("\n 2- Pop ");
		printf("\n 3- Empty");
		printf("\n 4- Stackpop");
		printf("\n 5- Mostrar elementos da pilha");
		printf("\n 6- Sair");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1:
				printf("Digite o numero que deseja inserir");
				fflush(stdin);
				scanf("%c",&letra);
				push(letra);				
				break;
			case 2:
				letra = pop();
				
				
				break;
			case 3:
				if (empty())
					{
						printf("\nPilha vazia");
					}
					else
					{
						printf("Existem elementos na pilha");
					}
				break;
			case 4:
				letra = stackpop();						
				break;
				
			case 5:
				mostra_pilha();
				break;
			case 6:
				printf("\n saindo do programa");
				break;
			default:
				printf("\nopcao invalida");
				break;
		}
		printf("\n");
		system("pause");
		
	}while(opcao!=6);
}

void push(char x)
{
	if (pos==20)
	{
		printf("\nPilha cheia, elemento nao inserido");
	}
	else
	{
		
		pilha[pos]=x;
		pos++;
		printf("\nNumero %c incluido na pilha",x);
	}
	
}

char pop()
{
	char retorno=0;
	if (pos==0)
	{
		printf("Nao existem elementos na pilha");
	}
	else
	{
		pos--;
		retorno=  pilha[pos];
		pilha[pos] = 0;
		printf("Elemento %c retirado da pilha",retorno);
		
		
	}
	
	return retorno;	
	
}

int empty()
{
	if (pos==0)
		return 1;
	else
		return 0;
	
}

char stackpop()
{
	char retorno= ' ';
	if (pos==0)
	{
		printf("Nao existem elementos na pilha");
	}
	else
	{
		
		retorno=  pilha[pos-1];
		
		printf("Elemento %c esta no topo da pilha",retorno);
		
		
	}
	
	return retorno;	
	
}

void mostra_pilha()
{
	int i;
	system("cls");
	
	printf("\n\n\n Mostrando pilha");
	for(i=0;i<pos;i++)
	{
		printf(" %c",pilha[i]);
	}
}


