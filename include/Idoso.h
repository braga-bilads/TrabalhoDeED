#ifndef IDOSO_H
#define IDOSO_H

#include "Cuidador.h"
#include "Registro.h"
#include "StreamWriter.h"

//  Tipo que define idoso (tipo opaco)
typedef struct idoso* Idoso;

/* 
 * Aloca memoria para o idoso e o inicializa
 * inputs: nome do idoso que nao necessita ter sido alocado dinamicamente
 * output: idoso criado
 * pre-condicao: nome existe
 * pos-condicao: idoso alocado e inicializado
 */
Idoso CriarIdoso(char *nome);

/*
 * Retorna o nome do idoso
 * inputs: idoso
 * output: nome do idoso
 * pré-condição: idoso existe
 * pos-condicao: idoso nao e modificado
 */
char *RecuperaNomeIdoso(Idoso idoso);

/*
 * Retorna o registro do idoso
 * inputs: idoso
 * output: registro do idoso
 * pré-condição: idoso existe
 * pos-condicao: idoso nao e modificado
 */
Registro RecuperaRegistroIdoso(Idoso idoso);

/*
 * Retorna o streamWriter do idoso
 * inputs: idoso
 * output: o streamWriter do idoso
 * pré-condição: idoso existe
 * pos-condicao: idoso nao e modificado
 */
StreamWriter RecuperaStreamWriterIdoso(Idoso idoso);

/* 
 * Libera memoria alocada para o idoso
 * inputs: o idoso
 * output: nenhum
 * pre-condicao: o idoso existe
 * pos-condicao: toda a memoria alocada para idoso foi liberada
 */
void DeletarIdoso(void *idoso);

/*
 * Cria uma amizade entre dois idosos
 * inputs: idoso e amigo
 * output: nenhum
 * pré-condição: idoso e amigo existem 
 * pos-condicao: amigo esta na lista de amigos de idoso,
 *               e idoso, esta na lista de amigos de amigo
 */
void AdicionarAmigo(Idoso idoso, Idoso amigo);

/*
 * Desfaz uma amizade entre dois idosos
 * inputs: idoso e amigo
 * output: nenhum
 * pré-condição: idoso e amigo existem
 * pos-condicao: amigo foi retirado da lista de amigos de idoso,
 *               e idoso, foi retirado da lista de amigos de amigo
 */
void RemoverAmigo(Idoso idoso, Idoso amigo);

/*
 * Retorna o Amigo mais proximo do idoso
 * inputs: idoso
 * output: amigo mais proximo
 * pré-condição: idoso existe
 * pos-condicao: amigo mais proximo ao idoso, ou amigo == NULL,
 *               caso nao tenham amigos na lista de amigos do idoso
 */
Idoso BuscarAmigoMaisProximo(Idoso idoso);

/*
 * Desfaz todas as amizades do idoso (caso de falecimento)
 * inputs: idoso
 * output: nenhum
 * pré-condição: idoso existe e foi declarado como falecido
 * pos-condicao: idoso desfez todos seus vinculos de amizade
 */
void DesfazerAmizades(Idoso idoso);

/*
 * Adiciona um cuidador na lista de cuidadores do Idoso selecionado
 * inputs: idoso e cuidador
 * output: nenhum
 * pré-condição: idoso e cuidador existem
 * pos-condicao: cuidador foi adicionado a lista de cuidadores do idoso
 */
void AdicionarCuidador(Idoso idoso, Cuidador cuidador);

/*
 * Retorna o cuidador mais próximo do Idoso
 * inputs: idoso 
 * output: cuidador
 * pré-condição: idoso existe
 * pos-condicao: cuidador mais proximo ao idoso, ou cuidador == NULL,
 *               caso nao tenham cuidadores na lista de cuidadores do idoso
 */
Cuidador BuscarCuidadorMaisProximo(Idoso idoso);

/* 
 * Atualiza os dados do idoso
 * inputs: idoso
 * output: nenhum
 * pre-condicao: idoso existe
 * pos-condicao: os dados do idoso foram alterados de 
 *               acordo com seus sensores
 */
void AtualizarIdoso(Idoso idoso);

/* 
 * Verifica se o idoso esta vivo
 * inputs: idoso
 * output: 1 se o idoso esta vivo, 0 caso contrario
 * pre-condicao: idoso existe
 * pos-condicao: foi verificado se idoso esta vivo
 */
int EhIdosoVivo(Idoso idoso);

/*
 * Compara nome do idoso com um nome passado como parametro 
 * inputs: idoso e nome
 * output: 1 se iguais, 0 caso contrario
 * pre-condicao: idoso e nome existem, nome nao necessita 
 *               ter sido alocado dinamicamente
 * pos-condicao: o nome do idoso foi comparado ao nome passado como parametro
 */
int CompararNomeIdoso(void *idoso, void *nome);

#endif