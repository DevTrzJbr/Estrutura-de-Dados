#include <stdio.h>
#define Tamanho 10

void imprimeVetor(int *v);
void imprimeVetorValor(int *v, int valor);

void insertionSort(int *v){
	int i, j, valor;

	
	for( i = 0; i < Tamanho; i++){
		valor = v[i];
		printf("\n\n----Rodada %d----\n", i+1);
		printf("\nValor: %d",valor);

		printf("\n");

		j = i -1;
		while(j >= 0 && v[j] > valor) {
			imprimeVetorValor(v, valor);
            v[j+1] = v[j];
            j--;
			
			if(j >= 0 && v[j] > valor){
				printf("\nDeslocando ", j);
			}
        }
        
        v[j+1] = valor;

		printf("\n");
		imprimeVetorValor(v, valor);
	}

	printf("\n----Fim----\n");
	
}

void imprimeVetor(int *v){
	printf("{ ");
	for( int i = 0; i < Tamanho; i++){
		if(i == Tamanho-1){
			printf("%d }\n", v[i]);
		} else {
			printf("%d, ", v[i]);
		}
	}
}

void imprimeVetorValor(int *v, int valor){
	printf("Vetor: { ");
	for( int i = 0; i < Tamanho; i++){
		if(i == Tamanho-1){
			printf("%d }\n", v[i]);
		} else if (v[i] == valor){
			printf("[%d], ", v[i]);
		}
		else {
			printf("%d, ", v[i]);
		}
	}
}

int main(void) {
	int vetor[Tamanho] = {5, 2, 20, 4, 1, 10, 6, 8, 12, 0};
    int i;
    
    printf("Array desordenado: ");
    imprimeVetor(vetor);
    
    insertionSort(vetor);
    
    printf("\nArray ordenado: ");
    imprimeVetor(vetor);

}