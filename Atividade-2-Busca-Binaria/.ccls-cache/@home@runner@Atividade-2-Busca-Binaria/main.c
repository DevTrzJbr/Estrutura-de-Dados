#include <stdio.h>
#define tamanho 10

// Prototipos. 
int buscaBinaria(int *v, int valor);
void impremeVetor(int *v);

int main(void) {
	int vetor[tamanho] = {-5,-2,1,5,7,8,12,45,67,90};
	int valor;

	impremeVetor(vetor);
	
	printf("\nDigite um número a buscar no vetor: ");
	scanf("%d", &valor);

	int resultado = buscaBinaria(vetor, valor);

	if( resultado == -1){
		printf("\nO número não pertence ao vetor!");
	} else {
		printf("\nValor %d está na posição %d", valor, resultado + 1);
	}
	return 0;
}

int buscaBinaria(int *v, int valor){
	int inicio = 0; 		// inicio do vetor
	int fim = tamanho - 1; 	// fim do vetor
	
	while( inicio <= fim ) { 				// Busca até inicio maior que meio.
		int meio = ( inicio + fim ) / 2; 	// Pega o meio do vetor.
		
		if( v[meio] == valor ){ 			// Retorna o indice do valor.
			return meio;
		} else if(v[meio] < valor){ 		// Busca a direita do meio do vetor.
			inicio = meio + 1;				// Define o inicio a partir do meio do vetor + 1.
		} else {							// Busca a esquerda do meio do vetor.
			fim = meio - 1;					// Define o fim no meio do vetor - 1.
		}
	}
	return -1; 			// retorna -1 caso valor não encontrado.
}

void impremeVetor(int *v){
	printf("Vetor { ");
	for( int i = 0; i < tamanho; i++){
		if( i == tamanho - 1){
			printf("%d }\n", v[i]);		
		} else {
			printf("%d, ", v[i]);
		}
	}	
}