#include <stdio.h>
#define alturaMaxima 225
// Definindo um valor padrão para uma variável (Caso você não defina um valor, o compilador colocará 225 como um valor default)


typedef struct{
  int peso; // peso em quilogramas
  int altura; // altura em centimetros
} PesoAltura;
// A sintaxe struct{...} define uma estrutura com os campos definidos dentro das chaves
// A sintaxe typedef...PesoAltura define o nome PesoAltura para o que foi definido nas reticências


// typedef int CHAVE;
// Definimos que a palavra CHAVE poderá ser usada no código para representar o tipo int (inteiro), isto é, demos um novo nome para o tipo



// Declaração de uma função padrão 
int main(){
  PesoAltura pessoa;
  pessoa.peso = 80;
  pessoa.altura = 185;

  printf("Peso: %i, Altura: %i ", pessoa.peso, pessoa.altura);

  if (pessoa.altura > alturaMaxima){
    printf("Altura acima da máxima. \n");
  }else{
    printf("Altura abaixo da máxima. \n");
  }
  return 0;
}



