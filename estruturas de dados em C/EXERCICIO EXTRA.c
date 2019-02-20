#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
/*DICA: � poss�vel acessar o registro de um elemento chamando [nome da variavel do tipo elemento]->reg->[o dado do registro]
Ex.:
lista * l;
elemento * aux;
aux = l->inicio;
aux->reg->media = (10+2)/2; Desse jeito voc� alterou o valor da m�dia registrada no elemento l->inicio pra 6.
*/
typedef struct elemento{ 
	struct registro * reg; 
	struct elemento * prox;
	struct elemento * ant; //como � duplamente encadeada, cada elemento tem um ponteiro para tanto o pr�ximo elemento quanto o anterior a ele
}elemento;
typedef struct lista{
	int qtd;
	struct elemento * inicio; //a lista em s� tem um ponteiro para o in�cio e o fim da lista
	struct elemento * fim;
}lista;
typedef struct registro{
	char nome[50];
	int A1, A2, media;
}registro;

void pthue();
lista * alocar();
void insr_inicio(lista * l, char nome[50], int num1, int num2);
void insr_fim(lista * l, char nome[50], int num1, int num2);
elemento * buscar(lista * l, char Anome[50]);
void listar(lista * l);
void maiorNota(lista * l);
int remover(lista * l, char Anome[50]);
void ordenanota(lista * l);
void ordena_alfabetico(lista * l);
void menu(lista * l);

int main(){
	lista * l;
	pthue();
	l = alocar();
	menu(l);
}

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

lista * alocar(){
	lista * auxiliar;
	auxiliar = (lista*)malloc(sizeof(lista));
	auxiliar->inicio = NULL;
	auxiliar->fim = NULL; //inicializa a coisa toda com os valores 'vazios'.
	auxiliar->qtd = 0;
	return auxiliar;
}

void insr_inicio(lista * l, char nome[50], int num1, int num2){
	elemento * aux, * aux2;
	registro * reg1;
	int med;
	med = (num1 + num2)/2;
	aux = (elemento*)malloc(sizeof(elemento));
	reg1 = (registro*)malloc(sizeof(registro));
	aux->ant = NULL;
	aux->prox = NULL;
	reg1->nome[50] == strcpy(reg1->nome, nome); //nessa parte inicia os valores do novo aluno registrado
	reg1->A1 = num1;
	reg1->A2 = num2;
	reg1->media = med;
	aux->reg = reg1;
	if(l->qtd == 0){
		l->inicio = aux;
		l->fim = aux;
	}
	else{
		aux2 = l->inicio;
		aux2->ant = aux;
		aux->prox = aux2;
		l->inicio = aux;
	}
	l->qtd++;
}

void insr_fim(lista * l, char nome[50], int num1, int num2){ //as fun��es de inserir definem um aux, aux2 e um reg1. esse reg1 � como um aux pra receber os dados do registro
	elemento * aux, * aux2;
	registro * reg1;
	int med;
	med = (num1 + num2)/2;
	aux = (elemento*)malloc(sizeof(elemento)); //tem que alocar tanto o aux quanto o registro
	reg1 = (registro*)malloc(sizeof(registro));
	aux->ant = NULL;
	aux->prox = NULL;
	reg1->nome[50] == strcpy(reg1->nome, nome); //passa o nome por strcpy. LEMBRANDO: strcpy(destino, fonte)
	reg1->A1 = num1;													  //Assim a vari�vel 'destino' vai ter o mesmo conte�do da var 'fonte'.
	reg1->A2 = num2;
	reg1->media = med;
	aux->reg = reg1; //define que o registro de aux � o reg q definimos.
	if(l->qtd == 0){
		l->inicio = aux;
		l->fim = aux;
	}
	else{
		aux2 = l->fim;
		aux2->prox = aux;
		aux->ant = aux2;
		l->fim = aux;
	}
	l->qtd++;
}

elemento * buscar(lista * l, char Anome[50]){ //ao inv�s de printar direto, a fun��o buscar retorna o elemento buscado, ai o menu imprime
	elemento * aux;
	int x;
	if(l->qtd == 0){
		return NULL;
		getch();
	}
	else{
		aux = l->inicio;
		while((strcmp(aux->reg->nome, Anome) != 0) && (aux->prox != NULL)){ //se o resultado strcmp for diferente de zero quer dizer que os nomes s�o diferentes
			aux = aux->prox;
		} 
		if(strcmp(aux->reg->nome, Anome) == 0){ 
			return aux;
		}
		else{
			return NULL;
		}
	}
}

void listar(lista * l){
	elemento * aux;
	aux = l->inicio;
	if (l->qtd==0){
		printf("\nN�o existem elementos na lista");
		getch();
	}
	else{
		printf("\nNome do aluno: %s", aux->reg->nome);
		printf("\nNota 1: %d || Nota 2: %d", aux->reg->A1, aux->reg->A2);
		printf("\nMedia: %d", aux->reg->media);
		while(aux->prox != NULL){
			aux=aux->prox;
			printf("\nNome do aluno: %s", aux->reg->nome);
			printf("\nNota 1: %d || Nota 2: %d", aux->reg->A1, aux->reg->A2);
			printf("\nMedia: %d", aux->reg->media);
		}
		getch();
	}
}

