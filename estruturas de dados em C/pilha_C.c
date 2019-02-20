#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
	int qtd; //total de espaços usados  
	int * elemento; //elementos guardados.
}pilha;

int tamanho;

pilha * alocar ( int tamanho); //define a função alocar.
void menu(pilha * p, int * posicao);
void push(pilha * p, int * posicao, int num);
int stackpop(pilha * aux, int * posicao);
int pop(pilha * aux, int * posicao);


int main (){
	int posicao = 0;
	setlocale(LC_ALL, "Portuguese");
	pilha * p;
	printf("Digite o tamanho da pilha: ");
	scanf("%d", &tamanho);
	p = alocar(tamanho);
	menu(p, &posicao);

	return 0;

}

pilha * alocar ( int tamanho)
{
	pilha * aux;
	aux = (pilha*)malloc(sizeof(pilha));
	aux->qtd= 0;
	aux->elemento = (int*)malloc(sizeof(int)*tamanho);
	return aux;

}


void menu(pilha * p, int * posicao)
{
	fflush(stdin);
	int opcao, val, i;
	do
	{
		system("CLS");
		printf("Tamanho da pilha: %d\n", tamanho);
		printf("\n 1 - Push");
		printf("\n 2 - Pop");
		printf("\n 3 - Size");
		printf("\n 4 - Stackpop");
		printf("\n 5 - Empty");
		printf("\n 6 - mostrar pilha");
		printf("\n 7 - Sair\n");
		fflush(stdin);
		printf("Digite sua opção: ");
		scanf("%d",&opcao);

		switch(opcao)
		{
			case 1: 
				printf("Digite o valor desejado: ");
				scanf("%d", &val);
				push(p, posicao, val);
				break;
			case 2:
				i = pop(p, posicao);
				if(i =! 0){
					printf("O valor no topo é %d\n", pop(p, posicao));
					getch();
				}
				else{
					printf("\n Stack underflow! \n");
					getch();
				}
				break;
			case 3:
				printf("\nNo momento existem %d itens na pilha.", *posicao);
				getch();
				break;
			case 4:
				i = stackpop(p, posicao);
				if(i != 0){
					printf("Item do topo da pilha: %d\n", i);
					getch();
				}
				else{
					printf("Não há itens na pilha.\n");
					getch();
				}
				break;
			case 5:
				if(*posicao != 0){
					printf("\nExistem itens na pilha");
					getch();
				}
				else{
					printf("\nA pilha está vazia.");
					getch();
				}
				break;
			case 6:
				mostrar(p, posicao);
				break;
			case 7:
				printf("\n Saindo do programa ");
				break;
			default:
				printf("\n Opcao invalida");
				getch();
				break;
		}
	}while(opcao != 7);


}

void push(pilha * aux, int * posicao, int num){
	if(*posicao >= tamanho){
		printf("\n Stack overflow! \n");
		getch();
		return;
	}
	else{
		fflush(stdin);
		aux->elemento[*posicao] = num;
		*posicao = *posicao + 1;
	}
}

int pop(pilha * aux, int * posicao){
	int i, num;
	if(*posicao <= 0){
		return 0;
	}
	else{
		*posicao = *posicao - 1;
        return aux->elemento[*posicao];
		
	}
	
}


int stackpop(pilha * aux, int * posicao){
	int paux = *posicao - 1;
	if(paux < 0){
		return 0;
	}
	else{
		return aux->elemento[paux];
	}
}

void mostrar(pilha * aux, int *posicao){
	int i;
	printf("Pilha: ");
	for(i=*posicao;i<0;i--)
	{
		printf("%d ", aux->elemento[*posicao]);
	}
	getch();
}
