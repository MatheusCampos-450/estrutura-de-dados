// Usando ponteiros e alocação de memória para resolver o primeiro exemplo dados no arquivo "Estrutura em C"

#include <stdio.h>
#include <malloc.h>
#define alturaMaxima 225


// definição da estrutura PesoAltura
typedef struct{
  int peso;
  int altura;
} PesoAltura;


int main() {
  PesoAltura* pessoa = (PesoAltura*) malloc(sizeof(PesoAltura)); // PesoAltura recebe o ponteiro como o nome de 'pessoa' + malloc armazena o ponteiro PessoaAltura
  pessoa->peso = 80; // utiliza-se a SETA (->) para o ponteiro pessoa ir buscar na estrutura o peso
  pessoa->altura = 185;

  //impressão dos elementos utiliza SETA (->) também
  printf("Peso: %i, Altura: %i ", pessoa->peso, pessoa->altura);

  // condição
  if (pessoa->altura > alturaMaxima) printf("Altura acima da máxima. \n");
  else printf("Altura abaixo da máxima. \n");
}