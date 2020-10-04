// Usando ponteiros e alocação de memória para resolver o primeiro exemplo dados no arquivo "Estrutura em C"

#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 225

typedef struct{
  int peso;
  int altura;
} PesoAltura;


int main() {
  PesoAltura* pessoa = (PesoAltura*) malloc(sizeof(PesoAltura));
  pessoa->peso = 80;
  pessoa->altura = 185;

  printf("Peso: %i, Altura: %i ", pessoa->peso, pessoa->altura);

  if (pessoa->altura > alturaMaxima) printf("Altura acima da máxima. \n");
  else printf("Altura abaixo da máxima. \n");
}