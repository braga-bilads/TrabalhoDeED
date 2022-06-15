#ifndef REGISTRO_H
#define REGISTRO_H

#include "Localizador.h"
#include "FebreEnum.h"

typedef struct registro* Registro;

/* 
 * Aloca memoria para o registro e o inicializa
 * inputs: nenhum
 * output: o registro criado
 * pre-condicao: nenhuma
 */
Registro CriarRegistro();

/* 
 * Retorna a febre registrada
 * inputs: o registro
 * output: a febre registrada
 * pre-condicao: o registro existe
 */
FebreEnum RecuperaFebreRegistro(Registro registro);

/* 
 * Retorna a queda registrada
 * inputs: o registro
 * output: a queda registrada
 * pre-condicao: o registro existe
 */
int RecuperaQuedaRegistro(Registro registro);

/* 
 * Retorna a localizacao registrada
 * inputs: o registro
 * output: a localizacao registrada
 * pre-condicao: o registro existe
 */
Localizador RecuperaLocalizadorRegistro(Registro registro);

/* 
 * Retorna a contagem de febres baixas registrada
 * inputs: o registro
 * output: a contagem de febres baixas 
 * pre-condicao: o registro existe
 */
int RecuperaContadorFebreBaixa(Registro registro);

/* 
 * Libera memoria alocada para o registro
 * inputs: o registro
 * output: nenhum
 * pre-condicao: o registro existe
 */
void DeletarRegistro(Registro registro);

/* 
 * Atualiza os dados do registro
 * inputs: o registro, febre, queda e localizador
 * output: nenhum
 * pre-condicao: o registro e o localizador existem
 */
void AtualizarRegistro(Registro registro, FebreEnum febre, int queda, Localizador localizador);

/* 
 * Reseta o contador de febre baixa do registro
 * inputs: o registro
 * output: nenhum
 * pre-condicao: o registro existe
 */
void ResetarContadorFebreBaixa(Registro registro);

#endif