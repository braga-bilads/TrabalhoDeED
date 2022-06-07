#ifndef LISTA_H
#define LISTA_H

typedef struct lista* Lista;

/* 
 * Aloca memoria para a lista e a inicializa
 * inputs: nenhum
 * output: a lista criada
 * pre-condicao: nenhuma
 */
Lista CriarLista();

/* 
 * Adiciona um item a lista
 * inputs: a lista e o item a ser adicionado
 * output: nenhum
 * pre-condicao: a lista e o item existem
 */
Lista AdicionarItem(Lista lista, void *item);

/* 
 * Busca um item na lista de acordo com sua chave
 * inputs: a lista, uma funcao que retorna a chave de acordo com o item, e a chave a ser comparada
 * output: o item
 * pre-condicao: a lista, a funcao e a chave existem
 */
void *BuscarItem(Lista lista, char *(*RetornarChave)(void *), char *chave);


/* 
 * Remove um item da lista de acordo com sua chave
 * inputs: a lista, uma funcao que retorna a chave de acordo com o item, e a chave a ser comparada
 * output: nenhum
 * pre-condicao: a lista, a funcao e a chave existem
 */
Lista RemoverItemChave(Lista lista, char *(*RetornarChave)(void *), char *chave);

/* 
 * Remove um item da lista de acordo com seu index
 * inputs: a lista e o index
 * output: nenhum
 * pre-condicao: a lista existe
 */
void RemoverItemIndex(Lista lista, int index);

/* 
 * Libera memoria alocada para a lista
 * inputs: a lista e uma funcao que libera a memoria alocada para item
 * output: nenhum
 * pre-condicao: a lista existe, se Free == NULL a funcao nao libera memoria para item
 */
void DeletarLista(Lista lista, void (*Free)(void *item));

#endif