typedef struct inode{
  char * nome;
  int no;
  struct inode * prox;
}NODE;

NODE * NODE_Insere(NODE * n ,char * nome, int no){
    if(!n){
        NODE * n = (NODE *)malloc(sizeof(NODE));
        n->nome = nome;
        n->no = no;
        n->prox = NULL;
        return n;
    }
    NODE * aux = n;
    while (aux->prox){aux = aux->prox;}
    aux->prox = NODE_Insere(aux->prox,nome,no);
    return n;
    
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