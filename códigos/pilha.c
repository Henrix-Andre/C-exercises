#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int qtd;
	int * elementos;
}pilha;


pilha * alocar_pilha ();
int * aloca_elemento(int qtd);
void push(pilha * p);
void mostrar_elementos(pilha * p);
void pop (pilha * p);
void size (pilha * p);
void stackpop(pilha * p);
void impar_par(pilha * p);

int main()
{
	int opcao;
	pilha * p1;
	p1 = alocar_pilha();
	do
	{
		system("cls");
		printf("\nQuantidade de elementos na pilha: %d",p1->qtd);
		printf("\n 1- Push");
		printf("\n 2- Mostrar");
		printf("\n 3- Pop");
		printf("\n 4- Size");
		printf("\n 5- Stackpop");
		printf("\n 6- Sair");
		printf("\n 7 - impar par");
		scanf("%d",&opcao);
		switch(opcao)
		{
			case 1:
				
				push(p1);
				break;
			case 2:
				
				mostrar_elementos(p1);
				break;
			case 3:
				pop(p1);
				
				break;
			case 4:
				size(p1);
				
				break;
			case 5:
				stackpop(p1);
				break;
			case 6:
				
				printf("Saindo do programa");
				break;
			case 7:
				impar_par(p1);
				break;
			default:
				printf("opcao invalida");
				break;
		}
		printf("\n");
		system("pause");
	}while(opcao!=6);
	
	return 0;
}

pilha * alocar_pilha ()
{
	pilha * aux;
	aux =(pilha*)malloc(sizeof(pilha));
	aux->elementos=NULL;
	aux->qtd=0;
	return aux;
	
}

void push(pilha * p)
{
	
	int x;
	int * aux;
	
	
	printf("Digite o numero que deseja inserir");
	scanf("%d",&x);
	
	if (p->qtd==0)
	{
		p->elementos=aloca_elemento(1);	
		
	}	
	else
	{
		aux = (int*)realloc(p->elementos,((p->qtd)+1)*sizeof(int));
		p->elementos=aux;	
	}
	p->elementos[p->qtd] = x;
	p->qtd++;
}

int * aloca_elemento(int qtd)
{
	int * aux;
	aux = (int *)malloc(sizeof(int)*qtd);
	return aux;
}

void mostrar_elementos(pilha * p)
{
	int i;
	if (p->qtd==0)
	{
		printf("\nNao existem elementos na pilha.");
	}
	else
	{
		printf("\nElementos da Pilha: ");	
		for(i=0;i<p->qtd;i++)
		{
			printf("\n %d",p->elementos[i]);
		}
	}
	
	

}
void pop (pilha * p)
{
	int * aux;
	if (p->qtd==0)
	{
		printf("Nao existem elementos na pilha");
	}
	else
	{
		printf("\nPop Realizado ->>> %d",p->elementos[p->qtd-1]);
		if (p->qtd==1)
		{
			free(p->elementos);
			p->elementos=NULL;
		}
		else
		{
			aux = (int*)realloc(p->elementos,(p->qtd-1)*sizeof(int));
			p->elementos = aux;		
		}
		p->qtd--;
	}
}

void size (pilha * p)
{
	printf("\n Tamanho da pilha : %d",p->qtd);
	mostrar_elementos(p);
}

void stackpop(pilha * p)
{
	if (p->qtd==0)
	{
		printf("Nao existem elementos na pilha");
	}
	else
	{
		printf("\nStack pop ->>> %d",p->elementos[p->qtd-1]);
	}
}

void impar_par(pilha * p)
{
	int * aux;
	int i=0,j;
	aux = (int*)malloc(sizeof(int)*p->qtd);
	
	j=0;
	
	for(i=0;i<p->qtd;i++)
	{
		if (p->elementos[i]%2==0)
		{
			aux[j] = p->elementos[i];
			j++;
		}
	}
	for(i=0;i<p->qtd;i++)
	{
		if (p->elementos[i]%2!=0)
		{
			aux[j] = p->elementos[i];
			j++;
		}
	}
	p->elementos=aux;
	
}


