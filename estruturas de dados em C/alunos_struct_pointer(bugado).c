#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

//int qtd = 0;

typedef struct aluno Aluno;
struct aluno{
	char *nome[81];
	char *matricula[8];
	char sala;
	float p1, p2, p3;
};
/*struct turma{
	aluno x;
	int qtd;
};*/

Aluno * alocar (int n){
	Aluno * aux;
	aux = (Aluno*)malloc(n*sizeof(Aluno));
	return aux;	
}

void preencher(int n, Aluno* a){
	int i;
	for(i = 0; i<n; i++){
		fflush(stdin);
		printf("\nDigite o nome do aluno: ");
		scanf("%80[^\n]", a[i].nome);
		fflush(stdin);
		printf("\nDigite a matricula do aluno: ");
		scanf("%8[^\n]", a[i].matricula);
		fflush(stdin);
		printf("\nDigite a turma/sala do aluno: ");
		scanf("%1[^\n]", a[i].sala);
		fflush(stdin);
		printf("\nDigite a nota da p1: ");
		scanf("%f", &a[i].p1);
		printf("\nDigite a nota da p2: ");
		scanf("%f", &a[i].p2);
		printf("\nDigite a nota da p3: ");
		scanf("%f", &a[i].p3);
	}
}
	/*else{ //guardar essa função p/depois, checar se qtd == 0 pra definir se vai reallocar ou nao.
		a = (Aluno*)realloc((qtd+1)sizeof(Aluno)); 
		do{
			qtd++;
			i = qtd;
			fflush(stdin);
			printf("\nDigite o nome do aluno: ");
			gets(&Aluno[i].nome);
			fflush(stdin);
			printf("\nDigite a matricula do aluno: ");
			gets(&Aluno[i].matricula);
			fflush(stdin);
			printf("\nDigite a turma do aluno: ");
			scanf("%c", &Aluno[i].turma);
			printf("\nDigite as notas da p1, p2 e p3 (em sequência): ");
			scanf("%f %f %f", &Aluno[i].p1, &Aluno[i].p2, &Aluno[i].p3);
		}
	}
	
}*/

void aprovados(int n, Aluno* a){
	float total, media, med;
	int i;
	/*for(i = 0; i < n; i++){
		total += a[i]->p1 + a[i]->p2 + a[i]->p3;
	}
	media = total/n;
	printf("\nMedia da turma %0.2f\n", media);*/
	printf("Alunos aprovados:\n");
	for(i = 0; i < n; i++){
		med = (a[i].p1 + a[i].p2 + a[i].p3)/5;
		if(med >= 5){
			printf("Nome: %s\n", a[i].nome);
			printf("Matrícula: %s\n\n", a[i].matricula);
		}
	}
}

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

int main(){
	pthue();
	int num;
	Aluno* turma;
	printf("Digite o numero de alunos da turma: ");
	scanf("%d", &num);
	turma = alocar(num);
	preencher(num,turma);
	aprovados(num,turma);
}
