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
int comparar1(pilha * p, pilha * a, char expr[]); //aqui vai pedir a express�o, s� que sem precisar definir o tamanho dela.
int comparar2(pilha * p, pilha * a, char expr[]); //as fun��es de comparar seguem a mesma l�gica da primeira, s� v�o dando push na pilha p.
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
	printf("Digite a express�o: ");
	gets(expr);
	a = alocar();
	p = alocar();
	if(empty(p) && (empty(a) != 0)){
		printf("Express�o correta.");
	}
	else{
		printf("Express�o incorreta.");
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
		if(expr[i] == '('){ //compara se � o caract�re desejado, dando push quando abre, e pop quando fecha.
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
		else{ //se for diferente dos padr�es desejados, ele somente continua, sem dar nenhum sinal.
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
	
	
}*/

void push(pilha * p, char x){ //recebe um ponteiro pra pilha e o valor a ser adicionado.
	char * aux;
	if(p->qtd == 0){ //se qtd == 0, isso quer dizer que o vetor ainda � = NULL, ent�o precisamos de espa�o 
		p->elemento=(char*)malloc(sizeof(char)); //alloca um espa�o de mem�ria p/ um int, j� que n�o tem nenhum item.
	}
	else{ //realoca a mem�ria pra adicionar um espa�o de mem�ria a mais do tipo int
		aux = (char*)realloc(p->elemento,(p->qtd+1)*sizeof(char)); //aux = quantidade de espa�o antiga + uma unidade de espa�o
		p->elemento=aux; //se qtd != 0, usar realloc pra criar mais espa�o, pois se usar malloc s� vai desmontar tudo e crirar um espa�o vazio.
	} //o realloc mant�m a pilha inteira inalterada e adiciona/remove um espa�o dependendo do usu�rio
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
			aux =(char*)realloc(p->elemento,(p->qtd-1)*sizeof(char)); //isso realloca a mem�ria para ter um elemento a menos.
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
	if(p->qtd == 0){ //se h� algum item na pilha, vai retornar 1 (verdadeiro)
		return 1;
	}
	else{ //em alguns exemplos � colocado pra retornar 1 se a p->qtd = 0 (em outras palavras, se a pilha est� vazia).
		return 0;
	}
}


/*void mostrar_pilha(pilha *p){
	int i;
	if(empty(p)){ //utiliza a fun��o empty pra verificar se est� vazia, se retorna 1, quer dizer que a pilha n�o est� vazia
		printf("\nMostrando pilha: \n");
		for(i=p->qtd-1;i>=0;i--){ //loop b�sico pra printar a jo�a toda.
			printf("\n%d", p->elemento[i]);
		}
	}
	else{
		printf("\nPilha vazia.");
	}
	
}*/
