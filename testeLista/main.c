#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct Idoso{
    char nome[100];
} Idoso;

int CompararNomeIdoso(void *idoso, void *nome);
void ImprimeLista();

int main(int argc, char const *argv[])
{
    Idoso idoso1 = {.nome = "joao"};
    Idoso idoso2 = {.nome = "maria"};
    Idoso idoso3 = {.nome = "carol"};
    Idoso idoso4 = {.nome = "ana"};
    Idoso idoso5 = {.nome = "davi"};
    void *idoso = NULL;

    Lista idosos = CriarLista();

    printf("ADD ITEM\n");
    AdicionarItem(idosos, &idoso1);
    AdicionarItem(idosos, &idoso2);
    AdicionarItem(idosos, &idoso3);
    AdicionarItem(idosos, &idoso4);
    AdicionarItem(idosos, &idoso5);
    ImprimeLista(idosos, &idoso);
    putchar('\n');

    printf("BUSCAR ITEM\n");
    printf("%s\n", ((Idoso *) BuscarItem(idosos, &CompararNomeIdoso, "davi"))->nome);
    printf("%s\n", ((Idoso *) BuscarItem(idosos, &CompararNomeIdoso, "joao"))->nome);
    printf("%s\n", ((Idoso *) BuscarItem(idosos, &CompararNomeIdoso, "carol"))->nome);
    printf("%s\n", ((Idoso *) BuscarItem(idosos, &CompararNomeIdoso, "maria"))->nome);
    printf("%s\n", ((Idoso *) BuscarItem(idosos, &CompararNomeIdoso, "ana"))->nome);
    putchar('\n');

    printf("REMOVER ITEM CHAVE\n");
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemChave(idosos, &CompararNomeIdoso, "davi");
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemChave(idosos, &CompararNomeIdoso, "joao");
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemChave(idosos, &CompararNomeIdoso, "carol");
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemChave(idosos, &CompararNomeIdoso, "ana");
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemChave(idosos, &CompararNomeIdoso, "maria");
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemChave(idosos, &CompararNomeIdoso, "maria");
    ImprimeLista(idosos, &idoso);
    putchar('\n');

    printf("REMOVER ITEM INDEX\n");
    AdicionarItem(idosos, &idoso1);
    AdicionarItem(idosos, &idoso2);
    AdicionarItem(idosos, &idoso3);
    AdicionarItem(idosos, &idoso4);
    AdicionarItem(idosos, &idoso5);
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemIndex(idosos, 4);
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemIndex(idosos, 0);
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemIndex(idosos, 1);
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemIndex(idosos, 1);
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemIndex(idosos, 0);
    ImprimeLista(idosos, &idoso);
    putchar('\n');
    RemoverItemIndex(idosos, -5);
    ImprimeLista(idosos, &idoso);
    putchar('\n');

    printf("RECUPERA CONTEUDO\n");
    AdicionarItem(idosos, &idoso1);
    AdicionarItem(idosos, &idoso2);
    AdicionarItem(idosos, &idoso3);
    printf("%s\n", ((Idoso *) RecuperaConteudoDaPrimeiraCelula(idosos))->nome);
    printf("%s\n", ((Idoso *) RecuperaConteudoDaUltimaCelula(idosos))->nome);

    DeletarLista(idosos, NULL);
    
    return 0;
}

int CompararNomeIdoso(void *idoso, void *nome){
    Idoso *idosoAux = (Idoso *) idoso;
    char *nomeAux = (char *) nome;

    return strcmp(idosoAux->nome, nomeAux) == 0;
}

void ImprimeLista(Lista idosos, void **idoso){
    for(ForEach(idosos, idoso); *idoso != NULL; ForEach(NULL, idoso)){
        Idoso idosoAux = **((Idoso **) idoso);
        printf("%s\n", idosoAux.nome);
    }
}