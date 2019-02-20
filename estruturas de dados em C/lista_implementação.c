#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//aqui definem os tipos e/ou structs.
typedef struct elemento{
	int valor;
	struct elemento * prox;
}elemento;
typedef struct lista{
	int qtd;
	struct elemento * inicio; //só usa o struct <nome> porque não colocou o }<nome_do_tipo>;
}lista; 

//definem as funções
lista * alocar_lista(){
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->qtd = 0;
	aux->inicio = NULL;
	return aux;
}
void inserir(lista * l, int num){
	elemento *aux, *novo; //aqui não precisa do struct <nome do struct> porque já foi definido antes.
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor = num;
	novo->prox = NULL;
	if(l->qtd == 0){
		l->inicio = novo;
	}
	else{
		aux = l->inicio;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
	l->qtd++;
}

void remover(lista * l, int x){ //vai verificando item por item, com aux começando desde o l->início, e anti vai sempre checando o item anterior.
	elemento *anti, *aux; //anti = anterior
	aux = l->inicio;//em teoria era pra checar quando o item da lista é o a ser removido, e etnão uma variável vai pegar o valor do aux->prox daquele item
	while(aux != NULL && anti->valor != x){ //ex: lista {1,2,3,4}, se 3 é pra ser removido, depois da remoção, o aux->prox de 2 deve ser 4.
		anti = aux;
		aux = aux->prox;	
	}
	if(aux->prox != NULL){
		anti = aux->prox;
		aux = aux->prox;
		free(anti);
		l->qtd--;
	}
}


//main
int main(){
	setlocale(LC_ALL, "Portuguese");
	int n, opt;
	lista *l1;
	l1 = alocar_lista();
	do{
		printf("\n(1)adicionar item\n(2)remover item\n(3)sair\nDigite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nDigite o valor a ser adicionado: ");
				scanf("%d", &n);
				inserir(l1, n);
				break;
			case 2:
				printf("\nDigite o valor a ser removido: ");
				scanf("%d", &n);
				remover(l1, n);
				break;
			case 3:
				printf("\nEncerrando");
				getch();
				break;
			default:
				printf("\nErro");
				getch();
				break;
		}
	}while(opt != 3);
	
	return 0;
}

