#include <stdio.h>

int buscaRecursiva(int *vetor, int valor, int tamanho, int posicao);

int buscaRecursivaMaior(int *v, int maior, int tamanho, int posicao) {
  if (posicao > tamanho) {
    printf("%d", maior);
    return maior; // final da busca recursiva, retorna maior
  }
  if (v[posicao] > maior) {
    maior = v[posicao]; // maior encontrado, maior recebe elemento do vetor
  }
  return buscaRecursivaMaior(
      v, maior, tamanho,
      posicao + 1); // chamada recursiva para o próximo elemento
}

int buscaBinaria(int *v, int valor, int tamanho, int inicio, int fim) {
  int meio = (inicio + fim) / 2;

  if (inicio > fim) {
    return -1;
  }
  if (v[meio] == valor) {
    return meio;
  }

  if (v[meio] > valor) {
    return buscaBinaria(v, valor, tamanho, inicio, fim - 1);
  } else {
    return buscaBinaria(v, valor, tamanho, inicio + 1, fim);
  }
}

int main(void) {
  // int vetor[10] = {1, 45, 20, 76, 90, 88, 44, 65, 13, 22};
  int vetor[10] = {1, 2, 4, 23, 34, 44, 52, 65, 79, 90};

  int tamanhoVetor = sizeof(vetor) / sizeof(int);

  // printf("\nDigite o número do elemento para ser encontrado dentro do vetor:
  // "); int valor; scanf("%d", &valor);

  // printf("\nDigite a posição que a função deve começar a percorrer dentro do
  // vetor (indice inicial = 0): "); int posicao; scanf("%d", &posicao);

  // int indiceElem = buscaRecursiva(vetor, valor, tamanhoVetor, posicao);

  // if(indiceElem == -1){
  // 	printf("\nO elemento %d não está dentro do vetor!", valor);
  // } else {
  // 	printf("\nO elemento %d está na posição %d do vetor: ", valor,
  // indiceElem);
  // }

  printf("\nMaior elemento do vetor é: %d",
         buscaRecursivaMaior(vetor, 0, tamanhoVetor, 0));
  printf("\nIndice elemento do vetor é: %d",
         buscaBinaria(vetor, 23, tamanhoVetor, 0, 10));

  return 0;
}

int buscaRecursiva(int *vetor, int valor, int tamanho, int posicao) {
  if (posicao >= tamanho) {
    return -1; // final da busca recursiva, valor não encontrado
  }
  if (vetor[posicao] == valor) {
    return posicao; // valor encontrado, retorna o índice do elemento
  }
  return buscaRecursiva(vetor, valor, tamanho,
                        posicao +
                            1); // chamada recursiva para o próximo elemento
}
