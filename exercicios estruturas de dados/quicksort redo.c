#include <stdio.h>
#include <stdlib.h>
//coisas pro quicksort por pilha
typedef struct elemento{
    int ini;
    int fim;
}elemento;

int tamanho=100;
int pos=0;
elemento pilha[100];

void push(int inicio, int fim){	
    if (pos>=100){
        printf("\n Pilha cheia");
    }
    else{
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

void quicksort(int vetor[], int ini, int fim){
	int pivo, aux, temp;
	if(ini == fim){ //se o in�cio � igual ao final, ent�o nao tem o que fazer.
		return;
	}
	pivo = ini; //define as vari�veis.
	aux = fim;
	while(pivo != aux){ //enquanto o pivo (inicio) != aux (final)
		if(pivo<aux){ //mais especificamente enquanto pivo � menor que o aux (que vai se mover)
			//fazendo as trocas
			if(vetor[pivo]>vetor[aux]){ 
				temp = vetor[pivo];
                vetor[pivo] = vetor[aux];
                vetor[aux] = temp; //aux e pivo trocam de indice quando h� uma troca de n�meros
                temp=pivo;
                pivo=aux;
                aux=temp;
			}
		}
		else{
			if(vetor[pivo]<vetor[aux]){
				temp = vetor[pivo];
				vetor[pivo] = vetor[aux];
				vetor[aux] = temp;
				temp = pivo;
				pivo = aux; //mesma l�gica aqui
				aux = temp;
			}
		}
		//os dois aqui s�o pra garantir que o aux vai se mover na dire��o certa.
		if(pivo<aux){
			aux--; 
		}
		else{
			aux++;
		}
	}
	//fazendo as parti��es via recursividade (considerando que aux � diferente do inicio e/ou o fim)
	if(aux != fim){
		quicksort(vetor,aux+1,fim);
	}
	if(aux != ini){
		quicksort(vetor,ini,aux-1);
	}
	return ;
}

//quicksort por pilha
//a pilha � feita por um vetor, em conjunto com um struct com marcador de inicio e fim.
//no geral a l�gica � id�ntica, exceto pelas fun��es de pilha e do struct.

void quicksort_pilha(int vetor[]){
	int aux, pivo, temp;
	elemento limites;
	if(!empty()){ //se o o vetor n�o est� vazio roda a fun��o
		limites = pop(); //nesse caso a fun��o pop da os valores de inicio e fim
		pivo = limites.ini;
		aux = limites.fim;
		while(pivo != aux){
			if(pivo < aux){
				if(vetor[pivo] > vetor[aux]){
					temp = vetor[pivo];
					vetor[pivo] = vetor[aux];
					vetor[aux] = temp;
					temp = pivo;
					pivo = aux;
					aux = temp;
				}
				else{ //aqui � um else com um if dentro pra no caso de n�o ter nenhuma troca poder prosseguir sem problema
					if(vetor[pivo] < vetor[aux]){
						temp = vetor[aux];
						vetor[aux] = vetor[pivo];
						vetor[pivo] = temp;
						temp = aux;
						aux = pivo;
						pivo = temp;
					}
				}
			}
			if(pivo>aux){
				aux++;
			}
			else{
				aux--;
			}
		}
		//fazendo as parti��es
		if(aux != limites.fim){
			if(aux+1 != limites.fim){
				push(aux+1, limites.fim);
			}
		}
		if(aux != limites.ini){
			if(aux-1!= limites.ini){
				push(limites.ini, aux-1);
			}
		}
	}
}


int main(){
    int i;
    int vet[10]={413,210,780,28,345,610,21,6,1050,500};
    quicksort(vet,0,9);
    for(i=0;i<10;i++){
        printf("\n %d",vet[i]);
    }
    return 0;
}

