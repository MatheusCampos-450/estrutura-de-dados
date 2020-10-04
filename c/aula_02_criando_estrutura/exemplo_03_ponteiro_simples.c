
//Ponteiro simples - Alocação de memória

#include<stdio.h>

int main(){
  
  int x = 25; // variável x
  int *y = &x; // endereço para inteiro y recebe referência de x (& define a referência)

  *y = 30; // referência de x recebe 30

  // imprimi novo valor de x
  printf("Valor atual de x: %i\n", x);


}