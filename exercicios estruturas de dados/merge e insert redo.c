#include <stdio.h>
#include <stdlib.h>
/*
	A ideia do insertion sort é a seguinte: pega dois itens de cada vez, e os ordena.
	Depois pega um terceiro item na sua frente, e o ordena em relação aos dois (na frente deles).
	Vai seguindo isso até o fim do vetor.
*/
void insert(int vetor[], int qtd){
	int i, j, aux;
	for(i = 0; i < qtd; i++){
		aux = vetor[i]; //coloca aux como o item a ser ordenado
		for(j = i-1; j >= 0 && aux < vetor[j]; j--){ //i-1 pra ordenar os itens anteriores ao aux.
			vetor[j+1] = vetor[j]; //reposiciona o item na frente do j
		}
		vetor[j+1] = aux; //reposiciona o aux
	}
	return ;
}
/*
	O selection sort funciona da seguinte maneira: Ele passa pela lista, e coloca o menor número na posição de inicio do vetor.
	Depois vai percorrendo o vetor (só que sem contar o item já ordenado), colocando os menores itens nas posições ordenadas.
	Lembrando que não guardamos o menor item diretamente, mas sim a posição do seu índice.
*/

void selection(int vetor[], int qtd){
	int i,j,min,aux;
	for(i = 0; i < qtd-1; i++){ //como i são as posições, ele deve sempre ser menor que qtd - 1
		min = i; //define o min como a última posição não ordenada
		for(j = i + 1; j < qtd; j++){ //j é a posição na sua frente, e esse loop roda até o fim do vetor
			if(vetor[min] > vetor[j]){ //se o item do vetor na posição j for menor do que na posição do item considerado como o mínimo
				min = j;             //guardamos o índice j como o menor item.
			}
		}
		//faz a troca dos dois
		aux = vetor[i];
		vetor[i] = vetor[min];
		vetor[min] = aux;
	}
	return ;
}

int main(){
    int i;
    int vet[10]={413,210,780,28,345,610,21,6,1050,500};
    //insert(vet,10);
    selection(vet,10);
    for(i=0;i<10;i++){
        printf("\n %d",vet[i]);
    }
    return 0;
}
