#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
//PILHA POR LISTA SIMPLES
typedef struct elemento{
  int item;
  struct elemento * prox;
  struct elemento * ant;
}elemento;
typedef struct lista{
  int qtd;
  struct elemento * final;
}lista;

lista * alocar();
void push(lista * l, int num);
int pop(lista * l);
void mostrar(lista * l);
int stackpop(lista * l);
elemento * buscar(lista * l, int num);
void menu(lista * l);

int main(){
  setlocale(LC_ALL, "portuguese");
  lista * l;
  l = alocar();
  menu(l);
}

lista * alocar(){
  lista *aux;
  aux = (lista*)malloc(sizeof(lista));
  aux->qtd = 0;
  aux->final = NULL;
  return aux;
}

void push(lista * l, int num){
  elemento *aux, *aux2;
  aux2 = l->final;
  aux = (elemento*)malloc(sizeof(elemento));
  aux->prox = NULL;
  aux->ant = NULL;
  aux->item = num;
  if(l->qtd == 0){
    l->final = aux;
  }
  else{
    aux2->prox = aux;
    l->final = aux;
    aux->ant = aux2;
  }
  l->qtd++;
  printf("\nElemento adicionado a pilha: %d\n", aux->item);
  getch();
}

int pop(lista * l){
  elemento *aux;
  aux = l->final;
  if(l->qtd == 0){
    printf("\nLista vazia.");
    getch();
  }
  else{
  	l->final = aux->ant;
  	printf("\nItem removido: %d\n", aux->item);
  	free(aux);
  	l->qtd--;
  }
  getch();
}

int stackpop(lista * l){
  elemento * aux;
  if(l->qtd == 0){
    printf("\nLista vazia.");
    getch();
  }
  else{
    aux = l->final;
    printf("\nElemento no topo da pilha: %d", aux->item);
    getch();
  }

}

void mostrar(lista * l){
  elemento *aux;
  if(l->qtd == 0){
  	printf("\nPilha vazia.");
  	getch();
  }
  else{
  	aux = l->final;
  	while(aux != NULL){
    	printf("\n%d", aux->item);
   		aux = aux->ant;
 	}
  }
  getch();
}

void empty(lista * l){
  if(l->qtd == 0){
    printf("\nLista vazia.");
    getch();
  }
  else{
    printf("\nA lista possui %d elemento(s) no momento.", l->qtd);
    getch();
  }
}

elemento * buscar(lista * l, int num){
  elemento * aux;
  aux = l->final;
  while(aux->item != num && aux->ant != NULL){
   	aux = aux->ant;
  }
  if(aux->item == num){
  	return aux;
  }
  else{
  	return NULL;
   }
}
void menu(lista * l){
  int opt, num;
  elemento * b;
  do{
  	system("CLS");
  	printf("(1)push\n(2)pop\n(3)stackpop\n(4)verificar se a pilha esta vazia\n(5)mostrar pilha\n(6)buscar item na pilha\n(7)sair");
  	printf("\nDigite a sua opção: ");
  	scanf("%d", &opt);
    switch(opt){
      case 1:
        printf("Digite o numero a ser adicionado: ");
        scanf("%d", &num);
        push(l,num);
        break;
      case 2:
        pop(l);
        break;
      case 3:
        stackpop(l);
        break;
      case 4:
        empty(l);
        break;
      case 5:
        mostrar(l);
        break;
      case 6:
      	if(l->qtd == 0){
  			printf("\nLista vazia.");
  			getch();
  		}
        else{
        	printf("\nDigite o numero a ser buscado: ");
 	        scanf("%d", &num);
      		b = buscar(l, num);
        	if(b == NULL){
        		printf("\nNúmero não encontrado.");
			}
			else{
				printf("\nNúmero encontrado: %d", b->item);
			}
			getch();
		}
		break;
      case 7:
        printf("\nEncerrando.");
        break;
      default:
        printf("\nOpção invalida.");
        getch();
        break;
      }
    }while(opt != 7);
}
