#ifndef LISTA_H
#define LISTA_H

//  Tipo que define lista (tipo opaco)
typedef struct lista* Lista;

/* 
 * Aloca memoria para a lista
 * inputs: nenhum
 * output: lista criada
 * pre-condicao: nenhuma
 * pos-condicao: lista alocada e vazia
 */
Lista CriarLista();

/* 
 * Adiciona um item a lista
 * inputs: lista e item a ser adicionado
 * output: nenhum
 * pre-condicao: lista e item existem
 * pos-condicao: item adicionado na ultima posicao da lista
 */
void AdicionarItem(Lista lista, void *item);

/* 
 * Busca um item na lista de acordo com sua chave
 * inputs: lista, funcao que compara a chave de acordo com o item, e chave a ser comparada
 * output: item
 * pre-condicao: lista, funcao e chave existem
 * pos-condicao: item referente a chave passada como parametro, ou item == NULL,
 *               caso nao esteja na lista
 */
void *BuscarItemChave(Lista lista, int (*CompararChave)(void *, void *), void *chave);

/* 
 * Busca um item na lista de acordo com seu index
 * inputs: lista e index
 * output: item
 * pre-condicao: lista existe
 * pos-condicao: item referente ao index passado como parametro, ou item == NULL,
 *               caso nao esteja na lista
 */
void *BuscarItemIndex(Lista lista, int index);

/* 
 * Remove um item na lista de acordo com sua chave
 * inputs: lista, funcao que compara a chave de acordo com o item, e chave a ser comparada
 * output: item
 * pre-condicao: lista, funcao e chave existem
 * pos-condicao: item referente a chave passada como parametro removido da lista, 
 *               ou item == NULL, caso nao esteja na lista
 */
void *RemoverItemChave(Lista lista, int (*CompararChave)(void *, void *), void *chave);

/* 
 * Libera memoria alocada para a lista
 * inputs: lista e funcao que libera a memoria alocada para item
 * output: nenhum
 * pre-condicao: lista existe, se Free == NULL a funcao nao libera memoria para item
 * pos-condicao: toda a memoria alocada para lista foi liberada, se Free == NULL,
 *               memoria alocada para item nao foi liberada
 */
void DeletarLista(Lista lista, void (*Free)(void *item));

/* 
 * Percorre o conteudo de uma lista
 * inputs: lista e ponteiro para ponteiro para item
 * output: nenhum
 * pre-condicao: se lista != de NULL, item eh o primeiro da lista,
 *               se lista == NULL, item eh o proximo da lista, de acordo
 *               com a primeira lista passada como parametro
 * pos-condicao: se lista != de NULL, item eh o primeiro da lista,
 *               se lista == NULL, item eh o proximo da lista
 */
void ForEach(Lista lista, void **item);

#endif