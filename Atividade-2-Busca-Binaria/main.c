#include <stdio.h>
#define tamanho 10

// Protótipos da função.
int buscaBinaria(int *v, int valor, int inicio, int fim);
void imprimeVetor(int *v);

int main(void) {
  	int vetor[tamanho] = {-8, -1, 4, 9, 18, 34, 52, 65, 79, 90}; // para busca binario o vetor é ordenado.

  	imprimeVetor(vetor);

  	printf("\nDigite um número para ser encontrado dentro do vetor: ");
  	int valor;
  	scanf("%d", &valor);

  	int indiceElem = buscaBinaria(vetor, valor, 0, tamanho);
	
	// Verifica se o número tem um indice no vetor.
	// indiceElem = -1, não pertence ao vertor.
  	if (indiceElem == -1) 
	{
    	printf("\nO elemento %d não está dentro do vetor!", valor);
  	} 
	else 
	{
    	printf("\nO elemento %d está no indice %d, posição %d do vetor: ", valor, indiceElem, indiceElem+1);
  	}

  	return 0;
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

int buscaBinaria(int *v, int valor, int inicio, int fim) 
{
  	int meio = (inicio + fim) / 2; // Recebe o indice do meio do veto.

  	if (inicio > fim) // Caso onde o valor não foi encontrado, 
	{
    	return -1; // retorna -1.
  	}
  	if (v[meio] == valor) // Caso valor encontrado, 
	{
    	return meio; // retorna o indice do elemento.
  	}

  	if (v[meio] > valor) // Se valor maior que meio,
	{
    	return buscaBinaria(v, valor, inicio, meio - 1); // busca recursiva pela metade do vetor a esquerda,
  	} else {
    	return buscaBinaria(v, valor, meio + 1, fim); // busca recursiva pela metade do vetor a direita.
  	}
}