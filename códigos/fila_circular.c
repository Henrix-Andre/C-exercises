#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
	int * vetor; //isso equivale a um vetor de tamanho igual a variavel 'tamanho'
	int inicio;
	int fim;
	int tamanho;
}fila;

fila * aloca_fila();
void mostrar( fila * f);
void push(fila * f, int numero);
void menu(fila * f);

int main()
{
	fila * a;
	int i;
	int numero;
	a = aloca_fila();
	menu(a);
	
	
	return 0;
}

fila * aloca_fila()
{
	int i , tamanho;
	fila * novo;
	novo = (fila*)malloc(sizeof(fila));
	printf("\n Digite o tamanho da fila");
	scanf("%d",&tamanho);
	novo->vetor=(int*)malloc(sizeof(int)*tamanho);
	for(i=0;i<tamanho;i++)
	{
		novo->vetor[i] =0;
	}
	novo->inicio   =0; //inicializando os itens
	novo->fim      =0;
	novo->tamanho  = tamanho;
	
	
}

void mostrar( fila * f)
{
	int i;
	
	for(i=0;i<f->tamanho;i++)
	{
		printf("\n %d",f->vetor[i]);
	}
}

void push(fila * f, int numero)
{

	if ((f->inicio==f->fim) && (f->vetor[f->inicio]!=0)) //aqui compara se o ponteiro de inicio voltou para o final
	{ 													 //ou seja, que a função chegou no limite
		printf("\n Fila cheia");
	}
	else
	{

		f->vetor[f->fim] = numero;
		f->fim++;
		if (f->fim == f->tamanho) //chegou no limite, f->fim é igual ao limite do vetor
		{
			f->fim = 0;
		}
	}

}

int pop (fila * f)
{
	int retorno;
	if (f->vetor[f->inicio]==0)
	{
		printf("\n Lista Vazia");
		return 0;
	}
	else
	{
		retorno = f->vetor[f->inicio];
		f->vetor[f->inicio] = 0;
		f->inicio ++; //muda a posição do início.
		if (f->inicio==f->tamanho)
		{
			f->inicio=0;
		}
	}
	return retorno;

}

void menu(fila * f)
{
	int opcao;
	int numero;
	do
	{
		system("cls");
		printf("\n 1 push");
		printf("\n 2 pop");
		printf("\n 3 mostrar\n");
		scanf("%d",&opcao);
		printf("\n");
		switch(opcao)
		{
			case 1:
				printf("\n Digite o numero que deseja isnerir");
				scanf("%d",&numero);
				push(f,numero);
				break;
			case 2:
				numero = pop(f);
				if (numero==0)
				{
					printf("nao tem ninguem na lista");
				}
				else
				{
					printf("numero que saiu = %d",numero);
				}
				break;
			case 3:
				mostrar(f);
				break;
		}
		printf("\n");
		system("pause");
	}while(opcao!=5);
}
