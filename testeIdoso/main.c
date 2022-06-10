#include <stdio.h>
#include <stdlib.h>
#include "Idoso.h"

int main(int argc, char const *argv[])
{
    char path[] = "apoio.txt";
    StreamReader sr = CriarStreamReader(path);
    Lista idosos = CriarLista();

    char *string = ReadLine(sr);
    DeletarStreamReader(sr);

    char *nome = strtok(string, ";");
    while(nome != NULL){
        AdicionarItem(idosos, CriarIdoso(nome));
        nome = strtok(NULL, ";");
    }
    free(string);

    void *idoso = NULL;
    for(ForEach(idosos, &idoso); idoso != NULL; ForEach(NULL, &idoso)){
        char *idosoToString = IdosoToString((Idoso) idoso);
        printf("%s\n", idosoToString);
        free(idosoToString);
    }
    putchar('\n');

    int i = 0;
    while(i < atoi(argv[1])){
        for(ForEach(idosos, &idoso); idoso != NULL; ForEach(NULL, &idoso)){
            if(EhIdosoVivo((Idoso) idoso)){
                AtualizarIdoso((Idoso) idoso);

                char *idosoToString = IdosoToString((Idoso) idoso);
                printf("%s\n", idosoToString);
                free(idosoToString);
            }      
        }
        putchar('\n');

        i++;
    }

    DeletarLista(idosos, &DeletarIdoso);
    
    return 0;
}