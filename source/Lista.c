#include <stdlib.h>
#include <assert.h>
#include "../include/Lista.h"

//  Tipo que define celula
typedef struct celula Celula;

/*------------------------ funcoes privadas -----------------------*/

/*
 * Busca uma celula na lista de acordo com a chave de seu item
 * inputs: lista, funcao que compara a chave de acordo com o item, e chave a ser comparada
 * output: celula
 * pré-condição: lista, funcao e chave existem
 * pos-condicao: celula referente a chave passada como parametro, ou celula == NULL,
 *               caso nao esteja na lista
 */
static Celula* _buscarCelulaChave(Lista lista, int (*CompararChave)(void *, void *), void *chave);

/*-----------------------------------------------------------------*/

struct celula{
    void* conteudo; 
    Celula* prox;
    Celula* ant;
};

struct lista{
    Celula* prim;
    Celula* ult;
};

Lista CriarLista(){
    Lista nova = (Lista)malloc(sizeof(struct lista));
    assert(nova != NULL);

    nova->prim = NULL;
    nova->ult = NULL;

    return nova;
}

void AdicionarItem(Lista lista, void *item){
    assert(lista != NULL && item != NULL);

    Celula* nova = (Celula*)malloc(sizeof(Celula));
    assert(nova != NULL);
    
    nova->ant = lista->ult;

    if(lista->ult)
        lista->ult->prox = nova;
    if(!lista->prim)
        lista->prim = nova;
    
    lista->ult = nova;
    nova->prox = NULL;
    nova->conteudo = item;
}

void *BuscarItemChave(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    assert(lista != NULL && CompararChave != NULL && chave != NULL);

    Celula *aux = _buscarCelulaChave(lista, CompararChave, chave);
    if(aux != NULL) return aux->conteudo;
    return NULL;
}

void *BuscarItemIndex(Lista lista, int index){
    assert(lista != NULL);

    Celula *p = lista->prim; 
    for(int i = 0; i < index && p != NULL; i++)
    {
        p = p->prox;
    }

    if(!p) return NULL;
    return p->conteudo;
}

void *RemoverItemChave(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    assert(lista != NULL && CompararChave != NULL && chave != NULL);

    Celula *aux = _buscarCelulaChave(lista, CompararChave, chave);

    //lista vazia
    if(aux == NULL) return NULL;

    void *conteudo = aux->conteudo;

    if(aux == lista->prim){
        //unico da lista
        if(aux == lista->ult){
            free(aux);
            lista->prim = NULL;
            lista->ult = NULL;
        }
        //primeiro da lista
        else{
            aux->prox->ant = NULL;
            lista->prim = aux->prox;
            free(aux);
        }
    }
    //ultimo da lista
    else if(aux == lista->ult){
        aux->ant->prox = NULL;
        lista->ult = aux->ant;
        free(aux);
    }
    // meio da lista
    else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
        free(aux);
    }

    return conteudo;
}

void DeletarLista(Lista lista, void (*Free)(void *item)){
    assert(lista != NULL);

    Celula* p = lista->prim;
    Celula* aux;
    while(p){
        aux = p->prox;
        if(Free)
            Free(p->conteudo);

        free(p);
        p = aux;
    }
    free(lista);
}

void ForEach(Lista lista, void **item){
    static Celula *aux = NULL;

    if(lista != NULL){
        aux = lista->prim;
    }
    else if(aux != NULL){
        aux = aux->prox;
    }

    if(aux == NULL){
        *item = NULL;
    }
    else{
        *item = aux->conteudo;
    }
}

static Celula* _buscarCelulaChave(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    assert(lista != NULL && CompararChave != NULL && chave != NULL);

    Celula *aux = lista->prim;
    while(aux != NULL && CompararChave(aux->conteudo, chave) != 1){
        aux = aux->prox;
    }

    return aux;
}