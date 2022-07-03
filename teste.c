#include <stdio.h>
#include <stdlib.h>

#include "TARVB.c"
#include "NODE.c"

#define Const_t 2

void main(int argc, char ** argv){
    FILE * fp;
    TARVB * arv = TARVB_Inicializa();
    int counter = 1;
    int size = 0;
    NODE * node = (NODE *)malloc(sizeof(NODE) * size);
    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "rb");
        if(!fp)exit(1);
        if(fp){
            fseek(fp,0,SEEK_SET);
            int lenght;
            ARQ arquivo;
            node = NODE_Insere(node,counter,argv[i],&size);
            while(1){
                VAL buffer;
                lenght = fread(buffer.texto,SEEK_CUR,TAM - 1,fp);
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
        fclose(fp);
    }

    arv = TARVB_Retira(arv,8,Const_t);
    TARVB_Change_Prox_ID(arv,8,9);
    TARVB_Imprime(arv);
    node = NODE_Retira(node, argv[1],&size);
    NODE_Imprime(node,size);
}