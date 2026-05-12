#include <stdio.h>


//ex 1
int potencia(int x, int n){
	if (n == 0) return 1;
	return x * potencia( x, n-1);
	
}
//2


//3

int main(){

	int p = potencia(3,3);
	printf("\n%d", p);
	
}
