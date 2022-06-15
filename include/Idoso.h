#ifndef IDOSO_H
#define IDOSO_H

#include "Cuidador.h"
#include "Registro.h"
#include "StreamWriter.h"

typedef struct idoso * Idoso;

/* 
 * Aloca memoria para o idoso e o inicializa
 * inputs: o nome do idoso
 * output: o idoso criado
 * pre-condicao: o nome existe
 */
Idoso CriarIdoso(char *nome);

/**
 * Retorna o nome do idoso
 * inputs: idoso
 * output: o nome do idoso
 * pré-condição: idoso existe
 */
char * RecuperaNomeIdoso(Idoso idoso);

/**
 * Retorna o registro do idoso
 * inputs: idoso
 * output: o registro do idoso
 * pré-condição: idoso existe
 */
Registro RecuperaRegistroIdoso(Idoso idoso);

/**
 * Retorna o streamWriter do idoso
 * inputs: idoso
 * output: o streamWriter do idoso
 * pré-condição: idoso existe
 */
StreamWriter RecuperaStreamWriterIdoso(Idoso idoso);

/* 
 * Libera memoria alocada para o idoso
 * inputs: o idoso
 * output: nenhum
 * pre-condicao: o idoso existe
 */
void DeletarIdoso(void *idoso);

/**
 * Coloca um amigo na lista de amigos do idoso
 * inputs: idoso e o amigo
 * output: void
 * pré-condição: idoso e amigo existem 
 */
void AdicionarAmigo(Idoso idoso, Idoso amigo);

/**
 * Retira um amigo da lista de amigos do idoso
 * inputs: Idoso e amigo a ser retirado
 * output: void 
 * pré-condição: idoso e amigo são validos 
 */
void RemoverAmigo(Idoso idoso, Idoso amigo);

/**
 * Retorna o Amigo mais proximo do idoso
 * inputs: idoso
 * output: idoso mais proximo
 * pré-condição: idoso é valido 
 */
Idoso BuscarAmigoMaisProximo(Idoso idoso);

/**
 * Desfaz todas as amizades do idoso (caso de falecimento)
 * inputs: idoso
 * output: void
 * pré-condição: idoso é valido e foi declarado como falecido
 */
void DesfazerAmizades(Idoso idoso);

/**
 * Adiciona um cuidador na lista de cuidadores do Idoso selecionado
 * inputs: idoso e cuidador
 * output: void
 * pré-condição: idoso e cuidador são validos
 */
void AdicionarCuidador(Idoso idoso, Cuidador cuidador);

/**
 * Retorna o cuidador mais próximo do Idoso
 * inputs: idoso 
 * output: cuidador
 * pré-condição: Idoso é valido
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
 * output: 1 se o idoso esta vivo
 * pre-condicao: o idoso existe
 */
int EhIdosoVivo(Idoso idoso);

/*
 * Compara nome do idoso com um nome passado como parametro 
 * inputs: void pointer para idoso e void pointer para nome
 * output: 1 se iguais, diferente de 1 caso contrário
 * pre-condicao: idoso e nome existem
 */
int CompararNomeIdoso(void *idoso, void *nome);

#endif