#include <stdio.h>

void mudaX(int x){
	x= 15;
	printf("X dentro da função(copia): %d\n")
}

void mudaXreferencia(int *x){
	x= 15;

}


int main(){
	int x = 10;
	mudaX(x)
	printf("%d", x);
		

}
