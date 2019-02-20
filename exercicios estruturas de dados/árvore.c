#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <locale.h>
//árvore binária
//a raiz é onde  
//árvore não pode ter elementos repetidos
//para esquerda são sempre os números menores que o pai (antecessor), a direita os maiores.
//2p + 1 é esquerda
//2p + 2 é direita
//pre ordem: raiz, esquerda, direita
//em ordem: esquerda, raiz, direita
//pos ordem: esquerda, direita, raiz

/*typedef struct arvore{
	int * valor; //vetor de valores
	int tamanho; //tamanho da árvore
};*/
//só nao apaguei isso aqui pq pode vir a ser útil em algum outro código.

void pause(){ //isso aqui é só pra pausar o programa por alguns segundos
	sleep(1); //por que diabos o felippe colocou isso no código é um mistério.
	system("cls");
}

int * planta_arvore(){ //alocação da árvore
	int * aux;
	int tamanho, i;
	printf("Digite o tamanho da arvore: ");
	scanf("%d", &tamanho);
	aux = (int*)malloc(sizeof(int)*tamanho); //aloca a árvore
	for(i = 0; i < tamanho;i++){
		aux[i] = 0; //zero vai ser nosso paceholder de nó/posição vazia
	}
	pause();
	return aux;
}

int galho_recursivo(int * arvore, int indice, int valor){ //função de insercão
	int posicao;
	//essa parte inicial aqui era pra pegar o tamanho do vetor e ter uma comparação com o índice
	//mas tá bugado, pesqusiar como resolver isso aqui
	/*int tamanho;
	tamanho = (sizeof(arvore))/(sizeof(int)); //temporário ate ter uma função pra pegar o tamanho da árvore
	if(indice >= tamanho){
		printf("\nÁrvore cheia.");
		return 0;
	}*/
	if(valor == 0){ //não dá pra inserir zero já que ele já é o valor paceholder
		return 0;
	}
	if(arvore[indice] == valor){ //não pode ter o mesmo valor mais de uma vez numa árvore
		printf("\nValor já existente na árvore.");
		return 0;
	}
	if(arvore[indice] != 0){ //se o índice não está vazio, ele joga pra uma das raizes do nó que existe nesse indice
		if(valor < arvore[indice]){
			posicao = (indice*2)+1; //esquerda
			galho_recursivo(arvore,posicao,valor); //e planta essa joça via recursividade
		}	
		else if(valor > arvore[indice]){
			posicao = (indice*2)+2; //direita
			galho_recursivo(arvore,posicao,valor);
		}
	}
	else{ //aqui é se o índice está vazio
		arvore[indice] = valor; //só planta essa coisa sem problema
		printf("\nElemento inserido: %d", valor);
		return 1;
	}
}

void mostrar_arvoreBasic(int * arvore){
	int i;
	for(i = 0; i < 60; i++){
		printf(" %d ", arvore[i]);
	}
	//pause();
}

void mostra_preorder(int * arvore, int indice){ //pre-ordem: raiz, esquerda, direita
	if(indice >= 60){
		return ;
	}
	if(arvore[indice] == 0){
		return ;
	}
	printf("%d ", arvore[indice]);
	mostra_preorder(arvore, (2*indice)+1); //esquerda
	mostra_preorder(arvore, (2*indice)+2); //direita
} //não tem bonus exclusivo por pre-order dessa joça

void mostra_em_ordem(int * arvore, int indice){ //em ordem: esquerda, raiz, direita
	if(indice >= 60){
		return ;
	}
	if(!arvore[indice]){ //também funciona
		return ;
	}
	mostra_em_ordem(arvore, (2*indice)+1); //esquerda
	printf("%d ", arvore[indice]);
	mostra_em_ordem(arvore, (2*indice)+2); //direita
}

void mostra_posorder(int * arvore, int indice){ //pos-ordem: esquerda, direita, raiz
	if(indice >= 60){
		return ;
	}
	if(arvore[indice] == 0){
		return ;
	}
	mostra_posorder(arvore, (2*indice)+1); //esquerda
	mostra_posorder(arvore, (2*indice)+2); //direita
	printf("%d ", arvore[indice]);
}
/*
if(arvore[indice] < valor){
	podar_arvore(arvore, (2*indice)+1, valor); //esquerda
}
else{
	podar_arvore(arvore, (2*indice)+2, valor); //direita
}
*/

//na parte de remoção, tem que pegar sempre o maior valor da ESQUERDA do item/nó a ser removido. 
//por que, eu não sei, deve ser alguma coisa pra não quebrar a ordem da árvore. aceita que dói menos.
int podar_arvore(int * arvore, int indice, int valor){ //o de remover tá MUITO bugado ainda.
	if(indice >= 60){
		printf("\nElemento não está na árvore");
		return 0;
	}
	if(arvore[indice] != valor){
		if(((indice*2)+1 != 0) && ((indice*2)+1 != 0)){ //se ele tem algum filho
				
		}
		else{
			if(((indice*2)+1 == 0) && ((indice*2)+1 == 0)){ //se não tem nenhum filho
				arvore[indice] = 0; //só apaga essa joça
				return 1;
			}
			else{ //se tem algum filho
				if((indice*2)+1 != 0){ //filho na esquerda
					arvore[indice] = arvore[(2*indice)+1]; //agora o filho toma o lugar do pai
					arvore[(2*indice)+1] = 0; //esvazia o espaço que o filho estava
					return 1;
				}
				else{//mesma lógica só que pra esquerda.
					arvore[indice] = arvore[(2*indice)+2]; 
					arvore[(2*indice)+2] = 0;
				}
			}
		}
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int * arvore;
	arvore = planta_arvore();
	galho_recursivo(arvore,0,30);
	galho_recursivo(arvore,0,20);
	galho_recursivo(arvore,0,5);
	galho_recursivo(arvore,0,25);
	galho_recursivo(arvore,0,35);
	galho_recursivo(arvore,0,36);
	printf("\n");
	mostrar_arvoreBasic(arvore);
	printf("\npre-ordem:\n");
	mostra_preorder(arvore,0);
	printf("\nem ordem:\n");
	mostra_em_ordem(arvore,0);
	printf("\npos-ordem:\n");
	mostra_posorder(arvore,0);
}












