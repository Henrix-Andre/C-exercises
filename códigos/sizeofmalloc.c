#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[50]; //awkduawkudh
	float media;
}registro;

registro * alocar(int qtd);
void preencher (registro * alunos , int tamanho);
void ordenar(registro * alunos , int tamanho);
void mostrar(registro * alunos, int tamanho);
int main()
{
	int qtd;
	registro * alunos;
	printf("\nDigite a quantidade de alunos:");
	scanf("%d",&qtd);
	alunos = alocar(qtd);
	preencher(alunos,qtd);
	ordenar(alunos,qtd);
	mostrar(alunos,qtd);
	
	return 0;
}

registro * alocar(int qtd)
{
	registro * aux;
	aux = (registro*)malloc(sizeof(registro)*qtd);
	aux->media=0;
	strcpy(aux->nome," ");
}

void preencher (registro * alunos , int tamanho)
{
	int i;
	
	for(i=0;i<tamanho;i++)
	{
		printf("\nDigite o nome do aluno: ");
		fflush(stdin);
		gets(alunos[i].nome);
		printf("\nDigite a media do aluno: ");
		scanf("%f",&alunos[i].media);
	}
}

void ordenar(registro * alunos , int tamanho)
{
	int i,j;
	registro * aux;
	aux = alocar(1);
	
	for(i=0;i<tamanho-1;i++)
	{
		for(j=i+1;j<tamanho;j++)
		{
			if (alunos[i].media>alunos[j].media)
			{
				*aux = alunos[i];
				alunos[i] = alunos[j];
				alunos[j] = *aux;
			}
		}
	}
	
	
}

void mostrar(registro * alunos, int tamanho)
{
	int i;
	printf("\n\n Relatorio de notas: ");
	for(i=0;i<tamanho;i++)
	{
		printf("\n Nome %s   Media: %.2f  ",alunos[i].nome,alunos[i].media);
	}
}

