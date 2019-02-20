#include <stdlib.h>  
#include <stdio.h>
#include <locale.h>
#include <conio.h>
 
//nó com os dados básicos
typedef struct node{
 	int valor;
 	struct node *esquerda;
 	struct node *direita;
 	int altura;
}node;

//prototipando
node* novo_node(int val);
int altura_get(node *b);
int fator(node *b);
int maior(int x, int y);
node *rot_left(node *b);
node *rot_right(node *b);
node *insert(node *b, int val);
node* deletar(node *b, int val);
node* successor(node* b);
void pre_order(node *b);
void pos_order(node *b);
void in_order(node *b);
void menu();
int verificar(node *b, int val);


int main(){
	setlocale(LC_ALL, "Portuguese");
	menu();
	return 0;
}

struct node* novo_node(int val){
	node* aux;
 	aux = (node*)malloc(sizeof(node));
 	aux->direita = NULL;
 	aux->esquerda = NULL;
 	aux->altura = 1;
 	aux->valor = val;
 	return aux;
}

//essa função serve pra verificar se um item existe nessa árvore, checando os nodes até ou alcaçar um node que tenha o valor ou chegar num ponto que seja NULL.
int verificar(node *b, int val){
	if(b == NULL){ //de cara se não existir nada (NULL) ele devolve 1 (que no nosso caso quer dizer que não existe)
		return 1;
	}
	else{ //se existir alguma coisa
		if(val == b->valor){ //primeiro verifica se é igual ao valor do node
			return 0; //se sim devovle 0 (que no nosso caso significa que existe esse item)
		}
		//os dois outros casos aqui são pra mandar olhar na direita ou esquerda do node pra ver se tem o item de um lado ou outro
		else if(val > b->valor){ 
			verificar(b->direita,val);
		}
		else if(val < b->valor){
			verificar(b->esquerda, val);
		}
	}
}

int altura_get(struct node *b){ //simplesmente retorna a altura do node (se ele existir)
 	if(!b){
 		return 0;
	}
	else{
	 	return b->altura;
	}
}
 
int fator(node *b){ //devolve o fator de correção de um node
	if(!b){
 		return 0;
	}
	else{
	 	return (altura_get(b->esquerda) - altura_get(b->direita));
	}
}
 
int maior(int x, int y){ //devolve o int que for maior
	if(x>y){
 		return x;
	}
	else{
	 	return y;
	}
}

node *rot_left(node *b){ 
	node *dir = b->direita; 
	node *esq = dir->esquerda;
	//faz a rotação
	dir->esquerda = b; //trocando de lugar
	b->direita = esq;
	//atualizando as alturas
	b->altura = maior(altura_get(b->esquerda), altura_get(b->direita)) + 1;
	dir->altura = maior(altura_get(dir->esquerda), altura_get(dir->direita)) + 1; //aqui faz o calculo da nova altura.
	return dir; //retorna a nova configuração. 
}
 
//mesma lógica pra rotação na direita
node *rot_right(node *b){
	struct node *esq = b->esquerda;
	struct node *dir = esq->direita;
	//faz a rotação
	esq->direita = b; //trocando de lugar
	b->esquerda = dir;
	//atualizando as alturas
	b->altura = maior(altura_get(b->esquerda), altura_get(b->direita)) + 1;
	esq->altura = maior(altura_get(esq->esquerda), altura_get(esq->direita)) + 1; //aqui faz o calculo da nova altura.
	return esq; //retorna a nova configuração. 
}

node *balancear(node *b){
	node *aux1, *aux2;
	int Hdireita, Hesquerda; //altura direita e altura esquerda, respectivamente.
	Hdireita = altura_get(b->direita);
	Hesquerda = altura_get(b->esquerda);
	//vai verificando qual lado tem a altura maior para balancear
	if(Hdireita <= Hesquerda){ //se a altura da direita for menor (ou seja, desbalanceia pra esquerda)
		aux1 = b->esquerda;    //aux1 analisa a esquerda
	}
	else{
		aux1 = b->direita;     //mesma lógica pra direita
	}
	Hdireita = altura_get(b->direita); //repete o processo da altura pros valores atualizados
	Hesquerda = altura_get(b->esquerda);
	if(aux1 == b->direita){ //vai colocando o segundo auxiliar na posição certa pra caso seja necessário fazer a rotação.
		if(Hdireita < Hesquerda){ //dependendo do lado que aux1 cair.
			aux2 = aux1->esquerda;
		}
		else{
			aux2 = aux1->direita;
		}
	}
	if(aux1 == b->esquerda){
		if(Hdireita <= Hesquerda){
			aux2 = aux1->esquerda;
		}
		else{
			aux2 = aux1->direita;
		}
	}
	// caso ++ (RSD)
	if(b->esquerda == aux1 && b->esquerda == aux2){
		b = rot_right(b);
	}
	//caso -- (RSE)
	else if(b->direita == aux1 && b->direita == aux2){
		b = rot_left(b);
	}
	//caso -+ (RDD)
	else if(b->esquerda == aux1 && b->direita == aux2){
		b->esquerda = rot_left(b);
		b = rot_right(b);
	}
	//caso +- (RDE)	
	else if(b->direita == aux1 && b->esquerda == aux2){
		b->direita = rot_right(b);
		b = rot_left(b);
	}
	return b;
}

