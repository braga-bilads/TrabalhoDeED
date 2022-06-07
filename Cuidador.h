#ifndef CUIDADOR_H
#define CUIDADOR_H

#include "Localizador.h"
#include "StreamReader.h"

typedef struct cuidador* Cuidador;

/* 
 * Aloca memoria para o cuidador e o inicializa
 * inputs: o nome do cuidador
 * output: o cuidador criado
 * pre-condicao: nenhuma
 */
Cuidador CriarCuidador(char *nome);

/* 
 * Retorna o nome do cuidador
 * inputs: o cuidador
 * output: o nome do cuidador
 * pre-condicao: o cuidador existe
 */
char *RecuperaNomeCuidador(Cuidador cuidador);

/* 
 * Retorna o localizador do cuidador
 * inputs: o cuidador
 * output: o localizador do cuidador
 * pre-condicao: o cuidador existe
 */
Localizador RecuperaLocalizadorCuidador(Cuidador cuidador);

/* 
 * Libera memoria alocada para o cuidador
 * inputs: o cuidador
 * output: nenhum
 * pre-condicao: o cuidador existe
 */
void DeletarCuidador(Cuidador cuidador);

/* 
 * Atualiza os dados do cuidador
 * inputs: o cuidador
 * output: nenhum
 * pre-condicao: o cuidador existe
 */
void AtualizarCuidador(Cuidador cuidador);



// DEBUG
char *CuidadorToString(Cuidador cuidador);

#endif