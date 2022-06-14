#include <stdlib.h>
#include <assert.h>
#include "Lista.h"

typedef struct celula Celula;

/**
 * Função para buscar celula por chave de comparação.
 * inputs: lista, função de CompararChave e a chave. 
 * outputs: ponteiro para celula
 * pré-condição: lista é valida, função existe, chave é valida 
 */
static Celula* _buscarCelula(Lista lista, int (*CompararChave)(void *, void *), void *chave);

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

Lista AdicionarItem(Lista lista, void *item){
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

    return lista;
}

void *BuscarItemChave(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    assert(lista != NULL && CompararChave != NULL && chave != NULL);

    Celula *aux = _buscarCelula(lista, CompararChave, chave);
    if(aux != NULL) return aux->conteudo;
    return NULL;
}

void *BuscarItemIndex(Lista lista, int index){
    Celula * p;
    p = lista->prim;
    
    for (int i = 0; i < index && p; i++)
    {
        p = p->prox;
    }

    if(!p) return NULL;

    return p->conteudo;
}

void *RemoverItemChave(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    assert(lista != NULL && CompararChave != NULL && chave != NULL);

    Celula *aux = _buscarCelula(lista, CompararChave, chave);

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

void *RemoverItemIndex(Lista lista, int index){
    assert(lista != NULL);

    Celula* p = lista->prim;    
    for (int i = 0; i < index && p ; i++)
    {
        p = p->prox;
    }
    
    //p == NULL vale se não tiver na lista ou for lista vazia    
    if(!p){
        return NULL;
    }

    void *conteudo = p->conteudo;

    //Unico
    if(lista->prim == p && p->prox == NULL){
        lista->prim = NULL;
        lista->ult = NULL;
        free(p);
    }
    //Primeiro
    else if(index == 0){
        lista->prim = p->prox;
        p->prox->ant = NULL;
        free(p);
    }
    //Ultimo
    else if(lista->ult == p){
        p->ant->prox = NULL;
        lista->ult = p->ant;
        free(p);
    }
    else{
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        free(p);
        
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

static Celula* _buscarCelula(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    assert(lista != NULL);
    Celula *aux = lista->prim;

    while(aux != NULL && CompararChave(aux->conteudo, chave) != 1){
        aux = aux->prox;
    }

    return aux;
}