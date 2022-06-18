#ifndef CUIDADOR_H
#define CUIDADOR_H

#include "Localizador.h"
#include "StreamReader.h"

//  Tipo que define cuidador (tipo opaco)
typedef struct cuidador* Cuidador;

/* 
 * Aloca memoria para o cuidador e o inicializa
 * inputs: nome do cuidador
 * output: cuidador criado
 * pre-condicao: nome existe e nao necessita ter sido alocado dinamicamente
 * pos-condicao: cuidador alocado e inicializado
 */
Cuidador CriarCuidador(char *nome);

/* 
 * Retorna o nome do cuidador
 * inputs: cuidador
 * output: nome do cuidador
 * pre-condicao: cuidador existe
 * pos-condicao: cuidador nao e modificado
 */
char *RecuperaNomeCuidador(Cuidador cuidador);

/* 
 * Retorna o localizador do cuidador
 * inputs: cuidador
 * output: localizador do cuidador
 * pre-condicao: cuidador existe
 * pos-condicao: cuidador nao e modificado
 */
Localizador RecuperaLocalizadorCuidador(Cuidador cuidador);

/* 
 * Libera memoria alocada para o cuidador
 * inputs: cuidador
 * output: nenhum
 * pre-condicao: cuidador existe
 * pos-condicao: toda a memoria alocada para cuidador foi liberada
 */
void DeletarCuidador(void *cuidador);

/* 
 * Atualiza os dados do cuidador
 * inputs: cuidador
 * output: nenhum
 * pre-condicao: cuidador existe
 * pos-condicao: os dados do cuidador foram alterados 
 *               de acordo com seus sensores
 */
void AtualizarCuidador(Cuidador cuidador);

/*
 * Compara nome do cuidador com um nome passado como parametro 
 * inputs: cuidador e nome
 * output: 1 se iguais, 0 caso contrario
 * pre-condicao: cuidador e nome existem, nome nao necessita 
 *               ter sido alocado dinamicamente
 * pos-condicao: o nome do cuidador foi comparado ao nome passado como parametro
 */
int CompararNomeCuidador(void *cuidador, void *nome);

#endif