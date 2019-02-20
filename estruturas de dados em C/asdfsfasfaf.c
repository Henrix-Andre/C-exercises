#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct fila{
	int qtd;
	int inicio;
	int fim;
	int * elemento;
}fila;

fila * alocar(){
	fila * aux;
	aux = (fila*)malloc(sizeof(fila));
	int qtd = 0;
	int inicio = 0;
	int fim = 0;
	int elemento = NULL;
	return aux;
}

void push(fila * f, int x){
	int * aux;
	if(f->qtd == 0){
		f->elemento = (int*)malloc(sizeof(int));
	}
	else{
		aux = (int*)realloc(f->elemento,(f->qtd+1)*sizeof(int));
		f->elemento = aux;
	}
	f->elemento[f->qtd] = x;
	f->qtd++;
	f->fim = f->qtd - 1;
}

int pop(fila * f){
	int * y, x;
	if(f->qtd == 0){
		return 0;
	}
	else if(f->qtd == 1){
		free(f->elemento);
		f->qtd--;
		f->fim = 0;
	}
	else{
		y = (int*)realloc(f->elemento,(f->qtd - 1)*sizeof(int));
		x = f->elemento[f->inicio];
		f->elemento = y;
		f->qtd--;
		f->inicio++;
	}
	return x;
}

int empty(fila * f){
	if(f->qtd != 0){
		return 1;
	}
	else{
		return 0;
	}
}

int stackpop(fila * f){
	int x;
	if(f->qtd == 0 && f->elemento[f->inicio] != 0){
		return 0;
	}
	else{
		x = f->elemento[f->inicio];
		return x;
	}
}

void mostrar(fila * f){
	int i;
	if(f->qtd == 0){
		printf("\nFila vazia.");
	}
	else if(f->inicio == f->fim){
		printf("\nFila vazia.");
	}
	else{
		for(i = f->inicio; i < f->fim; i++){
			printf("\n%d", f->elemento[i]);
		}
	}
}

void menu(fila * f){
	int opt, num;
	do{
		system("CLS");
		printf("\n(1)push\n(2)pop\n(3)empty\n(4)stackpop\n(5)mostrar\n(6)sair\n");
		printf("opcao: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Digite o numero: ");
				scanf("%d", &num);
				push(f, num);
				break;
			case 2:
				num = pop(f);
				printf("numero removido: %d", num);
				getch();
				break;
			case 3:
				num = empty(f);
				if(num != 0){
					printf("\nExistem %d itens na fila.", f->qtd);
					getch();
				}
				else{
					printf("\nFila vazia.");
					getch();
				}
				break;
			case 4:
				num = stackpop(f);
				printf("proximo a ser atendido: %d", num);
				getch();
				break;
			case 5:
				mostrar(f);
				getch();
				break;
			case 6:
				printf("\nEncerrando.");
				break;
			default:
				printf("\nOpcao invalida.");
				getch();
				break;
		}
	}while (opt!= 6);
}

int main(){
	fila * f;
	f = alocar();
	menu(f);
	return 0;
}

