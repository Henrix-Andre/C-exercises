#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#define max 20

typedef struct{
	int * item;
	int qtd;
}pilha;

pilha * alocar(){
	pilha * aux;
	aux = (pilha*)malloc(sizeof(pilha));
	aux->item = NULL;
	aux->qtd = 0;
	return aux;
}

void push(pilha * p, int a){
	int * num;
	if(p->qtd == 0){
		p->item = (int*)malloc(sizeof(int));
	}
	else{
		num = (int*)realloc(p->item,(p->qtd+1)*sizeof(int));
		p->item = num;
	}
	p->qtd++;
	p->item[p->qtd] = a;
}

void pop(pilha * p){ //nesse caso vai ser void pq não precisamos que retorne nada.
	int * remover;
	if(p->qtd != 0 && p->qtd != 1){
		remover = (int*)realloc(p->item,(p->qtd-1)*sizeof(int));
		p->item = remover;
	}
	else{
		free(p->item);
	}
	p->qtd--;
}

int empty(pilha * p){
	if(p->qtd == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int comparar_parenteses(char * expr, pilha * comp, pilha * certo){
	int i;
	for(i = 0; i < strlen(expr); i++){
		if(expr[i] == '('){
			push(comp, 1);
		}
		else if(expr[i] == ')'){
			if(empty(comp)){
				return 0;
			}
			else{
				pop(comp);
			}
		}
		else{
			continue;
		}
	}
	if(empty(comp) == 0){
		push(certo, 1);
	}
}
int comparar_colchetes(char * expr, pilha * comp, pilha * certo){
	int i;
	for(i = 0; i < strlen(expr); i++){
		if(expr[i] == '['){
			push(comp, 1);
		}
		else if(expr[i] == ']'){
			if(empty(comp)){
				return 0;
			}
			else{
				pop(comp);
			}
		}
		else{
			continue;
		}
	}
	if(empty(comp) == 0){
		push(certo, 1);
	}
}
int comparar_elChavo(char * expr, pilha * comp, pilha * certo){
	int i;
	for(i = 0; i < strlen(expr); i++){
		if(expr[i] == '{'){
			push(comp, 1);
		}
		else if(expr[i] == '}'){
			if(empty(comp)){
				return 0;
			}
			else{
				pop(comp);
			}
		}
		else{
			continue;
		}
	}
	if(empty(comp) == 0){
		push(certo, 1);
	}
}


int main(){
	setlocale(LC_ALL, "portuguese");
	char expA[max];
	pilha * comparar;
	pilha * verificar;
	comparar = alocar();
	verificar = alocar();
	printf("digite a expressão: ");
	gets(expA);
	fflush(stdin);
	comparar_parenteses(expA, comparar, verificar);
	comparar_colchetes(expA, comparar, verificar);
	comparar_elChavo(expA, comparar, verificar);
	if(empty(comparar) == 0 && empty(verificar) == 1){
		printf("\nExpressão válida.");
	}
	else{
		printf("\nExpressão inválida.");
	}
}

