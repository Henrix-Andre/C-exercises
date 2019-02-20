#include <stdio.h>
#include <stdlib.h>

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

void mergesort (int v[], int inicio, int fim);
void intercala(int v[], int inicio, int meio, int fim);

void mergesort(int v[],int inicio,int fim){
	int meio;
	if(inicio < fim){
		//fazendo as divis�es
		meio = (inicio+fim)/2; //aqui define o meio do seu vetor
		//aqui pra baixo faz as divis�es e aplica o sort (com a intercala��o) por meio de uma recursividade bisonha
		mergesort(v,inicio,meio);
		mergesort(v,meio+1,fim);
		intercala(v, inicio, meio, fim);
	}
	return;
} 

void intercala(int v[], int inicio, int meio, int fim){
	int i,j,k, *aux;
	aux = (int*)calloc(sizeof(int), fim-inicio+1); //diferen�a do calloc � que ele inicializa o conte�do da vari�vel em zero, pra fazer malloc usar (sizeof(int)*fim-inicio+1)
	i = inicio;
	j = meio+1; //+1 por causa dos �ndices.
	k = 0;
	//ordenando
	while(i<=meio && j<=fim){ //vai passando os itens pra o vetor auxiliar
		if(v[i] <= v[j]){ //vai fazendo as compara��es e trocas
			aux[k] = v[i]; 
			i++;
		}
		else{
			aux[k] = v[j];
			j++;
		}
		k++;
	}
	while(i <= meio){  //enquanto o i n�o alcan�ou o valor do meio e j o do fim, vai passando os valores pra aux.
		aux[k] = v[i];
		i++;
		k++;
	}
	while(j <= fim){
		aux[k] = v[j];
		j++;
		k++;
	}
	//copiando os vetores intercalados pro original
	for(i = 0; i<(fim-inicio)+1; i++){
		v[inicio+i] = aux[i];
	}
	free(aux); //libera o aux
	return;
}

int main(void){
	int contador;
	int vet[] = {4, 5, 8, 6, 3, 7, 1, 2, 10, 9};
	printf("original:\n");
	for(contador = 0; contador < 10; contador++){
		printf(" %d ", vet[contador]);
	}
	printf("\n");
	mergesort(vet,0,9);
	printf("ordenado:\n");
	for(contador = 0; contador < 10; contador++){
		printf(" %d ", vet[contador]);
	}
}


