#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

typedef struct{
	int * item;
	int qtd;
}pilha;

pilha * alocar(){
	pilha * aux;
	aux = (pilha*)malloc(sizeof(pilha));
	aux->qtd = 0;
	aux->item = NULL;
	return aux;
}

void push(pilha * p, int x){
	int * aux;
	if(p->qtd == 0){
		p->item = (int*)malloc(sizeof(int)); //aqui não existe a pilha ainda
	}
	else{
		aux = (int*)realloc(p->item,(p->qtd+1)*sizeof(int)); //aqui já existe, mas pra não apagar a pilha faz o realloc fora dela.
		p->item = aux;
	}
	p->item[p->qtd] = x;
	p->qtd++;
}

int pop(pilha * p){
	int * aux;
	int remover;
	if(p->qtd == 0){
		remover = 0;
	}
	else{
		if(p->qtd == 1){
			remover = p->item[p->qtd];
			free(p->item);
		}
		else{
			aux = (int*)realloc(p->item,(p->qtd-1)*sizeof(int));
			remover = p->item[p->qtd];
			p->item = aux;
		}
		p->qtd--;
	}
	return remover;
}

int stackpop(pilha * p){
	if(p->qtd != 0){
		return p->item[p->qtd-1]; //por causa da contagem que os vetores seguem, ex.: 5 iria de 0 até 4.
	}
	else{
		return 0;
	}
}

int empty(pilha * p){
	if(p->qtd == 0){
		return 0;
	}
	else{
		return p->qtd;
	}
}

void mostrar(pilha * p){
	int i;
	if(p->qtd == 0){
		printf("\nPilha vazia.");
		getch();
	}
	else{
		for(i = 0; i < p->qtd; i++){
			printf("\n%d", p->item[i]);
		}
	}
}

void quick_sort(pilha *a, int inicio, int fim) { 
    int i, j, k, x, y;
     
    i = inicio; //pega um ponto para ser o pivô na função
    j = fim;    //nesse caso pegamos o inicio e o final do vetor
    k = (i + j)/2;
    x = a->item[k]; //aqui pegamos o meio do vetor (se aplicável)
     
    while(i <= j) {
        while(a->item[i] < x && i < fim) {
            i++;
        }
        while(a->item[j] > x && j > inicio) {
            j--;
        }
        if(i <= j) { //se i for maior que j, faz a troca.
            y = a->item[i];
            a->item[i] = a->item[j];
            a->item[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > inicio) { //faz a recursividade aqui
        quick_sort(a, inicio, j); //pega do início até a metade do vetor
    }
    if(i < fim) {
        quick_sort(a, i, fim); //pega da metade do vetor até o final
    }
}


void menu(pilha * p){
	int opt, num;
	do{
		fflush(stdin);
		system("CLS");
		printf("(1)push\n(2)pop\n(3)stackpop\n(4)empty\n(5)mostrar pilha\n(6)ordenar\n(7)sair\n");
		printf("-----------------------------------------------------\n");
		printf("Digite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("Digite o número a ser adicionado: ");
				scanf("%d", &num);
				push(p, num);
				break;
			case 2:
				num = pop(p);
				if(num == 0 && p->qtd == 0){
					printf("\nStack underflow/pilha vazia.");
					getch();
				}
				else{
					printf("\nNúmero removido: %d", num);
					getch();
				}
				break;
			case 3:
				if(stackpop(p)){
					printf("\nNúmero no topo da pilha: %d", stackpop(p));
					getch();
				}
				else{
					printf("\nStack underflow/pilha vazia.");
					getch();
				}
				break;
			case 4:
				num = empty(p);
				if(num == 0){
					printf("\nPilha vazia.");
					getch();
				}
				else{
					printf("\nExistem itens na pilha.");
					getch();
				}
				break;
			case 5:
				mostrar(p);
				getch();
				break;
			case 6:
				quick_sort(p,0,p->qtd-1);
				printf("\nOrdenado.");
				getch();
				break;
			case 7:
				printf("\nEncerrando.");
				getch();
				break;
			default:
				printf("\nOpção inválda");
				getch();
				break;
		}
	}while(opt != 7);
}

int main(){
	setlocale(LC_ALL, "portuguese");
	pilha * p;
	p = alocar();
	menu(p);
	return 0;
}

