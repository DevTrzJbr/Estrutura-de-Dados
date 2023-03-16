#include <stdio.h>
#define tamanho 10

int buscaRecursiva(int *vetor, int valor, int posicao);
void imprimeVetor(int *v);

int main(void) {
	int vetor[10] = {1,45,20,76,90,88,44,65,13,22};

	imprimeVetor(vetor);
	
	printf("\nDigite o número do elemento para ser encontrado dentro do vetor: ");
	int valor;
	scanf("%d", &valor);

	int indiceElem = buscaRecursiva(vetor, valor, 0);

	if(indiceElem == -1){
		printf("\nO elemento %d não está dentro do vetor!", valor);
	} else {
    	printf("\nO elemento %d está no indice %d, posição %d do vetor: ", valor, indiceElem, indiceElem+1);
	}

	
  return 0;
}

int buscaRecursiva(int *vetor, int valor, int posicao) {
    if (posicao >= tamanho) {
        return -1;  // final da busca recursiva, valor não encontrado
    }
    if (vetor[posicao] == valor) {
        return posicao;  // valor encontrado, retorna o índice do elemento
    }
	
    return buscaRecursiva(vetor, valor, posicao+1);  // chamada recursiva para o próximo elemento
}

void imprimeVetor(int *v) 
{
  	printf("Vetor: [ ");
  	for (int i = 0; i < tamanho; i++) 
	{
    	if (i == tamanho - 1) 
		{
      	printf("%d ]\n", v[i]);
    	} 
		else 
		{
      		printf("%d, ", v[i]);
    	}
	}
}