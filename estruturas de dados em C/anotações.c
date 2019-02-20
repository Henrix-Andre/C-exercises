//PILHA POR VETOR FIXO (verificar como fazer o vetor dinâmico)
//aqui o vetor é global -> não precisa ficar passando o vetor pras funções
//para uma pilha em vetor fixo, verificar se a posição é igual ao limite do vetor, se não, adiciona o elemento incrementa uma posição
//para pop, decrementa uma posição, coloca o item anterior numa variável auxiliar (que vai ser retornada depois) e iguala vetor[posicao] = 0
//stackpop -> variável auxiliar = vetor[posicao - 1] -> retorna a variável auxiliar.

//PILHA POR STRUCT
//a alocação cria um ponteiro auxiliar, aux = o malloc de pilha/struct, o poteiro elementos = NULL e qtd = 0 (inicialização do ponteiro)
//realloc aux = realloc de memoriao, ponteiro elementos = aux (isso faz com que o vetor tenha mais elementos preservando os que já existiam)
//depois disso elementos[qtd] = x, qtd++
//*elementos -> todo ponteiro é vetor
//push se p->qtd == 0 -> função alocar(1) (isso inicializa o vetor), se não manda o realloc.
//ver como fazer alocação/realloc de quantidades grandes de elementos
//alocar multiplos elementos -> variavel auxiliar recebe o realloc -> retorna aux
//ver como fazer o pop (com as funções de free pra se qtd == 1)

//LISTA LIGADA (auxilia a alocação dinâica) lista *l1
//cada item da lista tem um valor e um ponteiro que aponta pro próx. elemento
//se a quantidade de itens é zero, o item da lista cai no l1->inicio
//um ponteiro no elemento aponta pro próximo
/*while (aux->prox != NULL){aux = aux->prox}; -> depois repassa o aux->prox pra o elemento que apontaria pro próximo item, e vai checando item por item até
chegar em um que seja nulo*/
//fazer um ponteiro que sempre aponta pro ÚLTIMO elemento da lista, para não ter que percorrer a porcaria da lista inteira pra adicionar um novo elemento


//PILHA POR LISTA
/*
muda a inserção dos elementos da lista: o ponteiro de início agora aponta para o final da lista
novo->prox(l1->fim), o novo elemento aponta pro item anterior, e o ponteiro para o final da lista aponta para ele
novo = recebe alocação, novo->prox = l1->fim, l1->fim = novo.
permite que use qualquer espaço de memória, já que sempre tem um ponteiro pro próximo item
*/


//FILAS
/*
	FILA CIRCULAR é o melhor modo de implementação de itens numa pilha com NÚMERO DE ITENS LIMITADOS, já que não é necessário mover as variáveis,
mas apenas um ou dois índices (primeiro/último). 
	Grandes quantidades de deslocamento de informação não é bom, mas filas básicas funcionam bem para grupos pequenos, fila circular é mais eficiente
para grupos pequenos.
*/


//PONTEIROS
/*
as estruturas vao estar em ponteiros, pra um struct, deve se declarar um ponteiro para o struct, ou tipo de struct.
exemplo: 
struct teste *t2; -> t2 é um ponteiro para um struct, e deve alocar a memmória necessária para isso.
t2 = (teste*)malloc(n*sizeof(teste)) - aloca um vetor de structs t2.
t2->ptr = (int*)malloc(sizeof(int)) - define um vetor dentro do struct apontado por t2, mas pode ser definido pra apontar para outro struct

ex.2:começa com um ponteiro para uma lista, definindo seu tamanho por um malloc pelo tamanho do struct da lista
l1 = (lista*)malloc(n*sizeof(lista))
dentro dessa lista tem uma varíavel que guarda quantidade, e um ponteiro para um elemento, para colocar um elemento
l1->inicio = (elemento*)malloc(sizeof(lista)); - mostra o primeiro elemento da lista, que tem um ponteiro para o próximo elemento 
(cada elemento terá um ponteiro para o próximo)
l1->qtd - indica a quantidade de elementos na lista.
*/

/* definição da lista (verificar como percorrer os elementos)

primeiro defninir os structs, depois um ponteiro para lista (e alocá-lo), depois os elementos

typedef struct lista{
	int qtd;
	elemento * inicio
}lista;

typedef struct elemento{
	int valor;
	elemento *prox;
};
*/





