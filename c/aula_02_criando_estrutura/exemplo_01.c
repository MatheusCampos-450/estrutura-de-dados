#include <stdio.h> // Standard Input/Output
#include <malloc.h> // Função Memory Allocation

int main(){
  int* y = (int*) malloc(sizeof(int));
  // Criando a váriavel y, do tipo ponteiro para inteiro. Logo após, função malloc aloca uma quantidade de memória para uma váriavel do tipo inteiro.

  *y = 20;
  int z = sizeof(int);
  printf("*y = %i   z = %i \n", *y, z);
  return 0;
}