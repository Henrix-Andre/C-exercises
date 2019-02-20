/******************************************************************** 
 *   Monitor: Diego Narciso Hernandes - 089941                      *  
 *   Versão: 1.0  - 24/03/2011                                      *  
********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//Definicoes
#define QUANTIDADE_OPERACOES 10000

//Métodos para controle de programa
void controle(); 

//Métodos de Interface com usuário
void interface(); 
void interfaceExibeTempo( int, double[], double );

//Métodos ordenação
void bubleSort( int[], int );
void selectSort( int[], int );
void insertionSort( int[], int );
void mergeSort( int*, int, int );
int partition( int*, int , int );
void quickSort( int*, int , int );

//Métodos auxiliares
void preencherVetorAleatoriamente( int [], int );
void trocarPosicaoValores( int *, int * );

//Método Principal
int main(int argc, char *argv[])
{ 
  controle();
  
  system("PAUSE");	
  return 0;
}

//Métodos para controle de programa
void controle()
{
   int i, j , f;
   double tempoTotal[5];
   clock_t tempoInicial, tempoFinal;
   interface();
   
   for ( i = 10; i<=1000; i=i*10 )
   {   
       int vetor[i];
       int fila[i];
       int pilha[i];
       
       srand(time(NULL));
       
       for( j = 0; j<5; j++ )
       {
          tempoTotal[j]=0;    
       }
       
     
      //bublesort
      for ( j = 0; j<QUANTIDADE_OPERACOES; j++ )
      {               
         preencherVetorAleatoriamente( vetor, i );       
         tempoInicial = clock();
         bubleSort( vetor, i );
         tempoFinal = clock();
         tempoTotal[0] += (double)(tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
      }
      
      //selectSort  
      for ( j = 0; j<QUANTIDADE_OPERACOES; j++ )
      {               
         preencherVetorAleatoriamente( vetor, i );       
         tempoInicial = clock();
         selectSort( vetor, i );
         tempoFinal = clock();
         tempoTotal[1] += (double)(tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
      }

      //insertionsort  
      for ( j = 0; j<QUANTIDADE_OPERACOES; j++ )
      {               
         preencherVetorAleatoriamente( vetor, i );       
         tempoInicial = clock();
         insertionSort( vetor, i );
         tempoFinal = clock();
         tempoTotal[2] += (double)(tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
      }
        
      //mergeSort  
      for ( j = 0; j<QUANTIDADE_OPERACOES; j++ )
      {               
         preencherVetorAleatoriamente( vetor, i );       
         tempoInicial = clock();
         mergeSort( vetor, 0, i-1 );
         tempoFinal = clock();
         tempoTotal[3] += (double)(tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
      }
      
      //quickSort  
      for ( j = 0; j<QUANTIDADE_OPERACOES; j++ )
      {               
         preencherVetorAleatoriamente( vetor, i );       
         tempoInicial = clock();
         quickSort( vetor, 0, i-1 );
         tempoFinal = clock();
         tempoTotal[4] += (double)(tempoFinal - tempoInicial)/CLOCKS_PER_SEC;
      }    
      interfaceExibeTempo( i, tempoTotal, 5 );
   }    
}

//Métodos de Interface com usuário
void interface()
{
   //Monta Menu
   system("cls");
   printf("## Comparações de Ordenadores ##\n\n"); 
   printf("## Tempo medido em segundos ##\n\n");    
   printf("Qtd Pos. x %d  - BubleSort|SelectSort|InsertionSort| MergeSort |QuickSort|.\n",QUANTIDADE_OPERACOES);   
}  

void interfaceExibeTempo( int quantidadeCampos, double vetorTempo[], double tamanhoVetorTempo )
{
   int i;
   
   printf("%d - x %d    = ",quantidadeCampos,QUANTIDADE_OPERACOES);
   
   
   for ( i =0; i<tamanhoVetorTempo; i++ )
   {
      printf("%lf | ",vetorTempo[i]);
   }
   printf("\n");

}  

//Métodos ordenação
void bubleSort( int vetorDesordenado[], int tamanhoVetor )
{
   int i, j;   
   for( i = 0; i < ( tamanhoVetor -1 );  i++ )
   {
      for( j=0; j <( tamanhoVetor -( i +1 ) ); j++ )  
      {
         if( vetorDesordenado[j] > vetorDesordenado[j+1] )  
         {          
            trocarPosicaoValores( &vetorDesordenado[j], &vetorDesordenado[j+1] ); 
         }
      } 
   }
}

void selectSort( int vetorDesordenado[], int tamanhoVetor )
{
   int i, j, posicaoValorMinimo;

   for (i = 0; i < ( tamanhoVetor - 1 ); i++) 
   {
      posicaoValorMinimo = i;
      for (j = ( i + 1 ); j < tamanhoVetor; j++) 
      {
         if( vetorDesordenado[j] < vetorDesordenado[posicaoValorMinimo] ) 
         {
           posicaoValorMinimo = j;
         }
       }
       
       if ( i != posicaoValorMinimo ) 
       {
          trocarPosicaoValores( &vetorDesordenado[i], &vetorDesordenado[posicaoValorMinimo] );  
       }
   }
}

void insertionSort(int vetorDesordenado[], int tamanhoVetor )
{
   int i, j, valorAtual;
 
   for( j=1; j < tamanhoVetor; j++ ) 
   {
      valorAtual = vetorDesordenado[j];
      i = j-1;
      
      while(i >= 0 && vetorDesordenado[i] > valorAtual)
      {
        vetorDesordenado[i+1] = vetorDesordenado[i];
        i--;
      } 
              
      vetorDesordenado[i+1] = valorAtual;
   }
}


void mergeSort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim ) 
{
   int i,j,k,metadeTamanho,*vetorTemp;
   if ( posicaoInicio == posicaoFim ) return;
   
   // ordenacao recursiva das duas metades
   metadeTamanho = ( posicaoInicio+posicaoFim )/2;
   mergeSort( vetorDesorndeado, posicaoInicio, metadeTamanho);
   mergeSort( vetorDesorndeado, metadeTamanho+1,posicaoFim );

   // intercalacao no vetor temporario t
   i = posicaoInicio;
   j = metadeTamanho+1;
   k = 0;
   vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));
   
   while( i<metadeTamanho+1 || j<posicaoFim+1 )
   { 
      if ( i == metadeTamanho+1 )
      { // i passou do final da primeira metade, pegar v[j]
         vetorTemp[k] = vetorDesorndeado[j];
         j++;
         k++;
      } 
      else
      {
         if (j==posicaoFim+1) 
         { 
            // j passou do final da segunda metade, pegar v[i]
            vetorTemp[k] = vetorDesorndeado[i];
            i++;
            k++;
         } 
         else 
         {
            if (vetorDesorndeado[i] < vetorDesorndeado[j]) 
            { // v[i]<v[j], pegar v[i]
               vetorTemp[k] = vetorDesorndeado[i];
               i++;
               k++;
            } 
            else
            { // v[j]<=v[i], pegar v[j]
              vetorTemp[k] = vetorDesorndeado[j];
              j++;
              k++;
            }
         }
      }
      
      

   }
   // copia vetor intercalado para o vetor original
   for( i=posicaoInicio; i<=posicaoFim; i++ )
   {
      vetorDesorndeado[i] = vetorTemp[i-posicaoInicio];
   }
   free(vetorTemp);
}

int partition( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
   int x,i,j,auxiliar;
   x = vetorDesordenado[posicaoInicio];
   i = posicaoInicio - 1;
   j = posicaoFim + 1;
   
   for(;;) 
   {
      do { j--; } while( vetorDesordenado[j]>x );
      do { i++; } while( vetorDesordenado[i]<x );
      
      if (i<j) 
      {
         auxiliar = vetorDesordenado[i];
         vetorDesordenado[i] = vetorDesordenado[j];
         vetorDesordenado[j] = auxiliar;
      }
      else
      {
         return j;
      }
   }
}

void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
   int pivot;
   if (posicaoInicio < posicaoFim) 
   {
      pivot = partition( vetorDesordenado, posicaoInicio, posicaoFim);
      quickSort( vetorDesordenado, posicaoInicio, pivot);
      quickSort(vetorDesordenado, pivot+1, posicaoFim);
   }
}

//Métodos auxiliares
void preencherVetorAleatoriamente( int vetor[], int tamanhoVetor )
{
   int i;
   srand(time(NULL));   

   for ( i = 0; i <tamanhoVetor; i++ )
   {
      vetor[i] = rand();
   }
     
}

void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
   int temporario;
   temporario = *posicaoA;
   *posicaoA = *posicaoB;
   *posicaoB = temporario;     
}
