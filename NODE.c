#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct inode{
  char * nome;
  int no;
}NODE;

int NODE_Busca(NODE * node, int size, char * nome){
    for (int i = 0; i < size; i++)
    {
        if(strcmp(nome, node[i].nome) == 0) return i;
    }
    return -1;
}

NODE * NODE_Insere(NODE * node, int no, char * nome, int * size){
    if(NODE_Busca(node,*size,nome) ==  -1 ){
        *size += 1;
        node = (NODE*)realloc(node,(*size)*sizeof(NODE));
        node[*size - 1].no = no;
        node[*size - 1].nome = nome;
    }
    return node;
}

NODE * NODE_Retira(NODE * node, char * nome, int * size){
    int pos = NODE_Busca(node,*size,nome);
    if(pos >= 0){
        for (int i = pos; i < *size - 1; i++)
        {
            node[i] = node[i + 1];
        }
        *size -= 1;
        node = (NODE *)realloc(node,sizeof(NODE) * (*size));
    }
    return node;
}



void NODE_Imprime(NODE * node,int size){
    for (int i = 0; i < size; i++)
    {
        printf("nome:%s no:%d\n",node[i].nome,node[i].no);
    }
}