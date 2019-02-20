#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int ini;
    int fim;
}elemento;

int tamanho=100;
int pos=0;
elemento pilha[100];

void quicksort(int vetor[]);

void limpa_pilha ( );
elemento pop ();
void push(int inicio, int fim);
void mostrar();

int main()
{
	elemento aux;
    limpa_pilha();
    int i;
    int vet[10]={5,9,2,8,3,7,4,6,10,1};
    push(0,9);
    quicksort(vet);

    for(i=0;i<10;i++)
    {
        printf("\n %d",vet[i]);
    }
    
    return 0;
}

void quicksort(int vetor[])
{
    int pivo, aux,temp;
	elemento limites;
    while(!empty())
    {
		limites=pop();
		pivo = limites.ini;
		aux  = limites.fim;
		while(pivo!=aux){
       		if (pivo<aux){
           		 if (vetor[pivo]> vetor[aux]){
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
	        if (pivo>aux){
	            aux++;
	
	        }
	        else{
	            aux--;
	        }

   		}
	    if (aux!=limites.fim){
	    	if (aux+1 != limites.fim){
	    		push(aux+1,limites.fim);
			}
	        //quicksort(vetor,aux+1,fim);
	    }
	
	    if (aux !=limites.ini){
	    	if (limites.ini != aux-1){
	    		push(limites.ini,aux-1);
			}
	     //   quicksort(vetor,ini,aux-1);
	    }
				
    }
    
}


void limpa_pilha ( ){
    int i;
    for(i=0;i<tamanho;i+){
        pilha[i].ini =0;
        pilha[i].fim=0;
    }
}



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

void mostrar(){
	int i;
	
	if (pos==0){
		printf("\n Pilha vazia");
	}
	else{
			
		for(i=0;i<pos;i++){
			printf("\n %d %d",pilha[i].ini,pilha[i].fim);
		}	
	}

}
