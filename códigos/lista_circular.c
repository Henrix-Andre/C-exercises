#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
	int * vetor;
	int tamanho;
	int inicio;
	int fim;
	int qtd;
}fila;

fila * aloca_fila();
void push(fila * f);
void pop(fila * f);
void mostrar(fila * f);
int main()
{
	int opcao;

	fila  * f1;
	f1 = aloca_fila();
	
	do
	{
		system("cls");
		printf("\n 1- push");
		printf("\n 2- pop");
		printf("\n 3- Mostrar");
		printf("\n 4- Sair");
		scanf("%d",&opcao);
		
		switch(opcao)
		{
			case 1:
				push(f1);
				break;
			case 2:
				pop(f1);
				break;
			case 3:
				mostrar(f1);
				break;
			case 4:
				printf("\n Saindo do programa");
				break;
			default:
				printf("\n opcao invalida");
				break;
		}
		printf("\n");
		system("pause");
	}while(opcao!=4);

	
	
}

fila * aloca_fila()
{
	int i;
	int size;
	fila * novo;
	novo = (fila*)malloc(sizeof(fila));
	printf("Digite o size da fila");
	scanf("%d",&size);
	novo->vetor = (int*)malloc(sizeof(int)*size);
	
	for(i=0;i<size;i++)
	{
		novo->vetor[i]=0;
	}
	novo->tamanho = size;
	novo->inicio=0;
	novo->fim = 0;
	novo->qtd=0;
	
	
}

void push(fila * f)

{
	int numero;
	printf("\n Inicio = %d",f->inicio);
	printf("\n Fim    = %d",f->fim);
	if (f->fim==f->tamanho)
	{
		f->fim = 0;
	}
	
	if ((f->inicio == f->fim) && (f->qtd!=0))
	{
		printf("\nFila cheia");
	}
	else
	{
		printf("\nDigite o numero que deseja inserir");
		scanf("%d",&numero);
		

		f->vetor[f->fim] = numero;
		f->fim++;	
		f->qtd++;
	}
	
}

void pop(fila * f)
{
	printf("\n Inicio = %d",f->inicio);
	printf("\n Fim    = %d",f->fim);
	if (f->qtd==0)
	{
		printf("\n Nao existem elementos na fila");
	}
	else
	{
		printf("\n Elemento %d removido da fila ",f->vetor[f->inicio]);
		f->vetor[f->inicio] = 0;
		f->inicio ++;
		f->qtd--;
		if (f->inicio  ==f->tamanho)
		{
			f->inicio = 0;
		}
	}
}

void mostrar(fila * f)
{
	int i;
	printf("\n Mostrando fila");
	for(i=0;i<f->tamanho;i++)
	{
		printf("\n %d",f->vetor[i]);
	}
}
