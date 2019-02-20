#include <stdlib.h>
#include <time.h>
#include <locale.h>

void tempo(){
	clock_t t;
	time_t timer = time(NULL);
	t = clock() - t; //isso aqui calcula o tempo atual - o tempo que o programa precisou rodar
	printf("%s\n", ctime(&timer)); //isso aqui por alguma razão gera uma string que mostra o tempo atual
	printf("O programa rodou em %f segundos", ((float)t)/CLOCKS_PER_SEC); //o final aqui converte de 'processor clicks' pra float
}

int main(){
	setlocale(LC_ALL, "portuguese");
	tempo();
	return 0;
}
