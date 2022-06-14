#ifndef IDOSO_H
#define IDOSO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Cuidador.h"
#include "FebreEnum.h"
#include "Lista.h"
#include "Registro.h"
#include "StreamWriter.h"

typedef struct idoso * Idoso;

/* 
 * Aloca memoria para o idoso e o inicializa
 * inputs: o nome do idoso
 * output: o idoso criado
 * pre-condicao: nenhuma
 */
Idoso CriarIdoso(char *nome);

/**
 * Retorna nome do idoso
 * inputs: idoso
 * output: nome
 * pré-condição : os parametros passados são validos
 */
char * RecuperaNomeIdoso(Idoso idoso);

Lista RecuperaAmigosIdoso(Idoso idoso);

Lista RecuperaCuidadoresIdoso(Idoso idoso);

Registro RecuperaRegistroIdoso(Idoso idoso);

StreamWriter RecuperaStreamWriterIdoso(Idoso idoso);

/* 
 * Libera memoria alocada para o idoso
 * inputs: o idoso
 * output: nenhum
 * pre-condicao: o idoso existe
 */
void DeletarIdoso(void *idoso);

/**
 * Coloca um amigo na lista de amigos do idoso. 
 * inputs: idoso e o amigo
 * output: void
 * pré-condição: idoso e amigo existem 
 */
void AdicionarAmigo(Idoso idoso, Idoso amigo);

/**
 * Retira um amigo da lista de amigos do idoso.
 * inputs: Idoso e amigo a ser retirado
 * output: void 
 * pré-condição:  idoso e amigo são validos 
 */
void RemoverAmigo(Idoso idoso, Idoso amigo);

/**
 * Retorna o Amigo mais proximo do idoso.
 * inputs: idoso
 * output: idoso mais proximo
 * pré-condição: idoso é valido 
 */
Idoso BuscarAmigoMaisProximo(Idoso idoso);

/**
 * Desfaz todas as amizades do idoso (caso de falecimento).
 * inputs: idoso
 * output: void
 * pré-condição : idoso é valido e foi declarado como falecido.
 */
void DesfazerAmizades(Idoso idoso);

/**
 * Adiciona um cuidador na lista de cuidadores do Idoso selecionado.
 * inputs: idoso e cuidador
 * output: void
 * pré-condição : idoso e cuidador são valido. 
 */
void AdicionarCuidador(Idoso idoso, Cuidador cuidador);

/**
 * Retorna o cuidador mais próximo na lista 
 * de cuidadores do Idoso.
 * inputs: idoso 
 * output: cuidador
 * pré-condição : Idoso é valido
 */
Cuidador BuscarCuidadorMaisProximo(Idoso idoso);

/* 
 * Atualiza os dados do idoso
 * inputs: o idoso
 * output: nenhum
 * pre-condicao: o idoso existe
 */
void AtualizarIdoso(Idoso idoso);

/* 
 * Verifica se o idoso esta vivo
 * inputs: o idoso
 * output: nenhum
 * pre-condicao: o idoso existe
 */
int EhIdosoVivo(Idoso idoso);

int CompararNomeIdoso(void *idoso, void *nome);



// DEBUG
char *IdosoToString(Idoso idoso);

#endif