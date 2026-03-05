#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int encontrarMaior(int arr[], int n){
	int maior = arr[0];
	for(int i =0; i < n;i++){
		if(arr[i]>maior){
			maior = arr[i];
		}
		
		
	}
	return maior;
}

int main(){
	//busca linear 
	//melhor caso O(1)
	int arr1[] = {10/* maior no começo*/, 5 ,6};
	int maior1 = encontrarMaior(arr1,3);
	printf("%d \n", maior1);
	//caso medio
	
	// caso médio  O(n/2)
	int arr2[] = {10, 50/* maior no meio*/ ,6};
	int maior2 = encontrarMaior(arr2,3);
	printf("%d \n", maior2);
	//pior caso O(n)
	int arr3[] = {5 ,6, 10/* maior no final*/};
	int maior3 = encontrarMaior(arr3,3);
	printf("%d \n", maior3);
	
	
}