node *insert(node *b, int val){
	int bal; //balanceamento
	node * new;
	if(b == NULL){ //caso não exista nada em b (a nossa raiz), vai criar um novo node.
 		new = novo_node(val);
 		return new;
	}
	if(b->valor > val){ //se o valor que o usuario pretende inserir é menor, manda pra esquerda.
		b->esquerda = insert(b->esquerda, val);
	}
	else{ //se for maior, manda pra direita.
		b->direita = insert(b->direita, val);
	}
	//a lógica desse pedaço acima é que vai ficar rodando recursivamente até cair numa posição que o filho a esquerda/direita é nulo.
	//agora abaixo vamos atualziar as alturas e balanceamento.
	b->altura = maior(altura_get(b->esquerda),altura_get(b->direita)) + 1;
	bal = fator(b);
	//RSD 
	if(bal > 1 && b->esquerda->valor > val){  
    	b = rot_right(b);  
	}  
   //RSE
	if(bal < -1 && b->direita->valor < val){  
		b = rot_left(b);  
	}  
   //RDD
   else if(bal > 1 && b->esquerda->valor < val){  
    	b->esquerda = rot_left(b->esquerda);  
    	b = rot_right(b);  
	}  
   //RDE  
   else if(bal < -1 && b->direita->valor > val){
		b->direita = rot_right(b->direita);
		b = rot_left(b);
	} //só repete as rotações por recursividade
	return b;
}
 
//se no balanceamento depois da remoção de um node tiver um node que tem fator de balanceamento 0
//tem que encontrar o maior successor da esquerda
node* successor(node* b){ 
	node * aux;
	aux = b->direita;
	while(aux->esquerda){
		aux = aux->esquerda;
	}
	return aux;
}
 
node* deletar(node *b, int val){
	node* aux;
	int balanca;
	if(b == NULL){ //não existe na árvore, ou a própria arvore não existe.
 		printf("\nItem inexistente na árvore ou árvore inexistente.");
		getch();
		return NULL;
	}
	if(b->valor < val){ //vai rodando recursivamente essa função até encontrar o valor pedido pelo usuário.
		b->direita = deletar(b->direita, val); //como é maior do que o valor comparado, manda rodar pro lado direito da árvore
	}
	else if(b->valor > val){ //mesma lógica.
		b->esquerda = deletar(b->esquerda,val);
	}
	else if(b->esquerda == NULL || b->direita == NULL){
		if(b->esquerda != NULL){ //se exite b->esquerda vai retornar 1 e esse if prosseuge, se não, retorna 0 e esse if não prossegue
			aux = b->esquerda;
		}
		else if(b->direita != NULL){ //mesma lógica aqui
			aux = b->direita;
		}
		else{
			aux = NULL; //não existe nenhum dos dois, então retorna null
		}
		b = NULL;
		free(b);
		return aux;
	}
	else{ //se existem os dois roda a função pra encontrar quem exatamente vai substituir o pai (indo pela esquerda).
		aux = successor(b);
		b->valor = aux->valor;
		b->direita = deletar(b->direita,b->direita->valor);
	}
	//atualizando as alturas e re-balanceando.
	if(b){
		b->altura = maior(altura_get(b->esquerda),altura_get(b->direita)) + 1;
		balanca = fator(b);
		if(balanca > 1 || balanca < -1){
			b = balancear(b);
		}
	}
	return b;
}

void pre_order(node *b){
	if(b == NULL){
		return ;
	}
	else{
		printf("%d  ", b->valor);
		pre_order(b->esquerda);
		pre_order(b->direita);
	}
}
void pos_order(node *b){
	if(b == NULL){
		return ;
	}
	else{
		pos_order(b->esquerda);
		pos_order(b->direita);
		printf("%d  ", b->valor);
	}
}
void in_order(node *b){
	if(b == NULL){
		return ;
	}
	else{
		in_order(b->esquerda);
		printf("%d  ", b->valor);
		in_order(b->direita);
	}
}
//Menu, super simples.
void menu(){
	int opt, x, y;
	node *raiz;
	int num;
	printf("\nDigite a raiz da árvore: ");
	scanf("%d", &num);
	raiz = novo_node(num);
	do{
		system("CLS");
		if(raiz != NULL){
			printf("Raiz atual: %d", raiz->valor);
		}
		printf("\n(1)inserir nó\n(2)Remover nó\n(3)imprimir\n(4)encerrar\n");
		printf("Digite sua opção: ");
		scanf("%d", &opt);
		fflush(stdin);
		switch(opt){
			case 1:
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d", &x);
				y = verificar(raiz,x);
				if(y == 1){
					insert(raiz,x);
				}
				else{
					printf("\nÁrvore não pode ter mais de um item de mesmo valor.");
					getch();
				}
				break;
			case 2:
				printf("\nDigite o valor a ser removido: ");
				scanf("%d", &x);
				raiz = deletar(raiz,x);
				break;
			case 3: //preferi por as opções de imprimir tudo junto ao invés de criar um monte de cases.
				printf("\n(1)Em ordem\n(2)pré-ordem\n(3)pós-ordem\n");
				printf("Digite sua opção: ");
				scanf("%d", &x);
				if(x == 1){
					in_order(raiz);
					getch();
				}
				else if(x == 2){
					pre_order(raiz);
					getch();
				}
				else if(x == 3){
					pos_order(raiz);
					getch();
				}
				else{
					printf("\nOpção inválida.");
					getch();
				}
			case 4:
				printf("\nEncerrando");
				break;
			default:
				printf("\nOpção inválida.");
				break;
		}
	}while(opt != 4);
}
