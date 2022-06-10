#include <stdio.h>
#include <stdlib.h>
#include "Idoso.h"

void ImprimeIdoso(Idoso idoso);

int main(int argc, char const *argv[])
{
    char path[] = "apoio.txt";
    StreamReader sr = CriarStreamReader(path);
    Lista idosos = CriarLista();

    char *string = ReadLine(sr);
    char *nome = strtok(string, ";");
    while(nome != NULL){
        AdicionarItem(idosos, CriarIdoso(nome));
        nome = strtok(NULL, ";");
    }
    free(string);

    string = ReadLine(sr);
    while(RecuperaEndOfStream(sr) != EOF){
        char *nomeIdoso = NULL, *nomeAmigo = NULL;
        sscanf(string, "%m[^;];%ms", &nomeIdoso, &nomeAmigo);

        Idoso idosoAux = BuscarItem(idosos, &CompararNomeIdoso, nomeIdoso);
        Idoso amigoAux = BuscarItem(idosos, &CompararNomeIdoso, nomeAmigo);
        AdicionarAmigo(idosoAux, amigoAux);

        free(nomeIdoso);
        free(nomeAmigo);
        free(string);
        string = ReadLine(sr);
    }
    DeletarStreamReader(sr);

    void *idoso = NULL;
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