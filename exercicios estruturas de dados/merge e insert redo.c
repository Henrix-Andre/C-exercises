#include <stdio.h>
#include <stdlib.h>
/*
	A ideia do insertion sort � a seguinte: pega dois itens de cada vez, e os ordena.
	Depois pega um terceiro item na sua frente, e o ordena em rela��o aos dois (na frente deles).
	Vai seguindo isso at� o fim do vetor.
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
	O selection sort funciona da seguinte maneira: Ele passa pela lista, e coloca o menor n�mero na posi��o de inicio do vetor.
	Depois vai percorrendo o vetor (s� que sem contar o item j� ordenado), colocando os menores itens nas posi��es ordenadas.
	Lembrando que n�o guardamos o menor item diretamente, mas sim a posi��o do seu �ndice.
*/

void selection(int vetor[], int qtd){
	int i,j,min,aux;
	for(i = 0; i < qtd-1; i++){ //como i s�o as posi��es, ele deve sempre ser menor que qtd - 1
		min = i; //define o min como a �ltima posi��o n�o ordenada
		for(j = i + 1; j < qtd; j++){ //j � a posi��o na sua frente, e esse loop roda at� o fim do vetor
			if(vetor[min] > vetor[j]){ //se o item do vetor na posi��o j for menor do que na posi��o do item considerado como o m�nimo
				min = j;             //guardamos o �ndice j como o menor item.
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
