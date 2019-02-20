#include <stdio.h>
#include <stdlib.h>

int pos=0;
int pilha[20];

void push(int x);
int pop();
int empty();
int stackpop();
void mostra_pilha();

void menu();

int main()
{
	menu();
	return 0;
}

void menu()
{
	int opcao,numero;
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
				scanf("%d",&numero);
				push(numero);				
				break;
			case 2:
				numero = pop();
				
				
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
				numero = stackpop();						
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

void push(int x)
{
	if (pos==20)
	{
		printf("\nPilha cheia, elemento nao inserido");
	}
	else
	{
		
		pilha[pos]=x;
		pos++;
		printf("\nNumero %d incluido na pilha",x);
	}
	
}

int pop()
{
	int retorno=0;
	if (pos==0)
	{
		printf("Nao existem elementos na pilha");
	}
	else
	{
		pos--;
		retorno=  pilha[pos];
		pilha[pos] = 0;
		printf("Elemento %d retirado da pilha",retorno);
		
		
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

int stackpop()
{
	int retorno=0;
	if (pos==0)
	{
		printf("Nao existem elementos na pilha");
	}
	else
	{
		
		retorno=  pilha[pos-1];
		
		printf("Elemento %d esta no topo da pilha",retorno);
		
		
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
		printf(" %d",pilha[i]);
	}
}


