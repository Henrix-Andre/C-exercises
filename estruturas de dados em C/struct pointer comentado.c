#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct{
	char nome[30];
	float media;	
}registro; //cria o tipo de dado registro

//https://www.programiz.com/c-programming/c-structures-pointers


//Prot�tipos
registro * alocar (int tamanho);
void preencher(registro * vetor, int tamanho);
void ordenar(registro * vetor, int tamanho);
void mostrar(registro * vetor, int tamanho);

int main(){
	setlocale(LC_ALL, "Portuguese");
	int Nalunos, i;
	registro * vetor; //cria um objeto do tipo 'registro' chamado vetor
	printf("Digite o n�mero de alunos: ");
	scanf("%d", &Nalunos);
	vetor = alocar(Nalunos); //cria um vetor com o tamanho do numero de alunos, pelo tamanho de mem�ria definido pela fu��o alocar
	preencher(vetor, Nalunos);
	ordenar(vetor, Nalunos);
	mostrar(vetor, Nalunos);
	return 0;
}

registro * alocar (int tamanho){
	registro * aux; //cria um ponteiro auxiliar para o struct.
	aux = (registro*) malloc(tamanho * sizeof(registro)); //isso aqui aloca a mem�ria pra ter os registros, isso � um cast (tipo*) -malloc-
	aux->media = 0; //isso e a linha de baixo inicializam o struct com valores padr�o.
	strcpy(aux->nome, " "); //fica um espa�o em branco, depois um /0 para sinalizar o fim da string, e o resto fica lixo de mem�ria.
}

//para usar a seta tem que ter o asterisco (exemplo *x), nunca se usa seta quanto se especifica o �ndice

void preencher(registro * vetor, int tamanho){ //recebe um vetor e o seu tamanho
	int i;
	for(i = 0; i < tamanho; i++){ //bem simples, s� vai preenchendo cada posi��o do vetor
		fflush(stdin); //limpeza de buffer
		printf("Digite o nome do aluno: ");
		gets(vetor[i].nome); //aqui especifica o �ndice, ent�o n�o se usa a seta
		printf("Digite a m�dia do aluno: ");
		scanf("%f", &vetor[i].media);
	}
}

void ordenar(registro * vetor, int tamanho){
	int i, j;
	registro * aux;
	aux = alocar(1);
	
	for(i=0;i<tamanho-1;i++) //nesse caso � pra evitar que a vari�vel que fica de contador passe do limite da var tamanho,considerando que j inicia por i+1;
	{						 //n�o � necess�rio fazer a compara��o depois de verificar na penultima posi��o via bubble sort.
		for(j=i+1;j<tamanho;j++)
		{
			if (vetor[i].media > vetor[j].media) //bubble sort, aqui com um vetor onde suas posi��es s�o ocupadas por ponteiros que apontam pra structs
			{
				*aux = vetor[i]; //nesse caso cada vetor[posi��o] j� move o struct inteiro, ao inv�s de manipular campo por campo.
				vetor[i] = vetor[j];
				vetor[j] = *aux;				
			}
		}
	}
}

void mostrar(registro * vetor, int tamanho){
	int i;
	for(i=0;i<tamanho;i++)
	{
		printf("\n Nome: %s \t media: %.2f",vetor[i].nome,vetor[i].media);
	}
}
