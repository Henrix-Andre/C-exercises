#include <stdio.h>
#include <stdlib.h>

void selection(int * vetor, int tamanho){
	int i, j, aux, min;
	for(i = 0; i < tamanho; i++){
		min = i;
		for(j = i + 1; j < tamanho; j++){
			if(vetor[j] < vetor[min]){
				min = j;
			}
		}
		aux = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = aux;
	}
}

void insertion(int * vetor, int tamanho){
	int i, j, aux;
	for(i = 1; i < tamanho; i++){
		aux = vetor[i];
		for(j = i - 1; j >= 0 && aux < vetor[j]; j--){
			vetor[j+1] = vetor[j];
		}
		vetor[j+1] = aux;
	}
}

int main(){
	int i, j = 7;
	int vetor[] = {7,3,4,5,9,2,8};
	selection(vetor, j);
	//insertion(vetor, j);
	for(i = 0;i < 7; i++){
		printf("%d  ", vetor[i]);
	}
}

