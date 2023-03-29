#include <stdio.h>
#define Tamanho 10

void selectionSort(int *v){
	int i, j, min_index, temp;
	for( i=0; i < Tamanho - 1; i++) {
		min_index = i;
		
		printf("\n-----Rodada %d-----\n\n", i);
		for( j = i + 1; j < Tamanho; j++) {
			printf("Valor j[%d]: %d\t Valor min[%d]: %d\n", j, v[j], min_index, v[min_index]);

			if(v[j]< v[min_index]){
				min_index = j; 
				
			}
		}
		temp = v[i];
		v[i] = v[min_index];
		v[min_index] = temp;
	}
	printf("Valor j[-1]: NaN\t Valor min[%d]: %d\n\n", min_index, v[min_index]);


	
}

void imprimeVetor(int *v){
	printf("Vetor: { ");
	for( int i = 0; i < Tamanho; i++){
		if(i == Tamanho-1){
			printf("%d }\n\n", v[i]);
		}
		else {
			printf("%d, ", v[i]);
		}
	}
}

int main(void) {

	int vetor[Tamanho] = {2, 3, 1, 74, 3, 9, 55, 0, 8, 4};

	imprimeVetor(vetor);
	insertionSort(vetor);
	imprimeVetor(vetor);
  printf("Hello World\n");
  return 0;
}