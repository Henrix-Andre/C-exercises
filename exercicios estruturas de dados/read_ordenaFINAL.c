#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include "pilha_functions.h"

/*void runtime(){
	clock_t t;
	t = clock() - t;
	printf("\nO programa rodou em %f segundos", ((float)t)/CLOCKS_PER_SEC);
}*/
int *vetor;
int *ordena;

int vetorizar(char nome[]){
	FILE *f;
	int i, ch, count = 0;
	int *aux;
	f = fopen(nome, "r");
	if(f == NULL){
		printf("\nProblemas na abertura do arquivo!");
	}
	else{
		printf("\nAbertura com sucesso.\n\n");
		fseek(f, 0, SEEK_END); //aqui 
    	count = ftell(f) / sizeof(long int); //
    	fseek(f, 0, SEEK_SET);
    	
		ordena = (int*)malloc((count)*sizeof(int)*count);
		aux = (int*)malloc((count)*sizeof(int)*count);
		int r = fread(aux, sizeof(int), count, f);
    	if (r != count) {
    		printf("Erro ao ler arquivo.\n\n");
		}
		vetor = aux;
	}
	fclose(f);
	return count;
}

void ordena_bubblesort(int tamanho){
	clock_t t;
	int i, j, aux;
	bool swapped = false;
	for(i = 0; i < tamanho - 1; i++){
		for(j = 0; j < tamanho - i- 1 ; j++){
			if(ordena[j] > ordena[j+1]){
				aux = ordena[j+1];
				ordena[j+1] = ordena[j];
				ordena[j] = aux;
				swapped = true;
			}
		}
		if(!swapped){
			break;
		}
	}
	printf("\nOrdenado: ");
	for(i = 0; i < tamanho; i++){
		printf("\n%d", ordena[i]);
	}
	t = clock() - t;
	printf("\nOperação rodou em %f segundos\n", ((float)t)/CLOCKS_PER_SEC);
	system("pause");
}

int quicksort(int ini, int fim){
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
    if (aux != fim){
        quicksort(aux+1,fim);
    }
    if (aux !=ini){
        quicksort(ini,aux-1);
    }
    return vetor;
}

void mergesort(int vet[], int ini, int fim){
	int meio;
	if(ini == fim){
		meio = (ini + fim)/2;
		mergesort(vet, ini, meio);
		mergesort(vet, meio+1,fim);
		intercala(vet,ini,meio,fim);
	}
	return ;
}

void intercala(int vet[], int ini, int meio, int fim){
	int a,b,c,*aux; //a = i, b = j, c = k
	//intercalando
	a = ini;
	b = meio+1;
	c = 0;
	aux = (int*)calloc(sizeof(int), fim-ini+1);
	while(a<meio+1 || b<fim+1){
		if( vet[a] <=  vet[b]){
			aux[c] =  vet[a];
			a++;
		}
		else{
			aux[c] =  vet[b];
			b++;
		}
		c++;
	}
	while(a<= meio){
		aux[c] =  vet[a];
		a++;
		c++;
	}
	while(b<= fim){
		aux[c] =  vet[b];
		b++;
		c++;
	}
	for(a = ini; a < (fim-ini)+1; a++){
		 vet[a] = aux[a - ini];
	}
	free(aux);
	return ;
}

