#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <windows.h>
#include <locale.h>
//�rvore bin�ria
//a raiz � onde  
//�rvore n�o pode ter elementos repetidos
//para esquerda s�o sempre os n�meros menores que o pai (antecessor), a direita os maiores.
//2p + 1 � esquerda
//2p + 2 � direita
//pre ordem: raiz, esquerda, direita
//em ordem: esquerda, raiz, direita
//pos ordem: esquerda, direita, raiz

/*typedef struct arvore{
	int * valor; //vetor de valores
	int tamanho; //tamanho da �rvore
};*/
//s� nao apaguei isso aqui pq pode vir a ser �til em algum outro c�digo.

void pause(){ //isso aqui � s� pra pausar o programa por alguns segundos
	sleep(1); //por que diabos o felippe colocou isso no c�digo � um mist�rio.
	system("cls");
}

int * planta_arvore(){ //aloca��o da �rvore
	int * aux;
	int tamanho, i;
	printf("Digite o tamanho da arvore: ");
	scanf("%d", &tamanho);
	aux = (int*)malloc(sizeof(int)*tamanho); //aloca a �rvore
	for(i = 0; i < tamanho;i++){
		aux[i] = 0; //zero vai ser nosso paceholder de n�/posi��o vazia
	}
	pause();
	return aux;
}

int galho_recursivo(int * arvore, int indice, int valor){ //fun��o de inserc�o
	int posicao;
	//essa parte inicial aqui era pra pegar o tamanho do vetor e ter uma compara��o com o �ndice
	//mas t� bugado, pesqusiar como resolver isso aqui
	/*int tamanho;
	tamanho = (sizeof(arvore))/(sizeof(int)); //tempor�rio ate ter uma fun��o pra pegar o tamanho da �rvore
	if(indice >= tamanho){
		printf("\n�rvore cheia.");
		return 0;
	}*/
	if(valor == 0){ //n�o d� pra inserir zero j� que ele j� � o valor paceholder
		return 0;
	}
	if(arvore[indice] == valor){ //n�o pode ter o mesmo valor mais de uma vez numa �rvore
		printf("\nValor j� existente na �rvore.");
		return 0;
	}
	if(arvore[indice] != 0){ //se o �ndice n�o est� vazio, ele joga pra uma das raizes do n� que existe nesse indice
		if(valor < arvore[indice]){
			posicao = (indice*2)+1; //esquerda
			galho_recursivo(arvore,posicao,valor); //e planta essa jo�a via recursividade
		}	
		else if(valor > arvore[indice]){
			posicao = (indice*2)+2; //direita
			galho_recursivo(arvore,posicao,valor);
		}
	}
	else{ //aqui � se o �ndice est� vazio
		arvore[indice] = valor; //s� planta essa coisa sem problema
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
} //n�o tem bonus exclusivo por pre-order dessa jo�a

void mostra_em_ordem(int * arvore, int indice){ //em ordem: esquerda, raiz, direita
	if(indice >= 60){
		return ;
	}
	if(!arvore[indice]){ //tamb�m funciona
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

//na parte de remo��o, tem que pegar sempre o maior valor da ESQUERDA do item/n� a ser removido. 
//por que, eu n�o sei, deve ser alguma coisa pra n�o quebrar a ordem da �rvore. aceita que d�i menos.
int podar_arvore(int * arvore, int indice, int valor){ //o de remover t� MUITO bugado ainda.
	if(indice >= 60){
		printf("\nElemento n�o est� na �rvore");
		return 0;
	}
	if(arvore[indice] != valor){
		if(((indice*2)+1 != 0) && ((indice*2)+1 != 0)){ //se ele tem algum filho
				
		}
		else{
			if(((indice*2)+1 == 0) && ((indice*2)+1 == 0)){ //se n�o tem nenhum filho
				arvore[indice] = 0; //s� apaga essa jo�a
				return 1;
			}
			else{ //se tem algum filho
				if((indice*2)+1 != 0){ //filho na esquerda
					arvore[indice] = arvore[(2*indice)+1]; //agora o filho toma o lugar do pai
					arvore[(2*indice)+1] = 0; //esvazia o espa�o que o filho estava
					return 1;
				}
				else{//mesma l�gica s� que pra esquerda.
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












