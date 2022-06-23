#include <stdio.h>
#include <stdlib.h>

#define TAM 11

typedef struct inode{
  char id[100];
  int node;
  struct inode * prox;
  
}NODE;

//Valores internos de um no;
typedef struct value_no{
  int id;
  char texto[TAM];
  int prox_id;
}VAL;

typedef struct arquivo{
  char nome[100];
  int id;
  char texto[TAM];
  int prox_id;
}ARQ;

typedef struct ArvB{
  int nchaves, folha;
  VAL * chave;
  struct ArvB **filho;
}TARVB;

TARVB *TARVB_Inicializa();
TARVB *TARVB_Cria(int t);
TARVB *TARVB_Libera(TARVB *a);
TARVB *TARVB_Busca(TARVB* x, int ch);
TARVB *TARVB_Insere(TARVB *T, VAL k, int t);
TARVB* TARVB_Retira(TARVB* arv, int k, int t);
void TARVB_Imprime(TARVB *a);
TARVB *Divisao(TARVB *x, int i, TARVB* y, int t);