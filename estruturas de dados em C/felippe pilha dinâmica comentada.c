#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
	int qtd;
	int * elementos;
}pilha;

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

pilha * alocar ( int tamanho);
void menu(pilha * p);
void push(pilha * p, int x);
int pop(pilha * p); 
int empty(p); 
int main ()
{
	pthue();
	pilha * p;
	int tamanho;
	printf("Digite o tamanho da pilha: ");
	scanf("%d",&tamanho);
	p = alocar(tamanho);
	menu(p);

	return 0;
	
}

pilha * alocar ( int tamanho)
{
	pilha * aux;
	aux = (pilha*)malloc(sizeof(pilha));
	aux->qtd=0;
	aux->elementos = (int*)malloc(sizeof(int)*tamanho);
	return aux;
		
} 


void menu(pilha * p)
{
	int opcao, num;
	do
	{
		printf("Quantidade de elementos na pilha: %d\n", p->qtd);
		printf("\n 1 - Push");
		printf("\n 2 - Pop");
		printf("\n 3 - Size");
		printf("\n 4 - Stackpop");
		printf("\n 5 - Empty");
		printf("\n 6 - Sair");
		scanf("%d",&opcao);
	
		switch(opcao)
		{
			case 1:
				printf("Digite o elemento a ser digitado: ");
				scanf("%d", num);
				push(p,num);
				break;
			case 2:
				num = pop(p);
				printf("N�mero removido da pilha: %d\n", num);
				break;
			case 3:
				
				break;
			case 4:
				if(stackpop(p)){ //se retornar algo diferente de zero (o que significa que funcionou), ent�o o if aqui segue caminho.
					printf("\nN�mero do topo: %d", stackpop(p));
				}
				break;
			case 5:
				if(empty(p)){
					printf("\nExistem %d elementos na pilha.", p->qtd);
				}
				else{
					printf("\nPilha vazia.");
				}
				break;
			case 6:
				printf("\n Saindo do programa ");
				break;
			default:
				printf("\n Opcao invalida");
				break;
		}
	}while(opcao !=6);
	
	
}

void push(pilha * p, int x){ //recebe um ponteiro pra pilha e o valor a ser adicionado.
	int * aux;
	if(p->qtd == 0){ //se qtd == 0, isso quer dizer que o vetor ainda � = NULL, ent�o precisamos de espa�o 
		p->elementos=(int*)malloc(sizeof(int)); //alloca um espa�o de mem�ria p/ um int, j� que n�o tem nenhum item.
	}
	else{ //realoca a mem�ria pra adicionar um espa�o de mem�ria a mais do tipo int
		aux = (int*)realloc(p->elementos,(p->qtd+1)*sizeof(int)); //aux = quantidade de espa�o antiga + uma unidade de espa�o
		p->elementos=aux; //se qtd != 0, usar realloc pra criar mais espa�o, pois se usar malloc s� vai desmontar tudo e crirar um espa�o vazio.
	} //o realloc mant�m a pilha inteira inalterada e adiciona/remove um espa�o dependendo do usu�rio
	p->elementos[p->qtd] = x;
	p->qtd++;
}

int pop(pilha * p){
	int retorno, *aux;
	if(p->qtd == 0){
		printf("\nPilha vazia."); //aqui n�o � preciso 
	}
	else{
		if(p->qtd==1){
			free(p->elementos); //como a pilha vai ficar vazia,o free esvazia tudo.
			retorno = 0;
		}
		else{
			retorno = p->elementos[p->qtd-1];
			aux = (int*)realloc(p->elementos,(p->qtd-1)*sizeof(int)); //isso realloca a mem�ria para ter um elemento a menos.
			p->elementos = aux; //recebe os dados de aux.
		}
		p->qtd--;
	}
	return retorno;
}

int stackpop(pilha * p){
	return p->elementos[p->qtd-1]; //simplesmente retorna a quantidade no topo.
}

int empty(pilha *p){
	if(p->qtd != 0){ //se h� algum item na pilha, vai retornar 1 (verdadeiro)
		return 1;
	}
	else{ //em alguns exemplos � colocado pra retornar 1 se a p->qtd = 0 (em outras palavras, se a pilha est� vazia).
		return 0;
	}
}


void mostrar_pilha(pilha *p){
	int i;
	if(empty(p)){ //utiliza a fun��o empty pra verificar se est� vazia, se retorna 1, quer dizer que a pilha n�o est� vazia
		printf("\nMostrando pilha: \n");
		for(i=p->qtd-1;i>=0;i--){ //loop b�sico pra printar a jo�a toda.
			printf("\n%d", p->elementos[i]);
		}
	}
	else{
		printf("\nPilha vazia.");
	}
	
}
