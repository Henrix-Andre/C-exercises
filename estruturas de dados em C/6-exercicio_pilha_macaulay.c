#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

typedef struct
{
    int qtd;
    int * elemento;
}pilha;

int tamanho;

int pop(pilha *p, int * posicao);
void push (pilha *p, int *posicao,int num);
int stackpop(pilha *aux, int *posicao);
pilha * alocar ( int tamanho);
void menu(pilha * p, int* posicao);
void idioma();

int main ()
{
    pilha * p;
    int posicao = 0;
    idioma();

    printf("Digite o tamanho da pilha: ");
    scanf("%d",&tamanho);
    p = alocar(tamanho);

    menu(p , &posicao);

    return 0;
}

pilha * alocar (int tamanho)
{
    pilha * aux;
    aux = (pilha*)malloc(sizeof(pilha));
    aux->qtd=0;
    aux->elemento = (int*)malloc(sizeof(int)*tamanho);
    return aux;

}

void push (pilha *aux, int *posicao,int num)
{
    if(*posicao >= tamanho)
    {
        printf("Pilha cheia.\n");
        return;
    }
    aux->elemento[*posicao] = num;
    *posicao = *posicao +1;
}

int pop(pilha *aux, int *posicao)
{
    if(*posicao <= 0)
    {
        return 0;
    }
    else {
    	*posicao = *posicao - 1;
        return aux->elemento[*posicao];
    }
}

int stackpop(pilha *aux, int *posicao)
{
    int paux = *posicao -1;
    if(paux < 0){
    	return 0;
	}
	else{
		return aux->elemento[paux];
	}
}

void menu(pilha * aux, int* posicao)
{
    int opcao;
    int num, i;
    do
    {
    	system("CLS");
    	printf("Tamanho da pilha: %d\n", tamanho);
        printf("\n 1 - Push");
        printf("\n 2 - Pop");
        printf("\n 3 - Size");
        printf("\n 4 - Stackpop");
        printf("\n 5 - Empty");
        printf("\n 6 - Sair\n");
        scanf("%d",&opcao);

        switch(opcao)
        {
            case 1:
                printf("Digite o número a ser colocado na pilha: ");
                scanf("%d", &num);
                push(aux, posicao, num);
                printf("");
                break;
            case 2:
            	i = pop(aux, posicao);
            	if(i != 0){
            		printf("O Valor do topo da pilha é :  %d\n", pop(aux, posicao));
            		getch();
				}
				else{
					printf("Stack underflow, nenhum item para ser removido.");
					getch();
				}
                break;
            case 3:
                printf("tem %d elementos na pilha\n", *posicao);
                getch();
                break;
            case 4:
                i = stackpop(aux, posicao);
				if(i !=0){
					printf("O elemento do topo da pilha é: %d\n",stackpop(aux,posicao));
				}
				else{
					printf("A lista não tem elementos.");
				}
                getch();
                break;
            case 5:
                *posicao != 0 ? printf("A pilha tem elemntos") : printf("A pilha está vazia");
                getch();
                break;
            case 6:
                printf("Saindo do programa\n");
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(opcao !=6);
}

void idioma()
{
    setlocale(LC_ALL, "portuguese");
}
