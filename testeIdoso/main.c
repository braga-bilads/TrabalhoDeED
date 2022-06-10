#include <stdio.h>
#include <stdlib.h>
#include "Idoso.h"

void ImprimeIdosos();
void ImprimeRelacoes(Lista idosos);

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

    printf("\tLISTA DE IDOSOS\n");
    ImprimeIdosos(idosos);
    putchar('\n');

    ImprimeRelacoes(idosos);

    void *idoso = NULL;
    int i = 0;
    while(i < atoi(argv[1])){
        for(ForEach(idosos, &idoso); idoso != NULL; ForEach(NULL, &idoso)){
            if(EhIdosoVivo((Idoso) idoso)){
                AtualizarIdoso((Idoso) idoso);

                char *idosoToString = IdosoToString((Idoso) idoso);
                printf("%s\n", idosoToString);
                free(idosoToString);
                putchar('\n');
            }      
        }
        putchar('\n');

        i++;
    }

    DeletarLista(idosos, &DeletarIdoso);
    
    return 0;
}

void ImprimeIdosos(Lista idosos){
    void *idoso = NULL;
    for(ForEach(idosos, &idoso); idoso != NULL; ForEach(NULL, &idoso)){
        char *idosoToString = IdosoToString(((Idoso) idoso));
        printf("%s\n", idosoToString);
        free(idosoToString);
    }
    putchar('\n');
}

void ImprimeRelacoes(Lista idosos){
    Idoso idoso1 = BuscarItem(idosos, &CompararNomeIdoso, "Joao");
    Idoso idoso2 = BuscarItem(idosos, &CompararNomeIdoso, "Maria");
    Idoso idoso3 = BuscarItem(idosos, &CompararNomeIdoso, "Pedro");
    Idoso idoso4 = BuscarItem(idosos, &CompararNomeIdoso, "Alice");

    printf("\tAMIGOS JOAO\n");
    ImprimeIdosos(RecuperaAmigosIdoso(idoso1));
    putchar('\n');

    printf("\tAMIGOS MARIA\n");
    ImprimeIdosos(RecuperaAmigosIdoso(idoso2));
    putchar('\n');

    printf("\tAMIGOS PEDRO\n");
    ImprimeIdosos(RecuperaAmigosIdoso(idoso3));
    putchar('\n');

    printf("\tAMIGOS ALICE\n");
    ImprimeIdosos(RecuperaAmigosIdoso(idoso4));
    putchar('\n');
}