#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void bubblesort(int vet[], int inicio, int fim){
	int i, j, aux;
	bool SWAPPED = false; //tem que ter o stdbool
	if(inicio == fim){
		return;
	}
	else{
		for(i = 0; i < fim - 1; i++){
			for(j = 0; j < fim - i - 1; j++){
				if(vet[j] > vet[j+1]){
					aux = vet[j+1];
					vet[j+1] = vet[j];
					vet[j] = aux;
					SWAPPED = true;	//verifica se o vetor na posição j é maior que o na posição a sua frente
				}					//faz a troca e marca que ouve uma troca.
			}
			if(!SWAPPED){
				break; //se verificou e não teve nenhuma troca, então quer dizer que já está ordenado.
			}
		}
	}
}

void quicksort(int inicio, int fim, int vet[]){
	int pivo, aux, temp;
	if(inicio == fim){
		return;
	}
	else{
		pivo = inicio;
		aux = fim;
		while(pivo != aux){
			if(pivo < aux){
				if(vet[pivo] > vet[aux]){
					temp = vet[pivo];
					vet[pivo] = vet[aux];
					vet[aux] = vet[pivo];
					temp = pivo;
					pivo = aux; 
					aux = temp;
				}
				else{
					if(vet[pivo]<vet[aux]){
						temp = vet[aux];
						vet[aux] = vet[pivo];
						vet[pivo] = temp;
						temp = aux;
						aux = pivo;
						pivo = temp;
					}
				}
			}
			if(pivo<aux){
				aux--;
			}
			else{
				aux++;
			}
		}
		//fazendo as partições
		if(aux != fim){
			quicksort(aux+1,fim,vet); //metade final
		}
		if(aux != inicio){
			quicksort(inicio,aux-1,vet); //primeira metade
		}
	}
	return ;
}
/*
void quicksortPilha(int vet[]){
	int pivo, aux, temp;
	elemento limites; //num struct guada-se os limites da pilha
	if(!empty()){
		limites = pop(); //pega os limties da pilha
		pivo = limites.ini;
		aux = limites.fim;
		while(pivo != aux){
			if(vet[pivo] > vet[aux]){
				temp = vet[pivo];
				vet[pivo] = vet[aux];
				vet[aux] = vet[pivo];
				temp = pivo;
				pivo = aux; 
				aux = temp
			}
			else{
				if(vet[pivo]<vet[aux]){
					temp = vet[aux];
					vet[aux] = vet[pivo];
					vet[pivo] = temp;
					temp = aux;
					aux = pivo;
					pivo = temp;
				}
			}
			if(pivo<aux){
				aux--;
			}
			else{
				aux++;
			}
		}
		if(aux != limites.ini){
			push(aux+1,limites.fim);
		}
		if(aux != limites.fim){
			push(limites.ini,aux-1);
		}
	}
}
*/

void intercala(int vet[], int ini, int meio, int fim){
	int i,j,k,*aux;
	i = ini;
	j = meio + 1;
	k = 0;
	aux = (int*)calloc(sizeof(int),(fim-ini)+1);
	while(i <= meio && j <= fim){
		if(vet[i] <= vet[j]){
			aux[k] = vet[i];
			i++;
		}
		else{
			aux[k] = vet[j];
			j++;
		}
		k++;
	}
	while(i <= meio){
		aux[i] = vet[i];
		i++;
		k++;
	}
	while(j <= fim){
		aux[j] = vet[j];
		j++;
		k++;
	}
	for(i = 0; i < (fim-ini)+1; i++){
		vet[ini + i] = aux[i];
	}
	free(aux);
	return ;
}

void mergesort(int vet[], int ini, int fim){
	int i, j, aux, meio;
	if(ini < fim){
		meio = (ini + fim)/2;
		mergesort(vet,ini,meio);
		mergesort(vet,meio+1,fim);
		intercala(vet,ini,meio,fim);
	}
}

void selection(){
	
}

int main(){
	int i;
	int x[] = {13, 7, 5, 1, 4, 3};
	quicksort(0,5,x);
	for(i = 0; i < 5; i++){
		printf(" %d ", x[i] );
	}
}

