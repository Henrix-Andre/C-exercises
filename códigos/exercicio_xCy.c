#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
	int qtd;
	char * elementos;
}pilha;


pilha * alocar_pilha ();
char * aloca_elemento(int qtd);
void push(pilha * p, char letra);
void mostrar_elementos(pilha * p);
char pop (pilha * p);
void size (pilha * p);
char stackpop(pilha * p);
int empty(pilha *p);

int main()
{
	pilha * p1;
	int i;
	int erro=0;
	char expressao[50];
	p1 = alocar_pilha();
	char letra;
	
	printf("Digite a expressao: \n");
	fflush(stdin);
	gets(expressao);
	
	for(i=0;expressao[i]!='C';i++)
	{
		push(p1,expressao[i]);
		
	}
	printf("Estou no C = %c",expressao[i]);
	i++;
	
	for(i=i;i<strlen(expressao);i++)
	{
		if (empty(p1))
		{
			erro=1;
		}
		else
		{
			letra = pop(p1);
			if (letra !=expressao[i])
			{
				erro=1;
			}
		}
	}
	
	if (erro)
	{
		printf("expressao invalida");
	}
	else
	{
		printf("expressao valida");
	}

	
	
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

void push(pilha * p, char letra)
{
	
	
	char * aux;	
	if (p->qtd==0)
	{
		p->elementos=aloca_elemento(1);	
		
	}	
	else
	{
		aux = (char*)realloc(p->elementos,((p->qtd)+1)*sizeof(char));
		p->elementos=aux;	
	}
	p->elementos[p->qtd] = letra;
	p->qtd++;
}

char * aloca_elemento(int qtd)
{
	char * aux;
	aux = (char *)malloc(sizeof(char)*qtd);
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
			printf("\n %c",p->elementos[i]);
		}
	}
	
	

}
char pop (pilha * p )
{
	char * aux;
	char retorno;
	if (p->qtd==0)
	{
		printf("Nao existem elementos na pilha");
	}
	else
	{
		
		retorno = p->elementos[p->qtd-1];
		if (p->qtd==1)
		{
			free(p->elementos);
			p->elementos=NULL;
		}
		else
		{
			aux = (char*)realloc(p->elementos,(p->qtd-1)*sizeof(char));
			p->elementos = aux;		
		}
		p->qtd--;
	}
	return retorno;
}

void size (pilha * p)
{
	printf("\n Tamanho da pilha : %d",p->qtd);
	mostrar_elementos(p);
}

char stackpop(pilha * p)
{
	char retorno;
	if (p->qtd==0)
	{
		printf("Nao existem elementos na pilha");
	}
	else
	{
		printf("\nStack pop ->>> %d",p->elementos[p->qtd-1]);
	}
	retorno = p->elementos[p->qtd-1];
	return retorno;
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


