#include <stdio.h>
#include <stdlib.h>
#define MAX 10
/*
	A ideia do quicksort é pegar uma variável pivô e uma auxiliar em um vetor, e ir comparando as duas até chegar num ponto definido
	No geral, se o pivô for maior que a auxiliar, troca de lugar e avança um espaço no vetor
	vai aplicando isso recursivamente até chegar no ponto definido (geralmente o "meio"/a metade do vetor)
	então vamos ter uma variável no lugar certo, e dois subgrupos (um depois dessa variável, e um antes)
	
	Após isso é só ir aplicando o quicksort nesses subgrupos (e nos grupos subsequentes) até ficar organizado.
*/

void quick_sort(int *a, int left, int right); //prototipando

int main(int argc, char** argv)
{
 int i, vet[MAX];
 for(i = 0; i < MAX; i++)
 {
  printf("Digite um valor: ");
  scanf("%d", &vet[i]);
 }
 quick_sort(vet, 0, MAX - 1);
 printf("\nValores ordenados\n");
 for(i = 0; i < MAX; i++)
 {
  printf("%d\n", vet[i]);
 }
 system("pause");
 return 0;
}

/*
AVISO: Esse não é o método mais eficaz de usar o quicksort,
	   Existe um melhor no livro do tanembaum, 
	   mas acho que vou esperar até o professor aplicar msm pra tentar usar.
*/

void quick_sort(int *a, int inicio, int fim) { 
    int i, j, x, y;
     
    i = inicio; //pega um ponto para ser o pivô na função
    j = fim;    //nesse caso pegamos o inicio e o final do vetor
    x = a[(inicio + fim) / 2]; //aqui pegamos o meio do vetor (se aplicável)
     
    while(i <= j) {
        while(a[i] < x && i < fim) {
            i++;
        }
        while(a[j] > x && j > inicio) {
            j--;
        }
        if(i <= j) { //se i for maior que j, faz a troca.
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > inicio) { //faz a recursividade aqui
        quick_sort(a, inicio, j); //pega do início até a metade do vetor
    }
    if(i < fim) {
        quick_sort(a, i, fim); //pega da metade do vetor até o final
    }
}

