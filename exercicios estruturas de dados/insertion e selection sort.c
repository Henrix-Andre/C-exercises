#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
//smith waterman algorithm -> ver essa jo�a
/*
INSERTION SORT
Consiste em pegar um item no vetor (x1), e verificar se ele � menor que os que est�o atr�s dele e encontrar qual a posi�ao que ele fica.
Vai verificando os itens anteriores at� ou chegar no fim do vetor ou encontrar um item que � menor que x1 (se um item for maior que x1, ele se move).
Quando uma das condi��es � alcan�ada o item vai para a posi��o nova e todos os itens na frente dele movem uma posi��o para frente.
VANTAGEM: � bom pra quando a primeira metade de um vetor est� embaralhada. Poss�velmente bom pra ordenar lista?
DESVANTAGEM: � meio bosta (mas ainda sim menos que o bubblesort).
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

/*void insert(int v[], int n){ esse � o que a sabrina fez
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
Na primeira passagem percore o vetor do inicio ao fim, buscando o menor elemento dentro dele. tipo, faz um for que pega uma vari�vel checando se � menor ou n�o, e guarda o �NDICE da menor vari�vel
Depos disso, fa�a uma troca de um jeito que a vari�vel no come�o do vetor vai ser a menor do vetor como um todo.
Agora, repita o processo anterior, do �ndice a frente do inicial, verificando qual � o menor item e trocando pra ele ficar no �ndice em que come�amos a verificar.
Vai repetindo essa jo�a at� terminar o vetor (at� os ultimos dois elementos)
VANTAGENS: at� que � bacana a aplica��o dele. -o professor literalmente n�o disse nenhuma vantagem ou caso espec�fico pra usar essa jo�a-
DESVANTAGENS: eificiente esse tro�o com certeza n�o �, e � desnecess�riamente complexo.
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
	printf("Digite sua op��o: ");
	scanf("%c", &opt);
	if(opt == 'I'){
		insert(x, 6);
	}
	else if(opt == 'S'){
		select(x,6);
	}
	else{
		printf("\nOp��o inv�lida!");
	}
	printf("Ordenado:");
	for(i = 0; i < 5; i++){
		printf(" %d ", x[i] );
	}
	printf("\n");	
	return 0;
}
