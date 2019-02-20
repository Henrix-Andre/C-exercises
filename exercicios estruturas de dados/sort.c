#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * aloca_vetor(int tamanho);
void confere(int * vetor, int n);
void bubblesort(int vetor[], int tamanho);
void quicksort(int vetor[], int ini, int fim);
void mergesort(int vetor[], int ini, int fim);
void intercala(int v[], int inicio, int meio, int fim);
void insertionsort(int vetor[], int tamanho);
void selectionsort(int vetor[], int tamanho);
void menu();

int main()
{
    srand(time(NULL));

    menu();

    // int i;

    // int * vetor;

    // vetor=aloca_vetor(30);
    /*




        for(i=0; i<10000; i++)
        {
            printf("\n %d",rand()%1);
        }




        ///CLOCKS_PER_SEC;
        printf("Tempo em segundos: %f", tempoGasto);
        */
    return 0;
}

int * aloca_vetor(int tamanho)
{
    int * novo, * novo2;
    int indice;
    int i,j,k;
    novo = (int*)malloc(sizeof(int)*tamanho);
    novo2 = (int*)malloc(sizeof(int)*tamanho);

    for(i=0; i<tamanho; i++)
    {
        novo[i] = i+1;
    }

    k=0;
    for(i=tamanho; i>=1; i--)
    {
        indice = rand() % i;
        novo2[k] = novo[indice];
        k++;
        for(j=indice; j<tamanho; j++)
        {
            novo[j] = novo[j+1];
        }
    }
    /*
        for(i=0; i<tamanho; i++)
        {
            printf("\n %d",novo2[i]);
        }
    */
    return novo2;


}

void menu()
{
    clock_t tempoInicial, tempoFinal;
    double tempoGasto;
    int i;
    int tamanho;

    int opcao;

    int * vetor;
    int * vetor2;
    printf("\n Digite o tamanho do Vetor :");
    scanf("%d",&tamanho);

    vetor=aloca_vetor(tamanho);
    vetor2 = (int*)malloc(sizeof(int)*tamanho);

    for(i=0; i<tamanho; i++)
    {
        vetor2[i] = vetor[i];
    }


    do
    {
        for(i=0; i<tamanho; i++)
        {
            vetor2[i] = vetor[i];
        }

        printf("\n 1- Bubblesort");
        printf("\n 2- Quicksort ");
        printf("\n 3- Mergesort ");
        printf("\n 4- Insertion ");
        printf("\n 5- Selection ");
        printf("\n10- sair      ");
        scanf("%d",&opcao);
        switch(opcao)
        {

        case 1:
            printf("Vetor que sera ordenado: \n");

          /*  for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }*/
            tempoInicial = clock();

            bubblesort(vetor2,tamanho);

            tempoFinal = clock();

            printf("\nVetor Ordenado: \n");

           /* for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }*/



            tempoGasto = (double)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC;
            printf("\nTempo em segundos: %f", tempoGasto);

            break;
        case 2:
            printf("Vetor que sera ordenado: \n");
            /*
            for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }*/
            tempoInicial = clock();

            quicksort(vetor2,0,tamanho-1);

            tempoFinal = clock();

            printf("\nVetor Ordenado: \n");
            /*
            for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }
*/


            tempoGasto = (double)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC;
            printf("\nTempo em segundos: %f", tempoGasto);
            break;
        case 3:
            printf("Vetor que sera ordenado: \n");
/*
            for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }*/
            tempoInicial = clock();

            mergesort(vetor2,0,tamanho-1);

            tempoFinal = clock();

            printf("\nVetor Ordenado: \n");
/*
            for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }

*/

            tempoGasto = (double)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC;
            printf("\nTempo em segundos: %f", tempoGasto);
            break;
        case 4:
            printf("Vetor que sera ordenado: \n");

            for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }
            tempoInicial = clock();

            insertionsort(vetor2,tamanho);

            tempoFinal = clock();

            printf("\nVetor Ordenado: \n");

            for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }



            tempoGasto = (double)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC;
            printf("\nTempo em segundos: %f", tempoGasto);
            break;
        case 5:
            printf("Vetor que sera ordenado: \n");

            for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }
            tempoInicial = clock();

            selectionsort(vetor2,tamanho);

            tempoFinal = clock();

            printf("\nVetor Ordenado: \n");

            for(i=0; i<tamanho; i++)
            {
                printf(" %d",vetor2[i]);
            }



            tempoGasto = (double)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC;
            printf("\nTempo em segundos: %f", tempoGasto);
            break;
        case 10:
            tempoInicial = clock();
            printf("\nSaindo do programa");
            break;
        default:
            tempoInicial = clock();
            printf("opcao invalida");
        }


    }
    while(opcao!=10);
}


