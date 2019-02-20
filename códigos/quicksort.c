#include <stdio.h>
#include <stdlib.h>
void quicksort(int vetor[], int ini, int fim);

int main(){
    int i;
    int vet[10]={413,210,780,28,345,610,21,6,1050,500};
    quicksort(vet,0,9);


    for(i=0;i<10;i++){
        printf("\n %d",vet[i]);
    }
    return 0;
}

void quicksort(int vetor[], int ini, int fim){
    int pivo, aux,temp;

    if (ini==fim){
        return ;
    }
    pivo = ini;
    aux  = fim;
    while(pivo!=aux){
        if (pivo<aux){
            if (vetor[pivo]> vetor[aux])
            {
                temp = vetor[pivo];
                vetor[pivo] = vetor[aux];
                vetor[aux] = temp;
                temp=pivo;
                pivo=aux;
                aux=temp;
            }
        }
        else{
            if (vetor[pivo]< vetor[aux]){
                temp = vetor[pivo];
                vetor[pivo] = vetor[aux];
                vetor[aux] = temp;
                temp=pivo;
                pivo=aux;
                aux=temp;
            }
        }
        if (pivo<aux){
            aux--;
        }
        else{
            aux++;
        }
    }
    if (aux!=fim){
        quicksort(vetor,aux+1,fim);
    }
    if (aux !=ini){
        quicksort(vetor,ini,aux-1);
    }

}
