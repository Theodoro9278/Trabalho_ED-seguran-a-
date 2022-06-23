#include <stdio.h>
#include <stdlib.h>

#include "TARVB.c"

void main(int argc, char ** argv){
    FILE * f;
    for (size_t i = 1; i < argc; i++)
    {
        f = fopen(argv[i], "rb");
        if(f){
            fseek(f,0,SEEK_SET);
            int lenght;
            while(1){
                char buffer[TAM];
                lenght = fread(buffer,SEEK_CUR,TAM - 1,f);
                if(!lenght){
                    break;
                }
                buffer[lenght] = '\0';
                printf("%s\n",buffer);
            }
            

        }
        fclose(f);
    }
}