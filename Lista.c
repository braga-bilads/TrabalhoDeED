#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include <string.h>
#include <assert.h>

typedef struct celula Celula;

/**
 * Função para buscar celula por chave de comparação.
 * inputs: lista, função de CompararChave e a chave. 
 * outputs: ponteiro para celula
 * pré-condição: lista é valida, função existe, chave é valida 
 */
static Celula* BuscarCelula(Lista lista, int (*CompararChave)(void *, void *), void *chave);
/**
 * Função para buscar celula por index (posição na lista).
 * inputs: lista e index.
 * outputs: ponteiro para celula.
 * pré-condição: lista é valida e index é valido.
 */
static Celula* BuscarCelulaIndex(Lista lista,int index);

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
    nova->prim = NULL;
    nova->ult = NULL;

    return nova;
}

Lista AdicionarItem(Lista lista, void *item){
    Celula* nova = (Celula*)malloc(sizeof(Celula));
    
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

void *BuscarItem(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    Celula *aux = BuscarCelula(lista, CompararChave, chave);
    if(aux != NULL) return aux->conteudo;
    return NULL;
}

Lista RemoverItemChave(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    Celula *aux = BuscarCelula(lista, CompararChave, chave);

    //lista vazia
    if(aux == NULL) return lista;

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

    return lista;
}

Lista RemoverItemIndex(Lista lista, int index){
    Celula* p;
    p = lista->prim;
    
    for (int i = 0; i < index && p ; i++)
    {
        p = p->prox;
    }
    
    
    //p == NULL vale se não tiver na lista ou for lista vazia    
    if(!p){
        return lista;
    }
    //Unico
    if(lista->prim == p && p->prox == NULL){
        lista->prim = NULL;
        lista->ult = NULL;
        free(p);
        return lista;
    }
    //Primeiro
    if(index == 0){
        lista->prim = p->prox;
        p->prox->ant = NULL;
        free(p);
        return lista;
    }
    //Ultimo
    if(lista->ult == p){
        p->ant->prox = NULL;
        lista->ult = p->ant;
        free(p);
        return lista;
    }
    else{
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        free(p);
        return lista;
    }
}

void DeletarLista(Lista lista, void (*Free)(void *item)){
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

static Celula* BuscarCelula(Lista lista, int (*CompararChave)(void *, void *), void *chave){
    assert(lista != NULL);
    Celula *aux = lista->prim;

    while(aux != NULL && CompararChave(aux->conteudo, chave) != 1){
        aux = aux->prox;
    }

    return aux;
}

static Celula* BuscarCelulaIndex(Lista lista,int index){
    Celula * p;
    p = lista->prim;
    
    for (int i = 0; i < index && p; i++)
    {
        p = p->prox;
    }

    if(!p) return NULL;

    return p;
}

void * RecuperaConteudoDaUltimaCelula(Lista lista){
    assert(lista != NULL);
    if(!lista->ult) 
        return NULL;

    return lista->ult->conteudo;
}

void * RecuperaConteudoDaPrimeiraCelula(Lista lista){
    assert(lista != NULL);
    if(!lista->prim) 
        return NULL;

    return lista->prim->conteudo;
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