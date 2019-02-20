#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIZE 50
void push(int i);
int pop(void);
int *tos, *p1, stack[SIZE]; 

int main(){
	tos = stack;
	p1 = stack;
	int num;
	do{
		system("CLS");
		printf("Digite um valor a ser adicionado na pilha, 0 para retirar o valor do topo e -1 para sair.\n");
		printf("Opcao: ");
		scanf("%d", &num);
		if(num != 0){
			push(num);
		}
		else if(num == 0){
			printf("\nO valor do topo da pilha e %d\n", pop());
			getch();
		}
		else{
			printf("Valor invalido");
			getch();
		}
	}while(num != -1);
}

void push(int i){
	p1++;
	if(p1 == tos + SIZE){
		printf("Estouro da pilha.");
		exit(1);
	}
	else{
		*p1 = i;
		printf("\nValor adicionado: %d", i);
		getch();
	}
}

int pop(void){
	if(p1 == tos || p1 == 0){
		printf("stack underflow");
	}
	p1--;
	return *(p1+1); //o p1-- retira 1 espaço da posição, e return *(p1+1) mostra o valor que previamente estava ali.
}
