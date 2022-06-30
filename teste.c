#include <stdio.h>
#include <stdlib.h>

#include "TARVB.c"
#include "NODE.c"

#define Const_t 2

void main(int argc, char ** argv){
    FILE * f;
    TARVB * arv = TARVB_Inicializa();
    int counter = 1;
    NODE * node = NULL;
    for (int i = 1; i < argc; i++)
    {
        node = NODE_Insere(node,argv[i],counter);
        f = fopen(argv[i], "rb");
        if(f){
            fseek(f,0,SEEK_SET);
            int lenght;
            ARQ arquivo;
            node->nome = argv[i];
            node->no = counter;
            while(1){
                VAL buffer;
                lenght = fread(buffer.texto,SEEK_CUR,TAM - 1,f);
                if(!lenght){
                    break;
                }
                buffer.texto[lenght] = '\0';
                buffer.id = counter;
                buffer.prox_id = ++counter;
                if(lenght < TAM - 1) buffer.prox_id = -1;
                arv = TARVB_Insere(arv,buffer,Const_t);
            }
        }
        node = node->prox;
        fclose(f);
    }
    Imprime_NODE(node);
    arv = TARVB_Retira(arv,8,Const_t);
    TARVB_Change_Prox_ID(arv,8,9);
    TARVB_Imprime(arv);
}