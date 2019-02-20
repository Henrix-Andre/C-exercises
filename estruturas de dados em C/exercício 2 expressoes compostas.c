#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct //edita todos os ints pra mudar pra char (menos o empty) para mudar 
{
	char qtd;
	char * elemento;
}pilha;

void pthue(){
	setlocale(LC_ALL, "Portuguese");
}

pilha * alocar ();
int comparar1(pilha * p, pilha * a, char expr[]); //aqui vai pedir a expressão, só que sem precisar definir o tamanho dela.
int comparar2(pilha * p, pilha * a, char expr[]); //as funções de comparar seguem a mesma lógica da primeira, só vão dando push na pilha p.
int comparar3(pilha * p, pilha * a, char expr[]);
void menu(pilha * p);
void push(pilha * p, char x);
char pop(pilha * p);
int empty(pilha * p); 
int main ()
{
	pthue();
	pilha * p;
	pilha * a;
	char expr[100];
	//int a, b, c;
	printf("Digite a expressão: ");
	gets(expr);
	a = alocar();
	p = alocar();
	if(empty(p) && (empty(a) != 0)){
		printf("Expressão correta.");
	}
	else{
		printf("Expressão incorreta.");
	}

	return 0;
	
}

pilha * alocar ()
{
	pilha * aux;
	aux = (pilha*)malloc(sizeof(pilha));
	aux->qtd=0;
	aux->elemento = (char*)malloc(sizeof(char));
	return aux;
		
} 

int comparar1(pilha * p, pilha * a, char expr[]){
	int i;
	for(i=0;i<strlen(expr);i++){ //strlen(string) te retorna o tamanho da string
		if(expr[i] == '('){ //compara se é o caractére desejado, dando push quando abre, e pop quando fecha.
			push(p, expr[i]);
		}
		else if(expr[i] == ')'){
			if(empty(p)){
				push(a, expr[i]);
				return 0;
			}
			else{
				pop(p);
			}
		}
		else{ //se for diferente dos padrões desejados, ele somente continua, sem dar nenhum sinal.
			continue;
		}
	}
}

int comparar2(pilha * p, pilha * a,  char expr[]){
	int i;
	for(i=0;i<strlen(expr);i++){ //strlen(string) te retorna o tamanho da string
		if(expr[i] == '['){
			push(p, expr[i]);
		}
		else if(expr[i] == ']'){
			if(empty(p)){
				push(a, expr[i]);
				return 0;
			}
			else{
				pop(p);
			}
		}
		else{
			continue;
		}
	}
}

int comparar3(pilha * p, pilha * a,  char expr[]){
	int i;
	for(i=0;i<strlen(expr);i++){ //strlen(string) te retorna o tamanho da string
		if(expr[i] == '{'){
			push(p, expr[i]);
		}
		else if(expr[i] == '}'){
			if(empty(p)){
				push(a, expr[i]);
				return 0;
			}
			else{
				pop(p);
			}
		}
		else{
			continue;
		}
	}
}

/*void menu(pilha * p)
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
				printf("Número removido da pilha: %d\n", num);
				break;
			case 3:
				
				break;
			case 4:
				if(stackpop(p)){ //se retornar algo diferente de zero (o que significa que funcionou), então o if aqui segue caminho.
					printf("\nNúmero do topo: %d", stackpop(p));
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
	
	
}*/

void push(pilha * p, char x){ //recebe um ponteiro pra pilha e o valor a ser adicionado.
	char * aux;
	if(p->qtd == 0){ //se qtd == 0, isso quer dizer que o vetor ainda é = NULL, então precisamos de espaço 
		p->elemento=(char*)malloc(sizeof(char)); //alloca um espaço de memória p/ um int, já que não tem nenhum item.
	}
	else{ //realoca a memória pra adicionar um espaço de memória a mais do tipo int
		aux = (char*)realloc(p->elemento,(p->qtd+1)*sizeof(char)); //aux = quantidade de espaço antiga + uma unidade de espaço
		p->elemento=aux; //se qtd != 0, usar realloc pra criar mais espaço, pois se usar malloc só vai desmontar tudo e crirar um espaço vazio.
	} //o realloc mantém a pilha inteira inalterada e adiciona/remove um espaço dependendo do usuário
	p->elemento[p->qtd] = x;
	p->qtd++;
}
char pop(pilha * p){
	char retorno;
	char * aux;
	if (p->qtd==0){
		printf("\n Pilha vazia");
		retorno = 0;
	}
	else{
		retorno = p->elemento[p->qtd-1];	
		if (p->qtd==1){
			free(p->elemento);	//como a pilha vai ficar vazia,o free esvazia tudo.
		}
		else{
			aux =(char*)realloc(p->elemento,(p->qtd-1)*sizeof(char)); //isso realloca a memória para ter um elemento a menos.
			p->elemento=aux; //recebe os dados de aux.
		}
		p->qtd--;		
	}
	return retorno;

}

/*int stackpop(pilha * p){
	return p->elemento[p->qtd-1]; //simplesmente retorna a quantidade no topo.
}*/

int empty(pilha *p){
	if(p->qtd == 0){ //se há algum item na pilha, vai retornar 1 (verdadeiro)
		return 1;
	}
	else{ //em alguns exemplos é colocado pra retornar 1 se a p->qtd = 0 (em outras palavras, se a pilha está vazia).
		return 0;
	}
}


/*void mostrar_pilha(pilha *p){
	int i;
	if(empty(p)){ //utiliza a função empty pra verificar se está vazia, se retorna 1, quer dizer que a pilha não está vazia
		printf("\nMostrando pilha: \n");
		for(i=p->qtd-1;i>=0;i--){ //loop básico pra printar a joça toda.
			printf("\n%d", p->elemento[i]);
		}
	}
	else{
		printf("\nPilha vazia.");
	}
	
}*/
