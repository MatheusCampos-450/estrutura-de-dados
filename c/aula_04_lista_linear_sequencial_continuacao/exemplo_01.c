// Uma lista linear é uma estrutura de dadas na qual cada elemento é precedido por um elemento é sucedido por outro (exceto o primeiro que não tem predecessor e o último que não tem sucessor)
// Os elementos estão em uma dada ordem (por exemplo, a ordem de inclusão ou ordenados por uma chave)


// A lista linear sequencial, é uma lista linear na qual a ordem lógica dos elementos (a ordem "vista" pelo usuário) é a mesma ordem física (em memória principal) dos elementos.
// Ịsto é, elemementos vizinhos na lista estarão em posições vizinhas na memória


// Modelagem:
// Modelaremos usando um arranjo de registros;
// Registros conterão as informações de interesse dos usuário;
// Nosso arranjo terá um tamanho fixo e controlaremos o número de elementos com uma variável adicional.


// Funções de Gerenciamento:
//  Implementaremos funções para: 
//    Inicializar a estrutura
//    Retornar a quantidade de elementos válidos
//    Exibir os elementos da estrutura
//    Buscar por um elemento na estrutura
//    Inserir elementos na estrutura
//    Excluir elementos da estrutura
//    Reinicializar a estrutura

#include <stdio.h>
#include <stdbool.h>


#define MAX 50

typedef int TIPOCHAVE; // Dando um novo nome para o tipo inteiro. Agora no código você pode declarar um "TIPO CHAVE"

typedef struct{
  TIPOCHAVE chave;
  // Outros campos
} REGISTRO;

typedef struct {
  REGISTRO A[MAX+1];
  int nroELem;
} LISTA;

// Inicialização
void inicializarLista(LISTA* l) {
  l->nroELem = 0;
}


/*
Erro cometido na inicialização de uma lista


void inicializarLista(LISTA l) {
  l.nroELem = 0;
}


Aqui, perceba que o usuário está passando uma lista como parametro. Por isso ele não irá popular a lista que ele criou, mas sim, criar um cópia dessa lista e popular a lista copia.

Observe que na primeira lista, temos como parametro da função o ENDEREÇO de uma lista que já existe, e por isso essa lista que receberá o valor.
*/


// Ṛetornar número de elementos
int tamanho(LISTA* l) {
  return l->nroELem;
}


// Exibição/Impressão
void exibirLista(LISTA* l) {
  int i;
  printf("Lista: \" ");
  for (i = 0; i < l->nroELem; i++)
    printf("%i ", l->A[i].chave);
  printf("\"\n");
}


// Buscar por elemento

int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  while (i < l->nroELem) {
    if(ch == l->A[i].chave) return i;
    else i++;
  }
  return -1;
}



// Busca por elementos (sentinela)
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroELem].chave = ch;
  while (l->A[i].chave != ch) i++;
  if (i == l->nroELem) return -1;
  else return i;
}


// Busca binaria
int buscaBinaria(LISTA* l, TIPOCHAVE ch) {
  int esq, dir, meio;
  esq = 0;
  dir = l->nroELem-1;
  while(esq <= dir) {
    meio = ((esq+dir) / 2);
    if(l->A[meio].chave == ch) return meio;
    else{
      if(l->A[meio].chave < ch) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return -1;
}




// Inserção de um elemento
/*
Há diferentes possibilidades de inserção:
No inicio
No fim
Ordenada por chave
Numa posição indicada pelo usuário


Como inserir?
  Se a lista não estiver cheia e o indice passado pelo usuário for valido: Deslocar todos os elementos posteriores um posição para a direita;
  
  Insere o elemento na posição desejada, soma um campo no nroElem e retorna true

  Caso contrario retorna false
*/


// Inserção de um elementos indicado pelo usuário:
/*
bool inserirElemLista(LISTA* l, REGISTRO reg, int i){
  int j;
  if ((l->nroELem == MAX) || (i < 0) || (i > l->nroELem))
    return false;
  for (j = l->nroELem; j > i; j--) l->A[j] = l->A[j-1];
  l->A[i] = reg;
  l->nroELem++;
  return true;
}
*/

// Inserção de elementos - Ordenada
bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  if(l->nroELem >= MAX) return false;
  int pos = l->nroELem;
  while(pos > 0 && l->A[pos-1].chave > reg.chave) {
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos] =  reg;
  l->nroELem++;
}



// Exclusão de um elemento
/*
O usuário passa a chave do elemento que ele quer excluir
  Se houver um elemento com esta chave na lista,
  "exclui este elemento", desloca todos os elementos posteriores uma posição para a esquerda, diminui em um o campo nroElem e retorna true

  Caso contrario, retorna false
*/


bool excluirElemLista(TIPOCHAVE ch, LISTA* l) {
  int pos, j;
  pos = buscaSequencial(l, ch);
  if(pos == -1)return false;
  for (j = pos; j < l->nroELem-1; j++)
    l->A[j] = l->A[j+1];
  l->nroELem--;
  return true;
}


// Reinicialização da lista
/*
Para está estrutura, para reiniciar a lista basta colocar 0 (zero) no campo nroElem
*/
void reinicializarLista(LISTA* l) {
  l->nroELem = 0;
}


