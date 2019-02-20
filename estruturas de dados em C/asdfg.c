#include <stdio.h>
#include <stdlib.h>
#include "abcu.h"

int main(){
	int a = 3, b = 2, c, *p, *l;
	float d, e;
	p = &a;
	l = &b;
	Ponto A1, B1;
	A1.x = 2;
	A1.y = 3;
	B1.x = 4;
	B1.y = 6;
	somaprod(p,l,2,3);
	fator(&c,4);
	d = distancia(A1,B1);
	printf("%d, %d, %d, %.2f\n", a,b,c,d);
	troca(&a, &b);
	troca2(&A1.x, &B1.x);
	troca2(&A1.y, &B1.y);
	e = distancia(A1,B1);
	printf("%d %d\n", a,b);
	printf("%.2f %.2f\n", A1.x, B1.x);
	printf("%.2f", e);
}
