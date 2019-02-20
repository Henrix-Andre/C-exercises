#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int ini;
    int fim;
}elemento;

int tamanho=100;
int pos=0;
elemento pilha[100];

void limpa_pilha(){
    int i;
    for(i=0;i<tamanho;i++)
    {
        pilha[i].ini =0;
        pilha[i].fim=0;
    }
}

void push(int inicio, int fim){	
    if (pos>=100)
    {
        printf("\n Pilha cheia");
    }
    else
    {
        pilha[pos].ini = inicio;
        pilha[pos].fim = fim;
        pos++; 
    }
}

elemento pop (){
    if (pos==0) {
        printf("\n Nao existem elementos na pilha");
    }
    else{
        pos--;
        return pilha[pos];
    }
}

int empty(){
	if (pos==0){
		return 1;
	}
	else{
		return 0;
	}
}

void mostrar(){
	int i;
	
	if (pos==0){
		printf("\n Pilha vazia");
	}
	else{
			
		for(i=0;i<pos;i++)
		{
			printf("\n %d %d",pilha[i].ini,pilha[i].fim);
		}	
	}

}
