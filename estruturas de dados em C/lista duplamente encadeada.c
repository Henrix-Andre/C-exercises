#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
typedef struct elemento{
	int valor;
	struct elemento * prox;
	struct elemento * ant; //como é duplamente encadeada, cada elemento tem um ponteiro para tanto o próximo elemento quanto o anterior a ele
}elemento;
typedef struct lista{
	int qtd;
	struct elemento * inicio; //a lista em sí tem um ponteiro para o início e o fim da lista
	struct elemento * fim;
}lista;

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

lista * alocar(){
	lista * aux;
	aux = (lista*)malloc(sizeof(lista));
	aux->inicio = NULL;
	aux->fim = NULL; //inicializa a coisa toda com os valores 'vazios'.
	aux->qtd = 0;
	return aux;
}

void insr_inicio(lista * l, int x){
	elemento * aux, * novo;
	novo = (elemento*)malloc(sizeof(elemento)); //aloca a nova lista
	novo->valor = x;
	novo->ant = NULL; //aqui TEM QUE INICIALIZAR COM NULO se não da pato na lógica mais pra frente
	novo->prox = NULL;
	if(l->qtd == 0){
		l->inicio = novo; //se não tem nada na lista, então tanto o ponteiro de início quanto final da lista apontam pro novo elemento.
		l->fim = novo;
	}
	else{ //se existe alguma coisa na lista
		aux = l->inicio; 
		aux->ant = novo; //coloca o novo elemento como o anterior a aux (que recebe o l->inicio)
		novo->prox = aux; //o proximo elemento do novo item agora é aux
		l->inicio = novo; //a lista aponta agora pro novo item como o inicial
	}
	l->qtd++; //não esquecer de atualizar a quantidade de elementos.
}

void insr_fim(lista * l, int x){
	elemento * aux, * novo;
	novo = (elemento*)malloc(sizeof(elemento));
	novo->valor = x;
	novo->ant = NULL; //inicialização do novo elemento.
	novo->prox = NULL;
	if(l->qtd == 0){ 
		l->inicio = novo;
		l->fim = novo;//até aqui a mesma lógica de insr_inicio
	}//--------------------------------------------------------------------------------------------------------------------
	else{ //a partir daqui é nova lógica (mas mais similar do que manteiga e margarina)
		aux = l->fim; //aux recebe o fim da lista
		aux->prox = novo; //o item depois de aux (que é l->fim) é o novo item
		novo->ant = aux; //o elemento anterior ao novo item agora é aux (e o item depois dele é NULL, já que inicializamos ele assim)
		l->fim = novo; //agora o l->fim aponta pro novo item
	}
	l->qtd++; //mais uma vez, não esqueca de atualizar o marcador de quantidade.
}

elemento * buscar(lista * l, int x){
	elemento * aux;
	if(l->qtd == 0){
		printf("\nLista vazia.");
		getch();
	}
	else{
		aux = l->inicio;
		while((aux->valor != x) && (aux->prox != NULL)){ //checa se o valor de aux é diferente de x E que seu próximo item NÃO É NULO.
			aux = aux->prox;
		}
		if(aux->valor = x){ //se encontra o valor de x dentro da lista, retorna o endereço do ponto da lista.
			return aux;
		}
		else{ //se não, retorna nulo.
			return NULL;
		}
	}
}

int remover(lista * l, int x){
	elemento *prev, *remover, *next; //ponteiros para o elemento a ser removido, para o elemento anterior e depois a ele.
	remover = l->inicio; //remover recebe o inicio da lista
	if(l->qtd == 0){ //se está vazio, já te retorna pato.
		printf("\nLista vazia.");
		getch();
		return 0;
	}
	else{
		remover = buscar(l,x); //remover recebe o resultado da função buscar, assim não precisa ter o código todo da função de buscar.
		prev = remover->ant; //ant e prox recebem os valores próprios
		next = remover->prox;
		if(remover == NULL){
			printf("\nLista vazia e/ou item inexistente.");
			return 0;	
		}
		else{
			if(prev != NULL){
				prev->prox = next; //se o anterior ao ponteiro remover não é nulo, então o próximo item do ponteiro prev é agora o next (o ponteiro remover some)
			}
			else{
				l->inicio = next; //se é nulo, então agora o novo item é o item next
			}
			if(next != NULL){ //se o item depois do ponteiro remover não é nulo
				next->ant = prev; //o item anterior ao item depois dele (nesse caso o ponteiro next), agora é o prev (e não o ponteiro remover)
			}
			else{
				l->fim = prev; //se é nulo (ou seja, está no fim da lista) o ponteiro do fim da lista recebe o prev (que aponta pro item anerior ao item a ser removido)
			}
			printf("\nValor removido: %d", remover->valor); //te mostra o item que foi removido
			getch();
			l->qtd--; //atualiza o nº de items na lista
			free(remover); //remove o item definido
			return 1; //retorna 1, ou seja diz que a função foi um SUCESSO
		}
	}
}

void mostrar( lista * l)
{
	elemento * aux;
	if (l->qtd==0){ //checa se a lista esta vazia
		printf("\n Nao existem elementos na lista");
	}
	else{
		aux = l->inicio;
		printf("\n %d",aux->valor);	
		while(aux->prox != NULL){ //pega do inicio da lista e vai verificando enquanto aux não é nulo.
			aux=aux->prox;
			printf("\n %d",aux->valor);	
		}
		getch();
	}
}

void menu(lista * l){
	int opt, num;
	elemento * i;
	do{
		system("cls");
		printf("(1)Inserir elemento no inicio da fila\n(2)Remover elemento\n(3)Mostrar lista\n(4)inserir item no fim da fila\n(5)Sair\n---------------------------\nDigite sua opção: ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d",&num);
				insr_inicio(l,num);
				break;
			case 2:
				printf("\nDigite o valor a ser removido: ");
				scanf("%d",&num);
				remover(l,num);
				break;
			case 3:
				mostrar(l);
				break;
			case 4:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d",&num);
				insr_fim(l,num);
				break;
			case 5:
				printf("\nEncerrando");
				getch();
				break;
			default:
				printf("\nOpção inválida.");
				getch();
				break;
		}
	}while(opt != 5);
}

int main(){
	pthue();
	lista *l1;
	l1 = alocar();
	menu(l1);
}
