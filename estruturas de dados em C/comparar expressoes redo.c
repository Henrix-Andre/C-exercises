#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#define max 50

typedef struct{
	char * item;
	int qtd;
}pilha;

pilha * alocar(){
	pilha * aux;
	aux = (pilha*)malloc(sizeof(pilha));
	aux->item = NULL;
	aux->qtd = 0;
	return aux;
}

void push(pilha * p, char x){
	char a;
	char * aux;																																																																																																																				
	if(p->qtd == 0){
		p->item = (char*)malloc(sizeof(char));
	}
	else{
		aux = (char*)realloc(p->item,(p->qtd+1)*sizeof(char));
		p->item = aux;
	}
	p->item[p->qtd] = x;
	p->qtd++;
}

void pop(pilha * p){
	char * aux;
	if(p->qtd == 0){
		free(p->item);
	}
	else{
		aux = (char*)realloc(p->item,(p->qtd-1)*sizeof(char));
		p->item = aux;
	}
	p->qtd--;
}

int empty(pilha * p){
	if(p->qtd == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int comparar(pilha * p, char * x, char * y){
	int i, j;
	i = 0; 
	j = strlen(y) - 1;
	for(i = 0; i < strlen(x); i++){
		if(x[i] == y[j]){
			continue;
		}
		else{
			push(p, x[i]);
		}
		j--;
	}while (i<strlen(x));
	if(empty(p) != 0){
		return 1;
	}
	else{
		return 0;
	}
}


int main(){
	setlocale(LC_ALL, "portuguese");
	pilha * p;
	char a[max], b[max];
	int x;
	p = alocar();
	printf("Digite a primeira expressão: ");
	gets(a);
	fflush(stdin);
	printf("\nDigite a segunda expressão: ");
	gets(b);
	if(strlen(a) != strlen(b)){
		printf("\nExpressões de tamanhos diferentes, não é possível serem iguais.");
	}
	else{
		x = comparar(p,a,b);
		if(x == 0){
			printf("\nExpressões válidas.");
		}
		else{
			printf("\nExpressões inválidas.");
		}
	}
}