void quicksort_pilha(){
    int pivo, aux,temp;

	elemento limites;

    while(!empty()){
		limites=pop();
		pivo = limites.ini;
		aux  = limites.fim;
		
		
		
		while(pivo!=aux){
       		if (pivo<aux){
           		 if (ordena[pivo]> ordena[aux]){
	                temp = ordena[pivo];
	                ordena[pivo] = ordena[aux];
	                ordena[aux] = temp;
	                temp=pivo;
	                pivo=aux;
	                aux=temp;
       	     	}
       		}
        	else{
	            if (ordena[pivo]< ordena[aux]){
	                temp = ordena[pivo];
	                ordena[pivo] = ordena[aux];
	                ordena[aux] = temp;
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
	        //quicksort(ordena,aux+1,fim);
	    }
	
	    if (aux !=limites.ini){
	    	if (limites.ini != aux-1){
	    		push(limites.ini,aux-1);
			}
	     //   quicksort(ordena,ini,aux-1);
	    }		
    }
    
}

void select(int qtd){
	int i, j, min, aux;
	for(i = 0; i<qtd-1; i++){
		min = i;
		for(j = i+1; j<qtd; j++){
			if(ordena[j] < ordena[min]){
				min = j;
			}
		}
		aux = ordena[i];
		ordena[i] = ordena[min];
		ordena[min] = aux;
	}
	return ;
}

void insert(int qtd){
	register int i,j, aux;
	for(i = 1; i < qtd; i++){
		aux = ordena[i];
		for(j = i-1; j >= 0 && aux < ordena[j]; j--){
			ordena[j+1] = ordena[j];
		}
		ordena[j+1] = aux;
	}
}

void menu(FILE *f, char nome[20], int i){ //o i fica como o contador de tamanho do vetor
	int opt, j, k;
	int *num;
	clock_t t;
	do{
		memcpy(ordena, vetor, sizeof(int) * i); //isso copia a memória e conteúdo dela pra o vetor definido
		system("CLS");
		printf("(1)Bubblesort\n(2)quicksort simples\n(3)quicksort pilha\n(4)merge sort\n(5)selection sort\n(6)insertion sort\n(7)Sair.\n");
		printf("Tamanho do vetor : %d\nDigite a sua opção: ", i);
		scanf("%d", &opt);
		switch(opt){
			case 1:
				ordena_bubblesort(i);
				break;
			case 2:
				num = (int*)malloc(sizeof(int)*i);
				num = quicksort(0, (i-1)); //pega i-1 pq i é o total de itens, mas a contagem de vetor vai de 0 até i-1 
				t = clock() - t;
				printf("\nOperação rodou em %f segundos\n", ((float)t)/CLOCKS_PER_SEC);
				for(j = 0; j < i; j++){
					printf("\n%d", num[j]);
				}
				system("pause");
				break;
			case 3:
				quicksort_pilha();
				t = clock() - t;
				printf("\nOperação rodou em %f segundos\n", ((float)t)/CLOCKS_PER_SEC);
				for(j = 0; j < i; j++){
					printf("\n%d", ordena[j]);
				}
				system("pause");
				break;
			case 4:
				num = (int*)malloc(sizeof(int)*i);
				for(j = 0; j < i; j++){
					num[j] = vetor[j];
				}
				mergesort(num,0,i-1);
				t = clock() - t;
				printf("\nOperação rodou em %f segundos\n", ((float)t)/CLOCKS_PER_SEC);
				for(j = 0; j < i; j++){
					printf("\n%d", num[j]);
				}
				system("pause");
				break;
			case 5:
				select(i);
				t = clock() - t;
				printf("\nOperação rodou em %f segundos\n", ((float)t)/CLOCKS_PER_SEC);
				for(j = 0; j < i; j++){
					printf("\n%d", ordena[j]);
				}
				system("pause");
				break;
			case 6:
				insert(i);
				t = clock() - t;
				printf("\nOperação rodou em %f segundos\n", ((float)t)/CLOCKS_PER_SEC);
				for(j = 0; j < i; j++){
					printf("\n%d", ordena[j]);
				}
				system("pause");
				break;
			case 7:
				printf("\nEncerrando...");
				system("pause");
				break;
			default:
				printf("\nOpção inválida!");
				break;
		}
	}while(opt != 7);
}

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

int main(){
	pthue();
	FILE *f;
	char nome[20];
	int i, j, tamanho, *k;
	printf("Digite o nome do arquivo: ");
	fflush(stdin);
	gets(nome);
	f = fopen(nome, "r");
	if(f == NULL){
		printf("\nProblemas na abertura do arquivo!");
	}
	else{
		i = vetorizar(nome);

		menu(f,nome,i);
	}
	//runtime();
}
