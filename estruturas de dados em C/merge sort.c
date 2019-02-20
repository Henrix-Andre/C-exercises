#include <stdio.h>
#include <stdlib.h>
#include <stdin.h>

/*
MERGESORT
vai dividindo o vetor em grupos menores (de dois em dois)
verifica qual � maior que o outro, coloca em ordem em um vetor auxiliar (de menor pra maior)
retorna os dois pro vetor inicial 
vai recursivamente, e junta dois grupos de dois (declarando um vetor de tamanho 4, e dois marcadores), aplicando a ideia de ver qual � menor e ordenar
os marcadores come�am no inicio de cada subgrupo
vai comparando eles. quem for menor passa pro vetor auxiliar e passa o marcador pro �ndice do lado.
se nao tiver mais pra onde o marcador se mover, coloca o item que ele est� primeiro e depois o resto (do segundo marcador pra frente em sequencia)

Em geral � recursivo, mas � poss�vel fazer sem recursividade.

n�o precisa definitivamente dividir o vetor, � s� colocar �ndices/marcadores que v�o nos pontos do vetor que termina a divis�o
(ex.: i = 0, j = 5, num vetor de 10 �ndices.)

  vantagem: mais r�pido que o bubblesort, mas mais lento que o quicksort, mas tem chance de ser mais eficiente em termos de mem�ria depenendo do tamanho
da coisa que voc� pretende ordenar
  desvantagem: MUITA aloca��o de mem�ria (muito uso de mem�ria auxiliar)
*/

//tamA = tamanho do vetor A, e tamB = mesma coisa so que pro B.
// A fun��o recebe vetores disjuntos crescentes a[0..N-1] e b[0..M-1] 
// e intercala os dois vetores produzindo o vetor crescente c[0..N+M-1].
void marge(int a[]){
	
}

int main(){
	int vet[10] = {9, 4, 5, 8, 6, 3, 7, 10, 1, 2};
}
