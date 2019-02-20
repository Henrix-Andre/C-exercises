#include <stdio.h>
#include <stdlib.h>

void intercala(int ini, int fim, int meio, int vet[]){
	int i,j,k,*aux;
	i = ini;
	j = meio+1;
	k = 0;
	aux = (int*)calloc(sizeof(int), fim-ini+1); //tem que ser por calloc
	while(i <= meio && j <= fim){
		if(vet[i] <= vet[j]){ //divide por tamanho cada um dos itens de cada grupo.
			aux[k] = vet[i];
			i++;
		}
		else{
			aux[k] = vet[j];
			j++;
		}
		k++;
	}
	//vai colocando os itens todos de volta no aux
	while(i<=meio){
		aux[k] = vet[i];
		i++;
		k++;	
	}
	while(j<=fim){
		aux[k]=vet[j];
		j++;
		k++;
	}
	//passa tudo pro vetor principal
	for(i = 0; i<(fim-ini)+1; i++){
		vet[ini + i] = aux[i];
	}
	free(aux);
	return ;
}

void mergesort(int ini, int fim, int vet[]){
	int meio;
	if(ini < fim){
		meio = (ini+fim)/2;
		mergesort(ini,meio,vet); //aqui separam as duas metades do vetor nos grupos menores via recursividade
		mergesort(meio+1,fim,vet);
		intercala(ini,fim,meio,vet);
	}
	return ;
}

int main(){
	int i;
    int vet[10]={413,210,780,28,345,610,21,6,1050,500};
    mergesort(0,9,vet);
    for(i=0;i<10;i++){
        printf("%d ",vet[i]);
    }
    return 0;
}

