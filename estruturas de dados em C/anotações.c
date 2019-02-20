//PILHA POR VETOR FIXO (verificar como fazer o vetor din�mico)
//aqui o vetor � global -> n�o precisa ficar passando o vetor pras fun��es
//para uma pilha em vetor fixo, verificar se a posi��o � igual ao limite do vetor, se n�o, adiciona o elemento incrementa uma posi��o
//para pop, decrementa uma posi��o, coloca o item anterior numa vari�vel auxiliar (que vai ser retornada depois) e iguala vetor[posicao] = 0
//stackpop -> vari�vel auxiliar = vetor[posicao - 1] -> retorna a vari�vel auxiliar.

//PILHA POR STRUCT
//a aloca��o cria um ponteiro auxiliar, aux = o malloc de pilha/struct, o poteiro elementos = NULL e qtd = 0 (inicializa��o do ponteiro)
//realloc aux = realloc de memoriao, ponteiro elementos = aux (isso faz com que o vetor tenha mais elementos preservando os que j� existiam)
//depois disso elementos[qtd] = x, qtd++
//*elementos -> todo ponteiro � vetor
//push se p->qtd == 0 -> fun��o alocar(1) (isso inicializa o vetor), se n�o manda o realloc.
//ver como fazer aloca��o/realloc de quantidades grandes de elementos
//alocar multiplos elementos -> variavel auxiliar recebe o realloc -> retorna aux
//ver como fazer o pop (com as fun��es de free pra se qtd == 1)

//LISTA LIGADA (auxilia a aloca��o din�ica) lista *l1
//cada item da lista tem um valor e um ponteiro que aponta pro pr�x. elemento
//se a quantidade de itens � zero, o item da lista cai no l1->inicio
//um ponteiro no elemento aponta pro pr�ximo
/*while (aux->prox != NULL){aux = aux->prox}; -> depois repassa o aux->prox pra o elemento que apontaria pro pr�ximo item, e vai checando item por item at�
chegar em um que seja nulo*/
//fazer um ponteiro que sempre aponta pro �LTIMO elemento da lista, para n�o ter que percorrer a porcaria da lista inteira pra adicionar um novo elemento


//PILHA POR LISTA
/*
muda a inser��o dos elementos da lista: o ponteiro de in�cio agora aponta para o final da lista
novo->prox(l1->fim), o novo elemento aponta pro item anterior, e o ponteiro para o final da lista aponta para ele
novo = recebe aloca��o, novo->prox = l1->fim, l1->fim = novo.
permite que use qualquer espa�o de mem�ria, j� que sempre tem um ponteiro pro pr�ximo item
*/


//FILAS
/*
	FILA CIRCULAR � o melhor modo de implementa��o de itens numa pilha com N�MERO DE ITENS LIMITADOS, j� que n�o � necess�rio mover as vari�veis,
mas apenas um ou dois �ndices (primeiro/�ltimo). 
	Grandes quantidades de deslocamento de informa��o n�o � bom, mas filas b�sicas funcionam bem para grupos pequenos, fila circular � mais eficiente
para grupos pequenos.
*/


//PONTEIROS
/*
as estruturas vao estar em ponteiros, pra um struct, deve se declarar um ponteiro para o struct, ou tipo de struct.
exemplo: 
struct teste *t2; -> t2 � um ponteiro para um struct, e deve alocar a memm�ria necess�ria para isso.
t2 = (teste*)malloc(n*sizeof(teste)) - aloca um vetor de structs t2.
t2->ptr = (int*)malloc(sizeof(int)) - define um vetor dentro do struct apontado por t2, mas pode ser definido pra apontar para outro struct

ex.2:come�a com um ponteiro para uma lista, definindo seu tamanho por um malloc pelo tamanho do struct da lista
l1 = (lista*)malloc(n*sizeof(lista))
dentro dessa lista tem uma var�avel que guarda quantidade, e um ponteiro para um elemento, para colocar um elemento
l1->inicio = (elemento*)malloc(sizeof(lista)); - mostra o primeiro elemento da lista, que tem um ponteiro para o pr�ximo elemento 
(cada elemento ter� um ponteiro para o pr�ximo)
l1->qtd - indica a quantidade de elementos na lista.
*/

/* defini��o da lista (verificar como percorrer os elementos)

primeiro defninir os structs, depois um ponteiro para lista (e aloc�-lo), depois os elementos

typedef struct lista{
	int qtd;
	elemento * inicio
}lista;

typedef struct elemento{
	int valor;
	elemento *prox;
};
*/





