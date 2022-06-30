#include <stdio.h>
#include <stdlib.h>

typedef struct inode{
  char * nome;
  int no;
  struct inode * prox;
}NODE;

void NODE_Insere(NODE * n ,char * nome, int no){
    NODE * aux = n;
    while (aux)
    {
        aux = aux->prox;
    }
    aux = (NODE *)malloc(sizeof(NODE));
    aux->no = no;
    aux->nome = nome;
    aux->prox = NULL;
}

void NODE_Libera(NODE * n){
    while (n)
    {
        NODE * temp = n;
        n = n->prox;
        free(temp);
    }    
}

NODE * NODE_Busca(NODE * n, char * nome){
    while (n)
    {
        if(strcmp(n->nome,nome) == 0) break;
        n = n->prox;
    }
    return n;
}

void Imprime_NODE(NODE * n){
    while (n)
    {
        printf("|%s|%d|\n",n->nome,n->no);
        n = n->prox;
    }
    
}