void bubblesort(int vetor[], int tamanho)
{
    int pass, i, trocou=1;
    int aux;



    for(pass=0; pass<tamanho-1 && trocou==1; pass++)
    {
        trocou=0;
        for(i=0; i<tamanho-1-pass; i++)
        {
            if (vetor[i] > vetor[i+1])
            {
                aux=vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                trocou=1;
            }
        }
    }

}

void quicksort(int vetor[], int ini, int fim)
{
    int pivo, aux,temp;

    if (ini==fim)
    {
        return ;
    }

    pivo = ini;
    aux  = fim;
    while(pivo!=aux)
    {
        if (pivo<aux)
        {
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
        else
        {
            if (vetor[pivo]< vetor[aux])
            {
                temp = vetor[pivo];
                vetor[pivo] = vetor[aux];
                vetor[aux] = temp;
                temp=pivo;
                pivo=aux;
                aux=temp;
            }



        }
        if (pivo<aux)
        {
            aux--;
        }
        else
        {
            aux++;
        }




    }

    if (aux!=fim)
    {
        quicksort(vetor,aux+1,fim);
    }

    if (aux !=ini)
    {
        quicksort(vetor,ini,aux-1);
    }

}

void mergesort(int vetor[], int ini, int fim)
{
    int meio;
    if (ini<fim)
    {
        meio = (ini+fim)/2;
        mergesort(vetor,ini,meio);
        mergesort(vetor,meio+1,fim);
        intercala(vetor, ini, meio, fim);
    }
    return ;

}

void intercala(int v[], int inicio, int meio, int fim)
{
    /* intercalação no vetor temporário auxiliar */
    int i,j,k, *auxiliar;
    auxiliar = (int *) calloc(sizeof(int), fim-inicio+1);
    i = inicio;
    j = meio+1;
    k = 0;
    while( i<=meio && j<=fim )
    {
        if( v[i] <= v[j] )
        {
            auxiliar[k] = v[i];
            i++;
        }
        else
        {
            auxiliar[k] = v[j];
            j++;
        }
        k++;
    }

    while( i <= meio )
    {
        auxiliar[k] = v[i];
        i++;
        k++;
    }
    while( j <= fim )
    {
        auxiliar[k] = v[j];
        j++;
        k++;

    }
    /* copia vetor intercalado para o vetor original */
    for( i = 0; i< (fim - inicio)+1; i++)
    {
        v[inicio + i] = auxiliar[i];
    }
    free(auxiliar);
    return;
}

void insertionsort(int vetor[], int tamanho)
{

    int i, j, aux;

    for(i=1; i<tamanho; i++)
    {
        aux = vetor[i];
        for(j=i-1; j>=0 && vetor[j]>aux; j--)
        {
            vetor[j+1] = vetor[j];
        }
        vetor[j+1] = aux;

    }

}

void selectionsort(int vetor[], int tamanho)
{
    int i,j,imenor, aux;

    for(i=0; i<tamanho-1; i++)
    {
        imenor =i;
        for(j=i+1; j<tamanho; j++)
        {
            if (vetor[j]<vetor[imenor])
            {
                imenor = j;
            }
        }
        aux = vetor[i];
        vetor[i] = vetor[imenor];
        vetor[imenor] = aux;
    }


}
