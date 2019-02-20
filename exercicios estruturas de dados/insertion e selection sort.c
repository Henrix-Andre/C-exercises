#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
//smith waterman algorithm -> ver essa joça
/*
INSERTION SORT
Consiste em pegar um item no vetor (x1), e verificar se ele é menor que os que estão atrás dele e encontrar qual a posiçao que ele fica.
Vai verificando os itens anteriores até ou chegar no fim do vetor ou encontrar um item que é menor que x1 (se um item for maior que x1, ele se move).
Quando uma das condições é alcançada o item vai para a posição nova e todos os itens na frente dele movem uma posição para frente.
VANTAGEM: é bom pra quando a primeira metade de um vetor está embaralhada. Possívelmente bom pra ordenar lista?
DESVANTAGEM: é meio bosta (mas ainda sim menos que o bubblesort).
*/

//website bom http://www.ft.unicamp.br/liag/siteEd/implementacao/insertion-sort.php

void insert(int vetor[], int qtd){
	register int i,j, aux;
	for(i = 1; i < qtd; i++){
		aux = vetor[i];
		for(j = i-1; j >= 0 && aux < vetor[j]; j--){
			vetor[j+1] = vetor[j];
		}
		vetor[j+1] = aux;
	}
}

/*void insert(int v[], int n){ esse é o que a sabrina fez
  int k,i,y;
  for (k = 1; k < n; k++) {
    y=v[k];
    for(i = k-1; i>=0 && v[i]>y; i--){
      v[i+1]=v[i];
    }
    v[i+1]=y;
  }
}*/

/*
SELECTION SORT
Na primeira passagem percore o vetor do inicio ao fim, buscando o menor elemento dentro dele. tipo, faz um for que pega uma variável checando se é menor ou não, e guarda o ÍNDICE da menor variável
Depos disso, faça uma troca de um jeito que a variável no começo do vetor vai ser a menor do vetor como um todo.
Agora, repita o processo anterior, do índice a frente do inicial, verificando qual é o menor item e trocando pra ele ficar no índice em que começamos a verificar.
Vai repetindo essa joça até terminar o vetor (até os ultimos dois elementos)
VANTAGENS: até que é bacana a aplicação dele. -o professor literalmente não disse nenhuma vantagem ou caso específico pra usar essa joça-
DESVANTAGENS: eificiente esse troço com certeza não é, e é desnecessáriamente complexo.
*/

void select(int vetor[], int qtd){
	int i, j, min, aux;
	for(i = 0; i<qtd-1; i++){
		min = i;
		for(j = i+1; j<qtd; j++){
			if(vetor[j] < vetor[min]){
				min = j;
			}
		}
		aux = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = aux;
	}
	return ;
}

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

int main(){
	pthue();
	int i;
	int x[] = {13, 7, 5, 1, 4, 3};
	char opt;
	printf("(I)nsert sort ou (S)elect sort?\n");
	printf("Digite sua opção: ");
	scanf("%c", &opt);
	if(opt == 'I'){
		insert(x, 6);
	}
	else if(opt == 'S'){
		select(x,6);
	}
	else{
		printf("\nOpção inválida!");
	}
	printf("Ordenado:");
	for(i = 0; i < 5; i++){
		printf(" %d ", x[i] );
	}
	printf("\n");	
	return 0;
}