void maiorNota(lista * l){
	elemento *aux1, *aux2, *maior;
	if (l->qtd == 0){ //checa se a lista esta vazia
		printf("\nN�o existem alunos na lista.");
		getch();
	}
	else{
		aux1 = l->inicio;
		aux2 = aux1->prox;
		maior = NULL;
		while(aux2 != NULL){ //aqui verifica se aux2 vai ser nulo
			if(aux1->reg->media > aux2->reg->media){
				maior = aux1;
			}
			aux1 = aux1->prox; //no ultimo elemento da lista o aux2 vai estar nulo, mas como o loop s� checa no come�o n�o d� problema.
			aux2 = aux1->prox;
		}
		printf("\nAluno com maior nota: \n");
		printf("\nNome: %s", maior->reg->nome);
		printf("\nNota 1: %d || Nota 2: %d", maior->reg->A1, maior->reg->A2);
		printf("\nMedia: %d", maior->reg->media);
		getch();
	}
}

int remover(lista * l, char Anome[50]){
	elemento *prev, *remover, *next;
	remover = l->inicio; 
	if(l->qtd == 0){ 
		printf("\nLista vazia.");
		getch();
		return 0;
	}
	else{
		remover = buscar(l, Anome);
		prev = remover->ant; //ant e prox recebem os valores pr�prios
		next = remover->prox;
		if(remover == NULL){
			printf("\nLista vazia e/ou item inexistente.");
			getch();
			return 0;	
		}
		else{
			if(prev != NULL){
				prev->prox = next; 
			}
			else{
				l->inicio = next;
			}
			if(next != NULL){ 
				next->ant = prev; 
			}
			else{
				l->fim = prev;
			}
			printf("\nAluno removido."); 
			getch();
			l->qtd--; 
			free(remover); 
			return 1; 
		}
	}
}

void ordenanota(lista * l){
	elemento *aux1, *aux2;
	registro * regAux; //define um registro auxiliar
	aux1 = l->inicio; //define os aux, e os registros deles
	aux2 = aux1->prox;
	for(aux1 = l->inicio; aux1->prox != NULL; aux1 = aux1->prox){
		for(aux2 = aux1->prox; aux2 != NULL; aux2 = aux2->prox){
			if(aux1->reg->media > aux2->reg->media){ //s� checa nos registros, n�o precisa mudar vari�vel
				regAux = aux1->reg; //aqui passa o registro inteiro de um aux pro outro.
				aux1->reg = aux2->reg;
				aux2->reg = regAux;
			}
		}
	}
	printf("\nLista ordenada.");
	getch();
}

void ordena_alfabetico(lista * l){
	elemento *aux1, *aux2;
	registro * regAux;
	for(aux1 = l->inicio; aux1->prox != NULL; aux1 = aux1->prox){
		for(aux2 = aux1->prox; aux2 != NULL; aux2 = aux2->prox){
			if(strcmp(aux1->reg->nome, aux2->reg->nome) == 1){ //s� checa nos registros, n�o precisa mudar vari�vel
				regAux = aux1->reg; //funcionamento aqui � igual ao de ordenar a nota, mas comparando os nomes.
				aux1->reg = aux2->reg;
				aux2->reg = regAux; 
			}
		}
	}
	printf("\nLista ordenada.");
	getch();
}

void menu(lista * l){
	int opt, P1, P2;
	char alnome[50];
	elemento * aux;
	do{
		system("cls");
		printf("(1)Inserir aluno no inicio da lista\n(2)Buscar aluno\n(3)Mostrar lista\n(4)Inserir aluno no fim da fila\n(5)maior nota\n(6)Remover aluno\n(7)Ordenar por nota\n(8)Ordenar alfabeticamente\n(9)Sair\n---------------------------\nDigite sua op��o: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				fflush(stdin);
				printf("\nDigite o nome do aluno a ser inserido: ");
				gets(alnome);
				printf("\nDigite a primeira e segunda nota (em ordem): ");
				scanf("%d %d",&P1, &P2);
				insr_inicio(l,alnome,P1,P2);
				break;
			case 2:
				fflush(stdin);
				if(l->qtd == 0){
					printf("\nLista vazia.");
					getch();
				}
				else{
					printf("\nDigite o nome do aluno a ser buscado:");
					gets(alnome);
					aux = buscar(l, alnome);
					if(aux == NULL){
						printf("\nAluno n�o encontrado na database e/ou lista de alunos vazia.");
						getch();
					}
					else{
						printf("\nNome do aluno: %s", aux->reg->nome);
						printf("\nNota 1: %d || Nota 2: %d", aux->reg->A1, aux->reg->A2);
						printf("\nMedia: %d", aux->reg->media);
						getch();
					}
				}
				break;
			case 3:
				listar(l);
				break;
			case 4:
				fflush(stdin);
				printf("\nDigite o nome do aluno a ser inserido: ");
				gets(alnome);
				printf("\nDigite a primeira e segunda nota (em ordem): ");
				scanf("%d %d",&P1, &P2);
				insr_fim(l,alnome,P1,P2);
				fflush(stdin);
				break;
			case 5:
				maiorNota(l);
				break;
			case 6:
				fflush(stdin);
				if(l->qtd == 0){
					printf("\nLista vazia.");
					getch();
				}
				else{
					printf("\nDigite o nome do aluno a ser removido: ");
					gets(alnome);
					remover(l, alnome);
				}
				break;
			case 7:
				ordenanota(l);
				break;
			case 8:
				ordena_alfabetico(l);
				break;
			case 9:
				printf("\nEncerrando");
				getch();
				break;
			default:
				printf("\nOp��o inv�lida.");
				getch();
				break;
		}
	}while(opt != 9);
}
